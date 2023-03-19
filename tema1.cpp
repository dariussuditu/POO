#include <iostream>
#include <cstring>
using namespace std;

class Ingredient {
public:

	Ingredient()
	{

	};

	Ingredient(const string& numeIngredient, const float& nrPret, const int& nrCantitate)
	{
		nume = numeIngredient;
		pret = nrPret;
		cantitate = nrCantitate;
	};

	string getNume() const {
		return nume;
	}

	Ingredient(const Ingredient& other) // copy constructor
	{
		nume = other.nume;
		pret = other.pret;
		cantitate = other.cantitate;
	}
	

	Ingredient& operator+=(const int& other){
		cantitate += other;
		return *this;
	}

	friend ostream& operator<<(ostream& os, const Ingredient& ingredient);
	friend istream& operator>> (istream& in, Ingredient& ingredient);

	~Ingredient()
	{

	}; 
private:
	string nume;
	float pret;
	int cantitate;

};

ostream& operator<<(ostream& os, const Ingredient& ingredient)
{
	os << "Ingredientul este: " << ingredient.nume << endl << "Pretul este de: " << ingredient.pret << endl << "Cantitatea este de: " << ingredient.cantitate << endl;
	return os;
}

istream& operator>> (istream& in, Ingredient& ingredient)
{
	in >> ingredient.nume >> ingredient.pret >> ingredient.cantitate;
	return in;
}


class Pizza {

public:
	Pizza() {};

	Pizza(const char numepi[50])
	{
		strcpy_s(denumire, numepi);
		nringrediente = 0;

	};


	Pizza& operator+(const Ingredient& ingred) {
		nringrediente += 1;
		for (int i = 1; i <= nringrediente; i++)
			ingr[i] = ingred;
		return *this;
	}


	bool operator>(const Pizza& pizza) {
		return nringrediente > pizza.nringrediente;
	}

	bool operator<(const Pizza& pizza) {
		return nringrediente < pizza.nringrediente;
	}


	friend ostream& operator<<(ostream& os, Pizza& pizza);
	friend istream& operator>> (istream& in,  Pizza& pizza);
private:
	char denumire[50];
	int nringrediente;
	Ingredient ingr[101];
	

};

ostream& operator<<(ostream& os, Pizza& pizza)
{
	os << "denumirea este: " << pizza.denumire << endl << "numarul de ingrediente este de: " << pizza.nringrediente << endl << "iar acestea sunt: "<< endl;
	for (int i = 1; i <= pizza.nringrediente; i++)
		os << pizza.ingr[i].getNume() << endl;
	return os;
}

istream& operator>> (istream& in, Pizza& pizza)
{
	in >> pizza.denumire>> pizza.nringrediente;
	for (int i = 1; i <= pizza.nringrediente; i++)
		in >> pizza.ingr[i];
	return in;
}


int main() {

	Ingredient i1("Piper", 0.5, 10), i2;
	cout << i1;
	//cin >> i2;
	i1 += 500; // aduna o valoare la cantitatea disponibila
	Ingredient i3 = i1, i4, i5(i1);
	i4 = i1;
	Pizza p1("clasic"),p2;
	p1 = p1 + i1;
	//cout << p1;
	cin >> p2;
	//cout << p2;
	if (p1 > p2)
		cout << "da";
	else
		cout << "nu";
	return 0;
}