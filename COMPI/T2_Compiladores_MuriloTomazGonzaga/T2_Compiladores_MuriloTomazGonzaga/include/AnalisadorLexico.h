#pragma once
#include <fstream>
#include <string>
#include "Token.h"
#include "TabelaSimbolos.h"

class AnalisadorLexico {
public:
    AnalisadorLexico(const std::string& nomeIn,
                     const std::string& nomeOut = "",
                     bool gerarArquivo = true);

    void analisar();
    Token proximoToken();

private:
    std::ifstream arquivoIn;
    std::ofstream arquivoOut;
    std::string nomeOut;
    bool gerarArquivo;
    TabelaSimbolos tabela;

    char proximo;
    std::string atomo;
    int simbolo;
    int linha;

    void PROXIMO();
    int  CODIGO(const std::string& lexema);
    void ERRO(const std::string& msg);

    void ANALISADOR_LEXICO();

    void imprimirCabecalho() const;
    void imprimirTabela(const Token& t) const;
    void imprimirArquivo(const Token& t);
};
