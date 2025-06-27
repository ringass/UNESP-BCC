from sympy import symbols, factorial, lambdify, pprint
import numpy as np
import matplotlib.pyplot as plt
import os
import tabulate
import time

def lagrange(xv, yv):
    if len(xv) != len(yv):
        return "N/A"

    x = symbols('x')
    poly = 0

    for i in range(len(yv)):
        Li = 1
        for j in range(len(xv)):
            if j != i:
                Li *= (x - xv[j]) / (xv[i] - xv[j])
        poly += yv[i] * Li

    return poly

def newton(xv, yv):
    if len(xv) != len(yv):
        return "N/A"

    n = len(xv)
    x = symbols('x')
    table = np.zeros((n, n))

    for i in range(n):
        table[i][0] = yv[i]

    for j in range(1, n):
        for i in range(n - j):
            table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (xv[i + j] - xv[i])

    poly = table[0][0]
    term = 1
    for i in range(1, n):
        term *= (x - xv[i - 1])
        poly += table[0][i] * term

    return poly

def newton_gregory(xv, yv):
    if len(xv) != len(yv):
        return "N/A"

    n = len(xv)
    h = xv[1] - xv[0]

    for i in range(1, n - 1):
        if not np.isclose(xv[i + 1] - xv[i], h):
            return "N/A"

    x = symbols('x')
    s = (x - xv[0]) / h
    table = np.zeros((n, n))

    for i in range(n):
        table[i][0] = yv[i]

    for j in range(1, n):
        for i in range(n - j):
            table[i][j] = table[i + 1][j - 1] - table[i][j - 1]

    poly = table[0][0]
    term = 1
    for i in range(1, n):
        term *= (s - (i - 1))
        poly += (table[0][i] * term) / factorial(i)

    return poly

def main():
    os.system("chcp 65001")
    xv = [0, 1, 2, 3, 4, 5]
    yv = [2.1, 3.8, 5.2, 6.1, 7.8, 8.9]

    x = symbols('x')

    t1 = time.time()
    p_lagrange = lagrange(xv, yv)
    t1 = time.time() - t1

    t2 = time.time()
    p_newton = newton(xv, yv)
    t2 = time.time() - t2

    t3 = time.time()
    p_gregory = newton_gregory(xv, yv)
    t3 = time.time() - t3

    err_ln = abs(p_lagrange.subs(x, 2.5) - p_newton.subs(x, 2.5))
    err_lg = abs(p_lagrange.subs(x, 2.5) - p_gregory.subs(x, 2.5))
    err_ng = abs(p_newton.subs(x, 2.5) - p_gregory.subs(x, 2.5))

    run = True

    while run:
        os.system("cls" if os.name == "nt" else "clear")

        print("Problema analisado:")
        tabela = list(zip(xv, yv))
        print(tabulate.tabulate(tabela, headers=["x", "f(x)"], tablefmt="heavy_outline"))
        
        print("1 - Executar métodos")
        print("2 - Comparar a eficiência dos métodos")
        print("3 - Gerar gráficos de comparação")
        print("4 - Sair\n")

        op = int(input("Insira sua escolha: "))

        match op:
            case 1:
                os.system("cls" if os.name == "nt" else "clear")

                print("1 - Lagrange")
                print("2 - Newton")
                print("3 - Newton-Gregory\n")

                op2 = int(input("insira sua escolha: "))

                match op2:
                    case 1:
                        os.system("cls" if os.name == "nt" else "clear")
                        print("Polinômio de Lagrange:\n")
                        pprint(p_lagrange)
                        print(f"\nValor em x = 2.5: {p_lagrange.subs(x, 2.5)}")
                        print(f"Tempo: {t1} s")
                        input("Enter para continuar: ")

                    case 2:
                        os.system("cls" if os.name == "nt" else "clear")
                        print("Polinômio de Newton: ")
                        pprint(p_newton)
                        print(f"\nValor em x = 2.5: {p_newton.subs(x, 2.5)}")
                        print(f"Tempo: {t2} s")
                        input("Enter para continuar: ")

                    case 3:
                        os.system("cls" if os.name == "nt" else "clear")
                        print("Polinômio de Newton-Gregory: ")
                        pprint(p_gregory)
                        print(f"\nValor em x = 2.5: {p_gregory.subs(x, 2.5)}")
                        print(f"Tempo: {t3} s")
                        input("Enter para continuar: ")
            
            case 2:
                os.system("cls" if os.name == "nt" else "clear")

                tab1 = [["Lagrange", t1, p_lagrange.subs(x, 2.5)],
                        ["Newton", t2, p_newton.subs(x, 2.5)],
                        ["Newton-Gregory", t3, p_gregory.subs(x, 2.5)]]

                tab2 = [["Lagrange x Newton", err_ln],
                        ["Lagrange x Newton-Gregory", err_lg],
                        ["Newton x Newton-Gregory", err_ng]]
                
                print("Comparação entre métodos: ")
                print(tabulate.tabulate(tab1, headers=["Método", "Tempo (s)", "Valor em x=2.5"], tablefmt="heavy_outline"))
                print(tabulate.tabulate(tab2, headers=["Erro entre métodos", "Erro"], tablefmt="heavy_outline"))
                input("Enter para continuar: ")

            case 3:
                os.system("cls" if os.name == "nt" else "clear")

                f_lagrange = lambdify(x, p_lagrange, modules='numpy')
                f_newton = lambdify(x, p_newton, modules='numpy')
                f_gregory = lambdify(x, p_gregory, modules='numpy')

                xv_plot = np.linspace(min(xv), max(xv), 400)
                y_lag = f_lagrange(xv_plot)
                y_new = f_newton(xv_plot)
                y_greg = f_gregory(xv_plot)

                plt.figure(figsize=(10, 6))
                plt.plot(xv_plot, y_lag, label='Lagrange', color='green')
                plt.plot(xv_plot, y_new, label='Newton', linestyle='--', color='red')
                plt.plot(xv_plot, y_greg, label='Newton-Gregory', linestyle='-.', color='yellow')
                plt.scatter(xv, yv, color='black', label='Pontos', zorder=5)
                plt.title('Interpolação')
                plt.xlabel('x')
                plt.ylabel('f(x)')
                plt.grid(True)
                plt.legend()
                plt.tight_layout()
                plt.savefig('grafico_polinomios.png')

                met = ['Lagrange', 'Newton', 'Newton-Gregory']
                tempos = [t1, t2, t3]

                plt.figure(figsize=(8, 5))
                plt.bar(met, tempos, color=['green', 'red', 'yellow'])
                plt.title('Tempo de Execução')
                plt.ylabel('Tempo (s)')
                plt.grid(axis='y')
                plt.tight_layout()
                plt.savefig('grafico_comparacao_tempo.png')

                input("Enter para continuar: ")

            case 4:
                run = False

if __name__ == "__main__":
    main()
