// File: Q13ComplexNumber.java
public class Q13ComplexNumber {
    private double real;
    private double imaginary;

    public Q13ComplexNumber(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    public double getReal() { return real; }
    public double getImaginary() { return imaginary; }

    // Add is done for you as an example!
    public Q13ComplexNumber add(Q13ComplexNumber other) {
        return new Q13ComplexNumber(this.real + other.getReal(), this.imaginary + other.getImaginary());
    }

    // TODO 1: Implement subtract() using the formula: (a-c) + (b-d)i
    public Q13ComplexNumber subtract(Q13ComplexNumber other) {
        return null; // Replace with correct logic
    }

    // TODO 2: Implement multiply() using the formula: (ac - bd) + (ad + bc)i
    public Q13ComplexNumber multiply(Q13ComplexNumber other) {
        return null; // Replace with correct logic
    }

    public String toString() { return real + " + " + imaginary + "i"; }
}
