#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H

#include <iostream>
#include <limits>

#include "smatrix.h"

bool checkColMin(node **col, node *elem, int base_elem, int size);
bool checkColMax(node **col, node *elem, int base_elem, int size);
void getSaddlePoints(node **row, node **col, int size, int base_elem);

#endif // SADDLE_POINTS_H
