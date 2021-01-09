#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main()
{
    setlocale(0, "RUS");
    int kol = 0;
    const int r = 10;
    int** s;

    s = (int**)calloc(r, sizeof(int*));
    for (int i = 0; i < r; i++)
    {
        s[i] = (int*)calloc(r, sizeof(int));
    }

    int mas[r][r] =
    { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
      {0, 1, 1, 1, 1, 1, 1, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
      {1, 1, 1, 1, 1, 1, 0, 1, 1, 0},
      {1, 1, 1, 1, 1, 1, 0, 1, 1, 0},
      {1, 1, 1, 1, 1, 1, 0, 1, 1, 0} };

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            s[i][j] = mas[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
            printf("%d ", s[i][j]);
        printf("\n");
    }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < r; j++)
            if (s[i][j] && ((j > 0 && !s[i][j - 1]) || (j == 0)) && ((i > 0 && !s[i - 1][j]) || (i == 0)))
            {
                ++kol;
            }

    printf("\nКоличество прямоугольников: %d\n", kol);
}
