import math

def f(x0):
    return math.exp(x0 - 2) + x0

def dfx(x0, h):
    return (f(x0 + h) - f(x0 - h)) / (2 * h)

def dfx_(x0, h):
    return (f(x0 + h) - 2*f(x0) + f(x0 - h)) / (h**2)

def diff(x0, h_inicial, grau, E=1e-3, max_i=100):
    h = h_inicial
    
    dfx_last = dfx(x0, h) if grau == 1 else dfx_(x0, h)
    
    print(f"Iteração 0: f{"'"if grau == 1 else "''"}(x) = {dfx_last:.5f}, h = {h:.5f}")
    
    for i in range(1, max_i + 1):
        h /= 2
        
        dfx_it = dfx(x0, h) if grau == 1 else dfx_(x0, h)
        
        erro = abs(dfx_it - dfx_last) / max(abs(dfx_it), 1)
        
        print(f"Iteração {i}: f{"'"if grau == 1 else "''"}(x) = {dfx_it:.5f}, erro = {erro:.5f}, h = {h:.5f}")
        
        if erro < E:
            print(f"\nConvergiu com h = {h:.5f} e f'(x) = {dfx_it:.5f}")
            return dfx_it
        
        
        if erro > abs(dfx_last) and i > 1:
            try_erro = dfx_last
            
            if try_erro < dfx_last:
                print("\nErro aumentou em 2 iterações")
                break
        
        dfx_last = dfx_it

    print("\nMáximo de iterações atingido")
    return dfx_it


diff(-2, 1, 1)
