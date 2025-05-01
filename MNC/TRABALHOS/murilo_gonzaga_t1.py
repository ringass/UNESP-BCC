import math
import os
import timeit
import matplotlib.pyplot as plt
import numpy as np

#valores globais de epsilon e sigma, utilados no problema 4
epsilon = 1.0 
sigma = 1.0

# Funções numéricas
def problema1(x):
    return 5 * x - 100


def problema2(V):
    return 1e-12 * (math.exp(V / 0.025) - 1) - 0.01


def problema3(x):
    return (x**2 / 1e5 - x) - 1e-5


def problema4(r):
    return 24 * epsilon * (2 * (sigma / r) ** 13 - (sigma / r) ** 7)


def problema5(K):
    return K - 1 - math.exp(-K)


funcoes_numericas = [problema1, problema2, problema3, problema4, problema5]


# Métodos numéricos

#bissecao
def bissecao(f, a, b, E=1e-4, max_i=1000):
    pontos = []
    for i in range(max_i):
        x = (a + b) / 2
        fx = f(x)
        pontos.append((i + 1, x, fx))
        if abs(fx) < E or abs(b - a) < E:
            return x, pontos
        if f(a) * fx < 0:
            b = x
        else:
            a = x
    return None, pontos


#falsa posicao
def falsa_posicao(f, a, b, E=1e-4, max_i=1000):
    pontos = []
    if f(a) * f(b) >= 0:
        return None, pontos
    for i in range(max_i):
        fa = f(a)
        fb = f(b)
        x = (a * fb - b * fa) / (fb - fa)
        fx = f(x)
        pontos.append((i + 1, x, fx))
        if abs(fx) < E or abs(b - a) < E:
            return x, pontos
        if fa * fx < 0:
            b = x
        else:
            a = x
    return None, pontos

#newton-raphson
def newton(f, df, x0, E=1e-4, max_i=1000):
    pontos = []
    for i in range(max_i):
        fx = f(x0)
        dfx = df(x0)
        if abs(dfx) < 1e-10:
            return None, pontos
        x1 = x0 - fx / dfx
        pontos.append((i + 1, x1, f(x1)))
        if abs(f(x1)) < E or abs(x1 - x0) / max(1, abs(x1)) < E:
            return x1, pontos
        x0 = x1
    return None, pontos

# Derivada por diferenca finita central
def derivada_numerica(f, x, h=1e-6):
    return (f(x + h) - f(x - h)) / (2 * h)

# Funções auxiliares
def clear_terminal():
    os.system("cls" if os.name == "nt" else "clear")


def medir_tempo(func): #funcao para medir o tempo de cada metodo
    inicio = timeit.default_timer()
    resultado = func()
    return resultado, timeit.default_timer() - inicio

def executar_metodo(nome, metodo, args, func, cor): #execucao do metodo de retorno das info para que o vet metodo na main consigo passar para as "show" functions
    (raiz, pontos), tempo = medir_tempo(lambda: metodo(*args))
    if pontos:
        return (nome, pontos, raiz, cor, tempo, len(pontos))
    return None


#funcao graficas
def plot_results(metodos, titulo):
    plt.figure(figsize=(15, 5))
    nomes = [m[0] for m in metodos]
    tempos = [m[4] for m in metodos]
    iteracoes = [m[5] for m in metodos]

    plt.subplot(1, 3, 1)
    plt.bar(nomes, tempos, color=["blue", "black", "red"])
    plt.title("Tempo de Execução (s)")
    plt.ylabel("Segundos")

    plt.subplot(1, 3, 2)
    plt.bar(nomes, iteracoes, color=["blue", "black", "red"])
    plt.title("Número de Iterações")
    plt.ylabel("Iterações")

    plt.subplot(1, 3, 3)
    for nome, pontos, _, cor, _, _ in metodos:
        i, x, _ = zip(*pontos)
        plt.plot(i, x, ".-", color=cor, label=nome)
    plt.xlabel("Iteração")
    plt.ylabel("Valor de x")
    plt.title(f"Convergência da Raiz - {titulo}")
    plt.legend()
    plt.grid(True)

    plt.tight_layout()
    plt.savefig(f"Analise de performance - {titulo}.png")
    plt.close()

#impressao de um relatorio no cmd
def relatorio(metodos, func):
    print("\nRELATÓRIO DE RESULTADOS:\n")
    for nome, pontos, raiz, _, tempo, iteracoes in metodos:
        convergiu = "Sim" if raiz is not None else "Não"
        erro = abs(func(raiz)) if raiz is not None else "-"
        print(
            f"[{nome}]\n - Convergiu: {convergiu}\n - Iterações: {iteracoes}\n - Tempo: {tempo:.6f} segundos\n - Raiz: {raiz if raiz is not None else '-'}\n - Erro absoluto |f(x)|: {erro if erro == '-' else f'{erro:.4e}'}\n"
        )

#escolha de um problema
def escolher_problema():
    global epsilon, sigma
    print("\nProblemas disponíveis:")
    for i in range(1, 6):
        print(f"[{i}] - Problema {i}")
    escolha = int(input("Escolha o problema: "))
    if escolha == 4:
        epsilon = float(input("Digite o valor de epsilon (padrão=1.0): ") or 1.0)
        sigma = float(input("Digite o valor de sigma (padrão=1.0): ") or 1.0)
    return escolha

#main function
def main():
    escolha = escolher_problema() #escolha do problema
    func = funcoes_numericas[escolha - 1]#vetor para pegar as funcoes de cada problema

    a = float(input("a = "))
    b = float(input("b = "))
    x0 = float(input("x (Newton) = "))
    E = float(input("Digite o valor de erro (ex: 1e-3): ") or 1e-4)
    
    clear_terminal()

    metodos = [] #vetor para guardar a informacao de cada metodo
    
    configs = [
        ("Bisseção", bissecao, (func, a, b, E), "blue"),
        ("Falsa Posição", falsa_posicao, (func, a, b, E), "black"),
        ("Newton", newton, (func, lambda x: derivada_numerica(func, x), x0, E), "red"),
    ]

    for nome, metodo, args, cor in configs: #iterar em configs executando os metodos
        resultado = executar_metodo(nome, metodo, args, func, cor)
        if resultado:
            metodos.append(resultado) #adiciona para realizar as funcoes de "show"

    titulo = f"Problema {escolha}"
    if metodos:
        plot_results(metodos, titulo)
        relatorio(metodos, func)
    else:
        print("Nenhum método convergiu para os parâmetros fornecidos.")


while True:
    clear_terminal()
    main()
    if input("Deseja resolver outro problema? (s/n): ").lower() != "s":
        break
