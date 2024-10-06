import numpy as np
import matplotlib.pyplot as plt
import math

# Matrix order (n)
matrix_orders = np.arange(1, 101)  # We'll consider matrices from order 1 to 100

# Number of operations for Cramer's Rule (Factorial growth due to determinant calculations)
operations = [math.factorial(n) + n**2 for n in matrix_orders]

# Plotting the graph
plt.figure(figsize=(10, 6))   # Set the figure size

plt.plot(matrix_orders, operations, marker='o', color='b', markersize=5, label="Cramer's Rule Operations")

# Labels and title
plt.title("Cramer's Rule: Number of Operations vs Matrix Order")
plt.xlabel("Matrix Order (n)")
plt.ylabel("Number of Operations")
plt.grid(True)
plt.legend()

# Show the plot
plt.show()
