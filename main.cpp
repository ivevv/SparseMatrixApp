#include <iostream>
#include <fstream>
#include <cstdlib>
#include <malloc.h>
#include "smatrix.h"

using namespace std;

void addNode(int val, int i, int j, node **&row, node **&col);
void getMatrix(node **&row, node **&col, int size, int &count);
node * makeHead();
void rowTraversal(node **row, int size);
void colTraversal(node **row, int size);

//just a draft to test current functions
//should probably write a menu with all options of working w/matrix
int main()
{
	int size = 12;
	node **row = (node**)malloc(sizeof(node)*size);
	node **col = (node**)malloc(sizeof(node)*size);
	for (int i = 0; i < size; i++)
	{
		row[i] = makeHead();
		col[i] = makeHead();
	}
	int count = 0;
	getMatrix(row, col, size, count);
	rowTraversal(row, size);
	colTraversal(col, size);
	return 0;
}