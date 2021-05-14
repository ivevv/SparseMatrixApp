#include <iostream>
#include <cstdlib>
#include <malloc.h>
#include "smatrix.h"

bool checkRowNeighborMax(node *elem, node *n8br, int base_elem, char dir)
{
	if (dir == 'r')
	{
		if (n8br->col == (elem->col + 1))
		{
			if (n8br->val >= elem->val)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			if (base_elem > elem->val)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	else
	{
		if (n8br->col == (elem->col - 1))
		{
			if (n8br->val >= elem->val)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			if (base_elem > elem->val)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
}

bool checkColNeighborMax(node *elem, node *n8br, int base_elem, char dir)
{
	if (dir == 'd')
	{
		if (n8br->row == (elem->row + 1))
		{
			if (n8br->val >= elem->val)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			if (base_elem > elem->val)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	else
	{
		if (n8br->row == (elem->row - 1))
		{
			if (n8br->val >= elem->val)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			if (base_elem > elem->val)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
}

bool checkDiagNeighborMax(node *elem, node *n8br, int base_elem, char colDir, char rowDir)
{
	bool temp;
	if (colDir == 'd')
	{
		if (n8br->row == (elem->row + 1))
		{
			temp = checkRowNeighborMax(elem, n8br, base_elem, rowDir);
			return temp;
		}
		else
		{
			if (base_elem > elem->val)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	else
	{
		if (n8br->row == (elem->row - 1))
		{
			temp = checkRowNeighborMax(elem, n8br, base_elem, rowDir);
			return temp;
		}
		else
		{
			if (base_elem > elem->val)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
}

void localMax(node **row, node **col, int size, int base_elem)
{
	int locCount = 0;
	node *elem, *n8br;
	bool isMax = true;
	bool check;
	for (int i = 0; i < size; i++)
	{
		elem = row[i]->right;
		if (elem != nullptr)
		{
			while (elem != row[i])
			{
				if (i == 0)
				{
					n8br = elem->down;
					check = checkColNeighborMax(elem, n8br, base_elem, 'd');
					if (check == false)
					{
						isMax = false;
					}
					n8br = elem->right;
					check = checkRowNeighborMax(elem, n8br, base_elem, 'r');
					if (check == false)
					{
						isMax = false;
					}
					n8br = n8br->down;
					check = checkDiagNeighborMax(elem, n8br, base_elem, 'd', 'r');
					if (check == false)
					{
						isMax = false;
					}
					n8br = elem->left;
					check = checkRowNeighborMax(elem, n8br, base_elem, 'l');
					if (check == false)
					{
						isMax = false;
					}
					n8br = n8br->down;
					check = checkDiagNeighborMax(elem, n8br, base_elem, 'd', 'l');
					if (check == false)
					{
						isMax = false;
					}
				}
				else
				{
					if (i == (size - 1))
					{
						n8br = elem->up;
						check = checkColNeighborMax(elem, n8br, base_elem, 'u');
						if (check == false)
						{
							isMax = false;
						}
						n8br = elem->right;
						check = checkRowNeighborMax(elem, n8br, base_elem, 'r');
						if (check == false)
						{
							isMax = false;
						}
						n8br = n8br->up;
						check = checkDiagNeighborMax(elem, n8br, base_elem, 'u', 'r');
						if (check == false)
						{
							isMax = false;
						}
						n8br = elem->left;
						check = checkRowNeighborMax(elem, n8br, base_elem, 'l');
						if (check == false)
						{
							isMax = false;
						}
						n8br = n8br->up;
						check = checkDiagNeighborMax(elem, n8br, base_elem, 'u', 'l');
						if (check == false)
						{
							isMax = false;
						}
					}
					else
					{
						n8br = elem->up;
						check = checkColNeighborMax(elem, n8br, base_elem, 'u');
						if (check == false)
						{
							isMax = false;
						}
						n8br = n8br->left;
						check = checkDiagNeighborMax(elem, n8br, base_elem, 'u', 'l');
						if (check == false)
						{
							isMax = false;
						}
						n8br = elem->left;
						check = checkRowNeighborMax(elem, n8br, base_elem, 'l');
						if (check == false)
						{
							isMax = false;
						}
						n8br = n8br->down;
						check = checkDiagNeighborMax(elem, n8br, base_elem, 'd', 'l');
						if (check == false)
						{
							isMax = false;
						}
						n8br = elem->down;
						check = checkColNeighborMax(elem, n8br, base_elem, 'd');
						if (check == false)
						{
							isMax = false;
						}
						n8br = n8br->right;
						check = checkDiagNeighborMax(elem, n8br, base_elem, 'd', 'r');
						if (check == false)
						{
							isMax = false;
						}
						n8br = elem->right;
						check = checkRowNeighborMax(elem, n8br, base_elem, 'r');
						if (check == false)
						{
							isMax = false;
						}
						n8br = n8br->up;
						check = checkDiagNeighborMax(elem, n8br, base_elem, 'd', 'r');
						if (check == false)
						{
							isMax = false;
						}
					}
				}
				if (isMax == true)
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
		std::cout << "This matrix doens't have local maximums!" << std::endl;
	}
	else
	{
		std::cout << std::endl;
	}
}
