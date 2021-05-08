#include "sum_all.h"

int sum_all(node **&row, node **&col, int size, int base_elem)
{
    int sum = 0;
    node *temp;
    int non_base_nodes = size*size;

    for (int i = 0; i < size; i++)
    {
        temp = row[i]->right;
        if (temp != nullptr)
        {
            while (temp != row[i])
            {
                sum += temp->val;
                temp = temp->right;
                --non_base_nodes;
            }
        }
    }

    sum += non_base_nodes * base_elem;

    return sum;
}