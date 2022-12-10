//
// 2nd Assignment (Mini game project without functions)
// developed by Tun Myat Kaung
//
#include "stdio.h"
#include "stdlib.h"

int db[100];
int memory[100];

int key=10;
int age,option,userId,userId2,flag,global_flag,amount,times,stop,money,no,count=0;

unsigned int rn=0;
int i,j,x,y,z=0;
int dbIndex=0;

int main(){

    while ( key<=10){

        printf(">> Welcome to NUMBERS BETTING GAMES << \n");
        printf(">> Win 3x if 3 Digits SAME <<\n\n");
        printf("Enter your age:");
        scanf("%d",&age);

        if(age>17){

            printf("\n* You can play game *\n");

            while(true){

                printf("\nPress 1 to Login! / Press 2 to Register: / Press 3 to Complete Quit: / Press 4 to Back : ");
                scanf("%d",&option);

                while (option != 0){

                    if(option == 1){

                        printf("\nLOGIN\nEnter your id to play game:");
                        scanf("%d",&userId);

                        for(i=0; i<100 ; i++){

                            if(db[i] == userId){
                                flag = 1;
                            }

                        }
                        if( flag==1 ){
                            printf("YOU CAN PLAY NOW...\n");
                            printf("\nOnce for 500__Maximum amount is 5000");
                            flag = 0;

                            while(1){

                                printf("\nInput money amount to play : ");
                                scanf("%d",&amount);

                                if(amount<500 || amount>5000){
                                    printf("!! Warning-Once for 500 & Maximum amount is 5000 !!\n");
                                    break;

                                }else{
                                    for(money=0; money<amount; money=money+500){}

                                    if(money != amount){
                                        printf("!! Warning-Once for 500 & Maximum amount is 5000 !!\n");
                                        break;
                                    }
                                }

                                printf("\n!! Numbers can be only 1 to 100000...If not, program will fail & NO REFUND !!");
                                printf("\n!! CANNOT enter the SAME NUMBER.. if not, YOU WILL LOSE YOUR TIMES !!");
                                printf("\n\n* GAME STARTED *");

                                for(times=0; times<amount/500; times++){

                                    printf("\nEnter a numbers : ");
                                    scanf("%d",&rn); //rn refers to random

                                    while(times<amount/500){

                                        if(rn==0 || rn>100000){
                                            printf("\nProgram Failed!!");
                                            exit(1);
                                        }

                                        for(i=0; i<100; i++){
                                            if(memory[i]==rn){
                                                no=1;
                                            }
                                        }

                                        if(no == 1){
                                            no=0;
                                            break;
                                        }
                                        memory[j]=rn;
                                        j++;


                                        for(i=0; i<=rn; i++){
                                            x = (i*5+2)%9;
                                        }

                                        for(i=0; i<=rn; i++){
                                            y = (i*x+2)%6;
                                        }

                                        for(i=0; i<=rn; i++){
                                            z = (i*y+2)%3;
                                        }

                                        printf("1st number : %d\n",x);
                                        printf("2nd number : %d\n",y);
                                        printf("3rd number : %d\n",z);
                                        printf("[%d , %d , %d]\n",x,y,z);

                                        if(x==y && x==z){
                                            printf("Congratulation you won 3x & get %d\n",amount*3);
                                            count++;
                                        }
                                    }


                                }
                                if(count==0){
                                    printf("\nWe are sorry...Game Over!\n\n");
                                }else{
                                    printf("\n** Congratulations You Won %d **\n\n",(amount*3)*count);
                                }

                                printf("Type 1 to continue/ Type 2 to exit : ");
                                scanf("%d",&stop);

                                if(stop == 2){
                                    printf("*Thank You Vey Much*");
                                    exit(0);

                                }else if(stop != 1){
                                    printf("Invalid Option!");
                                    exit(-1);
                                }
                            }
                        } else{
                            printf("Your id is not valid!!\n");
                            break;
                        }

                    } else if(option == 2){

                        printf("\nRegistration\nPls Enter your id :");
                        scanf("%d",&userId);

                        for(int i=0; i<100 ; i++){

                            if(db[i] == userId){
                                flag=1;
                            }
                        }
                        while (true){

                            if( flag==1 ){
                                printf("\nUser Id Already Taken!\n");
                                break;

                            } else{
                                printf("Confirm your ID: Enter: ");
                                scanf("%d",&userId2);

                                if(userId == userId2){

                                    db[dbIndex]=userId;
                                    dbIndex++;
                                    printf("* Registration success *\n");
                                    global_flag=1;

                                    break;

                                } else{
                                    printf("Id not same:\n");
                                    break;
                                }
                            }
                        }
                        if(global_flag==1){
                            break;
                        }

                    } else if(option==3){
                        exit(1);

                    } else if(option == 4){
                        break;

                    } else{
                        printf("Invalid Option!\n");
                    }
                }
            }
        } else{
            printf("You cannot play game!\nTry Again!\n");
        }
    }
    return 0;
}
