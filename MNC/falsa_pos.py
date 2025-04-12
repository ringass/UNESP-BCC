import math

#adicionar função
def f(x):
    return math.exp(x) - 4 * x**2

def falsa_posicao(a, b, E=1e-2, max_rep=100):
    if f(a) * f(b) >= 0:
        print("sinais iguais, erro")
        return None

    for i in range(max_rep):
        fa = f(a)
        fb = f(b)
        
        x = (a * fb - b * fa) / (fb - fa) #formula
        fx = f(x)
        print(f"Iteração {i+1}: a = {a:.6f}, b = {b:.6f}, x = {x:.6f}, f(x) = {fx:.6f}")

        if abs(fx) < E or (abs(b - a) < E): #duas situaçoes de erro
            print(f"Raiz = {x:.6f}")
            break

        if fa * fx < 0:
            b = x
        else:
            a = x


falsa_posicao(0, 1) #valor de a, b [a;b]
