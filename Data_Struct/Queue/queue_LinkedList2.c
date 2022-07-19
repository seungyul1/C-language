//더미 노드를 사용하는 경우 if-else문이 사라지는 경우가 많아 코드가 간단해짐
//https://lsoovmee-rhino.tistory.com/40?category=847612
#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct NODE *next;
}node;

typedef struct QUEUE{
    node *front;
    node *rear;
    int size;
}queue;



int main() {


    return 0;
}

