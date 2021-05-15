#include <iostream>
#include <fstream>
#include <cstdlib>
#include <malloc.h>
#include "smatrix.h"

void rowTraversal(node **row, int size)
{
	node *temp;
	for (int i = 0; i < size; i++)
	{
		temp = row[i]->right;
		if (temp != nullptr)
		{
			while (temp != row[i])
			{
				std::cout << temp->val << " ";
				temp = temp->right;
			}
		}
	}
	std::cout << std::endl;
}

void colTraversal(node **col, int size)
{
	node *temp;
	for (int i = 0; i < size; i++)
	{
		temp = col[i]->down;
		if (temp != nullptr)
		{
			while (temp != col[i])
			{
                std::cout << temp->val << " ";
				temp = temp->down;
			}
		}
	}
    std::cout << std::endl;
}
