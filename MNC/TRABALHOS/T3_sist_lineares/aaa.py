import os, time
import math
import matplotlib.pyplot as mpt
import functions
import numpy as np
import matplotlib.gridspec as gridspec
from tabulate import tabulate

A = np.array([[10, 2, -1], [-3, -6, 2], [1, 1, 5]], dtype=float)

B = np.array([27, -61.5, -21.5], dtype=float)


import matplotlib.pyplot as mpt
import matplotlib.gridspec as gridspec


def plot_grafico1(hist_jacobi, it_jacobi, hist_seidel, it_seidel):
    n_vars_jacobi = hist_jacobi.shape[1]
    n_vars_seidel = hist_seidel.shape[1]

    mpt.figure(figsize=(10, 6))

    marcadores = ["o", "s", "^"]
    cores_jacobi = ["#1f77b4", "#ff7f0e", "#2ca02c"]
    cores_seidel = ["#d62728", "#9467bd", "#8c564b"]

    for i in range(n_vars_jacobi):
        mpt.plot(
            range(it_jacobi),
            hist_jacobi[:it_jacobi, i],
            marker=marcadores[i],
            linestyle="--",
            color=cores_jacobi[i],
            label=f"Jacobi x{i+1}",
        )

    for i in range(n_vars_seidel):
        mpt.plot(
            range(it_seidel),
            hist_seidel[:it_seidel, i],
            marker=marcadores[i],
            linestyle="-",
            color=cores_seidel[i],
            label=f"Gauss-Seidel x{i+1}",
        )

    mpt.xlabel("Iterações")
    mpt.ylabel("Valores de X")
    mpt.title("Convergência dos Métodos Iterativos (Iterações no eixo X)")
    mpt.legend()
    mpt.grid(True)
    min_y = int(min(hist_jacobi.min(), hist_seidel.min())) - 1
    max_y = int(max(hist_jacobi.max(), hist_seidel.max())) + 1
    mpt.yticks(range(min_y, max_y + 1, 1))
    mpt.tight_layout()
    mpt.savefig("grafico_convergencia.png")
    mpt.close()


def plot_grafico2(it_jacobi, it_seidel):
    mpt.figure(figsize=(6, 6))
    metodos = ["Jacobi-Richardson", "Gauss-Seidel"]
    iteracoes = [it_jacobi, it_seidel]

    mpt.bar(metodos, iteracoes, color="#5B9BD5")
    mpt.ylabel("Número de Iterações")
    mpt.title("Número de Iterações por Método")
    mpt.tight_layout()
    mpt.savefig("grafico_iteracoes.png")
    mpt.close()


def plot_tabela(X_lu, X_gc, X_c, X_gj, X_jacobi, X_seidel, tempos, erros):
    metodos = [
        "LU",
        "Gauss-Compacto",
        "Cholesky",
        "Gauss-Jordan",
        "Jacobi-Richardson",
        "Gauss-Seidel",
    ]
    solucoes = [X_lu, X_gc, X_c, X_gj, X_jacobi, X_seidel]

    def formatar_solucao(solucao):
        if solucao is None or solucao is False:
            return ["Não Aplicável"] * 3
        try:
            return [f"x{i+1} = {v:.6g}" for i, v in enumerate(solucao)]
        except Exception:
            return [str(solucao)] * 3

    table_data = []
    for i, (metodo, solucao, tempo) in enumerate(zip(metodos, solucoes, tempos)):
        formatted_sol = formatar_solucao(solucao)
        # Erro só para métodos iterativos (Jacobi e Seidel)
        if metodo in ["Jacobi-Richardson", "Gauss-Seidel"]:
            erro_str = f"{erros[i]:.2e}" if erros[i] is not None else "N/A"
        else:
            erro_str = "N/A"

        row = [metodo] + formatted_sol + [f"{tempo:.8f}s"] + [erro_str]
        table_data.append(row)

    fig = mpt.figure(figsize=(12, 4))
    spec = gridspec.GridSpec(nrows=1, ncols=1)
    ax = fig.add_subplot(spec[0])
    ax.axis("off")
    ax.set_title("Soluções Obtidas", fontsize=14, pad=10)

    col_labels = ["Método", "x₁", "x₂", "x₃", "Tempo de exec.", "Erro Relativo"]

    tabela = ax.table(
        cellText=table_data, colLabels=col_labels, loc="center", cellLoc="left"
    )

    tabela.auto_set_font_size(False)
    tabela.set_fontsize(10)
    tabela.auto_set_column_width(col=list(range(len(col_labels))))
    tabela.scale(1.5, 2)

    mpt.tight_layout()
    mpt.savefig("tabela_solucoes.png")
    mpt.close()


