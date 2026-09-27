// File: Q13ComplexNumberTest.java
public class Q13ComplexNumberTest {
    public static void main(String[] args) {
        Q13ComplexNumber c1 = new Q13ComplexNumber(3, 2);
        Q13ComplexNumber c2 = new Q13ComplexNumber(1, 7);

        System.out.println("c1: " + c1.toString());
        System.out.println("c2: " + c2.toString());
        System.out.println("Addition: " + c1.add(c2).toString());
        System.out.println("Subtraction: " + c1.subtract(c2).toString());
        System.out.println("Multiplication: " + c1.multiply(c2).toString());
    }
}
