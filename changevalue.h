#ifndef CHANGE_VALUE_H
#define CHANGE_VALUE_H

#include <iostream>
#include <cstdlib>
#include <malloc.h>

#include "smatrix.h"

void insertNode(int val, int i, int j, node **&row, node **&col);
void deleteNode(node *&el);
void changeVal(node **&row, node **&col, int base_elem);

#endif // CHANGE_VALUE_H