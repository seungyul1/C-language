#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int data;
    struct NODE *next;
}node;

typedef struct LinkedList{
    node *head;
    node *tail;
    int size;
}LinkedList;

LinkedList *new();
//더미노드 사용시 head의next를 통해 다음 노드 참조 가능하므로 기본 포인터 사용
void Add_Node(LinkedList *lk,int data);
void Print_AllNode(LinkedList *lk);
void Insert_Node(LinkedList *lk, int n, int data);
int Size(LinkedList *lk);
void Delete_Node(LinkedList *lk, int n);
void Delete_All(LinkedList *lk);
node *Search_Node(LinkedList *lk, int data);
void Swap_Nodedata(node *node1, node *node2);
void Bubble_Sort_List(LinkedList *lk,int size);

int main() {

    LinkedList *lk = new();
    Add_Node(lk,10);
    Add_Node(lk,9);
    Add_Node(lk,20);
    Add_Node(lk,70);
    Add_Node(lk,30);
    Print_AllNode(lk);
    Insert_Node(lk,3,25);
    Print_AllNode(lk);
    Insert_Node(lk,1,5);
    Print_AllNode(lk);
    //Delete_Node(lk,1);
    //Print_AllNode(lk);
    //Delete_Node(lk,4);
    //Print_AllNode(lk);
    //Delete_Node(lk,2);
    //Print_AllNode(lk);
    //Delete_All(lk);
    Bubble_Sort_List(lk,Size(lk));
    Print_AllNode(lk);
    return 0;
}


LinkedList *new(){
    LinkedList *lk = malloc(sizeof(LinkedList)); 
    lk->head = lk->tail = malloc(sizeof(node)); //더미 노드 생성 및 대입
    lk->head->next = NULL;                      //NULL을 가르키도록 초기화
    lk->size =0;
    puts("-------------------------------------------------------");
    printf("%40s\n","Linked List Initiated.");
    puts("-------------------------------------------------------");
    return lk;  //주소 반환! malloc할당 시 stack에서 사라지지 않음!
}
void Print_AllNode(LinkedList *lk){
    node *curr = lk->head->next;
    puts("-----------------Print Start--------------------");
    while (curr != NULL){ 
        printf("%d\n",curr->data);
        curr = curr->next;
    }
}
int Size(LinkedList *lk){
    return lk->size;
}

void Add_Node(LinkedList *lk,int data){
    node *new_node = malloc(sizeof(node));  //노드 생성
    new_node->data = data;
    new_node->next = NULL;

    lk->tail->next = new_node;
    lk->tail = new_node;
    ++lk->size;
}

void Insert_Node(LinkedList *lk, int n, int data){
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if(n == Size(lk)+1)
        Add_Node(lk,data);
    else if(n < 1 || n > Size(lk)+1)
        printf("해당위치(%d)에 노드를 삽입할 수 없습니다!!\n",n);
    else{
        node *curr = lk->head;
        while (--n)//이전 위치 까지 이동
            curr = curr->next;
        new_node->next = curr->next;
        curr->next = new_node;
        ++lk->size;
    }

}

void Delete_Node(LinkedList *lk, int n){
    if(n > Size(lk) || n < 1)
        printf("해당 위치(%d)의 노드를 삭제할 수 없습니다.\n",n);
    else{
        node *target;
        node *curr = lk->head;
        while (--n)
            curr = curr->next;
        target = curr->next;
        curr->next = target->next;
        if(n == Size(lk))
            lk->tail = curr;
        free(target);
        --lk->size; 
    }
}

void Delete_All(LinkedList *lk){
    node *curr = lk->head;
    while (curr != NULL){
        node *nxt = curr ->next;
        free(curr);
        curr = nxt;
    }
    free(lk);
    puts("-------------------------------------------------------");
	printf("%40s\n", "Linked List Destructed.");
	puts("-------------------------------------------------------");   
}

node *Search_Node(LinkedList *lk, int data){
    int count = 0;
    node *curr = lk->head->next;
    while (curr != NULL){
        count++;
        if(curr->data == data){
            printf("리스트에서 데이터 \"%d\"을(를) 찾았습니다.\n",data);
            printf("데이터는 리스트에서 \"%d\"번 위치에 있습니다.\n",count);
            break;
        }
        curr = curr->next;
    }
    if(curr == NULL){
        printf("데이터 \"%d\"이(가) 리스트에 존재하지 않습니다.\n", data);
    }
}

void Swap_Nodedata(node *node1, node *node2){
    int tmp_data = node1->data;
    node1->data = node2->data;
    node2->data = tmp_data; 
}

void Bubble_Sort_List(LinkedList *lk,int size){
    node *curr = lk->head->next;
    for(int i=1; i<size; i++){
        //if(curr->next == NULL) break;
        for(int j=0; j<size-i; j++){
            if(curr->data > curr->next->data)
                Swap_Nodedata(curr,curr->next);
            curr = curr->next;
        }
        curr = lk->head->next;
    }
}