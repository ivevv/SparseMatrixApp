#ifndef LOCAL_MIN_H
#define LOCAL_MIN_H

#include <iostream>
#include <cstdlib>
#include <malloc.h>

#include "smatrix.h"

bool checkRowNeighborMin(node *elem, node *n8br, int base_elem, char dir);
bool checkColNeighborMin(node *elem, node *n8br, int base_elem, char dir);
bool checkDiagNeighborMin(node *elem, node *n8br, int base_elem, char colDir, char rowDir);
void localMin(node **row, node **col, int size, int base_elem);

#endif // LOCAL_MIN_H