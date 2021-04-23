#include <iostream>
#include <fstream>
#include <cstdlib>
#include <malloc.h>
#include "smatrix.h"

using namespace std;

void addNode(int val, int i, int j, node **&row, node **&col)
{
	node *el = new node;
	el->val = val;
	el->row = i;
	el->col = j;
	el->right = row[i];
	el->down = col[j];
	node *temp = row[i];
	while (temp->right != row[i])
	{
		temp = temp->right;
	}
	temp->right = el;
	el->left = temp;
	temp = col[j];
	while (temp->down != col[j])
	{
		temp = temp->down;
	}
	temp->down = el;
	el->up = el;
}

void getMatrix(node **&row, node **&col, int size, int &count)
{
	ifstream data("sparsematrix.txt");
	if (data.is_open())
	{
		int temp;
		for (int i = 0; i < size; i++) // row
		{
			for (int j = 0; j < size; j++) //column
			{
				data >> temp;
				if (temp != 0)
				{
					addNode(temp, i, j, row, col);
					count++;
				}
			}
		}
	}
	data.close();
}

node * makeHead()
{
	node *head = new node;
	head->down = head;
	head->up = head;
	head->left = head;
	head->right = head;
	return head;
};
