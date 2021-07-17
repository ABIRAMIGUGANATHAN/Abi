/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct details{
    char uname[100];
    int age;
    char mailid[100];
    char password[100];
    char mobile[100];
};
struct hotel{
    char hotel[100];
    char first_food[20];
    char second_food[20];
    char third_food[20];
    char fourth_food[20];
    int first,second,third,fourth;
};
struct hotel m[5];
struct details s[100];
void signup();
void account_check();
int validate();
void login();
void cart();
void search_by_food();
void search_by_hotel();
void hotel_initialize();
void food_order(int food);
void hotel(int hotel_choice);
int flag=1,i,j=0,count=0,small=0,caps=0,special=0,numbers=0,sucess=0,choice,x;
char temp_name[100],temp_mailid[100],temp_password1[100],temp_password2[100],temp_mobile[100];
int temp_age,total=0,search_choice,food_choice,hotel_choice,n,confirm;
int ch,food,hotel_id;
int main(){
    while(1){
        printf("\n\nWelcome to food ordering E portal\n\n they are few steps to order food\n1.signup \n2.login \n3.exit \nenter you choice\n");
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
                printf("Enter the valid choice");
            }
            }
        }
    }
void signup(){
    printf("\nEnter the name\t");
    scanf("%s",temp_name);
    printf("\nEnter the age\t");
    scanf("%d",&temp_age);
    printf("\nEnter the mailId\t");
    scanf("%s",temp_mailid);
    printf("\nEnter the password\t");
    scanf("%s",temp_password1);
    printf("\nenter the conform password\t");
    scanf("%s",temp_password2);
    printf("\nEnter the mobile\t");
    scanf("%s",temp_mobile);
    x=validate();
    if(x==1)
    account_check();
}
void login(){
    printf("\n\nLOGIN\n\n");
    printf("\nenter the mailId\t");
    scanf("%s",temp_mailid);
    printf("\nEnter the password\t");
    scanf("%s",temp_password1);
    for(i=0;i<100;i++){
        if(!strcmp(s[i].mailid,temp_mailid)){
            if(!strcmp(s[i].password,temp_password1)){
                printf("\nWelcome %s you are successfully logged in E portal\nWe provide two way of search they are \n1.search_by_food \n2.search_by_hotel \n3.exit \nEnter your choice\n",s[i].uname);
                scanf("%d",&search_choice);
                switch(search_choice){
                    case 1:
                    {
                        search_by_food();
                        break;
                    }
                    case 2:
                    {
                        search_by_hotel();
                        break;
                    }
                    case 3:
                    {
                        exit(1);
                    }
                    default:
                    {
                        printf("enter the valid choice");
                    }
                }
                    break;
                }
                else {
                    printf("\nInvalid password!\nplease enter the valid password\n");
                    main();
                    break;
                }
            }
            else{
                printf("\nAccount does'nt exist!\n please signup!!\n");
                main();
                break;
            }
        }
    }
