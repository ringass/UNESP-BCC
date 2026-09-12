#pragma once
#include <unordered_map>
#include <string>
#include <cctype>

enum CodigoToken {
    // CODE_IDENTIFICADOR = 1,
    CODE_NUMERO        = 2,

    /* palavras reservadas */
    CODE_PROGRAM = 10,
    CODE_VAR = 11,
    CODE_INTEGER = 12,
    CODE_REAL = 13,
    CODE_BOOLEAN = 14,
    CODE_PROCEDURE = 15,
    CODE_BEGIN = 16,
    CODE_END = 17,
    CODE_IF = 18,
    CODE_THEN = 19,
    CODE_ELSE = 20,
    CODE_WHILE = 21,
    CODE_DO = 22,
    CODE_READ = 23,
    CODE_WRITE = 24,
    CODE_DIV = 25,
    CODE_AND = 26,
    CODE_OR = 27,
    CODE_NOT = 28,
    CODE_TRUE = 29,
    CODE_FALSE = 30,
    CODE_FUNCTION = 31,

    /* simbolos especiais */
    CODE_PONTO = 40,
    CODE_VIRGULA = 41,
    CODE_PONTO_VIRGULA = 42,
    CODE_DOIS_PONTOS = 43,
    CODE_ATRIBUICAO = 44,
    CODE_ABRE_PAR = 45,
    CODE_FECHA_PAR = 46,
    CODE_MAIS = 50,
    CODE_MENOS = 51,
    CODE_ASTERISCO = 52,
    CODE_IGUAL = 53,
    CODE_DIFERENTE = 54,
    CODE_MENOR = 55,
    CODE_MAIOR = 56,
    CODE_MENOR_IGUAL = 57,
    CODE_MAIOR_IGUAL = 58,
    CODE_EOF = 99
};

class TabelaSimbolos {
public:
    TabelaSimbolos() {
        reservadas = {
            {"program",   CODE_PROGRAM},
            {"var",       CODE_VAR},
            {"integer",   CODE_INTEGER},
            {"real",      CODE_REAL},
            {"boolean",   CODE_BOOLEAN},
            {"procedure", CODE_PROCEDURE},
            {"function",  CODE_FUNCTION},
            {"begin",     CODE_BEGIN},
            {"end",       CODE_END},
            {"if",        CODE_IF},
            {"then",      CODE_THEN},
            {"else",      CODE_ELSE},
            {"while",     CODE_WHILE},
            {"do",        CODE_DO},
            {"read",      CODE_READ},
            {"write",     CODE_WRITE},
            {"div",       CODE_DIV},
            {"and",       CODE_AND},
            {"or",        CODE_OR},
            {"not",       CODE_NOT},
            {"true",      CODE_TRUE},
            {"false",     CODE_FALSE}
        };

        especiais = {
            {".",  CODE_PONTO},
            {",",  CODE_VIRGULA},
            {";",  CODE_PONTO_VIRGULA},
            {":",  CODE_DOIS_PONTOS},
            {":=", CODE_ATRIBUICAO},
            {"(",  CODE_ABRE_PAR},
            {")",  CODE_FECHA_PAR},
            {"+",  CODE_MAIS},
            {"-",  CODE_MENOS},
            {"*",  CODE_ASTERISCO},
            {"=",  CODE_IGUAL},
            {"<>", CODE_DIFERENTE},
            {"<",  CODE_MENOR},
            {">",  CODE_MAIOR},
            {"<=", CODE_MENOR_IGUAL},
            {">=", CODE_MAIOR_IGUAL}
        };
    }

    //Case insensitive
    int buscarReservada(const std::string& lexema) const {
        std::string lower = lexema;
        for (char& c : lower) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        auto it = reservadas.find(lower);
        return (it != reservadas.end()) ? it->second : -1;
    }

    int buscarEspecial(const std::string& simbolo) const {
        auto it = especiais.find(simbolo);
        return (it != especiais.end()) ? it->second : -1;
    }

    //para id progressivo dos identificadores
    int buscaOuinsercaoId(const std::string& lexema) {
        auto it = identificadores.find(lexema);
        if (it != identificadores.end())
            return it->second;

        int cod = proximoId++;
        identificadores[lexema] = cod;
        return cod;
    }

private:
    std::unordered_map<std::string, int> reservadas;
    std::unordered_map<std::string, int> especiais;
    std::unordered_map<std::string, int> identificadores;

    int proximoId  = 100;
};
