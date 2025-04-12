import math

#adicionar função
def f(x):
    return 5 + 28*x - 4.905*x**2
#adicionar derivada da função
def df(x):
    return 28 - 9.81*x


def newton(x0, E=1e-3, max_i=100):
    for i in range(max_i):
        fx = f(x0)
        dfx = df(x0)

        if dfx == 0:
            print("Nula")
            return None

        x1 = x0 - fx / dfx #formula
        
        print(f"Iteração {i+1}: x = {x0:.6f}, x_n+1 = {x1:.6f}, f(x) = {f(x0):.6f}, df(x) = {df(x0): .6f}, f(x_n+1) = {f(x1):.6f}")

        if abs(f(x1)) < E or abs(x1 - x0)/max(1, x1) < E:
            print(f"Raiz = {x1:.6f}")
            return x1

        x0 = x1

    print("máximo de iterações atingido.")
    return x0


newton(7) #valor de x
