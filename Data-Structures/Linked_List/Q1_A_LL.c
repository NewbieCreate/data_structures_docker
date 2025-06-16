//////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
Lab Test: Section A - Linked List Questions
Purpose: Implementing the required functions for Question 1 */

//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////
// LinkNode 구조체 정의 : 연결 리스트의 각 노드를 표현
typedef struct _listnode{
	int item;                  //노드가 저장하는 데이터(정수형)
	struct _listnode *next;   // 다음 노드를 가리키는 포인터
} ListNode;			          // ListNode라는 이름으로 구조체 별칭 정의 

// Linked 구조체 정의 : 연결 리스트 전체를 표현
typedef struct _linkedlist{   
	int size;                  // 리스트에 있는 노드의 갯수
	ListNode *head;            // 리스트의 첫번째 노드를 가리키는 포인터
} LinkedList;			       // Linkedlist라는 이름으로 구조체 정의


///////////////////////// function prototypes ////////////////////////////////////

//You should not change the prototype of this function
int insertSortedLL(LinkedList *ll, int item);          // 연결 리스트에 정렬된 상태를 유지하며 아이템을 삽입(성공시 0 또는 1 반환 예상)
void printList(LinkedList *ll);                       // 리스트의 모든 요소를 출력하는 함수
void removeAllItems(LinkedList *ll);                  // 리스트의 모든 노드를 제거하여 초기화 하는 함수
ListNode *findNode(LinkedList *ll, int index);        // 특정 인덱스의 노드를 찾아 반환하는 함수(없으면  Null 반환 예상)
int insertNode(LinkedList *ll, int index, int value); // 지정한 인덱스에 새로운 노드를 삽입하는 함수 (성공시 0 또는 1 반환)
int removeNode(LinkedList *ll, int index);            // 지정한 인덱스 노드를 삭제하는 함수 (성공시 0, 1 반환)


//////////////////////////// main() //////////////////////////////////////////////

