#ifndef LOCAL_MIN_H
#define LOCAL_MIN_H

#include <iostream>
#include <cstdlib>
#include <malloc.h>
#include <vector>

#include "smatrix.h"
#include "getvalueat.h"

bool isLocalMin(node* elem, node **row, int size, int base_elem);
void localMin(node **row, node **col, int size, int base_elem);

#endif // LOCAL_MIN_H