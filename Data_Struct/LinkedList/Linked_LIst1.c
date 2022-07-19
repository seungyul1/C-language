//https://blog.naver.com/hirit808/221490070600
//https://lsoovmee-rhino.tistory.com/38?category=847612
//더미노드가 있는 version

#include <stdio.h>
#include <stdlib.h> //malloc, free;

typedef struct Node {
    int data;
    struct Node *next;
}node;

typedef struct LinkedList { //하나의 연결리스트를 나타내기 위한 데이터들이므로 구조체로 처리!
    node *head; //머리 노드
    node *tail; //꼬리 노드
    int size;   //연결리스트 크기
} LinkedList;


void Add_Node(LinkedList *lk, int data){
    node *new_node= malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    lk->tail->next = new_node;  //더미노드를 쓰는 장점 if-else필요없음
    lk->tail = new_node;
    lk->size++;
}

int LinkedList_Size(LinkedList *lk) {
    return lk->size;
}


void Insert_Node(LinkedList *lk, int n,int data){ //n은 삽입 위치
    if(n == LinkedList_Size(lk)+1) //맨 끝에 삽입한다면 그냥 Add를 호출!
        Add_Node(lk, data);
    else if (n < 1 || n > LinkedList_Size(lk) + 1) 
        printf("해당위치에 노드를 삽입할 수 없습니다.\n");
    else {
        node *new_node = malloc(sizeof(node));
        new_node->data = data;
        new_node->next = NULL;

        node *curr = lk->head; //더미노드 가르킴!
        while (--n)                   //따로 반복변수가 필요없음.
            curr = curr->next;         //n=3이면 2->1 두번 반복(이전노드)
        
        new_node->next = curr->next;
        curr->next = new_node;
        lk->size++;
    }
}

LinkedList *new(){  //new라는 함수인데 구조체를 반환
    LinkedList *lk = malloc(sizeof(LinkedList));   //메모리 할당 및 구조체 포인터 선언
    lk->head = lk->tail = malloc(sizeof(node));     //더미 노드 생성 (head,tail 모두 더미 노드를 가르킴!)
    lk->head->next = NULL;
    lk->size = 0;
    printf("Linked List Initiated.\n");
    return lk;
}

void Delete_Node(LinkedList *lk, int n){
    if(n < 1 || n > LinkedList_Size(lk)+1)
        printf("해당 위치의 노드를 삭제할 수 없습니다.\n");
    else {
        node *curr;             
        node *prev = lk->head;  //더미 노드 가르킴!

        while (--n) 
            curr = curr->next;  //n위치로 이동
        curr = prev->next;
        prev->next = curr->next;
        if ( n == LinkedList_Size(lk))  //맨 마지막 노드이면
            lk->tail = prev;
        free(curr);
        lk->size--;
    }     
    
}

void Delete_All(LinkedList *lk){
    node *curr = lk->head;
    while (curr != NULL){
        node *tmp = curr->next;
        free(curr);
        curr = tmp;
    }
    free(lk); //연결리스트구조체 포인터도 해제!
}


void Search_Node(LinkedList *lk, int data){
    int idx=0;
    node *curr = lk->head->next;
    while (curr != NULL){
        idx++;
        if(curr->data == data){
            printf("리스트에서 %d 위치에 있습니다!\n",idx);
            break;
        }
        curr = curr->next;
    }
    printf("데이터가 리스트에 존재하지 않습니다.!!\n");
}


void Print_AllNode(LinkedList *lk){
    node *curr = lk->head->next;

    if(curr == NULL){
        puts("No DATA!\n");
    }
    while (curr != NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}



int main(){

    LinkedList *lk;
    lk = new();
    Add_Node(lk,10);
    Add_Node(lk,20);
    Add_Node(lk,30);
    Print_AllNode(lk);

    Insert_Node(lk,2,40);
    Insert_Node(lk,2,50);
    Insert_Node(lk,2,60);
    Print_AllNode(lk);
    return 0;
}