#ifndef MIN_MAX_H
#define MIN_MAX_H

#include "smatrix.h"
#include <limits>

int min(node **&row, node **&col, int size, int base_elem);
int max(node **&row, node **&col, int size, int base_elem);

#endif //MIN_MAX_H
