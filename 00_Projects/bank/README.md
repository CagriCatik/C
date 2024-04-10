**1. main.c**:

This file contains the `main` function, which serves as the entry point for the program execution. It presents a simple menu-driven interface to the user, allowing them to interact with the banking system. The `main` function repeatedly displays the menu options and prompts the user for input until they choose to exit. Each menu option corresponds to a specific banking operation, such as creating an account, depositing funds, withdrawing funds, checking the balance, or exiting the program.

**2. bank.h**:

This header file contains function prototypes and necessary definitions for the banking system. It serves as the interface between different parts of the program, providing a contract specifying the functions available for use. Here's what each component in bank.h does:

- **Function Prototypes**: These are declarations of functions defined in `bank.c`, allowing other parts of the program (like `main.c`) to call them without needing to know the implementation details.
- **Definitions**: This header also contains definitions for constants like `MAX_ACCOUNTS` and `INITIAL_BALANCE`, which specify the maximum number of accounts the bank can hold and the initial balance of newly created accounts, respectively.
- **Structure Definition**: The `Account` structure defines the blueprint for a bank account, including fields like account number, balance, and account holder's name.

**3. bank.c**:

This source file contains the implementations of the functions declared in `bank.h`. Each function in `bank.c` corresponds to a specific banking operation, such as creating an account, depositing funds, withdrawing funds, and checking the balance. Here's what each function does:

- **initialize**: Initializes the banking system by setting the number of accounts to zero.
- **createAccount**: Allows the user to create a new bank account by providing their name. It assigns a unique account number to the new account and initializes its balance to zero.
- **deposit**: Enables the user to deposit funds into an existing bank account by specifying the account number and the amount to be deposited. It updates the account's balance accordingly.
- **withdraw**: Allows the user to withdraw funds from an existing bank account, provided they have sufficient balance. It updates the account's balance after the withdrawal.
- **balanceInquiry**: Retrieves and displays the current balance of an existing bank account, along with the account holder's name and account number.

Overall, the project structure follows a modular approach, separating the main program logic (`main.c`) from the banking system's functionality (`bank.c` and `bank.h`). This organization improves code readability, maintainability, and reusability.
