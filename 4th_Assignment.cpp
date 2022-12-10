//
// 4th Assignment (To search word in a .txt FILE & show how many times including)
// by Tun Myat Kaung
//
#include "stdio.h"
#define SIZE 100

int i=0;
int w=0;
int count=0;

int main(){

    char etcVar[SIZE];
    char wordtFind[SIZE];


    printf("\nType & Search: ");
    scanf("%s",wordtFind);

    FILE* fptr;
    fptr=fopen("words.txt","r");

    char c=fgetc(fptr);

    while(!feof(fptr)){

        if(c == wordtFind[i]){
                etcVar[w]=c;
                i++;
                w++;

                if(wordtFind[i] == '\0'){
                        count++;
                }
        }else{
                i=0;
        }
            c=fgetc(fptr);
    }

    if(count != 0){
        printf("\nFound ( %s ) for (%d) times",wordtFind,count);
    }else{
        printf("Not found!!!");
    }
    return 0;
}
