import time
import numpy as np

N = 4096*2

if __name__ == "__main__":
    A = np.random.rand(N, N).astype(np.float32)
    B = np.random.rand(N, N).astype(np.float32)
    C = np.zeros((N, N))

    for _ in range(10):
        start = time.monotonic()
        C = A @ B
        flop = N * N * 2 * N
        s = time.monotonic() - start

        print(f"{flop / s / 1e12:.2f} TFLOPS")



    # for i in range(N):
    #     for j in range(N):
    #         for k in range(N):
    #             C[i, j] += A[i, k] * B[k, j]