def select():
    print("Deseja resolver o problema com: ")
    print("[1] - Decomposicao LU")
    print("[2] - Gauss-Compacto")
    print("[3] - Cholesky")
    print("[4] - Gauss-Jordan")
    print("[5] - Jacobi-Richardson")
    print("[6] - Gauss-Seidel")
    print("[7] - Tabelar métodos")
    print("[0] - Sair")

    while True:
        try:
            e = int(input("Digite o index desejado: "))
            if 0 <= e <= 7:
                return e
            else:
                print("Digite um numero entre 0 e 7")
        except ValueError:
            print("Digite um numero válido")


def exec(metodo=None):
    tempos = [0, 0, 0, 0, 0, 0]
    erros = [None, None, None, None, None, None]

    X_lu = X_gc = X_c = X_gj = X_jacobi = X_seidel = None
    hist_jacobi = None
    hist_seidel = None
    it_jacobi = it_seidel = 0
    
    print()
    
    if metodo is None or metodo == 1 or metodo == 7:
        start = time.time()
        tf, L, U = functions.decomposicao_lu(A)
        X_lu = functions.solution(L, U, B, tf, "LU")
        tempos[0] = time.time() - start

    if metodo == 2 or metodo == 7:
        start = time.time()
        tf, L, U = functions.gauss_compacto(A)
        X_gc = functions.solution(L, U, B, tf, "Gauss-Compacto")
        tempos[1] = time.time() - start

    if metodo == 3 or metodo == 7:
        start = time.time()
        tf, L = functions.cholesky(A)
        if tf:
            X_c = functions.solution(L, L.T, B, tf, "Cholesky")
        else:
            if metodo == 3:
                print("Cholesky não pôde ser aplicado por não atender aos critérios.")
            X_c = None
        tempos[2] = time.time() - start

    if metodo == 4 or metodo == 7:
            tf, X_gj = functions.gauss_jordan(A, B) 
        
    if metodo == 5 or metodo == 7:
        start = time.time()
        tf, X, it_jacobi, hist_jacobi, erros[4] = functions.jacobi_richardson(A, B)
        X_jacobi = functions.solution(None, X, B, tf, "Jacobi-Richardson")
        tempos[4] = time.time() - start

    if metodo == 6 or metodo == 7:
        start = time.time()
        tf, X, it_seidel, hist_seidel, erros[5] = functions.gauss_seidel(A, B)
        X_seidel = functions.solution(None, X, B, tf, "Gauss-Seidel")
        tempos[5] = time.time() - start

    if metodo == 7:
        plot_tabela(X_lu, X_gc, X_c, X_gj, X_jacobi, X_seidel, tempos, erros)
        plot_grafico1(hist_jacobi, it_jacobi, hist_seidel, it_seidel)
        plot_grafico2(it_jacobi, it_seidel)

        os.system('cls' if os.name == 'nt' else 'clear')
        print("Obrigado por utilizar")
        exit(1)
    else:
        
        metodos = [
            "LU",
            "Gauss-Compacto",
            "Cholesky",
            "Gauss-Jordan",
            "Jacobi-Richardson",
            "Gauss-Seidel",
        ]
        solucoes = [X_lu, X_gc, X_c, X_gj, X_jacobi, X_seidel]

        i = metodo - 1
        solucao = solucoes[i]
        tempo = tempos[i]
        erro = erros[i] if i >= 4 else None

        print(f"Resultado do metodo {metodos[i]}:")

        if solucao is None:
            print("Solução: N/A")
        
        else:
        
            table_data = []
            for idx, val in enumerate(solucao):
                table_data.append([f"x{idx+1}", f"{val:.6g}"])

        
            table_data.append(["Tempo de execucao", f"{tempo:.6f}s"])
            
            if erro is not None:
                
                table_data.append(["Erro relativo", f"{erro:.2e}"])
                
            else:
                
                table_data.append(["Erro relativo", "N/A"])

            print(tabulate(table_data, headers=["Variavel", "Valor"], tablefmt="simple"))
    time.sleep(5)  
    os.system('cls' if os.name == 'nt' else 'clear')

def main():
    while True:
        e = select()
        if e == 0:
            print("Saindo...")
            break
        else:
            exec(e)
            

if __name__ == "__main__":
    main()
