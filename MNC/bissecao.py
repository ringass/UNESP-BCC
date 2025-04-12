import math

#adicionar função
def f(x):
    return x + 2*math.cos(x)

def bissecao(a, b, E=1e-2, max_rep=100):
    for i in range(max_rep):
        
        c = (a + b) / 2 #formula
        fc = f(c)
        
        print(f"Iteração {i+1}: a = {a:.6f}, b = {b:.6f}, c = {c:.6f}, f(c) = {fc:.6f}")
        
        if abs(fc) < E or (abs(b - a) < E): #duas situaçoes de erro
            
            print(f"Raiz encontrada: x = {c:.6f}")
            break
        
        if f(a) * fc < 0:
            b = c
        else:
            a = c

bissecao(-3, 0.5) #valor de a, b [a;b]
