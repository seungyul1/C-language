//포인터 버전
//https://neohtux.tistory.com/51
//https://ititit1.tistory.com/78

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *next;
}node;

node* Create_Node(int data);
void Add_Node(int data);



int main() {

    node *head = NULL;      //헤드 노드 선언
    node *tail = NULL;      //꼬리 노드 선언







    return 0;
}

node* Create_Node(int data){                    //node구조체 포인터를 반환하는 함수
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;                            //포인터 반환
}



