import numpy as np
import matplotlib.pyplot as plt

# Operation count functions based on theoretical complexity
def gaussian_operations(n):
    return (2/3) * n**3  # Approximation of Gaussian Elimination operations

def gauss_jordan_operations(n):
    return (2/3) * n**3  # Similar to Gaussian elimination

def cramer_operations(n):
    return n**4  # Approximation for determinant calculations

def inverse_operations(n):
    return (2/3) * n**3  # Matrix inversion complexity

# Plotting number of operations vs matrix order
def plot_operations():
    sizes = range(2, 21)  # Vary matrix sizes from 2x2 to 20x20
    ops_gaussian = [gaussian_operations(n) for n in sizes]
    ops_gauss_jordan = [gauss_jordan_operations(n) for n in sizes]
    ops_cramer = [cramer_operations(n) for n in sizes]
    ops_inverse = [inverse_operations(n) for n in sizes]

    # Plotting
    plt.plot(sizes, ops_gaussian, label='Gaussian Elimination', marker='o')
    plt.plot(sizes, ops_gauss_jordan, label='Gauss-Jordan Elimination', marker='o')
    plt.plot(sizes, ops_cramer, label='Cramer\'s Rule', marker='o')
    plt.plot(sizes, ops_inverse, label='Inverse Method', marker='o')

    plt.xlabel('Matrix Size (n x n)')
    plt.ylabel('Number of Operations')
    plt.title('Operations vs Matrix Size for Linear Equation Solvers')
    plt.yscale('log')  # Log scale to better visualize differences
    plt.legend()
    plt.grid(True)
    plt.show()

plot_operations()
