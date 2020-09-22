#include "iostream"

using namespace std;

double fact(int n)

{

	double f;
	for (f = 1; n > 1; n = n - 1)
		f = f * n;
	return f;

}

int main() 

{

	cout << 2 * fact(5) + 3 * fact(8) / fact(6) + fact(4);

}