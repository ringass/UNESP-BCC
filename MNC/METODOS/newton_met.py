import math

#adicionar função
def f(x):
    return (x/4) - math.tan(x) 
#adicionar derivada da função
def df(x):
    return (1/4) - 1/math.cos(x)**2


def newton(x0, E=1e-3, max_i=100):
    for i in range(max_i):
        fx = f(x0)
        dfx = df(x0)

        if dfx == 0:
            print("Nula")
            return None

        x1 = x0 - fx / dfx #formula
        
        print(f"Iteração {i+1}: x = {x0:.5f}, x_n+1 = {x1:.5f}, f(x) = {f(x0):.5f}, df(x) = {df(x0): .5f}, f(x_n+1) = {f(x1):.5f}")

        if abs(f(x1)) < E or abs(x1 - x0)/max(1, x1) < E:
            print(f"Raiz = {x1:.5f}")
            return x1

        x0 = x1

    print("max iteracoes")
    return x0


newton(1.2) #valor de x
