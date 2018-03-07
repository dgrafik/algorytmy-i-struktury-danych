#include <iostream>

double Zad_3(double a[], int n, double x)
{
	double wynik = a[n];
	while (n)
	{
		wynik = wynik*x + a[--n];
	}
	return wynik;
}

int main(){
	double xx[4] = {1,-4,3,-5};
	std::cout<<Zad_3(xx, 3, 2) << std::endl;
	return 0;
}
