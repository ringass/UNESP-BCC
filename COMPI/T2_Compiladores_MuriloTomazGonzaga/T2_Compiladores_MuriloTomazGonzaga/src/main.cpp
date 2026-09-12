/*
    Nome:         Murilo Tomaz Gonzaga
    RA:           241024684
    Disciplina:   Compiladores
    Trabalho:     T2 - Analisador Sintatico
    OS:           Linux (EndeavourOS)
    Compilador:   Clang (clang++) version 22.1.3
    IDE:          Neovim

    COMPILAR:
        clang++ -std=c++17 -Iinclude src/main.cpp src/AnalisadorLexico.cpp src/AnalisadorSintatico.cpp -o bin/analisador

    EXECUTAR ANALISE SINTATICA:[obviamente utiliza o léxico porem não imprime as informações do léxico]
        ./bin/analisador tests/Trab1_Compiladores.txt

    EXECUTAR ANALISE LEXICA DO T1, OPCIONAL:
        ./bin/analisador --lexico tests/Trab1_Compiladores.txt tests/saida_codificada.txt
*/

#include <iostream>
#include <string>
#include "AnalisadorLexico.h"
#include "AnalisadorSintatico.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Uso sintatico: " << argv[0] << " <in.txt>\n"
                  << "Uso lexico:    " << argv[0] << " --lexico <in.txt> <out.txt>\n";
        return 1;
    }

    std::string primeiroArg = argv[1];

    if (primeiroArg == "--lexico") {
        if (argc < 3) {
            std::cerr << "Uso correto: " << argv[0] << " --lexico <in.txt> <out.txt>\n";
            return 1;
        }

        AnalisadorLexico analisador(argv[2], (argc >= 4) ? argv[3] : "");
        analisador.analisar();
        return 0;
    }

    AnalisadorSintatico analisador(argv[1]);
    analisador.analisar();

    return 0;
}
