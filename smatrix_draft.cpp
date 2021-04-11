#include <iostream>
#include <fstream>
#include <cstdlib>
#include <malloc.h>

using namespace std;

void get_smatrix()
{
	int msize = 12;
	int **smtx;
	smtx = (int**)malloc(3 * sizeof(int)); //�������� ������ �� ��� ������� ������� ��� value, column � row ��������� �-��� �������
	int elcount = 1;
	for (int i = 0; i < 3; i++)
	{
		smtx[i] = (int*)malloc(elcount * sizeof(int)); //�������� ������ �� ������ ������� �������
	}
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
					smtx[0][elcount - 1] = temp;
					smtx[1][elcount - 1] = row; 
					smtx[2][elcount - 1] = column;
					elcount++;
					for (int i = 0; i < 3; i++)
					{
						smtx[i] = (int*)realloc(smtx[i], elcount * sizeof(int)); //�������� ������ �� ��������� ������� �������
					}
				}
			}
		}
	}
	data.close();
	elcount = elcount - 1;
	for (int i = 0; i < 3; i++)
	{
		smtx[i] = (int*)realloc(smtx[i], elcount * sizeof(int)); //������� ������ ������� �������
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < elcount; j++)
			cout << smtx[i][j] << " ";
		cout << endl;
	}
	//������������ ������
	for (int i = 0; i < 3; i++)
	{
		free(smtx[i]);
	}
	free(smtx);
}

int main()
{
	get_smatrix();
	return 0;
}