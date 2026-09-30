// File: Q12ComputerAccount.java
public class Q12ComputerAccount {
    // Encapsulated properties
    private String realName;
    private String userName;
    private String password;

    // Constructor is already done for you
    public Q12ComputerAccount(String realName, String userName, String password) {
        this.realName = realName;
        this.userName = userName;
        this.password = password;
    }

    public void printRealName() { System.out.println("Real Name: " + this.realName); }
    public void printUserName() { System.out.println("Username: " + this.userName); }

    // TODO 1: Create public void printPassword() here
    public void printPassword() { System.out.println("Password: " + this.password); }
    // Display the current password stored in the account.

    // TODO 2: Create public void changePassword(String newPassword) here
    public void changePassword(String newPassword) { this.password = newPassword; }
    // Replace the current password with the new password provided.

}