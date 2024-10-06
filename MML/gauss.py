import numpy as np
import matplotlib.pyplot as plt
import math

# Matrix orders
matrix_orders = np.arange(1, 21)  # Considering matrix orders from 1 to 20

# Number of operations for Gaussian Elimination
gaussian_ops = [(2/3) * n**3 + n**2 for n in matrix_orders]

# Number of operations for Gauss-Jordan Elimination
gauss_jordan_ops = [n**3 for n in matrix_orders]  

# Plotting the graph
plt.figure(figsize=(10, 6))

# Plot Gaussian Elimination
plt.plot(matrix_orders, gaussian_ops, label="Gaussian Elimination", marker='o', color='blue')

# Plot Gauss-Jordan Elimination
plt.plot(matrix_orders, gauss_jordan_ops, label="Gauss-Jordan Elimination", marker='x', color='green')

# Labels and title
plt.title("Number of Operations vs Matrix Order")
plt.xlabel("Matrix Order (n)")
plt.ylabel("Number of Operations")
plt.grid(True)
plt.legend()

# Show the plot
plt.show()
