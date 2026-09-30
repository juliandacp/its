# File: q13_complex_number.py
class Q13ComplexNumber:
    def __init__(self, real, imaginary):
        self.real = real
        self.imaginary = imaginary

    def add(self, other):
        return Q13ComplexNumber(self.real + other.real, self.imaginary + other.imaginary)

    # TODO 1: Implement subtract(self, other)
    def subtract(self, other):
        return Q13ComplexNumber(self.real - other.real, self.imaginary - other.imaginary)
    # Subtract two complex numbers by subtracting their real and imaginary parts.
    # (a + bi) - (c + di) = (a - c) + (b - d)i.

    # TODO 2: Implement multiply(self, other)
    def multiply(self, other):
        real_part = (self.real * other.real - self.imaginary * other.imaginary)
        imaginary_part = (self.real * other.imaginary + self.imaginary * other.real)
        return Q13ComplexNumber(real_part, imaginary_part)
    # Multiply two complex numbers using the formula:
    # (a + bi)(c + di) = (ac - bd) + (ad + bc)i.

    def __str__(self):
        return f"{self.real} + {self.imaginary}i"

if __name__ == "__main__":
    c1 = Q13ComplexNumber(3, 2)
    c2 = Q13ComplexNumber(1, 7)

    print(f"c1: {c1}")
    print(f"c2: {c2}")
    print(f"Addition: {c1.add(c2)}")
    print(f"Subtraction: {c1.subtract(c2)}")
    print(f"Multiplication: {c1.multiply(c2)}")        