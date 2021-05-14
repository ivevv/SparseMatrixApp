#include <iostream>
#include <fstream>
#include <cstdlib>
#include <malloc.h>
#include <string>
#include "smatrix.h"
#include "sum_all.h"
#include "mul_all.h"
#include "min_max.h"

void addNode(int val, int i, int j, node **&row, node **&col);
void getMatrix(node **&row, node **&col, int size, std::string filename);
node * makeHead();
void rowTraversal(node **row, int size);
void colTraversal(node **row, int size);

//just a draft to test current functions

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
	int base_elem = 0; //for sparsematrix1
	//int base_elem = 5; //for sparsematrix2
	std::string = "sparsematrix1.txt"; //for sparsematrix1
	//std::string = "sparsematrix2.txt"; //for sparsematrix2
	getMatrix(row, col, size, base_elem, filename);
	rowTraversal(row, size);
	colTraversal(col, size);

	std::cout << "sum of all elements: " << sum_all(row, col, size) << "\n";
    	std::cout << "mul of all elements: " << mul_all(row, col, size) << "\n";
    	std::cout << "min: " << min(row, col, size) << "\n";
    	std::cout << "max: " << max(row, col, size) << "\n";
	return 0;
}
