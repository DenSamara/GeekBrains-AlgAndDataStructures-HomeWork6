#include "Main.h"
#include <malloc.h>
#include <stdio.h>
#include <locale.h>

typedef int T;
FILE * file;

typedef struct Node {
	T data;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;

// Построить идеально сбалансированное дерево с n узлами
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

// Распечатка двоичного дерева в виде скобочной записи
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

int main(int argc, const char * argv[]){
	Node* tree = NULL;
	int x = 0;

	setlocale(LC_ALL, "Rus");

	printf("Введите количество узлов для дерева:\n");
	scanf("%d", &x);
	printf("\n");

	tree = Tree(x);
	printTree(tree);

	printf("\n");
	system("pause");
	return 0;
}

