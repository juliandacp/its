// File: Q12ComputerAccountTest.java
public class Q12ComputerAccountTest {
    public static void main(String[] args) {
        Q12ComputerAccount acc = new Q12ComputerAccount("John Doe", "jdoe123", "secret123");
        acc.printRealName();
        acc.printUserName();
        acc.printPassword();
        acc.changePassword("newSecret456");
        acc.printPassword();
    }
}
