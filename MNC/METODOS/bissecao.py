import math

#adicionar função
def f(x):
    return (1 - (1 + x)**-12)/x - 8.5

def bissecao(a, b, E=1e-3, max_i=100):
    for i in range(max_i):
        
        x = (a + b) / 2 #formula
        fx = f(x)
        
        print(f"Iteração {i+1}: a = {a:.6f}, b = {b:.6f}, x = {x:.6f}, f(x) = {fx:.6f}")
        
        if abs(fx) < E or (abs(b - a) < E): #duas situaçoes de erro
            
            print(f"Raiz encontrada: x = {x:.6f}")
            break
        
        if f(a) * fx < 0:
            b = x
        else:
            a = x

bissecao(0.04, 0.06) #valor de a, b [a;b]
