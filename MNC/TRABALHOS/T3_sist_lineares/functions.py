import numpy as np
import math

## UTILS ##
def ver_pivos(A):

    n = len(A)

    for i in range(n):
        if A[i, i] == 0:
            return False

    return True


def ver_quadrada(A):

    lin, col = A.shape

    return lin == col

def ver_inversa(A):
    return np.linalg.det(A) != 0


def menores_principais(A, pos=False):

    n = len(A)

    for k in range(1, n + 1):

        sub = A[:k, :k]
        det = np.linalg.det(sub)

        if det != 0 and not pos:
            
            return False
        
        elif det < 0 and pos:
            
            return False
            
            
    return True

def ver_simetria(A):
    
    return np.array_equal(A, A.T)


## SOLUTION ##

# def solution(A, B, X, RES):
    
    
    


## metodos

## GAUSS-JORDAN ##
def gauss_jordan(A, B):

    if not ver_quadrada(A):
        return False, None
    
    elif not ver_pivos(A):
        return False, None
    
    elif not ver_inversa(A):
        return False, None
        
    
    n = len(B)

    M = np.hstack((A.astype(float), B.astype(float)))

    for i in range(n):

        M[i] = M[i] / M[i, i]

        for j in range(n):
            if i != j:
                M[j] = M[j] - M[j, i] * M[i]

    X = M[:, -1]

    return True, X


## DECOMPOSICAO LU ##
def decomposicao_lu(A):

    #convergencia dos amigos
    if(not ver_quadrada(A)):
        return False, None
    
    elif(not menores_principais(A)):
        return False, None
          
          
    n = len(A)

    L = np.identity(n, dtype=float)
    U = np.zeros((n, n), dtype=float)

    for k in range(n):
        
        for j in range(k, n):

            for s in range(k):
                U[k, j] = A[k, j] - (L[k, s] * U[s, k])

            for i in range(k + 1, n):

                for s in range(k):

                    L[i, k] = (1 / U[k, k]) * (A[i, k] - L[i, s] * U[s, k])
    
    return True, L, U

## CHOLESKY ##

def cholesky(A):
    
    #convergencia dos amigos
    if(not ver_simetria(A)):
        return False, None
    
    elif(not menores_principais(A, True)):
        return False, None
    
    n = len(A);
    
    L = np.zeros((n, n), dtype=float);
    
    for i in range (n):
        
        for j in range(i):
            soma = 0.0
            
            for k in range(j):
                soma += L[i, k] * L[j, k]

            if i == j:
                
                L[i, j] = math.sqrt(A[i, i] - soma)
            
            else:
                
                L[i, j] = (A[i, j] - soma)/L[j, j]
                
    
    return True, L

## GAUSS-COMPACTO ##

def gauss_compacto(A):
    
    if not ver_quadrada(A):
        return False, None
    
    elif not ver_pivos(A):
        return False, None
    
    elif not ver_inversa(A):
        return False, None

    n = len(B)

    M = np.hstack((A.astype(float), B.astype(float)))
    

## Jacobi-Richardson ##




## Gauss-Seidel ##
    
    
    
    
    
    
    
    
    
                




