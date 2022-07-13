//이중포인터 버전
//https://neohtux.tistory.com/51
//https://ititit1.tistory.com/78
//https://kirkim.github.io/c/2021/03/04/linked_list.html
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *next;
}node;

void Add_Node(node **head, int data);
void Print_All_Node(node **head);
void Insert_Node_First(node **head, int data);
void Remove_Node(node **head, int data);
void Remove_All_Node(node **head);

int main() {

    //head 노드를 가르키는 방법은 두가지 존재
    //1. 헤드 노드 또한 구조체로 동적할당하는 방법
    //node *head = malloc(sizeof(node));
    //2. 첫 번째 노드 자차가 헤드 노드로 지정하는 방법
    node *head = NULL;      //단순 널포인터 선언!(recommend)
    

    Add_Node(&head,10);
    Add_Node(&head,20);
    Add_Node(&head,30);
    //Print_All_Node(&head);
    Insert_Node_First(&head,50);
    Insert_Node_First(&head,70);
    Print_All_Node(&head);

    Remove_Node(&head, 70);
    Print_All_Node(&head);

    Remove_Node(&head, 30);
    Print_All_Node(&head);

    Remove_Node(&head, 10);
    Print_All_Node(&head);

    Remove_All_Node(&head);
    Print_All_Node(&head);
    return 0;
}


void Add_Node(node **head, int data){           //head포인터를 참조해야 하므로 이중포인터!
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    node *curr = *head;                         //탐색을 위한 임시 구조체 포인터 선언

    if(*head == NULL) {                         //head가 NULL포인터 이면
        *head = new_node;                       //첫 번째 노드 자체를 head로 지정함
    }
    else {
        while(curr->next != NULL){
            curr = curr->next;          
        }
        curr->next = new_node;
    }
}

void Print_All_Node(node **head){
    node *curr = *head;
    if(*head == NULL){
        printf("Linked List is Empty!!\n");
    }
    else {
        while (curr != NULL) {    //NULL포인터가 아닐 때 까지
            printf("%d \n",curr->data);
            curr = curr->next;
        }
    }    
}

void Insert_Node_First(node **head, int data){
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if(*head == NULL){
        *head = new_node;
    }
    else{
        new_node->next = *head; //즉 현재 head포인터가 가르키는 구조체의 주소 넣기
        *head = new_node;
    }
}


void Remove_Node(node **head, int data){ //삭제는 포인터 변수가 2개 필요
    node *prev = *head;
    node *curr = *head;

    if(*head == NULL){
        printf("Linked_List is Empty!\n");
    }
    else {
        //첫번쨰 노드를 삭제하는 경우
        if(curr->data == data){
            *head = curr->next;
            free(curr);
        }

        //중간 노드를 삭제하는 경우
        while (curr->next != NULL){
            if(curr->data == data){
                prev->next = curr->next;
                free(curr);
            }
            prev = curr;
            curr = curr->next;
        }

        //마지막 노드 삭제
        if(curr->next == NULL && curr->data == data){
            prev->next = NULL;
            free(curr);
        }

    } 
}


void Remove_All_Node(node **head){
    node *curr = *head;
    node *temp = *head;
    if(head == NULL) {
        printf("Linked List is Empty!!\n");
    }
    else {
        while (curr != NULL) {
            temp = curr->next;
            free(curr);
            curr = temp;
        }  
    }
    *head = NULL; //head 초기화
}