/*
    Nome:         Murilo Tomaz Gonzaga
    RA:           241024684
    Disciplina:   Compiladores
    Trabalho:     T1 - Analisador Lexico
    OS:           Linux (EndeavourOS)
    Compilador:   clang (clang++) version 22.1.3
    IDE:          Neovim
    
    COMPILAR: clang++ -std=c++17 main.cpp AnalisadorLexico.cpp -o analisador
    EXECUTAR: ./analisador Trab1_Compiladores.txt
    ANALISAR CÓDIGO CODIFICADO: cat saida_codificado.txt
 */

#include <iostream>
#include "AnalisadorLexico.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Uso correto: " << argv[0] << " <in.txt>" << argv[2] << " out.txt\n";
        return 1;
    }

    AnalisadorLexico analisador(argv[1], (argc >= 3) ? argv[2] : "");
    analisador.analisar();

    return 0;
}
