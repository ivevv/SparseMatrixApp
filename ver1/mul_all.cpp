#include "mul_all.h"


long long mul_all(node **&row, node **&col, int size, int base_elem)
{
    long long mul = 1;
    node *temp;
    int non_base_nodes = size*size;

    for (int i = 0; i < size; i++)
    {
        temp = row[i]->right;
        if (temp != nullptr)
        {
            while (temp != row[i])
            {
                mul = mul * (long long)temp->val;
                temp = temp->right;
                --non_base_nodes;
            }
        }
    }

    mul *= (long long)pow(base_elem, non_base_nodes);

    return mul;
}