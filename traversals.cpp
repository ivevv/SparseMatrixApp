#include <iostream>
#include <fstream>
#include <cstdlib>
#include <malloc.h>
#include "smatrix.h"

using namespace std;

void rowTraversal(node **row, int size)
{
	node *temp = new node;
	for (int i = 0; i < size; i++)
	{
		temp = row[i]->right;
		if (temp != NULL)
		{
			while (temp != row[i])
			{
				cout << temp->val << " ";
				temp = temp->right;
			}
		}
	}
	cout << endl;
}

void colTraversal(node **col, int size)
{
	node *temp = new node;
	for (int i = 0; i < size; i++)
	{
		temp = col[i]->down;
		if (temp != NULL)
		{
			while (temp != col[i])
			{
				cout << temp->val << " ";
				temp = temp->down;
			}
		}
	}
	cout << endl;
}