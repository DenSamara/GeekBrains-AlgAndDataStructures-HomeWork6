#include "Main.h"
#include <malloc.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

//��������� �����

typedef int T;
FILE * file;
static int const ARRAY_LENGTH = 30;

typedef struct Node {
	T data;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;

//-------------------------------Task 1------------------------------------
//����� ����������� ������� ����� �� ������� �������� �� ��� �������
//�������� � �� 1 �������� � �� 25
unsigned long long int hash(char data[], int arraylength){
	unsigned long long int result = 0;
	int i, charCode = 0;
	double tmp = 0.0, s;
	for(i = 0; i < arraylength; i++){
		charCode = (int)data[i];
		if (charCode > 0)
			tmp += ((double)(i+1)/(double)charCode );
	}

	//��������, ��� ����� 16 ������
	s = pow(10, 15);

	//����������� ������� ����� � �������� �����
	result = (unsigned long long int)(tmp*s);
	return result;
}

void printHash(char data[]){
	int i = 0;
	char c = ' ';
	while (c != '\n'){
		c = data[i];
		printf("%c", c);
		i++;
	}
	printf("\n");
}
//--------------------------------Task 2-----------------------------------
Node* getFreeNode(T value, Node *parent) {
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

void addNode(Node **head, int value){
	Node *tmp = NULL;
    Node *ins = NULL;
    if (*head == NULL) {
        *head = getFreeNode(value, NULL);
        return;
    }
     
    tmp = *head;
    while (tmp) {
        if (value > tmp->data) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = getFreeNode(value, tmp);
                return;
            }
        } else if (value < tmp->data) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = getFreeNode(value, tmp);
                return;
            }
        } else {
            break;
        }
    }
}

Node* getMaxNode(Node *root) {
    while (root->right) {
        root = root->right;
    }
    return root;
}

//����� ���
void printTree(Node *root, const char *dir, int level) {
    if (root) {
        printf("lvl %d %s = %d\n", level, dir, root->data);
        printTree(root->left, "left", level+1);
        printTree(root->right, "right", level+1);
    }
}

//����� ���
void printTreeKPL(Node *root, const char *dir, int level) {
    if (root) {
        printf("lvl %d %s = %d\n", level, dir, root->data);
        printTree(root->right, "right", level+1);
		printTree(root->left, "left", level+1);
    }
}

//����� ���
void printTreeLPK(Node *root, const char *dir, int level) {
    if (root) {
        printTree(root->left, "left", level+1);
        printTree(root->right, "right", level+1);
		printf("lvl %d %s = %d\n", level, dir, root->data);
    }
}

Node* findNodeByValue(Node *root, T value) {
    while (root) {
        if (root->data > value) {
            root = root->left;
            continue;
        } else if (root->data < value) {
            root = root->right;
            continue;
        } else {
            return root;
        }
    }
    return NULL;
}
	
//������� ���������� ������
Node* createBinarySearchTree(Node *root, int data[]){
	int i = 0, value = data[0];
	
	while (value > -1){
		addNode(&root, value);
		i++;
		value = data[i];
	}
	return root;
}

/*
      10
     /  \
    7   12
   /\   /\
  6  9 11 14
 /
3
 \
  4
*/
int main(int argc, const char * argv[]){
	Node *tree = NULL, *any = NULL;
	int x = 0;
	char dataForHash[] = {'S', 'i', 'm', 'p', 'l', 'e', ' ', 'd', 'a', 't', 'a', ' ', 't', 'o', ' ', 'd', 'e', 'm', 'o', 'n', 's', 't', 'r', 'a', 't', 'i', 'o', 'n', '\n'};
	int dataForTree[] = {10, 7, 9, 12, 6, 14, 11, 3, 4, -1};

	setlocale(LC_ALL, "Rus");

	//--== ������� 1 ==--
	// ����������� ���������� ���-�������. �� ���� ������� �������� ������, �� ������ ����� ����� ��������.
	printf("������ ��� �����������: ");
	printHash(dataForHash);

	printf("Hash = %llu\n", hash(dataForHash, ARRAY_LENGTH));
	printf("\n");

	//--== ������� 2 ==--
	//����������� �������� ������ ������
	//����� ��� ���� ��������� � ������ ��������: 10 7 9 12 6 14 11 3 4
	tree = createBinarySearchTree(tree, dataForTree);

	//--== ������� 2A ==--
	//�������� � ������ ��������� ������� ������;
	printf("���:\n");
	printTree(tree, "root", 0);
	
	printf("���:\n");
	printTreeKPL(tree, "root", 0);
	
	printf("���\n");
	printTreeLPK(tree, "root", 0);

	//--== ������� 2� ==--
	//����������� ����� � �������� ������ ������;
	printf("������� �������� ���� ��� ������: ");
	scanf("%d", &x);
	any = findNodeByValue(tree, x);
	if (any){
		printf("���� ������\n");
	}else
		printf("���� �� ������\n");

	printf("\n");
	system("pause");
	return 0;
}

