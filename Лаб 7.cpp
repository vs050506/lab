#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*9. ƒаны натуральное число n и символы  s1, Е, sn.
—троку s1, Е, sn обработать так, чтобы все слова, состо€щие только из цифр, были удалены,
их сумма сто€ла последним словом в строке.*/

int Atoi(char* str)
{
	int dec = 0;
	return dec = str[0] - '0';
}

char* Itoa(int nsum, char* mas, int sch) {
	int count = 0;
	do 
	{
		int digit = nsum % sch;
		mas[count++] = digit + '0';
	} while ((nsum /= sch) != 0);

	mas[count] = '\0';

	for (int i = 0; i < count / 2; ++i) 
	{
		char symbol = mas[i];
		mas[i] = mas[count - i - 1];
		mas[count - i - 1] = symbol;
	}
	return mas;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	char* s, * S;
	char* l = 0;
	char mas[50];
	int* c;
	int n, k, j = 0, ch = 0, za = 0;
	bool q = 1, e = 1;
	bool flag = 0;
	int sum = 0, nsum = 0;
	printf("¬ведите размер строки: ");
	scanf_s("%d", &n);

	s = (char*)calloc(n, sizeof(char));
	c = (int*)calloc(n, sizeof(int));

	printf("¬ведите строку длинной не более %d символов: ", (n - 1));
	rewind(stdin);  /*чистка буфера*/
	gets_s(s, n + 1); /*ввод*/
	printf("\n");

	for (int i = 0; i < n; i++)
	{
		if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
		{
			for (k = i; k < n; k++)
			{
				if (s[k] == ' ' || s[k] == '\0') 
				{
					break;
			    }
				if (s[k] == '0' || s[k] == '1' || s[k] == '2' || s[k] == '3' || s[k] == '4' || s[k] == '5' || s[k] == '6' || s[k] == '7' || s[k] == '8' || s[k] == '9')
				{
					q = 1;
				}
				else
				{
					q = 0;
					break;
				}
			}
			k = i;
			do
			{
				if (s[k] == ' ') 
				{
					break;
				}
				if (s[k] == '0' || s[k] == '1' || s[k] == '2' || s[k] == '3' || s[k] == '4' || s[k] == '5' || s[k] == '6' || s[k] == '7' || s[k] == '8' || s[k] == '9')
				{
					e = 1;
				}
				else
				{
					e = 0;
					break;
				}
				k--;
			} while (k >= 0);

			if (q && e)
			{
				c[i] = 1;
				q = 1;
				l = &(s[i]);
				sum = sum * 10 + Atoi(l);
			}
		}
		else
		{
			nsum += sum;
			sum = 0;
			q = 0;
			e = 0;
			continue;
		}
	}

	Itoa(nsum, mas, 10);
	int i;
	S = (char*)calloc((n), sizeof(char));
	for (i = 0; i < (n); i++)
	{
		if (za == 0)
		{
			if (!c[i])
			{
				S[j] = s[i];
				j++;
			}
			if (S[j] == '\0' && S[j - 1] == '\0')
			{
				za = 1;
				i = 0;
				j--;
				S[j] = ' ';
				j++;
			}
		}
		if (za == 1)
		{
			if (mas[i] == '\0') { break; }
			S[j] = mas[i];
			j++;
		}
	}
	printf("\n");
	puts(S); 
}