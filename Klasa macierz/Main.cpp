#include "macierz.h"

int main()
{
	macierz a, b, c, d;

	a.set(0, 0, 56);
	a.set(0, 1, 2);
	a.set(1, 0, 63);
	a.set(1, 1, 18);
	
	macierz g(a);
	std::cout << "Macierz g - kopia a\n" << g << std::endl;

	b.set(0, 0, 0);
	b.set(0, 1, 14);
	b.set(1, 0, 10);
	b.set(1, 1, 25);
	std::cout << "A \n" << a << std::endl;
	std::cout << "B \n" << b << std::endl;
	
	c = a + b;
	std::cout << "Wynik operacji: + \n" << c << std::endl;

	c.transpozycja();
	std::cout << "Wynik operacji: transpozycja \n" << c << std::endl;
	std::cout << "Wynik operacji: * \n" << a * b << std::endl;
	std::cout << "Wynik operacji: * \n" << a * 2 << std::endl;
	d += a;
	std::cout << "Wynik operacji: += \n" << d << std::endl;
	d *= 2;
	std::cout << "Wynik operacji: *= \n" << d << std::endl;

	if (c == a)
		std::cout << "c i a s? identyczne" << std::endl;
	else 
		std::cout << "c i a s? r??ne" << std::endl;


	std::cout << "Macierz C\n" << c << "\n Wartosc w c[1][0]\n" << c.get(1, 0) << std::endl;

	return 0;
}