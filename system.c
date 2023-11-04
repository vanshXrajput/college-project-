#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void acc_detail();
void transfer_money();
void withdraw_money();
void deposit();
void menu();

char name[30];
int dep_amt, tot_amt = 10000, acc_num, wit_draw;
int trans, trans_acc;

int main()
{
    {
        int choice;
        printf("Enter your name:");
        gets(name);

        printf("Enter your Account number:");
        scanf("%d", &acc_num);
        while (1)
        {

            menu();
            printf("Enter your Choice:");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                acc_detail();
                break;
            case 2:
                transfer_money();
                break;
            case 3:

                withdraw_money();
                break;
            case 4:
                deposit();
                break;

            case 5:
                exit(0);

                break;

            default:
                printf("PLS Enter a valid option!!!");
                break;
            }
        }
        return 0;
    }
}
void menu()
{
    printf("*********************\n");
    printf("Main menu\n");
    printf("1.Account Detail\n");
    printf("2.Transfer Money\n");
    printf("3.Withdraw Money\n");
    printf("4.Deposit Money\n");
    printf("5.Exit\n");
    printf("*********************\n");
}
void acc_detail()
{
    printf("Name : %s", name);
    printf("Account number: %d", acc_num);
    printf("Total balance: %d", tot_amt);
}
void deposit()

{
    time_t tm;
    time(&tm);

    FILE *ptr = fopen("History.txt", "a");
    printf("Money Deposite!!\n");
    printf("Enter the amount to be deposited: \n");
    scanf("%d", &dep_amt);
    tot_amt += dep_amt;
    printf("current balance : %d\n", tot_amt);
    fprintf(ptr, "RS %d has been deposited to your account\n", dep_amt);
    fprintf(ptr, " The time and date of transaction %s\n", ctime(&tm));
    fclose(ptr);
}
void transfer_money()
{
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("History.txt", "a");

    printf("Transfer Money");
    printf("Enter the amount to be transfered: \n");
    scanf("%d", &trans);

    if (tot_amt < trans)
    {
        printf("Insuffecient Balance");
    }
    else
    {

        tot_amt -= trans;
        printf("Enter the number of acc in which amount has to be transferred:");
        scanf("%d", &trans_acc);
        printf("Amount of %d is transferred to %d", trans, trans_acc);
        printf("current balance : %d\n", tot_amt);
        fprintf(ptr, "RS %d has been  transferred to %d\n", trans, trans_acc);
        fprintf(ptr, " The time and date of transaction %s\n", ctime(&tm));
    }
    fclose(ptr);
}
void withdraw_money()
{
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("History.txt", "a");
    if (tot_amt < wit_draw)
    {
        printf("Insuffecient Balance");
    }
    else
    {
        printf("Money withdraw\n");
        printf("Enter the amount to be withdrawed: \n");
        scanf("%d", &wit_draw);
        tot_amt -= wit_draw;
        printf("Money Withdraw!!\n");
        printf("current balance : %d\n", tot_amt);
        fprintf(ptr, "RS %d has been  withdrawed to your account\n", wit_draw);
        fprintf(ptr, " The time and date of transaction %s\n", ctime(&tm));
    }
    fclose(ptr);
}
