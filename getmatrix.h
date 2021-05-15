#ifndef GETMATRIX_H
#define GETMATRIX_H

#include <fstream>
#include <string>

#include "smatrix.h"

//reading sparse matrix from file
//each row & column is a circular doubly linked list
//each list head is an element of an array (row/col)

void addNode(int val, int i, int j, node **&row, node **&col);
void getMatrix(node **&row, node **&col, int size, int base_elem, std::string filename);
node* makeHead();

#endif //GETMATRIX_H