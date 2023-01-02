//
// Created by TunMyatKaung on 1/1/2023.
//
#include "stdio.h"
#include "math.h"

int jumpSearch(int arr[],int size,int key);
int min(int first,int second);

int main(){

    int arr[]={1,3,4,5,6,7,8,9,99,100,101,
               102,103,104,105,111,112,113,114,333};

    int arr_size=sizeof(arr)/sizeof(arr[0]);
    int toFind=333;
    int indexNum=jumpSearch(arr,arr_size,toFind);
    if(indexNum!=-1){
        printf("Found data: %d at indexno.[%d]\n",arr[indexNum],indexNum);
    }else{
        printf("Data Not Found!!\n");
    }
    return 0;
}

int min(int first,int second){
    if(first<second){
        return first;
    }else{
        return second;
    }
}

int jumpSearch(int arr[],int size,int key){

    int step= sqrt(size); //cannot think equation better than sqrt to calculate BLOCK SIZE//
    int previous=0;

    while(arr[min(step,size)-1]<key){
        previous=step;
        step+=sqrt(size);
            if(previous>=size){
                return -1;
            }
    }
    if(step>=size){ //(step control)..without step control key between previous & over step cannot not result sometimes//
        step=size-1;
    }
        if(arr[step]==key){
            return step;
        }else if(arr[previous]==key){
            return previous;
        }

    int mid=(step-previous)/2+previous; //to search using Binary//
    if(arr[mid]==key){
        return mid;
    }
    while(key<arr[mid]){
        mid--;
        if(arr[mid]==key){
            return mid;
        }
    }
    while(key>arr[mid]){
       mid++;
       if(arr[mid]==key){
           return mid;
        }
    }
    return -1;
}
