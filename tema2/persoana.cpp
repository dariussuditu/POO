#include "persoana.h"

Persoana::Persoana() {}

Persoana::Persoana(const int& ID, const std::string& name, const std::string& CNP)
	:id(ID), nume(name), cnp(CNP)
{


}

Persoana::Persoana(const Persoana& other)
{
	id = other.id;
	nume = other.nume;
	cnp = other.cnp;

}

Persoana& Persoana::operator=(const Persoana& other)
{
	id = other.id;
	nume = other.nume;
	cnp = other.cnp;
	return *this;
}

void Persoana::getInfo()
{
	std::cout << "ID-ul este " << id << std::endl << "Numele este " << nume << std::endl << "CNP-ul este " << cnp << std::endl;
}

Persoana::~Persoana()
{

}

std::ostream& operator<<(std::ostream& os, const Persoana& pers)
{
	os << "ID-ul este " << pers.id << std::endl << "Numele este " << pers.nume << std::endl << "CNP-ul este " << pers.cnp << std::endl;
	return os;
}

std::istream& operator>>(std::istream& in, Persoana& pers)
{
	in >> pers.id >> pers.nume >> pers.cnp;
	return in;
}



Abonat::Abonat() {}

Abonat::Abonat(const int id, const std::string& nume, const std::string& cnp, const std::string& nr_telefon, Abonament* Ab)
	:Persoana(id, nume, cnp), nr_telefon(nr_telefon), x(Ab)
{

}

Abonat::Abonat(const Persoana& pers, const std::string& nr_telefon, Abonament* Ab) 
	:Persoana(pers), nr_telefon(nr_telefon), x(Ab)
{
}

Abonat::Abonat(const Abonat& other)
{
	*this = other;
}

Abonat& Abonat::operator=(const Abonat& abonat)
{
	this->id = abonat.id;
	this->nume = abonat.nume;
	this->cnp = abonat.cnp;
	this->nr_telefon = abonat.nr_telefon;
	if (typeid(*(abonat.x)) == typeid(Abonament))
		this->x = abonat.x;
	else
		this->x = (Abonament_Premium*)abonat.x;
	return *this;
}


std::string Abonat::getType()
{
	Abonament_Premium* premium_abonament = dynamic_cast<Abonament_Premium*>(x);
	if (premium_abonament)
		return "premium";
	else
		return "standard";
}


void Abonat::getInfo()
{
	Persoana(id, nume, cnp).getInfo();
	std::cout << "Numarul de telefon este " <<nr_telefon<<std::endl;
	x->getInfo();
}

float Abonat::getPret()
{
	return x->getPret();
}

Abonat::~Abonat(){}

std::ostream& operator<<(std::ostream& out, const Abonat& abonat)
{
	out << "ID-ul este " << abonat.id << std::endl << "Numele este " << abonat.nume << std::endl << "CNP-ul este " << abonat.cnp << std::endl;
	out<< std::endl << "Numarul de telefon este " <<abonat.nr_telefon<<std::endl << std::endl;
	if (abonat.x != nullptr) {
		abonat.x->getInfo();
	}
	else {
		std::cout << "Error: abonat.x is null" << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Abonat& abonat)
{
	std::cout << "ID-ul abonatului: ";
	in >> abonat.id;
	std::cout << "Numele abonatului: ";
	in >> abonat.nume;
	std::cout << "CNP-ul abonatului: ";
	in >> abonat.cnp;
	std::cout << "Telefon abonat: ";
	in >> abonat.nr_telefon;
	//alegerea tipului de abonament
	int abtype;
	std::cout << "Pentru abonament standard apasati tasta 1, iar pentru premium tasta 2" << std::endl;
	in >> abtype;

	while (true) {
		try {
			if (abtype == 1)
			{
				abonat.x = new Abonament();
				in >> *abonat.x;
				return in;
			}
			else if (abtype == 2)
			{
				abonat.x = new Abonament_Premium();
				in >> *(Abonament_Premium*)abonat.x;
				return in;
			}
			else {
				throw std::invalid_argument("Tipul de abonament trebuie sa fie 1 sau 2!");
			}
		}
		catch (std::invalid_argument& e) {
			std::cout << e.what() << std::endl;
			std::cout << "Introduceti din nou tipul de abonament (1 sau 2): ";
			/*in.clear();
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');*/
			in >> abtype;
		}
	}

	return in;
}