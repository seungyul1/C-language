

#include <stdio.h>
#include <stdlib.h> //malloc, free;

typedef struct Node {
    int data;
    struct Node *next;
}Node;

int main(){

    Node *head = malloc(sizeof(Node));  //머리 노드 생성

    Node *node1 = malloc(sizeof(Node)); //첫 번째 노드 생성
    head->next = node1;
    node1->data = 10;

    Node *node2 = malloc(sizeof(Node)); //두 번째 노드 생성
    node1->next = node2;
    node2->data = 20;

    node2->next = NULL;

    Node *curr = head->next; //구조체 포인터 변수(curr)선언하고 
    while(curr != NULL){
        printf("%d\n", curr->data);
        curr = curr->next;
    }

    free(node2);
    free(node1);
    free(head);

    return 0;


}