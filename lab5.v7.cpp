#include<stdio.h>
#include<locale.h>
#include<ctime>
#include<stdlib.h>
#define STR 5
#define STB 5
int main()
{
	setlocale(0, "RUS");
	srand(time(NULL));
	printf("Массив:\n");

	int mas[STR][STB];
	int maxD = mas[0][0];
	int Max = 0;
	int k, u = 0, strw = 0;

	for (int i = 0; i < STR; i++)
	{
		for (int h = 0; h < STB; h++)
		{
			mas[i][h] = rand() % 100;
		}
	}

	for (int j = 0; j < STR; j++)
	{
		for (int k = 0; k < STB; k++)
		{
			printf("%d\t", mas[j][k]);
		}
		printf("\n");
		k = 0;
	}

	for (int d = 0; d < STR; ++d)
		if (mas[d][d] > maxD)
			maxD = mas[d][d];
	
	for (int n = 0; n < STR; n++)
	{
		for (int l = 0; l < n; l++)
		{
			if (n == 0)
			{
			continue;
			}
			if (Max < mas[n][l])
			{
				Max = mas[n][l];
			}
		}
	}


	printf("\nМаксимальный элемент на главной диагонали: %d\n", maxD);
	printf("\nМаксимальный элемент ниже главной диагонали: %d\n", Max);
}