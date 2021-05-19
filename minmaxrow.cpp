#include "minmaxrow.h"

void minMaxRow(node **row, int size, int base_elem)
{
	int *rowMax;
	rowMax = (int*)malloc(size*sizeof(int));
	int rowCount;
	int max;
	node *temp;
	for (int i = 0; i < size; i++)
	{
		temp = row[i]->right;
		max = std::numeric_limits<int>::min();
		rowCount = 0;
		if (temp != nullptr)
		{
			while (temp != row[i])
			{
				if (temp->val > max)
				{
					max = temp->val;
				}
				rowCount++;
				temp = temp->right;
			}
			if (rowCount < size)
			{
				if (max > base_elem)
				{
					rowMax[i] = max;
				}
				else
				{
					rowMax[i] = base_elem;
				}
			}
			else
			{
				rowMax[i] = max;
			}
		}
		else
		{
			rowMax[i] = base_elem;
		}
	}
	int min = std::numeric_limits<int>::max();
	int rowId;
	for (int i = 0; i < size; i++)
	{
		if (rowMax[i] < min)
		{
			min = rowMax[i];
			rowId = i;
		}
	}
	std::cout << min << " (row " << rowId << ")" << std::endl;
	free(rowMax);
}
