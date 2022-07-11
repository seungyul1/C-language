//배열의 경우 컴파일 시 크기가 선언되어야하고 크기의 수정이 불가능함
//또한 중간 데이터를 삭제 했을때 빈 배열을 처리하는 것이 어려움!
//연결리스트는 필요할 떄 마다 데이터를 생성하여 연결
// --> 메모리 효율적(동적) 사용가능(삭제 및 추가 시 데이터 재구성이 용이함), 대용량 처리에 용이
// 탐색이 매우 느림(순차적으로 탐색해야 하므로), 주소를 저장하는 공간이 추가적으로 필요함
//
// Data를 저장하는 공간과 다음 주소를 가리키는 공간으로 구성된 Node라는 객체로 구성됨!
//데이터를 추가할 때마다 포인트에 주소를 할당함.

#include <stdio.h>
#include <stdlib.h> //malloc, free

typedef struct Node{
    int data;
    struct Node *next;    
}Node;



//초기화 (head, tail 선언)
//추가
//탐색
//삭제
//삽입


int main() {    

    Node *head = malloc(sizeof(Node));  //머리 노드 생성
    Node *tail = malloc(sizeof(Node));  //꼬리 노드 생성


    return 0;
}