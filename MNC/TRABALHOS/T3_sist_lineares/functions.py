import numpy as np
import math
import threading


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


def cri_linhas(A):

    n = len(A)
    X = np.zeros(n)

    for i in range(n):
        for j in range(n):
            if(i != j):
                X[i] = abs(A[i, j] / A[i, i]);

    if(max(X) < 1):
        return True
    
    return False

def cri_colunas(A):

    n = len(A)
    X = np.zeros(n)

    for j in range(n):
        for i in range(n):
            if(j != i):
                X[j] = abs(A[i, j] / A[j, j]);

    if(max(X) < 1):
        return True
    
    return False

def estri_diagonal(A):

    n = len(A)

    for i in range(n):
        soma = 0.0

        for j in range(n):

            if(j != i):
                soma += A[i, j]

        if abs(A[i, i]) > abs(soma):
            return True

    return False

                
## SOLUTION ##

def solution(A, B, RES):

    

    




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

    # convergencia dos amigos
    if not ver_quadrada(A):
        return False, None

    elif not menores_principais(A):
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

    # convergencia dos amigos
    if not ver_simetria(A):
        return False, None

    elif not menores_principais(A, True):
        return False, None

    n = len(A)

    L = np.zeros((n, n), dtype=float)

    for i in range(n):

        for j in range(i):
            soma = 0.0

            for k in range(j):
                soma += L[i, k] * L[j, k]

            if i == j:

                L[i, j] = math.sqrt(A[i, i] - soma)

            else:

                L[i, j] = (A[i, j] - soma) / L[j, j]

    return True, L


## GAUSS-COMPACTO ##


def gauss_compacto(A):

    if not ver_quadrada(A):
        return False, None

    elif not ver_pivos(A):
        return False, None

    elif not ver_inversa(A):
        return False, None

    n = len(A)

    L = np.eye(n)

    U = A.copy()

    for i in range(n):

        for j in range(i + 1, n):

            if U[i, i] == 0:

                return False, None
            else:

                L[j, i] = U[j, i] / U[i, i]
                U[j, i:] = U[j, i:] - L[j, i] * U[i, i:]

    return True, L, U


## Jacobi-Richardson ##

def jacobi_richardson(A, B):
    n = len(A)
    k_max = 50
    err = 1e-5
    X = np.zeros(n, dtype=float)
    
    
    def calcula_linha(A, B, X_, i, results):
        
        soma = 0.0
        
        for j in range(n):
            
            if j != i:
                soma += A[i, j] * X_[j] 
        
        results[i] = (B[i] - soma) / A[i, i]


    for k in range(k_max): 
        X_ = X.copy()
        
        threads = []
        results = np.zeros(n, dtype=float)

        
        for i in range(n):
            thread = threading.Thread(target=calcula_linha, args=(A, B, X_, i, results))
            threads.append(thread)
            thread.start()

        
        for thread in threads:
            thread.join()

        X = results

       
        if np.linalg.norm(X - X_, ord=np.inf) < tol:
            return True, X, k + 1

    return False, X, k_max


## Gauss-Seidel ##
def gauss_seidel(A, B):
    n = len(A)
    k_max = 50
    err = 1e-5

    X = np.zeros(n, dtype=float)

    for k in range(k_max):

        X_ = X.copy()

        for i in range(n):
            soma1 = 0.0
            soma2 = 0.0

            for j in range(i):
                soma1 += A[i, j] * X[j]

            for j in range(i + 1, n):
                soma2 += A[i, j] * X_[j]

            X[i] = (B[i] - soma1 - soma2) / A[i, i]

        if np.linalg.norm(X[i] - X_[i], ord=np.inf) < err:

            return True, X, k + 1

    return False, X, k_max
