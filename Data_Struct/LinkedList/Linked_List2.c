//https://sycho-lego.tistory.com/17
//전역변수 버전

#include <stdio.h>
#include <stdlib.h> //malloc, free


typedef struct NODE{    //구조체 선언
    int data;
    struct NODE *next;
}Node;

Node *head;     //전역 변수 선언
Node *tail;

void Init();
void AddNodeLast(int data);
void AddNodeFirst(int data);
void Insert_Node(int target, int data);
void Search_List(int data);

int main(){

    Init();         //head,tail 노드 초기화
    AddNodeLast(10);    //추가!
    AddNodeLast(20);
    AddNodeLast(30);
    AddNodeFirst(50);
    Search_List(20);
    Search_List(199);

    Node *curr = head;
    while (curr != NULL){
        printf("%d\n",curr->data);
        curr = curr->next;
    }
    
    
    //메모리 해제
    curr = head;
    while (curr != NULL){
        Node *tmp = curr->next;     //free전 임시저장
        free(curr);
        curr = tmp;
    }
    

    return 0;
}

void Init(){
    head = NULL;    //아무것도 가르키지 않음!
    tail = NULL;    //초기화 !
}


void AddNodeLast(int data){
    Node *newNode = malloc(sizeof(Node));       //새로운 노드 생성
    newNode->next = NULL;                         //초기화
    newNode->data = data;

    if(head == NULL){                          //연결리스트가 비어있는 경우(맨 앞에 추가)
        head = newNode;                        //머리 노드 생성 (head라는 구조체 포인터 변수에 newNode라는 시작주소를 할당!)
        tail = newNode;
    }
    else{                                       //2번쨰 추가부터는 tail만 움직임!                               
        tail->next = newNode;                   //tail의 다음주소 -->새로 생성한 노드                                                  
        tail = newNode;                         //tail이 가르키는 노드의 다음 주소 --> 새로 생성한 노드 
    }
}
void AddNodeFirst(int data){
    Node *newNode = malloc(sizeof(Node));       //새 노드 생성
    newNode->next = NULL;
    newNode->data = data;

    newNode->next = head;
    head = newNode;
}

void Insert_Node(int target, int data){
    Node *curr = head;

}







void Search_List(int data){
    Node *curr = head;
    if(head == NULL){
        printf("Linked List is Empty!!\n");
    }
    else {
        while(curr != NULL){
            if(curr->data == data){
                printf("%d\n",data);
                return;
            }
            curr = curr->next;
        }
        printf("찾는 데이터가 없습니다.\n");
    }
}