import numpy as np
import time
import matplotlib.pyplot as plt
import scipy.linalg as la

# Define matrix sizes
matrix_sizes = np.arange(100, 1000, 100)

# Initialize lists to store times
qr_times = []
lu_times = []
cholesky_times = []

# Benchmark QR, LU, and Cholesky decompositions for different matrix sizes
for n in matrix_sizes:
    # Generate a random matrix
    A = np.random.rand(n, n)
    
    # QR decomposition timing
    start_time = time.time()
    np.linalg.qr(A)
    qr_times.append(time.time() - start_time)
    
    # LU decomposition timing
    start_time = time.time()
    la.lu(A)
    lu_times.append(time.time() - start_time)
    
    # Cholesky decomposition timing (matrix must be symmetric positive definite)
    A_symmetric = np.dot(A.T, A)  # Making A symmetric positive definite
    start_time = time.time()
    try:
        la.cholesky(A_symmetric)
        cholesky_times.append(time.time() - start_time)
    except np.linalg.LinAlgError:
        cholesky_times.append(None)  # In case Cholesky fails (shouldn't happen)

# Plot the results
plt.figure(figsize=(10, 6))
plt.plot(matrix_sizes, qr_times, label='QR Decomposition', marker='o')
plt.plot(matrix_sizes, lu_times, label='LU Decomposition', marker='s')
plt.plot(matrix_sizes, cholesky_times, label='Cholesky Decomposition', marker='^')

# Graph details
plt.title('Time Complexity Comparison of QR, LU, and Cholesky Decomposition')
plt.xlabel('Matrix Size (n x n)')
plt.ylabel('Time (seconds)')
plt.legend()
plt.grid(True)
plt.show()
