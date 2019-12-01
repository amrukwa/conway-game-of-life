#include <stdio.h>
void printing(int alive)
{
	if (alive == 0)
	{
		printf("  ");
	}
	else
	{
		printf("o ");
	}
}
int result(int neighbourhood, int ancestor) 
{
	if(neighbourhood<=1 || neighbourhood>=4)
	{
		return 0;
	}
	if(neighbourhood==3)
	{
		return 1;
	}
	return ancestor;
}
int firstset(int probability, int cell)
{
	cell= rand() % 100 + 1;
	if (cell <= probability)
	{
		return 1;
	}
	return 0;
}

int main()
{
	int m_rows, n_cols;
	int p;
	int gen=5;
	int nearby;
	printf("Set the number of rows.\n");
	scanf_s("%i", &m_rows);
	printf("Set the number of columns.\n");
	scanf_s("%i", &n_cols);
	printf("Set the chance of cell to be alive.\n");
	scanf_s("%i", &p);
	printf("\n");

	long int* array = malloc(m_rows * n_cols * sizeof(int));
	long int* newarray = malloc(m_rows * n_cols * sizeof(int));
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < n_cols; j++)
		{
			array[i * n_cols + j] = firstset(p,array[i*n_cols+j]);
			printing(array[i * n_cols + j]);
		}
		printf("\n");
	}
	//printf("How many more generations would you like?\n");
	//scanf_s("%i", &gen);
	for (; gen > 0; gen--)
	{
		for (int i = 0; i < m_rows; i++)
		{
			for (int j = 0; j < n_cols; j++)
			{
				if (i == 0 && j == 0)
				{
					nearby = array[n_cols] + array[1] + array[n_cols + 1];
				}
				else if(i==0 && j==(n_cols-1))
				{
					nearby = array[n_cols-2] + array[2 * n_cols - 2] + array[2*n_cols - 1];
				}
				else if(i==(m_rows-1)&&j==0)
				{
					nearby = array[n_cols*(m_rows - 2)] + array[n_cols*(m_rows-1)+n_cols-2] + array[(m_rows-2)* n_cols + 1];
				}
				else if (i == (m_rows - 1) && j == (n_cols - 1))//end of corners
				{
					nearby = array[n_cols * (m_rows - 2)+n_cols-1] + array[n_cols * (m_rows - 2) + n_cols - 1] + array[n_cols*(m_rows - 2) + n_cols-2];
				}

				newarray[n_cols * i + j] = result(nearby, array[n_cols * i + j]);
			}
		}
		for (int i = 0; i < m_rows; i++)//rotation of arrays
		{
			for (int j = 0; j < n_cols; j++)
			{
				array[i * n_cols + j] = newarray[i * n_cols + j];
			}
		}
	}
	for (int i = 0; i < m_rows; i++)//printing the last generation
	{
		for (int j = 0; j < n_cols; j++)
		{
			printing(array[i * n_cols + j]);
		}
		printf("\n");
	}
	return 0;
}
