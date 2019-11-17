// Projekt1stTry.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int p, a, m, n, g, array[50][50], newarray[50][50];

	printf("Type the value of the percentage of chance for the cell to be alive.\n");
	scanf_s("%i", &p);
	printf("\n"); 

	printf("Type the height of the laboratory (an integer number between 1 and 50).\n");
	scanf_s("%i", &m);
	printf("\n");

	printf("Type the width of the laboratory (an integer number between 1 and 50).\n");
	scanf_s("%i", &n);
	printf("\n");

	printf("Type the number of generations.\n");
	scanf_s("%i", &g);
	printf("\n");

	 for(int i=0; i<m; i++)
	{
		 for (int j = 0; j < n; j++)
		 {
			 array[i][j] = rand() % 100 + 1; //random loop
			 a = array[i][j];

			if (a > p)
			 {
				 array[i][j] = 0;
			 }
			 if (a<= p)
			 {
				 array[i][j] = 1;
			 }
		 }
	}; 
	
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j <n; j++)
		{
			if (array[i][j]==1)
			printf("o ");
			else
				printf("  ");
		}

		printf("\n");
	};
	
	

	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
