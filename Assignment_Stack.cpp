//
// Created by TunMyatKaung on 1/1/2023.
//
#include <iostream>
#define SIZE 10
using namespace std;

int count=0;

class myData{
public:
    int top;
    int array[SIZE];
};

void display(myData *stackM){   //display data from stack
    cout<<count<<" DATA IN STACKMEMORY"<<endl;
    for(int i=0; i<count; i++){
        cout<<stackM->array[i]<<" / ";
    }
}

void createStackmemory(myData *stackM){
    stackM->top=-1;
}

int empty(myData *stackM){
    if(stackM->top==-1){
        return 1;
    }else{
        return 0;
    }
}

int full(myData *stackM){
    if(stackM->top == SIZE-1){
        return 1;
    }else{
        return 0;
    }
}

void push(myData *stackM, int data){
    if (full(stackM)){
        cout<<"StackMemory storge is full!";
    }else{
        stackM->top++;
        stackM->array[stackM->top]=data;
        cout<<"\n\nData : "<< data<<" pushed at memory index : " <<stackM->top <<endl;
    }
    count++;
    display(stackM);
}

void pop(myData *stackM, int data){
    if (empty(stackM)){
        cout<<"StackMemory storge is empty!";
    }else{
        cout << "\n\nData : " << data << " popped from memory index : " << stackM->top <<endl;
        stackM->top--;
    }
    count--;
    display(stackM);
}

int main(){

    myData *stackMemory =(myData *)malloc(sizeof(myData));
    createStackmemory(stackMemory);

    push(stackMemory, 99);
    push(stackMemory, 100);
    push(stackMemory, 101);
    push(stackMemory, 102);
    push(stackMemory, 103);

    pop (stackMemory, 102);
    pop (stackMemory, 103);

    push(stackMemory, 104);
    push(stackMemory, 105);



    return 0;
}
