#include <stdio.h>
#include"myBank.h"

int main(){
    char activity=0;
    int accountnumber=0;
    while(1){
        printf("Transaction type?:");
        scanf(" %c", &activity);
        switch (activity)
        {
        case 'O':
            openaccount();
            break;
        case 'B':
            printf("Account number?:");
            scanf(" %d", &accountnumber);
            if (accountnumber>=901 && accountnumber<=950){balance(accountnumber);}
            break;
        case 'D':
            printf("Account number?:");
            scanf(" %d", &accountnumber);
            if (accountnumber>=901 && accountnumber<=950){deposit(accountnumber);}
            break;
        case 'W':
            printf("Account number?:");
            scanf(" %d", &accountnumber);
            if (accountnumber>=901 && accountnumber<=950){withdraw(accountnumber);}
            break;
        case 'C':
            printf("Account number?:");
            scanf(" %d", &accountnumber);
            printf("accountNumber: %d\n",accountnumber);
            if (accountnumber>=901 && accountnumber<=950){closeAccount(accountnumber);}
            break;
        case 'I':
            interest();
            break;
        case 'P':
            printAll();
            break;
        case 'E':
            closeAll();
            return 0;
            break;
        default:
            printf("wrong Transaction type please enter another one!");
            break;
        }
    }
}