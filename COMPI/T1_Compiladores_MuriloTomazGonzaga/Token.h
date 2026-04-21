#pragma once
#include <string>
#include "TabelaSimbolos.h"


class Token {
public:
    int codigo;
    std::string lexema;
    int linha;

    Token(int codigo, const std::string& lexema, int linha)
        : codigo(codigo), lexema(lexema), linha(linha) {}

    inline std::string tipoToken() const {
        switch (codigo) {
            case CODE_IDENTIFICADOR: return "IDENTIFICADOR";
            case CODE_NUMERO:        return "NUMERO";
            case CODE_PROGRAM:       return "program";
            case CODE_VAR:           return "var";
            case CODE_INTEGER:       return "integer";
            case CODE_REAL:          return "real";
            case CODE_BOOLEAN:       return "boolean";
            case CODE_PROCEDURE:     return "procedure";
            case CODE_BEGIN:         return "begin";
            case CODE_END:           return "end";
            case CODE_IF:            return "if";
            case CODE_THEN:          return "then";
            case CODE_ELSE:          return "else";
            case CODE_WHILE:         return "while";
            case CODE_DO:            return "do";
            case CODE_READ:          return "read";
            case CODE_WRITE:         return "write";
            case CODE_DIV:           return "div";
            case CODE_AND:           return "and";
            case CODE_OR:            return "or";
            case CODE_NOT:           return "not";
            case CODE_TRUE:          return "true";
            case CODE_FALSE:         return "false";
            case CODE_PONTO:         return ".";
            case CODE_VIRGULA:       return ",";
            case CODE_PONTO_VIRGULA: return ";";
            case CODE_DOIS_PONTOS:   return ":";
            case CODE_ATRIBUICAO:    return ":=";
            case CODE_ABRE_PAR:      return "(";
            case CODE_FECHA_PAR:     return ")";
            case CODE_MAIS:          return "+";
            case CODE_MENOS:         return "-";
            case CODE_ASTERISCO:     return "*";
            case CODE_IGUAL:         return "=";
            case CODE_DIFERENTE:     return "<>";
            case CODE_MENOR:         return "<";
            case CODE_MAIOR:         return ">";
            case CODE_MENOR_IGUAL:   return "<=";
            case CODE_MAIOR_IGUAL:   return ">=";
            case CODE_EOF:           return "EOF";
            default:                return "DESCONHECIDO";
        }
    }
};