void search_by_hotel(){
    hotel_initialize();
    printf("\n\nplease choose the hotels\n1.%s \n2.%s \n3.%s \n4.exit \nenter the choice\n",m[1].hotel,m[2].hotel,m[3].hotel);
    scanf("%d",&hotel_choice);
    if(hotel_choice>4){
        printf("\nEnter the valid choice");
        search_by_hotel();
    }
    else if(hotel_choice==4)
        exit(1);
    else
        hotel(hotel_choice);
}
void search_by_food(){
    total=0;
    hotel_initialize();
    while(1){
        printf("\n please choose food\n\n1.%s\t%d\n 2.%s\t%d\n 3.%s\t%d\n 4.%s\t%d\n 5.%s\t%d\n 6.%s\t%d\n 7.%s\t%d\n 8.%s\t%d\n 9.%s\t%d\n 10.cart\n 11.exit\n",m[1].first_food,m[1].first,m[1].second_food,m[1].second,m[1].third_food,m[1].third,m[2].first_food,m[2].first,m[2].second_food,m[2].second,m[2].third_food,m[2].third,m[3].first_food,m[3].first,m[3].second_food,m[3].second,m[3].third_food,m[3].third);
        printf("Enter your choice\t");
        scanf("%d",&food);
        if(food>10){
            printf("\nenter the valid choice\n\n");
            search_by_food();
        }
        else if(food==10)
        cart();
        else if(food==11)
        exit(1);
        else 
        food_order(food);
    }
}
void food_order(int food){
    if(food>=1 && food<=3)
        hotel_id=1;
    else if(food>=4 && food<=6)
        hotel_id=2;
    else 
        hotel_id=3;
        if((food%3)==1){
            printf("\nEnter the count of %s\t",m[hotel_id].first_food);
            scanf("%d",&n);
            total=total+(n*m[hotel_id].first);
        }
        else if((food%3)==2){
            printf("\n Enter the count %s\t",m[hotel_id].second_food);
            scanf("%d",&n);
            total=total+(n*m[hotel_id].second);
        }
        else if((food%3)==3){
            printf("\n Enter the count %s\t",m[hotel_id].third_food);
            scanf("%d",&n);
            total=total+(n*m[hotel_id].third);
        }
        else{
            exit(1);
        }
}
void hotel(int hotel_choice){
    while(1){
        printf("\n\nList of food available in %s\n\n 1.%s\tRs: %d\n 2.%s\tRs: %d\n 3.%s\tRs: %d\n 4.cart\n 5.exit\n enter your choice\n",m[hotel_choice].hotel,m[hotel_choice].first_food,m[hotel_choice].first,m[hotel_choice].second_food,m[hotel_choice].second,m[hotel_choice].third_food,m[hotel_choice].third);
        scanf("%d",&food_choice);
        if(food_choice==1){
            printf("\n Enter the count of %s\t",m[hotel_choice].first_food);
            scanf("%d",&n);
            total=total+(n*m[hotel_choice].first);
        }
        else if(food_choice==2){
            printf("\n Enter the count of %s\t",m[hotel_choice].second_food);
            scanf("%d",&n);
            total=total+(n*m[hotel_choice].second);
        }
        else if(food_choice==3){
            printf("\n Enter the count of %s\t",m[hotel_choice].third_food);
            scanf("%d",&n);
            total=total+(n*m[hotel_choice].third);
        }
        else if(food_choice==4){
            cart();
        }
        else{
            printf("Please enter a valid choice\n");
        }
    }
}
void cart(){
    printf("\n\n------------cart-----------");
    printf("\nyour total order amount is %d\n",total);
    printf("Do you wish to order(y=1/n=0):");
    scanf("%d",&ch);
    if(ch==1){
        printf("\n thank you for your order!! your food is on the way,Welcome again\n\n");
        exit(1);
    }
    else if(ch==0){
        printf("Do you want to exit -1 or go back -0");
        scanf("%d",&confirm);
        if(confirm==1){
            printf("\n your order is cancelled! exiting ! thank you visit again\n\n");
            exit(1);
        }
        else {
            printf("\n\nThank you\n");
            login();
        }
    }
    else {
        printf("Please enter the correct choice\n");
        cart();
    }
}
void account_check(){
    for(i=0;i<100;i++){
        if(!(strcmp(temp_mailid,s[i].mailid) && strcmp(temp_password1,s[i].password))){
            printf("\nAccount already existed\n please login\n");
            main();
            break;
        }
    }
    if(i=100){
        strcpy(s[j].uname,temp_name);
        s[j].age=temp_age;
        strcpy(s[j].mailid,temp_mailid);
        strcpy(s[j].password,temp_password1);
        strcpy(s[j].mobile,temp_mobile);
        j++;
        printf("\n\nAccount successfully Created!\n\n");
    }
}
int validate(){
    for(i=0;temp_name[i]!='\0';i++){
    if(!((temp_name[i]>='a' && temp_name[i]<='z')|| (temp_name[i]>='A' && temp_name[i]<='Z'))){
        printf("\n Enter the valid name\n");
        flag=0;
        break;
    }
}
    if(flag==1){
        count=0;
        for(i=0;temp_mailid[i]!='\0';i++){
            if(temp_mailid[i]=='@'||temp_mailid[i]=='.'){
                count++;
            }
        }
            if(count>=2 && strlen(temp_mailid)>=5){
                if(!strcmp(temp_password1,temp_password2)){
                    if(strlen(temp_password1)>=8 && strlen(temp_password1)<=12){
                        caps=0,small=0,numbers=0,special=0;
                        for(i=0;temp_password1[i]!='\0';i++){
                            if(temp_password1[i]>='A' && temp_password1[i]<='Z')
                            caps++;
                            else if(temp_password1[i]>='a' && temp_password1[i]<='z')
                            small++;
                            else if(temp_password1[i]>='0' && temp_password1[i]<='9')
                            numbers++;
                            else if(temp_password1[i]=='@' || temp_password1[i]=='*' || temp_password1[i]=='#'|| temp_password1[i]=='&');
                            special++;
                        }
                        if(caps>=1 && small>=1 && numbers>=1 && special>=1){
                            if(temp_age!=0 && temp_age>0){
                                if(strlen(temp_mobile)==10){
                                    for(i=0;i<10;i++){
                                        if(temp_mobile[i]>='0' && temp_mobile[i]<='9'){
                                            sucess=1;
                                        }
                                        else{
                                            printf("\nEnter the valid mobile number\n\n");
                                            return 0;
                                            break;
                                        }
                                    }
                                    if(sucess==1)
                                        return 1;
                                    }
                                    else {
                                        printf("\nPlease enter the 10 digit mobile number\n");
                                        return 0;
                                    }
                                }
                                    else {
                                        printf("\n Enter the valid age\n");
                                        return 0;
                                    }
                                }
                                else {
                                    printf("please enter the strong password\n your password contains special letter,caps,small,numbers\n\n");
                                    return 0;
                                }
                        }
                        else {
                            printf("your password is very short\n Length must between 8 to 12\n\n");
                            return 0;
                        }
                    }
                    else{
                    printf("\n Password Mismatch\n\n");
                    return 0;
                }
                }
                else {
                    printf("\nplease enter the valide mailid\n");
                    return 0;
                }
            }
            
        }
void hotel_initialize(){
    strcpy(m[1].hotel,"Araya_Bhavan");
    strcpy(m[1].first_food,"Pizza");
    strcpy(m[1].second_food,"Sandwich");
    strcpy(m[1].third_food,"fried_Rice");
    m[1].first=70;
    m[1].second=100;
    m[1].third=95;
    
    strcpy(m[2].hotel,"Banu_Hotel");
    strcpy(m[2].first_food,"Parotta");
    strcpy(m[2].second_food,"Noodles");
    strcpy(m[2].third_food,"chicken_Rice");
    m[2].first=15;
    m[2].second=75;
    m[2].third=80;
    
    strcpy(m[3].hotel,"SR_Bhavan");
    strcpy(m[3].first_food,"chicken_briyani");
    strcpy(m[3].second_food,"Prawn");
    strcpy(m[3].third_food,"Faloda");
    m[3].first=90;
    m[3].second=120;
    m[3].third=35;
}