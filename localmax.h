#ifndef LOCAL_MAX_H
#define LOCAL_MAX_H

#include <iostream>
#include <cstdlib>
#include <malloc.h>
#include <vector>

#include "smatrix.h"
#include "getvalueat.h"

bool isLocalMax(node* elem, node **row, int size, int base_elem);
void localMax(node **row, node **col, int size, int base_elem);

#endif // LOCAL_MAX_H