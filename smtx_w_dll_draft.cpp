#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct smtx
{
	int val;
	int row;
	int col;
	smtx *next;
	smtx *prev;
};

smtx *head = NULL;
smtx *tail = NULL;
int elcount = 0;

void add_elmt(int val, int row, int col, smtx *&head)
{
	smtx *temp = new smtx;
	if (head == NULL)
	{
		temp->val = val;
		temp->row = row;
		temp->col = col;
		temp->next = NULL;
		temp->prev = NULL;
		head = temp;
	}
	else
	{
		smtx *elmt = new smtx;
		elmt->val = val;
		elmt->row = row;
		elmt->col = col;
		elmt->next = NULL;
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = elmt;
		elmt->prev = temp;
	}
}

void get_smatrix(smtx *&head, int &elcount)
{
	int msize = 12;
	ifstream data("sparsematrix.txt");
	if (data.is_open())
	{
		int temp;
		for (int row = 0; row < msize; row++)
		{
			for (int column = 0; column < msize; column++)
			{
				data >> temp;
				if (temp != 0)
				{
					add_elmt(temp, row, column, head);
					elcount++;
				}
			}
		}
	}
	data.close();
	tail = head;
	smtx *tempt = head;
	cout << "value:" << '\t';
	while (tempt != NULL)
	{
		cout << tempt->val << " ";
		tempt = tempt->next;
	}
	cout << endl << "row:" << '\t';
	tempt = head;
	while (tempt != NULL)
	{
		cout << tempt->row << " ";
		tempt = tempt->next;
	}
	cout << endl << "column:" << '\t';
	tempt = head;
	while (tempt != NULL)
	{
		cout << tempt->col << " ";
		tempt = tempt->next;
	}
}

int main()
{
	get_smatrix(head, elcount);
	return 0;
}