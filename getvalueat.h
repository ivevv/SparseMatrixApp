#ifndef GET_VALUE_AT_H
#define GET_VALUE_AT_H

#include <vector>
#include <stdexcept>

#include "smatrix.h"

int getValueAt(int x, int y, node **row, int size, int base_elem);
void checkAndAddValueOfNode(std::vector<int> &n8brs, node *elem, int row_diff, int col_diff, node **row, int size, int base_elem);

#endif // GET_VALUE_AT_H