#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void read_params(int* m_rows, int* n_cols, int* p)
{
	printf("Set the number of rows.\n");
	scanf_s("%i", m_rows);
	printf("Set the number of columns.\n");
	scanf_s("%i", n_cols);
	printf("Set the percentage chance of cell to be alive (0 to 100).\n");
	scanf_s("%i", p);
	printf("\n");
}


void printing(FILE* lab, int alive)
{
	if (alive == 0)
	{
		printf("  ");
		fprintf(lab, "  ");
	}
	else
	{
		printf("o ");
		fprintf(lab, "o ");
	}
}


void print_game_state(FILE* lab, long int* game, int m_rows, int n_cols)
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < n_cols; j++)
		{
			printing(lab, game[i * n_cols + j]);
		}
		printf("\n");
		fprintf(lab, "\n");
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


void initialize_game(long int* game, int m_rows, int n_cols, int p)
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < n_cols; j++)
		{
			game[i * n_cols + j] = firstset(p, game[i * n_cols + j]);
		}
	}
}


int neighbours(long int* district, int x, int y, int cols, int rows)
{
	if (x == 0 && y == 0) //left-up corner
		return district[x * cols + y + 1]+ district[(x + 1) * cols + y]+ district[(x + 1) * cols + y + 1];
	if (x == 0 && y == cols - 1) //right-up corner
		return district[x * cols + y - 1]+ district[(x + 1) * cols + y - 1]+ district[(x + 1) * cols + y];
	if (x == rows-1 && y == 0) //left-down corner
		return district[(x - 1) * cols + y]+ district[(x - 1) * cols + y + 1]+ district[x * cols + y + 1];
	if (x == rows - 1 && y == cols - 1) //right-down corner
		return district[(x - 1) * cols + y - 1]+ district[(x - 1) * cols + y]+ district[x * cols + y - 1];
	if (y == 0) //left side
		return district[(x - 1) * cols + y]+ district[(x - 1) * cols + y + 1]+ district[x * cols + y + 1]+ district[(x + 1) * cols + y]+ district[(x + 1) * cols + y + 1];
	if (y == cols - 1) //right side
		return district[(x - 1) * cols + y - 1]+ district[(x - 1) * cols + y]+ district[x * cols + y - 1]+ district[(x + 1) * cols + y - 1]+ district[(x + 1) * cols + y];
	if (x == 0) //top
		return district[x * cols + y - 1]+ district[x * cols + y + 1]+ district[(x + 1) * cols + y - 1]+ district[(x + 1) * cols + y]+ district[(x + 1) * cols + y + 1];
	if (x == rows - 1) //bottom
		return district[(x - 1) * cols + y - 1]+ district[(x - 1) * cols + y]+ district[(x - 1) * cols + y + 1]+ district[x * cols + y - 1]+ district[x * cols + y + 1];
	return district[(x - 1) * cols + y - 1]+ district[(x - 1) * cols + y]+ district[(x - 1) * cols + y + 1]+ district[x * cols + y - 1]+ district[x * cols + y + 1]+ district[(x + 1) * cols + y - 1]+ district[(x + 1) * cols + y]+ district[(x + 1) * cols + y + 1];
			//left-up neighbour - district[(x-1)*cols+y-1];
			// straight-up neighbour - district[(x-1)*cols+y];
			// right-up neighbour - district[(x-1)*cols+y+1];
			// left-side neighbour - district[x*cols+y-1];
			// right-side neighbour - district[x*cols+y+1];
			// left-down neighbour - district[(x+1)*cols+y-1];
			// straight-down neighbour - district[(x+1)*cols+y];
			// right-down neighbour - district[(x+1)*cols+y+1];
	
}


void compute_next_state(long int* current, long int* next, int m_rows, int n_cols)
{
	int nearby;
	for (int i = 0; i < m_rows; i++)
	{

		for (int j = 0; j < n_cols; j++)
		{
			nearby = neighbours(current, i, j, n_cols, m_rows);
			next[n_cols * i + j] = result(nearby, current[n_cols * i + j]);
		}
	}
}

void stopFromClosing()
{
	printf("Press any key to continue...\n");
	char c = getchar();
}

int main()
{
	FILE* lab;
	int m_rows, n_cols;
	int p;
	int gen;

	read_params(&m_rows, &n_cols, &p);

	fopen_s(&lab, "result.txt", "w");
	fprintf(lab, "Number of columns is %i, number of rows is %i, chance of being alive at start: %i.\n", n_cols, m_rows, p);

	size_t size = m_rows * n_cols * sizeof(int);
	long int* current = malloc(size);
	long int* next = malloc(size);
	initialize_game(current, m_rows, n_cols, p);
	print_game_state(lab, current, m_rows, n_cols);

	printf("\n\nHow many more generations would you like?\n");
	scanf_s("%i", &gen);
	fprintf(lab, "\nThe number of generations is %i. ", gen+1);

	for (; gen > 0; gen--)
	{
		compute_next_state(current, next, m_rows, n_cols);
		memcpy(current, next, size); // copy next into current - the only suggested on Stack Overflow
	}

	fprintf(lab, "This is your last generation:\n");
	printf("This is your last generation:\n");
	print_game_state(lab, current, m_rows, n_cols);

	free(current);
	free(next);
	fclose(lab);
	stopFromClosing;
	return 0;
}
