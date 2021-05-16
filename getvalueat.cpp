#include "getvalueat.h"

int getValueAt(int x, int y, node **row, int size, int base_elem)
{
	if(y < 0 || x < 0 || y > size - 1 || x > size - 1)
	{
		throw std::range_error("x or y out of range");
	}
	node *it = row[y]->right;
	while(it != row[y])
	{
		if(it->col == x)
		{
			return it->val;
		}
		else if (it->col > x)
		{
			return base_elem;
		}
		it = it->right;
	}
	return base_elem;
}

void checkAndAddValueOfNode(std::vector<int> &n8brs, node *elem, int row_diff, int col_diff, node **row, int size, int base_elem)
{
	int x = elem->col+col_diff;
	int y = elem->row+row_diff;
	if(y < 0 || x < 0 || y > size - 1 || x > size - 1)
	{
		return;
	}
	n8brs.push_back(getValueAt(x, y, row, size, base_elem));
}