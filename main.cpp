#include <iostream>
#include <fstream>
#include <cstdlib>
#include <malloc.h>
#include <string>

#include "smatrix.h"
#include "sum_all.h"
#include "mul_all.h"
#include "min_max.h"
#include "traversals.h"
#include "getmatrix.h"
#include "saddlepoints.h"
#include "changevalue.h"
#include "minmaxrow.h"
#include "maxmincol.h"
#include "localmin.h"
#include "localmax.h"

void clearMatrix(node **&row, node **&col, int size)
{
	node *temp, *curr;
	for (int i = 0; i < size; i++)
	{
		temp = row[i]->right;
		if (temp != nullptr)
		{
			while (temp != row[i])
			{
				curr = temp;
				temp = curr->right;
				delete[] curr;
			}
			row[i]->right = row[i];
			row[i]->left = row[i];
		}
		col[i]->down = col[i];
		col[i]->up = col[i];
	}
}

void processMatrix(node **&row, node **&col, int size, int base_elem, std::string filename)
{
	getMatrix(row, col, size, base_elem, filename);
	std::cout << "1. Sum of all elements: " << sum_all(row, col, size) << "\n"
			  << "Multiplication of all elements: " << mul_all(row, col, size) << "\n"
			  << "2. Minimum of the matrix: " << min(row, col, size) << "\n"
			  << "Maximum of the martix: " << max(row, col, size) << "\n"
			  << "3. Row traversal: ";
	rowTraversal(row, size);
	std::cout << "Column traversal: ";
	colTraversal(col, size);
	std::cout << "4. Local minimums: ";
	localMin(row, col, size, base_elem);
	std::cout << "Local maximums: ";
	localMax(row, col, size, base_elem);
	std::cout << "5. Minimum of row maximums: ";
	minMaxRow(row, size, base_elem);
	std::cout << "6. Maximum of column minimums: ";
	maxMinCol(col, size, base_elem);
	std::cout << "7. Saddle points: ";
	getSaddlePoints(row, col, size, base_elem);
	std::cout << "Do you want to change the value of an element? y/n \n";
	char choice;
	std::cin >> choice;
	std::cin.clear();
	if (choice == 'y')
	{
		changeVal(row, col, base_elem);
		std::cout << "Row traversal: ";
		rowTraversal(row, size);
		std::cout << "Column traversal: ";
		colTraversal(col, size);
	}
}

void interface(node **&row, node **&col, int size)
{
	std::cout << "Choose your matrix: 1/2?\n";
	int choice1;
	std::cin >> choice1;
	std::cin.clear();
	switch (choice1)
	{
	case 1:
	{
		processMatrix(row, col, size, 0, "../matrices/sparsematrix1.txt");
	}
	break;
	case 2:
	{
		processMatrix(row, col, size, 5, "../matrices/sparsematrix2.txt");
	}
	break;
	default:
	{
		std::cout << "Invalid input! Try again. \n";
		interface(row, col, size);
	}
	}
	std::cout << "Do you want to try again? y/n \n";
	char choice2;
	std::cin >> choice2;
	std::cin.clear();
	if (choice2 == 'y')
	{
		clearMatrix(row, col, size);
		interface(row, col, size);
	}
}

int main()
{
	int size = 12;
	node **row = (node **)malloc(sizeof(node) * size);
	node **col = (node **)malloc(sizeof(node) * size);
	for (int i = 0; i < size; i++)
	{
		row[i] = makeHead();
		col[i] = makeHead();
	}
	interface(row, col, size);
	clearMatrix(row, col, size);
	free(row);
	free(col);
	return 0;
}