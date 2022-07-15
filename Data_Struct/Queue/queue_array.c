//https://velog.io/@mcc919/Data-Structure-%EC%9B%90%ED%98%95-%ED%81%90Circular-Queue-%EC%95%8C%EC%95%84%EB%B3%B4%EA%B8%B0 개념
//https://hellmath.tistory.com/8 코드
//rear가 마지막 저장된 데이터 앞을 가르키는 구조임!

#include <stdio.h>
#define MAX_QUEUE_SIZE 8

int IsFull();
int IsEmpty();
void Clear_Queue();
void Enqueue(int data);
int Dequeue();
int Peak();
void Print_Queue();

int queue[MAX_QUEUE_SIZE];
int front = 0;
int rear = 0;


int main(){
    int peak = 0;
    
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    peak = Peak();
    printf("%d \n",peak);
    Enqueue(50);
    Enqueue(60);
    Print_Queue();
    Enqueue(70);
    Dequeue();
    Dequeue();
    Dequeue();
    Enqueue(100);
    Enqueue(200);
    Enqueue(300);
    Print_Queue();

    return 0;
}

void Clear_Queue(){
    front = rear = 0;
    return;
}
int IsFull(){
    if((rear+1)%MAX_QUEUE_SIZE == front){
        return 0;
    }
    return 1;
}

int IsEmpty(){
    if(front == rear){
        return 0;
    }
    return 1;
}

void Enqueue(int data) {
    if(!IsFull()){
        printf("Queue is Full!!\n");
        return;
    }
    queue[rear] = data;   //저장 후 rear값 증가인가
    rear = (rear + 1)%MAX_QUEUE_SIZE;
}

int Dequeue() {
    int tmp;
    if(!IsEmpty()){
        printf("Queue is Empty!!\n");
        return -1;
    }

    tmp = queue[front];
    front = (front+1) % MAX_QUEUE_SIZE;
    return tmp;
}

int Peak() {
    if(!IsEmpty()){
        printf("Queue is Empty!!\n");
        return -1;
    }
    return queue[rear-1];
}


void Print_Queue(){
    int i;
    printf("Queue From Front -------> To Rear\n");
    for (i = front; i != rear; i = (i+1)%MAX_QUEUE_SIZE){
        printf("%d ", queue[i]);
    }
    printf("\n");
}