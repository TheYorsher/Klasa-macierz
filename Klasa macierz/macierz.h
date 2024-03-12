#pragma once
#ifndef macierz_h
#define macierz_h

#include <iostream>
class macierz
{
private:
	double mat[2][2];

public:
	macierz();
	macierz(const macierz& copy);
	~macierz();

	macierz operator * (const macierz& copy) const;
	macierz operator + (const macierz& copy) const;
	macierz operator * (const double x) const;
	macierz& operator = (const macierz& copy);
	bool operator == (const macierz& copy) const;
	macierz& operator += (const macierz& copy);
	macierz& operator *= (const macierz& copy);
	macierz& operator *= (const double x);
	friend std::ostream& operator <<(std::ostream& s, const macierz& m);
	void set(int i, int j, double x);
	double get(int i, int j) const;
	void transpozycja();
};
#endif
