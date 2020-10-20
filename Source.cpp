#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "RUS");
	int amount, count = 0, m = 50;
	printf("¬ведите количество копеек: ");
	scanf_s("%d", &amount);

	for (int i = 0; ; )
	{
		if (amount >= m)
		{
			amount -= m;
			i++;
		}
		else
		{
			if (i > 0)
			{
				printf("\n%dx%d", i, m);
				i = 0;
			}
			if (m == 2)
			{
				m = 1;
			}
			if (m == 3)
			{
				m = 2;
			}
			if (m == 5)
			{
				m = 3;
			}
			if (m == 10)
			{
				m = 5;
			}
			if (m == 15)
			{
				m = 10;
			}
			if (m == 20)
			{
				m = 15;
			}
			if (m == 50)
			{
				m = 20;
			}
			if (amount==0)
			{
				break;
			}
		}
	}
	printf("\n");
}