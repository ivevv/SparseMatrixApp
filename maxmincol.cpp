#include "maxmincol.h"

void maxMinCol(node **col, int size, int base_elem)
{
	int *colMin;
	colMin = (int*)malloc(size * sizeof(int));
	int colCount;
	int min;
	node *temp;
	for (int i = 0; i < size; i++)
	{
		temp = col[i]->down;
		min = std::numeric_limits<int>::max();
		colCount = 0;
		if (temp != nullptr)
		{
			while (temp != col[i])
			{
				if (temp->val < min)
				{
					min = temp->val;
				}
				colCount++;
				temp = temp->down;
			}
			if (colCount < size)
			{
				if (min < base_elem)
				{
					colMin[i] = min;
				}
				else
				{
					colMin[i] = base_elem;
				}
			}
			else
			{
				colMin[i] = min;
			}
		}
		else
		{
			colMin[i] = base_elem;
		}
	}
	int max = std::numeric_limits<int>::min();
	int colId;
	for (int i = 0; i < size; i++)
	{
		if (colMin[i] > max)
		{
			max = colMin[i];
			colId = i;
		}
	}
	std::cout << max << " (column " << colId << ")" << std::endl;
}
