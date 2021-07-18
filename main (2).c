/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct userdetails{
    char name[50];
    char password[100];
};
struct userdetails s[100];
int choice,i,j=0,x,flag=1;
char temp_name[100],temp_password[100];
int caps=0,small=0,numbers=0,special=0;
void signup();
int validate();
int valid_input();
void login();
int main(){
    while(1){
    printf("\n\nSIGNUP LOGIN PORTAL\n\n");
    printf("We have few steps they are\n1.signup() \n2.login() \n3.exit() \nenter your choice\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        {
            signup();
            break;
        }
        case 2:
        {
            login();
            break;
        }
        case 3:
        {
            exit(1);
        }
        default:
        {
            printf("\nEnter the valid choice\n");
        }
    }
}
}
int validate(){
    for(i=0;i<100;i++){
        if(!strcmp(temp_name,s[i].name)){
            if(!strcmp(temp_password,s[i].password)){
                printf("\nAccount is already exist!!\n please login\n");
                main();
                break;
            }
        }
    }
    if(i==100){
        valid_input();
    }
}
int valid_input(){
    for(i=0;temp_name[i]!='\0';i++){
        if(!((temp_name[i]>='a' && temp_name[i]<='z')||(temp_name[i]>='A' && temp_name[i]<='Z'))){
            printf("\n Enter the valid name\n");
            flag=0;
            break;
        }
        else
        flag=1;
    }
    if(flag==1){
        caps=0,small=0,numbers=0,special=0;
        for(i=0;temp_password[i]!='\0';i++){
            if(temp_password[i]>='a' && temp_password[i]<='z')
                small++;
                else if(temp_password[i]>='A' && temp_password[i]<='Z')
                caps++;
                else if(temp_password[i]>='0' && temp_password[i]<='9')
                numbers++;
                else if(temp_password[i]=='@' || temp_password[i]=='#' || temp_password[i]=='*' || temp_password[i]=='.');
                special++;
        }
        if(caps>=1 && small>=3 && numbers>=3 && special>=1){
            return 1;
        }
        else {
            printf("\n Your password  is weak please enter the strong password\n\n");
            main();
        }
    }
}
void signup(){
    printf("\nEnter your name:\t");
    scanf("%s",temp_name);
    printf("\nEnter your password:\t");
    scanf("%s",temp_password);
    x=validate();
    if(x==1){
        strcpy(s[j].name,temp_name);
        strcpy(s[j].password,temp_password);
        j++;
        printf("\n\nSignup Successfully\n\n");
        
    }
}
void login(){
    printf("\nEnter your name\t");
    scanf("%s",temp_name);
    printf("\n Enter your password\t");
    scanf("%s",temp_password);
    x=valid_input();
    if(x==1){
        for(i=0;i<100;i++){
            if(!strcmp(s[i].name,temp_name)){
                if(!strcmp(s[i].password,temp_password)){
                    printf("\n\nlogin successfully!\nWelcome %s",s[i].name);
                    break;
                }
                else{
                    printf("\nEnter the valid username or password\n\n");
                    break;
                }
            }
            else {
                printf("\nAccount does'nt exist please signup first\n");
                main();
                break;
            }
        }
    }
    
}