#include "Main.h"
#include <malloc.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

typedef int T;
FILE * file;
static int const ARRAY_LENGTH = 30;

typedef struct Node {
	T data;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;

// ��������� �������� ���������������� ������ � n ������
Node *Tree ( int n)
{
	Node *newNode;
	int x , nl , nr;

	if ( n == 0 )
		newNode = NULL;
	else
	{
		x = n+n;
		nl = n / 2;
		nr = n - nl - 1;
		newNode = ( Node*) malloc ( sizeof ( Node ));
		newNode -> data = x;
		newNode -> left = Tree ( nl );
		newNode -> right = Tree ( nr );
	}

	return newNode;
}

// ���������� ��������� ������ � ���� ��������� ������
void printTree (Node *root ) {
	if (root)
	{
		printf ( "%d" , root -> data );
		if ( root -> left || root -> right)
		{
			printf ( "(" );

			if ( root -> left )
				printTree ( root -> left );
			else
				printf ( "NULL" );

			printf ( "," );

			if ( root -> right )
				printTree ( root -> right );
			else
				printf ( "NULL" );

			printf ( ")" );
		}
	}
}

void preOrderTravers ( Node *root ) {
	if ( root ) {
		printf ( "%d " , root -> data );

		preOrderTravers ( root -> left );
		preOrderTravers ( root -> right );
	}
}

//����� ����������� ������� ����� �� ������� �������� �� ��� �������
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

int main(int argc, const char * argv[]){
	Node* tree = NULL;
	int x = 0;
	char data[] = {'S', 'i', 'm', 'p', 'l', 'e', ' ', 'd', 'a', 't', 'a', ' ', 't', 'o', ' ', 'd', 'e', 'm', 'o', 'n', 's', 't', 'r', 'a', 't', 'i', 'o', 'n', '\n'};

	setlocale(LC_ALL, "Rus");

	//--== ������� 1 ==--
	// ����������� ���������� ���-�������. �� ���� ������� �������� ������, �� ������ ����� ����� ��������.
	printf("������ ��� �����������: ");
	printHash(data);

	printf("Hash = %llu\n", hash(data, ARRAY_LENGTH));
	printf("\n");

	//--== ������� 2 ==--
	// ����������� �������� ������ ������
	printf("������� ���������� ����� ��� ������:\n");
	scanf("%d", &x);
	printf("\n");

	tree = Tree(x);
	printTree(tree);

	printf("\n");
	system("pause");
	return 0;
}

