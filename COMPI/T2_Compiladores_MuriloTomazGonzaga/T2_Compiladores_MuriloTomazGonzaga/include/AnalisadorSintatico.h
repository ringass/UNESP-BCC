#pragma once
#include <string>
#include <vector>
#include "Token.h"
#include "TabelaSimbolos.h"

class AnalisadorSintatico {
public:
    explicit AnalisadorSintatico(const std::string& nomeArquivo);
    void analisar();

private:
    std::vector<Token> tokens;
    std::size_t pos;

    const Token& atual() const;
    const Token& verproximo(std::size_t distancia = 1) const;
    bool aceitar(int codigo);
    void esperar(int codigo, const std::string& esperado);
    void erro(const std::string& mensagem) const;

    bool tokenIdentificador(const Token& t) const;
    bool tokenTipo(const Token& t) const;
    bool operadorRelacional(int codigo) const;
    bool inicioComandoSemRotulo(int codigo) const;

    void programa();
    void bloco();
    void parteDeclaracoesVariaveis();
    void declaracaoVariaveis();
    void listaIdentificadores();
    void parteDeclaracoesSubRotinas();
    void declaracaoProcedimento();
    void declaracaoFuncao();
    void parametrosFormais();
    void secaoParametrosFormais();
    void comandoComposto();
    void comando();
    void comandoSemRotulo();
    void atribuicao();
    void chamadaProcedimento();
    void comandoCondicional();
    void comandoRepetitivo();
    void listaExpressoes();
    void expressao();
    void relacao();
    void expressaoSimples();
    void termo();
    void fator();
    void variavel();
    void chamadaFuncao();
    void numero();
    void identificador();
    void tipo();
};
