//https://rpatm.tistory.com/40
//원소의 삽입/삭제가 한쪽 끝에서만 발생하는 자료구조!
#include <stdio.h>
#define MAX_STACK_SIZE 100


int stack[MAX_STACK_SIZE];
int top = -1;

int IsEmpty();
int IsFull();
void Push(int data);
int Pop();
int Peek();
void Print_Stack();


int main(){
    
    Push(10);
    Push(20);
    Push(30);
    Push(40);
    Push(50);
    Push(60);

    Pop();
    Pop();
    Print_Stack();

    return 0;
}



void Print_Stack(){
    int curr = 0;
    if(!IsEmpty()){
        while (curr <= top){
            printf("%d \n",stack[curr]);
            curr++;
        }
        printf("All Stack Value Printed!!\n");
    }
}

int IsEmpty(){
    if(top == -1) {
        printf("Stack is Empty!!\n");
        return 1;
    }
    return 0;
}

int IsFull(){
    if(top >= MAX_STACK_SIZE-1) {
        printf("Stack is Full!!\n");
        return 1;
    }
    return 0;
}

void Push(int data) {
    if(!IsFull()) {
        stack[++top] = data;
    }
}

int Pop(){
    int temp;
    if(!IsEmpty()){
        temp = stack[top--];
    }
    return temp;
}

int Peek(){
    if(!IsEmpty()) {
        return stack[top]; //오직 값만 보기
    }
}