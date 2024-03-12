#include "macierz.h"

macierz::macierz()
{
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			mat[i][j] = 0.0;
		}
	}
}

macierz::macierz(const macierz& copy)
{
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			this->mat[i][j] = copy.mat[i][j];
		}
	}
}

macierz::~macierz()
{

}

macierz macierz::operator * (const macierz& copy) const
{
	macierz res;

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			res.mat[i][j] = 0;
			for (int k = 0; k < 2; ++k) {
				res.mat[i][j] += this->mat[i][k] * copy.mat[k][j];
			}
		}
	}

	return res;
}

macierz macierz::operator + (const macierz& copy) const
{
	macierz rez;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			rez.mat[i][j] = this->mat[i][j] + copy.mat[i][j];
		}
	}
	return rez;
}
macierz macierz::operator * (const double x) const
{
	macierz res;

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			res.mat[i][j] = this->mat[i][j] * x;
		}
	}

	return res;
}
macierz &macierz::operator = (const macierz& copy)
{
	if (this != &copy) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				this->mat[i][j] = copy.mat[i][j];
			}
		}
	}
	return *this;
}
bool macierz::operator == (const macierz& copy) const
{
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			if (this->mat[i][j] != copy.mat[i][j]) {
				return false;
			}
		}
	}
	return true;
}
macierz& macierz::operator += (const macierz& copy)
{
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			this->mat[i][j] += copy.mat[i][j];
		}
	}
	return *this;
}
macierz& macierz::operator *= (const macierz &copy)
{
	macierz res;

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			res.mat[i][j] = 0;
			for (int k = 0; k < 2; ++k) {
				res.mat[i][j] += this->mat[i][k] * copy.mat[k][j];
			}
		}
	}

	*this = res;
	return *this;
}
macierz& macierz::operator *= (const double x)
{
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			this->mat[i][j] *= x;
		}
	}
	return *this;
}
std::ostream& operator << (std::ostream& s, const macierz& m)
{
for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			s << m.mat[i][j] << " ";
		}
		s << std::endl;
	}
	return s;
}
double macierz::get(int i, int j) const
{
	if (i >= 0 && i < 2 && j >= 0 && j < 2) {
		return this->mat[i][j];
	}
	else {
		return 0.0;
	}
}

void macierz::set(int i, int j, double x)
{
	if (i >= 0 && i < 2 && j >= 0 && j < 2) {
		this->mat[i][j] = x;
	}
	else {
		std::cerr << "B??d: Nieprawid?owe indeksy macierzy. Ustawienie nie powiod?o si?." << std::endl;
	}
}
void macierz::transpozycja()
{
	macierz res;

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			res.mat[i][j] = this->mat[j][i];
		}
	}

	*this = res;
}