#ifndef SMATRIX_H
#define SMATRIX_H

struct node
{
	int val;
	int row;
	int col;
	node *down;
	node *up;
	node *left;
	node *right;
};

#endif 

