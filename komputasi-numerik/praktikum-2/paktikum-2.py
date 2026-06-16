import numpy as np
import sympy as sp

# Fungsi User Input
def parse_function(func_str):
    x = sp.symbols('x')
    func = sp.sympify(func_str)
    return sp.lambdify(x, func, modules=['numpy'])

# Aturan Trapezoidal
def trapezoidal(f, a, b, n):
    h = (b - a) / n
    x = np.linspace(a, b, n + 1)
    y = f(x)
    return h * (0.5*y[0] + np.sum(y[1:n]) + 0.5*y[n])

# Integrasi Romberg
def romberg(f, a, b, max_level):
    R = np.zeros((max_level, max_level))

    # R(i,0) = Trapezoidal dengan 2^i Interval
    for i in range(max_level):
        n = 2**i
        R[i, 0] = trapezoidal(f, a, b, n)

    # Ekstrapolasi Richardson
    for j in range(1, max_level):
        for i in range(j, max_level):
            R[i, j] = R[i, j-1] + (R[i, j-1] - R[i-1, j-1]) / (4**j - 1)

    return R

# Output
def main():
    print("=== INTEGRASI ROMBERG ===")

    func_str = input("Masukkan fungsi f(x): ")
    a = float(input("Batas bawah (a): "))
    b = float(input("Batas atas (b): "))
    level = int(input("Level Romberg (contoh: 7): "))

    f = parse_function(func_str)
    R = romberg(f, a, b, level)

    print("\n=== TABEL ROMBERG ===")
    for i in range(level):
        for j in range(i+1):
            print(f"{R[i,j]:12.8f}", end=" ")
        print()

    print("\nHasil akhir (R[n,n]):", R[level-1, level-1])

if __name__ == "__main__":
    main()