#include "Main.h"
#include <stdio.h>
#include <locale.h>

typedef struct Node {
	int data;
	struct Node * left;
	struct Node * right;
	struct Node * parent;
} Node;

// Распечатка двоичного дерева в виде скобочной записи
void printTree (Node *root ) {
	if ( root)
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

int main(int argc, const char * argv[]){
	int x = 0;

	setlocale(LC_ALL, "Rus");



	system("pause");
	return 0;
}

