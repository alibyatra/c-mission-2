#include <stdio.h>
#include"myBank.h"

#define length 50
int num=0;
#define CLOSED_ACCOUNT 0
#define OPENED_ACCOUNT 1

double Accounts[length][2];


void openaccount(){
    if(num == length){
        printf("we're sorry, the bank is full and we couldnt open a new account\n");
        return;
    }
    int i=0;
    while (i < length && Accounts[i][0] != CLOSED_ACCOUNT){
        i++;
        if(i == length){
           i=0;
        }
    }
    printf("Initial deposit?:" );
    double amount=0;
    if (scanf("%lf",&amount)>=0){
        num++;
        Accounts[i][0] = OPENED_ACCOUNT;
        Accounts[i][1] = amount;
        printf("Your account number is: %d\n", i+901);
    }
}

void balance(int AccountNumber){
    int j=AccountNumber-901;
    if ((Accounts[j][0]) == OPENED_ACCOUNT){
        double balance = Accounts[j][1];
        printf("Your balance: %.2lf\n",balance);
    }else
        printf("Sorry!, You can't see the balance, your account is closed! \n");
}


void deposit(int AccountNumber){
    int j=AccountNumber-901;
    if ((Accounts[j][0]) == OPENED_ACCOUNT){
        printf("Amount?");
        double charge=0;
        scanf("%lf",&charge);
        Accounts[j][1] += charge;
        printf("your new balance: %.2lf \n",Accounts[j][1]);
    }else
        printf("we're sorry, your account is closed! \n");
}

void withdraw(int AccountNumber){
    int j=AccountNumber-901;
    printf("Amount?:" );
    double draw;
    scanf("%lf",&draw);
    if((Accounts[j][0]== OPENED_ACCOUNT)&&(Accounts[j][1] >= draw)&& (draw>=0)){
        Accounts[j][1] -= draw;
        printf("your new balance: %.2lf \n",Accounts[j][1]);
    }
    else if (Accounts[j][1] < draw || draw<0)
        printf("you couldnt draw from your account!\n");
    else
        printf("we're sorry, your account is closed! \n");
}


void closeAccount(int AccountNumber){
    int j=AccountNumber-901;
    if(Accounts[j][0]==OPENED_ACCOUNT){
        Accounts[j][0]=CLOSED_ACCOUNT;
        Accounts[j][1]=0.0;
        printf("Your account is closed now! \n");
        num--;
    }else
        printf("You don't have an account \n");
}

void interest(){
    printf("Interest rate?:" );
    double rate;
    scanf("%lf",&rate);
    for(int i = 0; i < length; i++)
        if(Accounts[i][0]==OPENED_ACCOUNT){
            Accounts[i][1] += ((Accounts[i][1])*(rate/100.0));
            Accounts[i][1] = ((int)((Accounts[i][1])*100))/100.0;
        }
}


void printAll(){
    for(int i = 0; i < length; i++)
        if(Accounts[i][0]==OPENED_ACCOUNT)
            printf("Account Number: %d , Balance: %0.2lf \n",i+901, Accounts[i][1]);
}


void closeAll(){
    for(int i = 0; i <= length; i++){
        if(Accounts[i][0]==OPENED_ACCOUNT){
            Accounts[i][0]=CLOSED_ACCOUNT;
            Accounts[i][1]=0.0;
            num--;
        }
    }
    printf("All the accounts are closed!\n");
}


