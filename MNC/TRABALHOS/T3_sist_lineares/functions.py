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
        soma = 0
        for j in range(n):
            if i != j:
                soma += abs(A[i, j] / A[i, i])
        X[i] = soma

    return max(X) < 1


def cri_colunas(A):
    n = len(A)
    X = np.zeros(n)

    for j in range(n):
        soma = 0
        for i in range(n):
            if i != j:
                soma += abs(A[i, j] / A[j, j])
        X[j] = soma

    return max(X) < 1


def estri_diagonal(A):
    n = len(A)
    for i in range(n):
        for j in range(n):
            if i != j:
                soma += abs(A[i, j])
        
            if abs(A[i, i]) <= soma:
                return False
        
    return True


def criterio_sassenfeld(A):

    n = len(A)
    beta = np.zeros(n, dtype=float)

    for i in range(n):
        soma1 = sum(abs(A[i, j]) * beta[j] for j in range(i))
        soma2 = sum(abs(A[i, j]) for j in range(i + 1, n))

        beta[i] = (soma1 + soma2) / abs(A[i, i])

    return np.all(beta < 1)


## SOLUTION ##


def solution(L, U, B, tf, name):
    if not tf:
        return None

    n = len(B)

    if name in ["Decomposicao LU", "Gauss-Compacto", "Cholesky"]:

        Y = np.zeros(n)
        for i in range(n):
            Y[i] = B[i] - sum(L[i, j] * Y[j] for j in range(i))

        X = np.zeros(n)
        for i in range(n - 1, -1, -1):
            X[i] = (Y[i] - sum(U[i, j] * X[j] for j in range(i + 1, n))) / U[i, i]

    elif name in ["Jacobi-Richardson", "Gauss-Seidel"]:
        X = U
    else:
        return None

    return X


## GAUSS-JORDAN ##
def gauss_jordan(A, B):

    if not ver_quadrada(A):
        return False, None

    elif not ver_pivos(A):
        return False, None

    elif not ver_inversa(A):
        return False, None

    n = len(B)
    
    B = B.reshape(-1, 1)

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
        return False, None, None

    elif not menores_principais(A):
        return False, None, None

    n = len(A)

    L = np.identity(n, dtype=float)
    U = np.zeros((n, n), dtype=float)

    for k in range(n):

        for j in range(k, n):

            soma = 0
            for s in range(k):
                soma += L[k, s] * U[s, j]

            U[k, j] = A[k, j] - soma

        for i in range(k + 1, n):
            soma = 0

            for s in range(k):

                soma += L[i, s] * U[s, k]

            L[i, k] = (A[i, k] - soma) / U[k, k]

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

    if not cri_linhas(A) and not cri_colunas(A):
        return False, None, None, None
    n = len(A)
    k_max = 50
    err = 1e-5
    X = np.zeros(n, dtype=float)
    h = []

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
        h.append(X.copy())

        erro_relativo = np.linalg.norm(X - X_, ord=np.inf) / np.linalg.norm(
            X, ord=np.inf
        )

        if erro_relativo < err:
            return True, X, k + 1, np.array(h), erro_relativo

    erro_relativo = np.linalg.norm(X - X_, ord=np.inf) / np.linalg.norm(X, ord=np.inf)
    return False, X, k_max, np.array(h), erro_relativo


## Gauss-Seidel ##
def gauss_seidel(A, B):

    if not cri_linhas(A) or not criterio_sassenfeld(A):
        return False, None, None, None

    n = len(A)
    k_max = 50
    err = 1e-5

    X = np.zeros(n, dtype=float)
    h = []

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

        h.append(X.copy())

        erro_relativo = np.linalg.norm(X - X_, ord=np.inf) / np.linalg.norm(
            X, ord=np.inf
        )

        if erro_relativo < err:
            return True, X, k + 1, np.array(h), erro_relativo

    erro_relativo = np.linalg.norm(X - X_, ord=np.inf) / np.linalg.norm(X, ord=np.inf)
    return False, X, k_max, np.array(h), erro_relativo
