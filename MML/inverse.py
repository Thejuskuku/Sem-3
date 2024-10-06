import numpy as np
import matplotlib.pyplot as plt

# Matrix orders
matrix_orders = np.arange(1, 21)  # Considering matrix orders from 1 to 20

# Number of operations for matrix inversion using Gaussian elimination (approx 2/3 n^3)
gaussian_inversion_ops = [(2/3) * n**3 for n in matrix_orders]

# Number of operations for Gauss-Jordan Elimination (which is approximately n^3)
gauss_jordan_ops = [n**3 for n in matrix_orders]

# Plotting the graph for matrix inversion
plt.figure(figsize=(10, 6))

# Plot for Gaussian Elimination Matrix Inversion
# plt.plot(matrix_orders, gaussian_inversion_ops, label="Matrix Inversion (Gaussian Elimination)", marker='o', color='red')

# Plot for Gauss-Jordan Elimination (which is approximately n^3)
plt.plot(matrix_orders, gauss_jordan_ops, label="Matrix Inversion (Gauss-Jordan Elimination)", marker='x', color='purple')

# Labels and title
plt.title("Number of Operations for Matrix Inversion vs Matrix Order")
plt.xlabel("Matrix Order (n)")
plt.ylabel("Number of Operations")
plt.grid(True)
plt.legend()

# Show the plot
plt.show()
