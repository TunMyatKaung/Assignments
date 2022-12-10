//
// 3rd Assignment (write numbers to FILE & input to an array)
// by Tun Myat Kaung
//
#include "stdio.h"

int numArr[100];
int read;
int i =0;
int accept=0;

int main(){

    FILE *fptr;

    fptr=fopen("numbers.txt","w");

    if(fptr==NULL){

        printf("File cannot open");

    }else{

        for(i=1; i<=100; i++){

            fprintf(fptr,"%d%c",i,'\n');
        }

    }

    fclose(fptr);


    fptr=fopen("numbers.txt","r");

    for(accept=0; accept<100; accept++){

        fscanf(fptr,"%d",&numArr[accept]);
    }
    printf("* Numbers(1 to 100) from text file to an array *\n\n");

    for(accept=0; accept<100; accept++){

        printf("%d ",numArr[accept]);
    }


    fclose(fptr);

    return 0;

}
