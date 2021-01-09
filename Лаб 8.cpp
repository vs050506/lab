#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*1. ��� �����, ��������� �� n �����������.
����������� ������������ ����� �������������� ���������.
������� ������, ���������� � ���� �������������� �� ���� �����������.*/

int main()
{
	setlocale(LC_ALL, "RUS");
	char** S;
	char** SS;
	int** C;
	int i = 0, k = 0, j = 0, q = 0;
	int n;	                            // n - ���������� �����
	int m;                             //  m - ���������� �������� � ������
	int za = 0;
	// ��������� ������ ��� ������ �����
	printf(" ������� ���������� �����: ");
	scanf_s(" %d", &n);
	C = (int**)calloc(n, sizeof(int*));
	S = (char**)calloc(n, sizeof(char));
	SS = (char**)calloc(n, sizeof(char*));		        // ��������� ������ ��� ������ ����������
	printf("\n ������� ����������  �������� � ������: ");
	scanf_s(" %d", &m);

	//��������� ������ ��� ������
	for (i = 0; i < n; i++)
	{
		SS[i] = (char*)calloc(m, sizeof(char));
		S[i] = (char*)calloc(m, sizeof(char));
		C[i] = (int*)calloc(m, sizeof(int));
	}

	printf("\n ������� %d ����� ������� �� ����� %d ��������:\n\n", n, (m - 1));
	for (i = 0; i < n; i++)
	{
		rewind(stdin);
		gets_s(SS[i], m * sizeof(char));
	}
	printf("\n\n");
	
	for (j = 0; j < n; j++)
	{
		for (k = 0; k < m; k++)
		{
			if (SS[j][k] != '+' && SS[j][k] != '-' && SS[j][k] != '=' && SS[j][k] != '*' && SS[j][k] != '/' && SS[j][k] != '(' && SS[j][k] != ')')
			{
				C[j][k] = 1;
			}
		}
	}
	for (j = 0; j < n; j++)
	{
		for (k = 0; k < m; k++)
		{
			if (j > za)
			{
				q = 0;
				za = j;
			}
			if (SS[j][k] == '\0' && C[j][k] == '\0')
			{ 
				continue; 
			}
			if (C[j][k] == 1)
			{
				S[j][q] = SS[j][k];
				q++;
			}
		}
	}

	for (int a = 0; a < n; a++)
 
	{
			free(SS[a]);
			free(C[a]);
	}
	free(SS);
	free(C);

	for (i = 0; i < n; i++)
	{
		puts(S[i]);
	}
}