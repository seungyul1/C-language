//https://ansohxxn.github.io/datastructure2/ch5-2/
//https://code-lab1.tistory.com/6
//연결리스트로 큐를 구현할 땐 원형큐, 순환구조로 구현할 필요가 없다.
//기존 head --> front로 tail --> rear로 생각하면 똑같다.

#include <stdio.h>
#include <stdlib.h>


typedef struct NODE {
    int data;
    struct NODE *next;
}node;

typedef struct QUEUE {
    node *front;       //큐의 첫번쨰 원소 위치
    node *rear;        //큐의 마지막 원소 위치
    int count;         //원소 갯수
}queue;


void Queue_Init(queue *queue);
int IsEmpty(queue *queue);
void Enqueue(queue *queue, int data);
int Dequeue(queue *queue);
void Print_AllQueue(queue *queue);

int main(){

    queue q;
    Queue_Init(&q);
    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);
    Enqueue(&q, 40);
    Enqueue(&q, 50);
    //Print_AllQueue(&q);
    printf("%d ", Dequeue(&q));
    printf("%d ", Dequeue(&q));
    printf("%d ", Dequeue(&q));
    printf("%d ", Dequeue(&q));
    printf("%d ", Dequeue(&q));
    
    return 0;

}

void Queue_Init(queue *queue){
    queue->front = NULL;
    queue->rear = NULL;
    queue->count = 0;    //노드 개수 0으로 설정!
}

int IsEmpty(queue *queue){
    if(queue->count == 0){
    //if(queue->front == queue->rear){
        //printf("Queue is Empty!!\n");
        return 0;
    }
    return 1;
}


void Enqueue(queue *queue, int data){
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if(!IsEmpty(queue)){  //큐가 비어있으면
        queue->front = new_node;
    }
    else{
        queue->rear->next = new_node;      
    }
    queue->rear = new_node;
    queue->count++;
}

int Dequeue(queue *queue){  //삭제는 front에서
    int data; //리턴할 데이터
    node *tmp;

    if(!IsEmpty(queue)){
        printf("Error : Queue is Empty!!\n");
        return 1;
    }
    else{
        tmp = queue->front;
        data = tmp->data;
        queue->front = tmp->next;
        free(tmp);
        queue->count--;
    }
    return data;
}



//오류남 수정해야함
void Print_AllQueue(queue *queue){
    while(!IsEmpty(queue)){
        printf("%d ", Dequeue(queue));
    }
    printf("\n");
}