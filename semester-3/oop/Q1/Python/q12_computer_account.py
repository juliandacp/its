# File: q12_computer_account.py
class Q12ComputerAccount:
    def __init__(self, real_name, user_name, password):
        self._real_name = real_name
        self._user_name = user_name
        self._password = password

    def print_real_name(self):
        print(f"Real Name: {self._real_name}")

    def print_user_name(self):
        print(f"Username: {self._user_name}")

    # TODO 1: Create print_password(self) here
    def print_password(self):
        print(f"Password: {self._password}")
    # Display the current password stored in the account.

    # TODO 2: Create change_password(self, new_password) here
    def change_password(self, new_password):
        self._password = new_password
    # Replace the current password with the new password provided.

if __name__ == "__main__":
    acc = Q12ComputerAccount("John Doe", "jdoe123", "secret123")
    acc.print_real_name()
    acc.print_user_name()
    acc.print_password()
    acc.change_password("newSecret456")
    acc.print_password()