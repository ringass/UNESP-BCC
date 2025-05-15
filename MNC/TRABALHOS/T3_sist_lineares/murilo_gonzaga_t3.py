import os, time
import math
import matplotlib.pyplot as mpt
import functions



def select():
    print("Selecione um metodo: ")
    print("[1] - Eliminacao de Gauss-Compacto")
    print("[2] - Eliminacao de Gauss-Jordan")
    print("[3] - Decomposicao LU")
    print("[4] - Fatoracao de Cholesky")
    print("[5] - Metodo de Jacobi-Richardson")
    print("[6] - Metodo de Gauss-Seidel")
    print("[0] - Sair")
    
    e = int(input("Digite o index desejado: "))
    
    while(not e.is_integer or (e < 0 and e > 6)):
        e = int(input("Digite um num (0-6): "))
    
    return e


def main():
    
    e = select()
    
    if e == 0:
        exit(1)
    # elif e == 1:    
    # elif e == 2:
    # elif e == 3:  
    # elif e == 4:
    # elif e == 5:
    # elif e == 6:
    
    
        
    
    
    
    
    