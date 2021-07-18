/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct account_details{
    int account_no;
    int password;
    int amount;
};
void deposit();
void withdraw();
void balance_enquire();
int validate(int account_no_temp,int password_temp);
int account_no_temp;
int password_temp;
int amount_temp;
int i,x,choice;
struct account_details s[3]={{12345678,1234,0},{23456789,2345,0},{34567891,4567,0}};
int main(){
    while(1){
        printf("\n\n----ATM MACHINE------\n\n");
        printf("\n1.deposit() \n2.withdraw() \n3.balance_enquire \n4.exit() \nEnter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            { 
            deposit();
            break;
        }
        case 2:{
            withdraw();
            break;
        }
        case 3:{
            balance_enquire();
            break;
        }
        case 4:{
            exit(1);
        }
        default:
            printf("\nEnter the valid choice\n");
        }
    }
}
int validate(int account_no_temp,int password_temp){
    for(i=0;i<3;i++){
        if(s[i].account_no==account_no_temp){
            if(s[i].password==password_temp){
                return i;
                break;
            }
            else {
                printf("\nPassword Mismatch\n");
                exit(1);
            }
        }
        if(i==2){
            printf("\nAccount does'nt exist!\n");
            exit(1);
        }
    }
}
void deposit(){
    printf("\nenter the account no:\t");
    scanf("%d",&account_no_temp);
    printf("\nEnter the amount to deposit:\t");
    scanf("%d",&amount_temp);
    printf("\nEnter the password:\t");
    scanf("%d",&password_temp);
    x=validate(account_no_temp,password_temp);
    s[x].amount+=amount_temp;
    printf("\nRs.%d is successfully deposited to your account! Now the balance is %d to your account",amount_temp,s[i].amount);
    }
void withdraw(){
    printf("\n enter the account_no:\t");
    scanf("%d",&account_no_temp);
    printf("\n Enter the amount to withdraw:\t");
    scanf("%d",&amount_temp);
    printf("\n Enter the password:\t");
    scanf("%d",&password_temp);
    if(s[x].amount<amount_temp){
        printf("\nUnable to withdraw from your account!! please check your balance");
    }
    else {
        s[x].amount-=amount_temp;
        printf("Rs.%d is successfully withdraw from your account!Now your balance is %d",amount_temp,s[x].amount);
    }
}    
void balance_enquire(){
    printf("\nenter the account number\t");
    scanf("%d",&account_no_temp);
    printf("\nEnter the password:\t");
    scanf("%d",&password_temp);
    x=validate(account_no_temp,password_temp);
    printf("\nYour account no:%d contains %d",account_no_temp,s[x].amount);
}