#include "min_max.h"

int min(node **&row, node **&col, int size, int base_elem)
{
    int min = std::numeric_limits<int>::max();
    node *temp;

    for (int i = 0; i < size; i++)
    {
        temp = row[i]->right;
        if (temp != nullptr)
        {
            while (temp != row[i])
            {
                if(temp->val < min)
                {
                    min = temp->val;
                }
                temp = temp->right;
            }
        }
    }

    if(base_elem < min)
    {
        min = base_elem;
    }

    return min;
}

int max(node **&row, node **&col, int size, int base_elem)
{
    int max = std::numeric_limits<int>::min();
    node *temp;

    for (int i = 0; i < size; i++)
    {
        temp = row[i]->right;
        if (temp != nullptr)
        {
            while (temp != row[i])
            {
                if(temp->val > max)
                {
                    max = temp->val;
                }
                temp = temp->right;
            }
        }
    }

    if(base_elem > max)
    {
        max = base_elem;
    }

    return max;
}