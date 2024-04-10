#ifndef BANK_H
#define BANK_H

#define MAX_ACCOUNTS 100
#define INITIAL_BALANCE 0.0

typedef struct {
    int accountNumber;
    float balance;
    char name[50];
} Account;

void initialize();
void createAccount();
void deposit();
void withdraw();
void balanceInquiry();

#endif // BANK_H
