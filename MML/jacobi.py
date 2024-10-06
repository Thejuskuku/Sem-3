import numpy as np
import matplotlib.pyplot as plt

def gauss_sidel(A, b, tol=1e-10, max_iter=10000):
    """
    Gauss Sidel method for solving a system of linear equations.

    Parameters:
    A (numpy array): coefficient matrix
    b (numpy array): right-hand side vector
    tol (float): tolerance for convergence
    max_iter (int): maximum number of iterations

    Returns:
    x (numpy array): solution vector
    num_iter (int): number of iterations
    """
    n = len(b)
    x = np.zeros(n)
    num_iter = 0

    while num_iter < max_iter:
        x_new = np.copy(x)
        for i in range(n):
            s = np.dot(A[i, :], x_new) - A[i, i] * x_new[i]
            x_new[i] = (b[i] - s) / A[i, i]
        if np.linalg.norm(x_new - x) < tol:
            break
        x = x_new
        num_iter += 1

    return x, num_iter

def jacobi(A, b, tol=1e-10, max_iter=10000):
    """
    Jacobi method for solving a system of linear equations.

    Parameters:
    A (numpy array): coefficient matrix
    b (numpy array): right-hand side vector
    tol (float): tolerance for convergence
    max_iter (int): maximum number of iterations

    Returns:
    x (numpy array): solution vector
    num_iter (int): number of iterations
    """
    n = len(b)
    x = np.zeros(n)
    num_iter = 0

    while num_iter < max_iter:
        x_new = np.copy(x)
        for i in range(n):
            s = np.dot(A[i, :], x) - A[i, i] * x[i]
            x_new[i] = (b[i] - s) / A[i, i]
        if np.linalg.norm(x_new - x) < tol:
            break
        x = x_new
        num_iter += 1

    return x, num_iter

def plot_iterations(matrix_orders, gs_iterations, jacobi_iterations):
    """
    Plot the number of iterations vs matrix order for both methods.
    """
    plt.plot(matrix_orders, gs_iterations, label="Gauss Sidel")
    plt.plot(matrix_orders, jacobi_iterations, label="Jacobi")
    plt.xlabel("Matrix Order")
    plt.ylabel("Number of Iterations")
    plt.title("Number of Operations vs Matrix Order")
    plt.legend()
    plt.show()

# Example usage
n = 10  # matrix order
A = np.random.rand(n, n)
b = np.random.rand(n)

x_gs, num_iter_gs = gauss_sidel(A, b)
x_jacobi, num_iter_jacobi = jacobi(A, b)

print("Gauss Sidel method:")
print("Number of iterations:", num_iter_gs)
print("Solution:", x_gs)

print("Jacobi method:")
print("Number of iterations:", num_iter_jacobi)
print("Solution:", x_jacobi)

# Plotting
matrix_orders = range(1, 21)
gs_iterations = []
jacobi_iterations = []

for n in matrix_orders:
    A = np.random.rand(n, n)
    b = np.random.rand(n)
    x_gs, num_iter_gs = gauss_sidel(A, b)
    x_jacobi, num_iter_jacobi = jacobi(A, b)
    gs_iterations.append(num_iter_gs)
    jacobi_iterations.append(num_iter_jacobi)

plot_iterations(matrix_orders, gs_iterations, jacobi_iterations)