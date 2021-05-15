#ifndef LOCAL_MAX_H
#define LOCAL_MAX_H

#include <iostream>
#include <cstdlib>
#include <malloc.h>

#include "smatrix.h"

bool checkRowNeighborMax(node *elem, node *n8br, int base_elem, char dir);
bool checkColNeighborMax(node *elem, node *n8br, int base_elem, char dir);
bool checkDiagNeighborMax(node *elem, node *n8br, int base_elem, char colDir, char rowDir);
void localMax(node **row, node **col, int size, int base_elem);

#endif // LOCAL_MAX_H