//
// Created by Tun Myat Kaung on 1/20/2023.
// 6th Assignment (Registration Program)
//

#include "stdio.h"
#include "stdlib.h"
#define SIZE 10000

struct Employee{
    int id;
    int age;
    char name[30];
    char email[50];
    char password[50];

};

struct Employee info[SIZE];

void loadingAllDataFromFile();
void printingAllData();
void lobby();
void registration();
void checkmailFun();
int gmailValidation(int n,int n2);
void login();
void myStrCmp(char userInputChar[50]);
void passChecking(char pass[50] , int userIndex);
int charCounting(char toCount[50]);
void recordingAllDataToFile();
void userActionSector();

int globalIndex=0;

char format[]={'@','g','m','a','i','l','.','c','o','m'}; //for gmail validation

int eFound=-1;
int pFound=-1;

int main(){

    loadingAllDataFromFile();
    printingAllData();
    lobby();

    return 0;
}

void loadingAllDataFromFile(){

    FILE *fptr = fopen("dipDB.txt","r");

    if(fptr == NULL){
        printf("Data Empty!!\n");
    }else{

        for(int gcc=0; gcc<SIZE ; gcc++){

            fscanf(fptr,"%d%s%d%s%s",&info[gcc].id,&info[gcc].name,&info[gcc].age,&info[gcc].email,&info[gcc].password);

            if(info[gcc].name[0] == '\0'){
                break;
            }
            globalIndex++;
        }
    }
}

void lobby(){
    int lob=0;
    printf("\nThis is Lobby Sector!\n");
    printf("Press 1 to Register:\n");
    printf("Press 2 to Login:\n");
    printf("Press 3 to Exit:\n");

    scanf(" %d",&lob);

    if(lob == 1){
        registration();
    } else if(lob == 2){
        login();
    } else if(lob == 3){
        recordingAllDataToFile();
        exit(1);
    } else{
        printf("Invalid Option!\n");
        lobby();
    }

}

void printingAllData(){

    for(int gcc=0; gcc<globalIndex; gcc++ ){

        printf("id: %d - name:%s - age:%d - email:%s - password:%s\n",info[gcc].id,info[gcc].name,info[gcc].age,info[gcc].email,info[gcc].password);

    }

}

void registration(){

    printf("\nThis is registration!\n");

    printf("Enter your ID:");
    scanf("%d",&info[globalIndex].id);

    printf("Enter your name:");
    scanf(" %[^\n]",&info[globalIndex].name);

    printf("Enter your age:");
    scanf(" %d",&info[globalIndex].age);

    printf("Enter your email:");
    scanf(" %[^\n]",&info[globalIndex].email);

    checkmailFun();

    eFound=-1;
    myStrCmp(info[globalIndex].email);

    if(eFound == -1){
        printf("Enter your password:");
        scanf(" %[^\n]",&info[globalIndex].password);

        recordingAllDataToFile();

    }else{
        printf("Invalid!! This Email is registered already!!\n");
        registration();
    }

}
void checkmailFun(){

    int checked;

    for(int i=0; i<50; i++){
        if(info[globalIndex].email[i]==format[0]){
            checked=gmailValidation(i,0);
            break;
        }else if(info[globalIndex].email[i]==' '){
            checked=1;
            break;
        }
    }

    if(checked==1){
        printf("\n!!Invalid Email (Please don't don't use 'space' in your mail)\n");
        registration();
    }
    else if(checked==-1){
        printf("\n!!Invalid Email (Please register with '@gmail' format)\n");
        registration();
    }
}
int gmailValidation(int n,int n2){

        if(info[globalIndex].email[n]!=format[n2]){
            return -1;
        }else if(info[globalIndex].email[n]=='\0'){
            return n;
        }
        return gmailValidation(n+1,n2+1);
}

void login(){
    char lEmail[50];
    char passWord[50];

    printf("This is login form:\n");

    printf("Enter your email to login:");
    scanf(" %[^\n]",&lEmail);

    eFound = -1;
    myStrCmp(lEmail);

    printf("Enter your password :");
    scanf(" %[^\n]",&passWord);

    pFound = -1;
    passChecking(passWord , eFound);


    if(eFound != -1 && pFound == 1){
        userActionSector();

    } else{
        printf("Invalid email: or Password \n");
        login();

    }

}

void myStrCmp(char userInputChar[50]){

    int sameCount=0;
    int sec = charCounting(userInputChar);

    for(int i=0; i<globalIndex ; i++){
        int first = charCounting(info[i].email);

        if( first == sec){

            for(int gcc=0; gcc<first ; gcc++){

                if( info[i].email[gcc] != userInputChar[gcc]){
                    break;
                } else{
                    sameCount++;
                }
            }
        }
        if( sec == sameCount){
            eFound = i;
            break;
        }

    }

}

void passChecking(char pass[50] , int userIndex){

    int passCount = charCounting(pass);
    int infoPassCount = charCounting(info[userIndex].password);

    int sameCount=0;

    if(passCount == infoPassCount) {

        for (int ncc = 0; ncc < passCount; ncc++) {

            if (pass[ncc] == info[userIndex].password[ncc]) {

                sameCount++;

            } else{
                break;
            }
        }
        if( sameCount == passCount){
            pFound = 1;
        }
    }
}

int charCounting(char toCount[50]){ // toCount[50] = {'w','i','n','@'gmail.com,'\0' , '\0'}
    int charCount = 0;
    for(int gcc=0; gcc<50 ; gcc++){

        if( toCount[gcc] == '\0'){
            break;
        } else{
            charCount++;
        }
    }
    return charCount;
}

void recordingAllDataToFile(){

    FILE *fptr = fopen("dipDB.txt","w");

    if(fptr == NULL){
        printf("Error at recordingAllDataToFile fun():\n");
    }else{

        for(int gcc=0; gcc<=globalIndex; gcc++){
            fprintf(fptr , "%d %s %d %s %s\n",info[gcc].id,info[gcc].name,info[gcc].age,info[gcc].email,info[gcc].password);

        }
        printf("*All Data Recorded*\n");
    }

    fclose(fptr);

}

void userActionSector(){

    int userAction=0;

    printf("\nWelcome Sir: %s\n",info[eFound].name);
    printf("Press 1 to User Action Sector:\n");
    printf("Press 2 to Home:\n");
    printf("Press 3 to Exit:");
    scanf(" %d",&userAction);

    if(userAction == 1){
        printf("this is user action sector:\n");
    } else if( userAction == 2){
        login();
    } else if(userAction == 3){
        exit(1);
    } else{
        printf("Invalid Option!\n");
        userActionSector();
    }
}


