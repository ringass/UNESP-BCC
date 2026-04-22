#include "AnalisadorLexico.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>

AnalisadorLexico::AnalisadorLexico(const std::string& nomeIn, const std::string& nomeOut)
    : proximo(' '), simbolo(0), linha(1)
{
    this->nomeOut = nomeOut.empty() ? "saida_codificada.txt" : nomeOut;

    arquivoIn.open(nomeIn);
    arquivoOut.open(this->nomeOut); 

    if (!arquivoIn.is_open() || !arquivoOut.is_open()) {
        std::cerr << "Erro ao abrir arquivos.\n";
        exit(1);
    }

    PROXIMO();
}
//funcao proximo
void AnalisadorLexico::PROXIMO() {
    int c = arquivoIn.get();

    if (c == EOF) {
        proximo = '\0';
        return;
    }

    if (c == '\n') {
        proximo = '\n';
        // linha++;
        return;
    }

    proximo = static_cast<char>(c);
}
//funcao codigo
int AnalisadorLexico::CODIGO(const std::string& lexema) {
    int cod = tabela.buscarEspecial(lexema); //busca no map especiais
    if (cod != -1) return cod;

    cod = tabela.buscarReservada(lexema); //busca no map reservadas
    if (cod != -1) return cod;

    return -1;
}
//funcao erro
void AnalisadorLexico::ERRO(const std::string& msg) {
    std::cerr << "\n[ERRO] Linha " << linha << ": " << msg << " (caractere: '" << proximo << "')\n";
    exit(1);
}

//algoritmo da aula 5 com ressalvas para implementacao do arquivo codificado
void AnalisadorLexico::ANALISADOR_LEXICO() {
    atomo.clear();

    
    while (proximo != '\0' && std::isspace(static_cast<unsigned char>(proximo))) {
        if (proximo == '\n')
            linha++;
        arquivoOut << proximo; //imprime os espaços (qualquer tipo já quee usamos isspace) para reproduzir identacao no out.txt
        PROXIMO();
    }

   
    if (proximo == '\0') {
        simbolo = CODE_EOF;
        return;
    }

    
    if (std::string(".,;:()+-*=<>").find(proximo) != std::string::npos) {
        std::string s(1, proximo);
        
        PROXIMO();

        if ((s == ":" && proximo == '=') ||
            (s == "<" && proximo == '=') ||
            (s == ">" && proximo == '=') ||
            (s == "<" && proximo == '>')) {
            s += proximo;
            PROXIMO();
        }

        simbolo = CODIGO(s);
        atomo = s;
        return;
    }

    
    if (std::isalpha(static_cast<unsigned char>(proximo))) {
        do {
            atomo += proximo;
            PROXIMO();
        } while (std::isalnum(static_cast<unsigned char>(proximo)) || proximo == '_');

        int cod = CODIGO(atomo);
        simbolo = (cod != -1) ? cod : tabela.buscaOuinsercaoId(atomo);
        return;

    }
    
    if (std::isdigit(static_cast<unsigned char>(proximo))) {
        do {
            atomo += proximo;
            PROXIMO();
        } while (std::isdigit(static_cast<unsigned char>(proximo)));

        if (std::isalpha(static_cast<unsigned char>(proximo)))
            ERRO("Identificador ou numero mal formado");

        simbolo = CODE_NUMERO;
        return;
    }

    ERRO("Simbolo especial desconhecido");
}

void AnalisadorLexico::analisar() {
    imprimirCabecalho();
    
    do {
        ANALISADOR_LEXICO();
        if (simbolo != CODE_EOF) {
            Token t(simbolo, atomo, linha);

            imprimirTabela(t);
            imprimirArquivo(t);

        }
    } while (simbolo != CODE_EOF);

    std::cout << "\n[OK] Analise lexica concluida com sucesso!! " << linha << " linha(s) processada(s).\nArquivo " << nomeOut << " gerado.\n";
}

//tabela e cabecalho formada no terminal, utilizando left e setw para formatacao
void AnalisadorLexico::imprimirCabecalho() const {
    std::cout << std::left
              << std::setw(15)  << "LINHA"
              << std::setw(22) << "ATOMO"
              << std::setw(10)  << "CODIGO"
              << "\n"
              << std::string(62, '-') << "\n";
}

void AnalisadorLexico::imprimirTabela(const Token& t) const {
    std::cout << std::left
              << std::setw(15)  << t.linha
              << std::setw(22) << t.lexema
              << std::setw(10)  << t.codigo
              << "\n";
}

//impressão no arquivo out
void AnalisadorLexico::imprimirArquivo(const Token& t) {

    if (t.codigo >= 100) {
        arquivoOut << "id_" << t.codigo << "(" << t.lexema << ")";
    } 
    else if (t.codigo >= 10 && t.codigo <= 30) {
        arquivoOut << "res_" << t.codigo;
    } 
    else if (t.codigo >= 40 && t.codigo <= 58) {
        arquivoOut << "op_" << t.codigo;
    } 
    else if (t.codigo == CODE_NUMERO) {
        arquivoOut << "num_" << t.lexema;
    }

    if (proximo != '\0' && !std::isspace(static_cast<unsigned char>(proximo))) {
        arquivoOut << " ";
    }
}
