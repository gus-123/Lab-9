/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>
//트리의 노드 구조를 구조체로 정의
typedef struct node {
	int key;
	struct node *left;   //왼쪽 노드
	struct node *right;   //오른쪽 노드
} Node;

int initializeBST(Node** h);

//함수 리스트
void inorderTraversal(Node* ptr);	  //중위 순회 연산
void preorderTraversal(Node* ptr);    //전위 순회 연산
void postorderTraversal(Node* ptr);	  //후위 순회 연산
int insert(Node* head, int key);  //트리에 노드를 추가
int deleteLeafNode(Node* head, int key);  //트리에 Leaf노드 삭제
Node* searchRecursive(Node* ptr, int key);  //순환으로 탐색 연산
Node* searchIterative(Node* head, int key);  //반복으로 탐색 연산
int freeBST(Node* head); //트리의 메모리 해제




int main()
{
	char command;
    printf("[----- [김현민]  [2018038088] -----]");
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Leaf Node             = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) {

	//headNode가 null이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제
	if(*h != NULL)
		freeBST(*h);

	//headNode에 대한 메모리를 할당하여 다시 리턴
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;
	return 1;
}



void inorderTraversal(Node* ptr)
{
    if (ptr) {  //중위 순회 연산
		inorderTraversal(ptr->left); 
		printf("%d ", ptr->key); 
		inorderTraversal(ptr->right); 
	} 
}

void preorderTraversal(Node* ptr)
{
    if (ptr) {  //전위 순회 연산 
		printf("%d ", ptr->key); 
		preorderTraversal(ptr->left); 
		preorderTraversal(ptr->right); 
	} 
}

void postorderTraversal(Node* ptr)
{
    if (ptr) {  //후위 순회 연산
		postorderTraversal(ptr->left); 
		postorderTraversal(ptr->right); 
		printf("%d ", ptr->key); 
	} 
}


int insert(Node* head, int key)
{
    Node* temp;
	Node* node = (Node*)malloc(sizeof(Node));  //삽입할 새로운 노드의 동적 메모리 할당
	node->key = key;  //새로운 노드의 데이터필드에 key 저장

	node->left = NULL;  //새로운 노드의 left는 null을 할당하여 연결을 해제
	node->right = NULL;  //새로운 노드의 right는 null을 할당하여 연결을 해제
	
	if (head->left == NULL) {  //head의 left가 null인 경우
		head->left = node;  //새로운 노드의 주소를 head의 left에 저장

		return 0;
	}
    //head의 left가 null이 아닐 경우 
	temp = head->left;  //temp가 head의 left를 참조
	while (head) {
		if (key > temp->key) {  //넣는 값보다 루트노드의 키값이 작은 경우
			if (temp->right == NULL) {  //temp의 right가 null인 경우 
				temp->right = node;  //새로운 노드의 주소를 temp의 right에 저장
                break;
			}
			else {
				temp = temp->right;  //temp의 right를 temp에 저장
			}
		}
		else if (key < temp->key) {  //넣는 값보다 루트노드의 키값이 큰 경우
			if (temp->left == NULL) {  //temp의 left가 null인 경우 
				temp->left = node;  //새로운 노드의 주소를 temp의 left에 저장
                break;
			}
			else {
				temp = temp->left;  //temp의 left를 temp에 저장
			}
		}
		else {  //중복 하는 키 값을 넣은 경우
  			printf("\n 이미 같은 키가 있습니다! \n");
			break;
		}
	}

	return 0;
}

int deleteLeafNode(Node* head, int key)
{
    Node* temp;
	Node* deleted = searchIterative(head,key);  //반복으로 탐색 연산을 이용
	
	if (deleted == NULL) {  //deleted가 null인 경우
		printf("\n 찾는 키가 이진트리에 없습니다!\n");

		return 0;
	}
	if ((deleted->left != NULL) || (deleted->right != NULL)) {  //Leaf노드가 아닐 경우
		printf("\n 노드 %d은 leaf노드가 아닙니다!\n");	
		
		return 0;
	}
	
	temp = head->left;  //temp가 head의 left를 참조	
	if (temp == deleted) {  //노드가 하나인 경우
		head->left = NULL;  //head의 left는 null을 할당하여 연결을 해제
		free(deleted);  //deleted의 메모리 할당 해제
		
		return 0;
	}	
	while (head) {  //노드가 여러개인 경우	
		if (temp->left == deleted) {  //temp의 left값을 삭제
			temp->left = NULL;  //temp의 left는 null을 할당하여 연결을 해제 
			free(deleted);  //deleted의 메모리 할당 해제
			break;
		}
		else if (temp->right == deleted) {  //temp의 right값을 삭제
			temp->right = NULL;  //temp의 right는 null을 할당하여 연결을 해제  
			free(deleted);  //deleted의 메모리 할당 해제
			break;
		}
		else if (key > temp->key) {	//삭제 할 값보다 루트노드의 키값이 작은 경우
			temp = temp->right;  //temp의 right를 temp에 저장
		}	
		else {  //삭제 할 값보다 루트노드의 키값이 큰 경우
			temp = temp->left;  //temp의 left를 temp에 저장
		}
	}

	return 0;
}

Node* searchRecursive(Node* ptr, int key)
{
    if (ptr == NULL) {  //ptr이 null인 경우
    	return 0;
	}
    //ptr이 null이 아닐 경우(탐색) 
  	if (key == ptr->key) {  //순환으로 탐색 중 원하는 키 값을 발견 했을 경우
    	return ptr;  //ptr의 주소를 반환
   	}
  	else if (key > ptr->key) {  //찾는 값보다 루트노드의 키값이 작은 경우
    	searchRecursive(ptr->right, key);  //오른쪽 서브트리로 이동
	}
  	else {  //찾는 값보다 루트노드의 키값이 큰 경우
    	searchRecursive(ptr->left, key);  //왼쪽 서브트리로 이동
	}
}

Node* searchIterative(Node* head, int key)
{
    Node* temp;
	
	if (temp == NULL) {  //temp가 null인 경우
    	return 0;
	}
    //temp가 null이 아닐 경우(탐색) 
	temp = head->left;  //temp가 head의 left를 참조
  	while (temp) {  
    	if (key == temp->key) {  //반복으로 탐색 중 원하는 키 값을 발견 했을 경우
			return temp;  //temp의 주소를 반환
		}
    	else if (key > temp->key) {  //찾는 값보다 루트노드의 키값이 작은 경우
			temp = temp->right;  //temp의 right를 temp에 저장
		}		
		else {  //찾는 값보다 루트노드의 키값이 큰 경우
			temp = temp->left;  //temp의 left를 temp에 저장
		}
	}
}


int freeBST(Node* head)
{
    Node* p = head;  //p는 head가 가리키는 노드를 할당

	Node* prev = NULL;  //prev를 null로 초기화
	while(p != NULL) {
		prev = p;
		p = p->right;
		freeBST(prev);  //prev의 메모리 할당 해제
	}
	freeBST(head); //head의 메모리 할당 해제

    return 0;
}