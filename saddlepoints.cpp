#include "saddlepoints.h"

bool checkColMin(node **col, node *elem, int base_elem, int size)
{
	int colCount = 0;
	bool isColMin = true;
	node *temp = col[elem->col]->down;
	if (temp != nullptr)
	{
		while (temp != col[elem->col])
		{
			if (temp->val < elem->val)
			{
				isColMin = false;
			}
			colCount++;
			temp = temp->down;
		}
	}
	if (colCount < size)
	{
		if (base_elem < elem->val)
		{
			isColMin = false;
		}
	}
	return isColMin;
}

bool checkColMax(node **col, node *elem, int base_elem, int size)
{
	int colCount = 0;
	bool isColMax = true;
	node *temp = col[elem->col]->down;
	if (temp != nullptr)
	{
		while (temp != col[elem->col])
		{
			if (temp->val > elem->val)
			{
				isColMax = false;
			}
			colCount++;
			temp = temp->down;
		}
	}
	if (colCount < size)
	{
		if (base_elem > elem->val)
		{
			isColMax = false;
		}
	}
	return isColMax;
}

void getSaddlePoints(node **row, node **col, int size, int base_elem)
{
	int saddleCount = 0;
	node *temp, *rowMax, *rowMin;
	bool isColMin, isColMax;
	int min, max, rowCount;
	for (int i = 0; i < size; i++)
	{
		temp = row[i]->right;
		min = std::numeric_limits<int>::max();
		max = std::numeric_limits<int>::min();
		rowCount = 0;
		rowMax = nullptr;
		rowMin = nullptr;
		if (temp != nullptr)
		{
			while (temp != row[i])
			{
				if (temp->val < min)
				{
					min = temp->val;
					rowMin = temp;
				}
				if (temp->val > max)
				{
					max = temp->val;
					rowMax = temp;
				}
				rowCount++;
				temp = temp->right;
			}
			if (rowMin != nullptr)
			{
				if (rowCount < size)
				{
					if (rowMin->val < base_elem)
					{
						isColMax = checkColMax(col, rowMin, base_elem, size);
						if (isColMax == true)
						{
							std::cout << rowMin->val << " (" << rowMin->row
								<< ", " << rowMin->col << ") ";
							saddleCount++;
						}
					}
				}
				else
				{
					isColMax = checkColMax(col, rowMin, base_elem, size);
					if (isColMax == true)
					{
						std::cout << rowMin->val << " (" << rowMin->row
							<< ", " << rowMin->col << ") ";
						saddleCount++;
					}
				}
			}
			if (rowMax != nullptr)
			{
				if (rowCount < size)
				{
					if (rowMax->val > base_elem)
					{
						isColMin = checkColMin(col, rowMax, base_elem, size);
						if (isColMin == true)
						{
							saddleCount++;
							std::cout << rowMax->val << " (" << rowMax->row
								<< ", " << rowMax->col << ") ";
						}
					}
				}
				else
				{
					isColMin = checkColMin(col, rowMax, base_elem, size);
					if (isColMin == true)
					{
						saddleCount++;
						std::cout << rowMax->val << " (" << rowMax->row
							<< ", " << rowMax->col << ") ";
					}
				}
			}
		}
	}
	if (saddleCount == 0)
	{
		std::cout << "This matrix doesn't have saddle points!" << std::endl;
	}
	else
	{
		std::cout << std::endl;
	}
}
