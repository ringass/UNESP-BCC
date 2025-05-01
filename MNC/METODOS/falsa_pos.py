import math

#adicionar função
def f(x):
    return (5 * x) - 100

def falsa_posicao(a, b, E=1e-3, max_i=100):
    if f(a) * f(b) >= 0:
        print("sinais iguais, erro")
        return None

    for i in range(max_i):
        fa = f(a)
        fb = f(b)
        
        x = (a * fb - b * fa) / (fb - fa) #formula
        fx = f(x)
        print(f"Iteração {i+1}: a = {a:.5f}, b = {b:.5f}, x = {x:.5f}, f(x) = {fx:.5f}")

        if abs(fx) < E or (abs(b - a) < E): #duas situaçoes de erro
            print(f"Raiz = {x:.5f}")
            break

        if fa * fx < 0:
            b = x
        else:
            a = x


falsa_posicao(-0.5, -1) #valor de a, b [a;b]
