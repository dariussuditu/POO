#include "abonament.h"


Abonament::Abonament() {}

Abonament::Abonament(const std::string& nume_ab, const float& pret_ab, const int& per)
	:nume_abonament(nume_ab), pret(pret_ab), perioada(per)
{

}

Abonament::Abonament(const Abonament& other)
{
	nume_abonament = other.nume_abonament;
	pret = other.pret;
	perioada = other.perioada;

}


Abonament& Abonament::operator=(const Abonament& other)
{
	nume_abonament = other.nume_abonament;
	pret = other.pret;
	perioada = other.perioada;
	return *this;
}

std::string Abonament::Type() {
	return "standard";
}

void Abonament::getInfo()
{
	std::cout << "Abonamentul este de tip standard si se numeste " << nume_abonament << std::endl << "Pretul acestuia este de " << pret << " lei" << std::endl << "Iar perioada contractului este de " << perioada << " luni";
}

float Abonament::getPret()
{
	return pret * perioada;
}


Abonament::~Abonament()
{
	
}

std::ostream& operator<<(std::ostream& os, const Abonament& ab)
{
	os << "Abonamentul este " << ab.nume_abonament << std::endl << "Pretul este de " <<ab.pret << " lei" << std::endl << "Perioada este de " <<ab.perioada << " luni" << std::endl;
	return os;
}

std::istream& operator>>(std::istream& in, Abonament& ab)
{
	std::cout << "Nume abonament standard: " << std::endl;
	in >> ab.nume_abonament;

	while (true) {
		std::cout << std::endl << "Pret abonament: " << std::endl;
		try {
			in >> ab.pret;
			if (ab.pret < 0) {
				throw std::invalid_argument("Pretul abonamentului trebuie sa fie pozitiv!");
			}
			break;
		}
		catch (std::invalid_argument& e) {
			std::cout << e.what() << std::endl;
			
		}
	}

	while (true) {
		std::cout << std::endl << "Perioada abonamentului: " << std::endl;
		try {
			in >> ab.perioada;
			if (ab.perioada < 0) {
				throw std::invalid_argument("Perioada abonamentului trebuie sa fie pozitiva!");
			}
			break;
		}
		catch (std::invalid_argument& e) {
			std::cout << e.what() << std::endl;

		}
	}

	return in;

}



Abonament_Premium::Abonament_Premium() {}

Abonament_Premium::Abonament_Premium(const std::string& nume_ab, const float& pret_ab, const int& per, const int& red)
	:Abonament(nume_ab, pret_ab, per), reducere(red)

{


}

Abonament_Premium::Abonament_Premium(const Abonament_Premium& other)
{
	nume_abonament = other.nume_abonament;
	pret = other.pret;
	perioada = other.perioada;
	reducere = other.reducere;

}

Abonament_Premium& Abonament_Premium::operator=(const Abonament_Premium& other)
{
	nume_abonament = other.nume_abonament;
	pret = other.pret;
	perioada = other.perioada;
	reducere = other.reducere;
	return *this;
}

std::string Abonament_Premium::Type() {
	return "premium";
}

void Abonament_Premium::getInfo()
{
	std::cout << "Abonamentul este de tip premium si se numeste " << nume_abonament << std::endl << "Pretul acestuia este de " << pret << " lei" << std::endl << "Iar perioada contractului este de " << perioada << " luni" << std::endl << "Reducerea data de abonamentul premium este de " << reducere << " lei";
}

float Abonament_Premium::getPret()
{
	return (pret - reducere) * perioada;
}

Abonament_Premium::~Abonament_Premium()
{
	
}

std::ostream & operator<<(std::ostream & os, const Abonament_Premium & ab)
{
	std::cout << "Abonamentul este de tip premium si se numeste " << ab.nume_abonament << std::endl << "Pretul acestuia este de " << ab.pret << " lei" << std::endl << "Iar perioada contractului este de " << ab.perioada << " luni" << std::endl << "Reducerea data de abonamentul premium este de " << ab.reducere << " lei";
	return os;
}

std::istream& operator>>(std::istream& in, Abonament_Premium& ab)
{
	std::cout << "Nume abonament premium: " << std::endl;
	in >> ab.nume_abonament;

	while (true) {
		std::cout << std::endl << "Pret abonament: " << std::endl;
		try {
			in >> ab.pret;
			if (ab.pret < 0) {
				throw std::invalid_argument("Pretul abonamentului trebuie sa fie pozitiv!");
			}
			break;
		}
		catch (std::invalid_argument& e) {
			std::cout << e.what() << std::endl;

		}
	}

	while (true) {
		std::cout << std::endl << "Perioada abonamentului: " << std::endl;
		try {
			in >> ab.perioada;
			if (ab.perioada < 0) {
				throw std::invalid_argument("Perioada abonamentului trebuie sa fie pozitiva!");
			}
			break;
		}
		catch (std::invalid_argument& e) {
			std::cout << e.what() << std::endl;

		}
	}


	while (true) {
		std::cout << std::endl << "Reducerea abonamentului: " << std::endl;
		try {
			in >> ab.reducere;
			if (ab.reducere < 0) {
				throw std::invalid_argument("Reducerea abonamentului trebuie sa fie pozitiva!");
			}
			break;
		}
		catch (std::invalid_argument& e) {
			std::cout << e.what() << std::endl;

		}
	}

	return in;
}