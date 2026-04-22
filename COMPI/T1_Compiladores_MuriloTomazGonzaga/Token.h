#pragma once
#include <string>

class Token {
public:
    int codigo;
    std::string lexema;
    int linha;

    Token(int codigo, const std::string& lexema, int linha)
        : codigo(codigo), lexema(lexema), linha(linha) {}

};
