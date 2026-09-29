#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack for undo operation
int stack[MAX];
int top = -1;

// Transaction array
int transactions[MAX];
int count = 0;

// Functions for stack
void push(int amount)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = amount;
}

int pop()
{
    if (top == -1)
    {
        return -1;
    }
    return stack[top--];
}

// Main function
int main()
{
    int balance = 10000;
    int choice, amount;

    while (1)
    {
        printf("\n===== ATM MENU =====\n");
        printf("1. Withdraw\n");
        printf("2. Deposit\n");
        printf("3. Undo Last Withdrawal\n");
        printf("4. Show Balance\n");
        printf("5. Transaction History\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1: // Withdraw
            printf("Enter amount to withdraw: ");
            scanf("%d", &amount);

            if (amount <= balance)
            {
                balance -= amount;
                push(amount);
                transactions[count++] = -amount;

                printf("Withdrawal successful!\n");
            }
            else
            {
                printf("Insufficient balance!\n");
            }
            break;

        case 2: // Deposit
            printf("Enter amount to deposit: ");
            scanf("%d", &amount);

            balance += amount;
            transactions[count++] = amount;

            printf("Deposit successful!\n");
            break;

        case 3: // Undo last withdrawal
            amount = pop();

            if (amount == -1)
            {
                printf("No withdrawal to undo!\n");
            }
            else
            {
                balance += amount;
                transactions[count++] = amount;

                printf("Undo successful! Amount refunded: %d\n", amount);
            }
            break;

        case 4: // Show balance
            printf("Current Balance: %d\n", balance);
            break;

        case 5: // Transaction history
            if (count == 0)
            {
                printf("No transactions yet.\n");
            }
            else
            {
                printf("Transaction History:\n");
                for (int i = 0; i < count; i++)
                {
                    if (transactions[i] < 0)
                        printf("Withdraw: %d\n", -transactions[i]);
                    else
                        printf("Deposit/Undo: %d\n", transactions[i]);
                }
            }
            break;

        case 6: // Exit
            printf("Thank you for using ATM!\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}