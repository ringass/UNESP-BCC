#include "AnalisadorSintatico.h"
#include "AnalisadorLexico.h"
#include <iostream>
#include <stdexcept>

//carrega os tokens usando o lexico
AnalisadorSintatico::AnalisadorSintatico(const std::string& nomeArquivo)
    : pos(0)
{
    AnalisadorLexico lexico(nomeArquivo, "", false);

    Token t = lexico.proximoToken();
    while (t.codigo != CODE_EOF) {
        tokens.push_back(t);
        t = lexico.proximoToken();
    }
    tokens.push_back(t);
}

//funcao analisar
void AnalisadorSintatico::analisar() {
    try {
        programa();
        esperar(CODE_EOF, "fim do arquivo");
        std::cout << "[OK] Analise sintatica concluida com sucesso.\n";
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << '\n';
        std::exit(1);
    }
}

//retorna token atual
const Token& AnalisadorSintatico::atual() const {
    return tokens[pos];
}

//olha tokens a frente
const Token& AnalisadorSintatico::verproximo(std::size_t distancia) const {
    std::size_t alvo = pos + distancia;
    if (alvo >= tokens.size())
        return tokens.back();
    return tokens[alvo];
}

//aceita token se for o esperado
bool AnalisadorSintatico::aceitar(int codigo) {
    if (atual().codigo == codigo) {
        pos++;
        return true;
    }
    return false;
}

//obriga token esperado
void AnalisadorSintatico::esperar(int codigo, const std::string& esperado) {
    if (!aceitar(codigo)) {
        erro("Esperado " + esperado + ", encontrado '" + atual().lexema + "'");
    }
}

//funcao erro sintatico
void AnalisadorSintatico::erro(const std::string& mensagem) const {
    throw std::runtime_error("[ERRO SINTATICO] Linha " + std::to_string(atual().linha) + ": " + mensagem);
}

//verificacoes auxiliares
bool AnalisadorSintatico::tokenIdentificador(const Token& t) const {
    return t.codigo >= 100;
}

bool AnalisadorSintatico::tokenTipo(const Token& t) const {
    return t.codigo == CODE_INTEGER ||
           t.codigo == CODE_BOOLEAN ||
           t.codigo == CODE_REAL ||
           tokenIdentificador(t);
}

bool AnalisadorSintatico::operadorRelacional(int codigo) const {
    return codigo == CODE_IGUAL ||
           codigo == CODE_DIFERENTE ||
           codigo == CODE_MENOR ||
           codigo == CODE_MENOR_IGUAL ||
           codigo == CODE_MAIOR ||
           codigo == CODE_MAIOR_IGUAL;
}

bool AnalisadorSintatico::inicioComandoSemRotulo(int codigo) const {
    return codigo >= 100 ||
           codigo == CODE_READ ||
           codigo == CODE_WRITE ||
           codigo == CODE_BEGIN ||
           codigo == CODE_IF ||
           codigo == CODE_WHILE;
}

//regra programa
void AnalisadorSintatico::programa() {
    esperar(CODE_PROGRAM, "'program'");
    identificador();
    esperar(CODE_PONTO_VIRGULA, "';'");
    bloco();
    esperar(CODE_PONTO, "'.'");
}

//regra bloco
void AnalisadorSintatico::bloco() {
    if (atual().codigo == CODE_VAR)
        parteDeclaracoesVariaveis();

    if (atual().codigo == CODE_PROCEDURE || atual().codigo == CODE_FUNCTION)
        parteDeclaracoesSubRotinas();

    comandoComposto();
}

//declaracoes de variaveis
void AnalisadorSintatico::parteDeclaracoesVariaveis() {
    esperar(CODE_VAR, "'var'");
    declaracaoVariaveis();
    esperar(CODE_PONTO_VIRGULA, "';'");

    while (tokenIdentificador(atual())) {
        declaracaoVariaveis();
        esperar(CODE_PONTO_VIRGULA, "';'");
    }
}

void AnalisadorSintatico::declaracaoVariaveis() {
    listaIdentificadores();
    esperar(CODE_DOIS_PONTOS, "':'");
    tipo();
}

void AnalisadorSintatico::listaIdentificadores() {
    identificador();
    while (aceitar(CODE_VIRGULA))
        identificador();
}

//declaracoes de sub-rotinas
void AnalisadorSintatico::parteDeclaracoesSubRotinas() {
    while (atual().codigo == CODE_PROCEDURE || atual().codigo == CODE_FUNCTION) {
        if (atual().codigo == CODE_PROCEDURE)
            declaracaoProcedimento();
        else
            declaracaoFuncao();

        esperar(CODE_PONTO_VIRGULA, "';' depois da sub-rotina");
    }
}

void AnalisadorSintatico::declaracaoProcedimento() {
    esperar(CODE_PROCEDURE, "'procedure'");
    identificador();

    if (atual().codigo == CODE_ABRE_PAR)
        parametrosFormais();

    esperar(CODE_PONTO_VIRGULA, "';'");
    bloco();
}

void AnalisadorSintatico::declaracaoFuncao() {
    esperar(CODE_FUNCTION, "'function'");
    identificador();

    if (atual().codigo == CODE_ABRE_PAR)
        parametrosFormais();

    esperar(CODE_DOIS_PONTOS, "':'");
    tipo();
    esperar(CODE_PONTO_VIRGULA, "';'");
    bloco();
}

//parametros das sub-rotinas
void AnalisadorSintatico::parametrosFormais() {
    esperar(CODE_ABRE_PAR, "'('");
    secaoParametrosFormais();

    while (aceitar(CODE_PONTO_VIRGULA))
        secaoParametrosFormais();

    esperar(CODE_FECHA_PAR, "')'");
}

