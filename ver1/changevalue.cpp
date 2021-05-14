#include <iostream>
#include <cstdlib>
#include <malloc.h>
#include "smatrix.h"

void insertNode(int val, int i, int j, node **&row, node **&col)
{
	node *el = new node;
	el->val = val;
	el->row = i;
	el->col = j;
	node *tempU, *tempD, *tempL, *tempR;
	tempU = col[j]->down;
	if (tempU != nullptr)
	{
		while (tempU->col < j)
		{
			tempU = tempU->down;
		}
		tempD = tempU->down;
		el->up = tempU;
		el->down = tempD;
		tempU->down = el;
		tempD->up = el;
	}
	else
	{
		col[j]->down = el;
		el->up = col[j];
		el->down = col[j];
	}
	tempL = row[i]->right;
	if (tempL != nullptr)
	{
		while (tempL->col < i)
		{
			tempL = tempL->right;
		}
		tempR = tempL->right;
		el->right = tempR;
		el->left = tempL;
		tempL->right = el;
		tempR->left = el;
	}
	else
	{
		row[i]->right = el;
		el->right = row[i];
		el->left = row[i];
	}
}

void deleteNode(node *&el)
{
	node *tempU, *tempD, *tempR, *tempL;
	tempU = el->up;
	tempD = el->down;
	tempR = el->right;
	tempL = el->left;
	tempU->down = tempD;
	tempD->up = tempU;
	tempR->left = tempL;
	tempL->right = tempR;
	delete[]el;
}

void changeVal(node **&row, node **&col, int base_elem)
{
	int newVal, newRow, newCol;
	std::cout << "Enter new value:" << std::endl;
	std::cin >> newVal;
	std::cin.clear();
	std::cout << "Enter its position. Row:" << std::endl;
	std::cin >> newRow;
	std::cin.clear();
	std::cout << "Column:" << std::endl;
	std::cin >> newCol;
	std::cin.clear();
	if (newVal == base_elem)
	{ 
		node *temp;
		temp = row[newRow]->right;
		if (temp != nullptr)
		{
			while (temp != row[newRow])
			{
				if (temp->col == newCol)
				{
					node *curr;
					curr = temp;
					deleteNode(curr);
					break;
				}
				temp = temp->right;
			}
		}
	}
	else
	{
		node *temp;
		temp = row[newRow]->right;
		if (temp != nullptr)
		{
			bool changeDone = false;
			while (temp != row[newRow])
			{
				if (temp->col == newCol)
				{
					temp->val = newVal;
					changeDone = true;
					break;
				}
				temp = temp->right;
			}
			if (changeDone != true)
			{
				insertNode(newVal, newRow, newCol, row, col);
			}
		}
		else
		{
			insertNode(newVal, newRow, newCol, row, col);
		}
	}
}