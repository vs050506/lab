#include <stdio.h>

int fact(int n)
{
	int i;
	for (i = 1; n > 1; n--)
		i *= n;
	return i;
}

int main() 
{
	int a;
	a = 2 * fact(5) + 3 * fact(8) / fact(6) + fact(4);
	printf("%d", a);
}