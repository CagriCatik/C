#include <stdio.h>
#include "bank.h"

Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

void initialize() {
    numAccounts = 0;
}

void createAccount() {
    if (numAccounts < MAX_ACCOUNTS) {
        printf("Enter account holder's name: ");
        scanf("%s", accounts[numAccounts].name);
        accounts[numAccounts].accountNumber = numAccounts + 1;
        accounts[numAccounts].balance = INITIAL_BALANCE;
        printf("Account created successfully. Account number is: %d\n", accounts[numAccounts].accountNumber);
        numAccounts++;
    } else {
        printf("Cannot create more accounts. Bank capacity reached.\n");
    }
}

void deposit() {
    int accNum;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (accNum >= 1 && accNum <= numAccounts) {
        accounts[accNum - 1].balance += amount;
        printf("Deposit successful. Current balance: %.2f\n", accounts[accNum - 1].balance);
    } else {
        printf("Invalid account number.\n");
    }
}

void withdraw() {
    int accNum;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (accNum >= 1 && accNum <= numAccounts) {
        if (accounts[accNum - 1].balance >= amount) {
            accounts[accNum - 1].balance -= amount;
            printf("Withdrawal successful. Current balance: %.2f\n", accounts[accNum - 1].balance);
        } else {
            printf("Insufficient balance.\n");
        }
    } else {
        printf("Invalid account number.\n");
    }
}

void balanceInquiry() {
    int accNum;
    printf("Enter account number: ");
    scanf("%d", &accNum);

    if (accNum >= 1 && accNum <= numAccounts) {
        printf("Account holder: %s\n", accounts[accNum - 1].name);
        printf("Account number: %d\n", accounts[accNum - 1].accountNumber);
        printf("Current balance: %.2f\n", accounts[accNum - 1].balance);
    } else {
        printf("Invalid account number.\n");
    }
}
