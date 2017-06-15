////Ali Saad
//CIS 170 - 01
//Banking Program

#include <stdio.h>
#include <ctype.h>

char getMenu();
void displayBalance(float);
float getDeposit();
float getWithdrawal(float);

int main(void)
{   char choice;
    float balance=0;
    
    printf("Welcome to HFCC Federal Credit Union\n");
    
    do {
         choice=getMenu();
        
        switch (choice) {
            case 'D':
                balance+=getDeposit();
                break;
            case 'W':
                balance-=getWithdrawal(balance);
                break;
            case 'B':
                displayBalance(balance);
                break;
            case 'Q':
                printf("Thank You! Come Again!");
                break;
            default:
                printf("\nInvalid selection. Try again.\n");
                break;
        }
        
    } while (choice!='Q');
    
    return 0;
}

char getMenu(){
    char c;
    
printf("o-------------------------------------------------------------------------------------o\n");
printf("|                  Welcome to the Henry Ford College Money Center                     |\n");
printf("| ------------------------------------------------------------------------------------|\n");
printf("|                             Follow the prompts.                                     |\n");
printf("o-------------------------------------------------------------------------------------o\n\n");
    
printf("\n\t\tPlease choose from the following menu:\n\n");
printf("\t\tD:\t-\tDeposit\n\n");
printf("\t\tW:\t-\tMake a withdrawel\n\n");
printf("\t\tB:\t-\tCheck your account balance\n\n");
printf("\t\tQ:\t-\tQuit");
printf("\n\n\t\tMake your selection:");
scanf("\n%c",&c);
    
    c=toupper(c);
    
    return c;
}

void displayBalance(float balance){
    printf("\nYour current balance is $%.2f\n",balance);
}

float getDeposit(){
    int i;
    float deposit;
    
    for (i=0; i<100; i++) {
        
        
        printf("\nEnter the amount you want to deposit: $");
        scanf("%f",&deposit);
        
        if (deposit<0){
            printf("\nError! Deposit is negative. Please try again.");
            continue;
        }
        else
            i=100;
    }
    return deposit;

}

float getWithdrawal(float balance){
    int i;
    float withdrawal;
    
    for (i=0; i<100; i++) {
        printf("Enter the amount you would like to Withdraw: $");
        scanf("%f",&withdrawal);
        
        if (withdrawal>balance)
            printf("\nError! Insufficient funds!\n");
        else if (withdrawal<0)
            printf("\nError! Withdrawel is less than 0. Please try again.\n");
            
        else
            i=100;
    }
    return withdrawal;
}
