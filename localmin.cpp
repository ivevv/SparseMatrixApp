#include "localmin.h"

bool isLocalMin(node* elem, node **row, int size, int base_elem)
{
	std::vector<int> n8brs;
	checkAndAddValueOfNode(n8brs, elem, -1,  0, row, size, base_elem); // up
	checkAndAddValueOfNode(n8brs, elem, -1,  1, row, size, base_elem); // up right
	checkAndAddValueOfNode(n8brs, elem,  0,  1, row, size, base_elem); // right
	checkAndAddValueOfNode(n8brs, elem,  1,  1, row, size, base_elem); // down right
	checkAndAddValueOfNode(n8brs, elem,  1,  0, row, size, base_elem); // down
	checkAndAddValueOfNode(n8brs, elem,  1, -1, row, size, base_elem); // down left
	checkAndAddValueOfNode(n8brs, elem,  0, -1, row, size, base_elem); // left
	checkAndAddValueOfNode(n8brs, elem, -1, -1, row, size, base_elem); // up left

	for(auto val : n8brs)
	{
		if(val <= elem->val)
			return false;
	}
	return true;
}

void localMin(node **row, node **col, int size, int base_elem)
{
	int locCount = 0;
	node *elem, *n8br;
	bool isMin = true;
	bool check;
	for (int i = 0; i < size; i++)
	{
		elem = row[i]->right;
		if (elem != nullptr)
		{
			while (elem != row[i])
			{
				if (isLocalMin(elem, row, size, base_elem))
				{
					locCount++;
					std::cout << elem->val << " (" << elem->row
						<< ", " << elem->col << ") ";
				}
				elem = elem->right;
			}
		}
	}
	if (locCount == 0)
	{
		std::cout << "This matrix doesn't have local minimums!";
	}
	std::cout << std::endl;
}