void AnalisadorSintatico::secaoParametrosFormais() {
    aceitar(CODE_VAR);
    listaIdentificadores();
    esperar(CODE_DOIS_PONTOS, "':'");
    tipo();
}

//comando begin-end
void AnalisadorSintatico::comandoComposto() {
    esperar(CODE_BEGIN, "'begin'");

    if (atual().codigo != CODE_END) {
        comando();

        while (aceitar(CODE_PONTO_VIRGULA)) {
            if (atual().codigo == CODE_END)
                break;
            comando();
        }

        if (atual().codigo != CODE_END)
            erro("Esperado ';' ou 'end' depois do comando");
    }

    esperar(CODE_END, "'end'");
}

//comandos
void AnalisadorSintatico::comando() {
    if (atual().codigo == CODE_NUMERO && verproximo().codigo == CODE_DOIS_PONTOS) {
        numero();
        esperar(CODE_DOIS_PONTOS, "':' depois do rotulo");
    }

    comandoSemRotulo();
}

void AnalisadorSintatico::comandoSemRotulo() {
    if (tokenIdentificador(atual())) {
        if (verproximo().codigo == CODE_ATRIBUICAO)
            atribuicao();
        else
            chamadaProcedimento();
        return;
    }

    if (atual().codigo == CODE_READ || atual().codigo == CODE_WRITE) {
        chamadaProcedimento();
        return;
    }

    if (atual().codigo == CODE_BEGIN) {
        comandoComposto();
        return;
    }

    if (atual().codigo == CODE_IF) {
        comandoCondicional();
        return;
    }

    if (atual().codigo == CODE_WHILE) {
        comandoRepetitivo();
        return;
    }

    erro("Inicio de comando invalido: '" + atual().lexema + "'");
}

//comando de atribuicao
void AnalisadorSintatico::atribuicao() {
    variavel();
    esperar(CODE_ATRIBUICAO, "':='");
    expressao();
}

//chamada de procedimento
void AnalisadorSintatico::chamadaProcedimento() {
    if (tokenIdentificador(atual()) || atual().codigo == CODE_READ || atual().codigo == CODE_WRITE)
        pos++;
    else
        erro("Esperado identificador de procedimento");

    if (aceitar(CODE_ABRE_PAR)) {
        if (atual().codigo != CODE_FECHA_PAR)
            listaExpressoes();
        esperar(CODE_FECHA_PAR, "')'");
    }
}

//comando if
void AnalisadorSintatico::comandoCondicional() {
    esperar(CODE_IF, "'if'");
    expressao();
    esperar(CODE_THEN, "'then'");
    comandoSemRotulo();

    if (aceitar(CODE_ELSE))
        comandoSemRotulo();
}

//comando while
void AnalisadorSintatico::comandoRepetitivo() {
    esperar(CODE_WHILE, "'while'");
    expressao();
    esperar(CODE_DO, "'do'");
    comandoSemRotulo();
}

//lista de expressoes
void AnalisadorSintatico::listaExpressoes() {
    expressao();
    while (aceitar(CODE_VIRGULA))
        expressao();
}

//expressao relacional
void AnalisadorSintatico::expressao() {
    expressaoSimples();

    if (operadorRelacional(atual().codigo)) {
        relacao();
        expressaoSimples();
    }
}

void AnalisadorSintatico::relacao() {
    if (operadorRelacional(atual().codigo))
        pos++;
    else
        erro("Esperado operador relacional");
}

//expressao simples
void AnalisadorSintatico::expressaoSimples() {
    if (atual().codigo == CODE_MAIS || atual().codigo == CODE_MENOS)
        pos++;

    termo();

    while (atual().codigo == CODE_MAIS || atual().codigo == CODE_MENOS || atual().codigo == CODE_OR) {
        pos++;
        termo();
    }
}

//termo da expressao
void AnalisadorSintatico::termo() {
    fator();

    while (atual().codigo == CODE_ASTERISCO || atual().codigo == CODE_DIV || atual().codigo == CODE_AND) {
        pos++;
        fator();
    }
}

//fator da expressao
void AnalisadorSintatico::fator() {
    if (tokenIdentificador(atual())) {
        if (verproximo().codigo == CODE_ABRE_PAR)
            chamadaFuncao();
        else
            variavel();
        return;
    }

    if (atual().codigo == CODE_NUMERO) {
        numero();
        return;
    }

    if (atual().codigo == CODE_TRUE || atual().codigo == CODE_FALSE) {
        pos++;
        return;
    }

    if (aceitar(CODE_ABRE_PAR)) {
        expressao();
        esperar(CODE_FECHA_PAR, "')'");
        return;
    }

    if (aceitar(CODE_NOT)) {
        fator();
        return;
    }

    erro("Fator invalido: '" + atual().lexema + "'");
}

//variavel
void AnalisadorSintatico::variavel() {
    identificador();
}

//chamada de funcao
void AnalisadorSintatico::chamadaFuncao() {
    identificador();

    if (aceitar(CODE_ABRE_PAR)) {
        if (atual().codigo != CODE_FECHA_PAR)
            listaExpressoes();
        esperar(CODE_FECHA_PAR, "')'");
    }
}

//numero
void AnalisadorSintatico::numero() {
    esperar(CODE_NUMERO, "numero");
}

//identificador
void AnalisadorSintatico::identificador() {
    if (tokenIdentificador(atual()))
        pos++;
    else
        erro("Esperado identificador, encontrado '" + atual().lexema + "'");
}

//tipo
void AnalisadorSintatico::tipo() {
    if (tokenTipo(atual()))
        pos++;
    else
        erro("Esperado tipo, encontrado '" + atual().lexema + "'");
}