int main()
{
	LinkedList ll;     //링크드리스트 타입의 변수 ll선언 (연결 리스트 저장할 구조체)
	int c, i, j;       // 정수형 변수 c, i, j선언 (메뉴 선택 및 반복문 등에 사용)
	c = 1;             // c 값을 1로 초기화(반목문 제어용으로 사용될 가능성 있음)

	//Initialize the linked list 1 as an empty linked list
	// 연결 리스트 ll을 빈 리스트로 초기화
	ll.head = NULL;  // 리스트의 시작노드(head)를 NULL로 설정(아직 노드가 없음)
	ll.size = 0;     // 리스트의 크기를 0으로 초기화

	printf("1: Insert an integer to the sorted linked list:\n");      //정수 입력 및 정렬 삽입
	printf("2: Print the index of the most recent input value:\n");   // 최근 입력한 값의 인덱스 출력
	printf("3: Print sorted linked list:\n");                         // 전체 정렬된 연결 리스트 출력
	printf("0: Quit:");                                               // 프로그램 종료 선택

	while (c != 0)                                                    // 0을 입력할때 까지 반복
	{
		printf("\nPlease input your choice(1/2/3/0): ");              // 입력선택
		scanf("%d", &c);                                              // 사용자 입력받을 변 수 c에 저장

		switch (c)                                                    // 입력된 값에 따라 분기
		{
		case 1:
		     // 정수를 입력 받아 정렬된 연결리스트에 삽입
			printf("Input an integer that you want to add to the linked list: ");
			scanf("%d", &i); // 사용자로부터 삽입할 정수 i입력
			j = insertSortedLL(&ll, i);  //i를 정렬된 리스트에 삽입하고 인덱스를 j에 저장
			printf("The resulting linked list is: "); 
			printList(&ll);   //현재연결 리스트 출력
			break;
		case 2:
			printf("The value %d was added at index %d\n", i, j);  //가장 최근에 삽입한 값과 그 인덱스를 출력
			break;
		case 3:
			printf("The resulting sorted linked list is: ");       //현재 연결 리스트 출력 후 전체 삭제
			printList(&ll);
			removeAllItems(&ll);                                   // 리스트 초기화(모든 노드 제거)
			break;
		case 0:
			removeAllItems(&ll);                                  //메모리 누수 방지를 위해 리스트 정리
			break;
		default:
			printf("Choice unknown;\n");                          // 잘못된 메뉴 입력 처리
			break;
		}


	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////

/* 	사용자에게 정수를 입력받은 후, 해당 값을 **오름차순으로 정렬된 연결 리스트에 삽입하는 C 함수 insertSortedLL()**를 작성하시오.
1.이 함수는 현재 연결 리스트에 이미 존재하는 정수는 삽입하지 않아야 하며, 정상적으로 삽입되었을 경우에는 새 항목이 추가된 인덱스 위치를 반환해야 합니다.
함수가 정상적으로 완료되지 못한 경우에는 -1을 반환해야 합니다. 연결 리스트는 **정렬된 상태이거나 비어 있다고 가정할 수 있습니다. */
int insertSortedLL(LinkedList *ll, int item)
{
	ListNode *cur; 
    // cur을 최초 헤드 위치로 지정
	cur = ll -> head;
	// 추가 인덱스 반환하기 위해 지정
	int index = 0; 
	if(cur == NULL) {
		if (insertNode(ll,0,item) == 0) {
           return 0;
		}else {	
			return -1;
		}
	}
	while(cur != NULL && cur -> item <item) {
		// 인덱스의 위치를 찾아야 하기 때문에 한칸씩 이동한다
		cur = cur -> next;
		index ++;
	}
	// 만약에 cur은 비어있지 않아야 하고 cur의 item이 현재 item과 같을 경우
		if(cur != NULL && cur -> item == item) {
		return -1;               //return -1  
		}
		
		if(insertNode(ll,index,item) == 0) {
			return index;
		}else {
			return -1;
		}
}

///////////////////////////////////////////////////////////////////////////////////
// 연결 리스트의 모든 항목(item)을 출력하는 함수
void printList(LinkedList *ll){

	ListNode *cur;     //현재 노드를 가리키는 포인터 선언
	if (ll == NULL)    // 리스트 자체가 NULL일 경우
		return;        // 출력없이 함수 종료
	cur = ll->head;    // 리스트의 첫번째 노드를 cur에 할당

	if (cur == NULL)    // 리스트가 비어있는경우
		printf("Empty");  // 비어있다 메세지 출력
	while (cur != NULL)   // 노드가 존재하는동안 반복
	{
		printf("%d ", cur->item); // 현재 노드의 item 값 출력
		cur = cur->next;          // 다음 노드로 이동
	}
	printf("\n");                //줄 바꿈 출력 마무리
}

// 연결 리스트의 모든 노드를 삭제하고, 리스트를 초기화하는 함수
void removeAllItems(LinkedList *ll)
{
	ListNode *cur = ll->head;  //현재 노드를 가리키는 포인터 (초기값은 NULL)
	ListNode *tmp;             // 다음 노드를 임시 저장할 포인터

	while (cur != NULL){      // 현재 노드가 NULL이 아닐때까지 반복
		tmp = cur->next;      // 다음 노드의 주소를 임시로 저장
		free(cur);            // 현재 노드 메모리 해체
		cur = tmp;            // 다음 노드로 이동
	}
	ll->head = NULL;          //모든 노드 삭제 후 head를 NULL로 초기화
	ll->size = 0;             // 리스트의 크기도 0으로 초기화
}


ListNode *findNode(LinkedList *ll, int index){

	ListNode *temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0){
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

int insertNode(LinkedList *ll, int index, int value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// If empty list or inserting first node, need to update head pointer
	if (ll->head == NULL || index == 0){
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}


int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){

		if (pre->next == NULL)
			return -1;

		cur = pre->next;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 0;
	}

	return -1;
}
