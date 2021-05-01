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

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{
	char command;
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

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;
	return 1;
}



void inorderTraversal(Node* ptr)
{
   
}

void preorderTraversal(Node* ptr)
{
    
}

void postorderTraversal(Node* ptr)
{

}


int insert(Node* head, int key)
{
    Node* temp;
	Node* node = (Node*)malloc(sizeof(Node));  //삽입할 새로운 노드의 동적 메모리 할당
	node->key = key;  //새로운 노드의 데이터필드에 key 저장

	node->left = NULL;  //새로운 노드의 left는 null을 할당하여 연결을 해제
	node->right = NULL;  //새로운 노드의 right는 null을 할당하여 연결을 해제
	
	if(head->left == NULL) {  //head의 left가 null인 경우
		head->left = node;  //새로운 노드의 주소를 head의 left에 저장

		return 0;
	}

	temp = head->left;  //temp가 head의 left를 참조
	while (head) {
		if (key > temp->key) {  //넣는 값보다 루트노드의 키값이 작은 경우
			if(temp->right == NULL) {  //temp의 right가 null인 경우 
				temp->right = node;  //새로운 노드의 주소를 temp의 right에 저장
			}
			else {
				temp = temp->right;  //temp의 right를 temp에 저장
			}
		}
		else if (key < temp->key) {  //넣는 값보다 루트노드의 키값이 큰 경우
			if(temp->left == NULL) {  //temp의 left가 null인 경우 
				temp->left = node;  //새로운 노드의 주소를 temp의 left에 저장
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

}

Node* searchRecursive(Node* ptr, int key)
{

}

Node* searchIterative(Node* head, int key)
{

}


int freeBST(Node* head)
{
    Node* p = head;  //p는 head가 가리키는 노드를 할당

	Node* prev = NULL;  //prev 노드를 null로 초기화
	while(p != NULL) {
		prev = p;
		p = p->right;
		freeBST(prev);  //prev의 메모리 할당 해제
	}
	freeBST(head); //head의 메모리 할당 해제

    return 0;
}