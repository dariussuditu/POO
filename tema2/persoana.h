#pragma once
#include "abonament.h"

class Persoana
{
public:
	Persoana();

	Persoana(const int& ID, const std::string& name, const std::string& CNP);

	Persoana(const Persoana& other);


	Persoana& operator=(const Persoana& other);

	virtual void getInfo();


	~Persoana();

	friend std::ostream& operator<<(std::ostream& os, const Persoana& pers);

	friend std::istream& operator>> (std::istream& in, Persoana& pers);


protected:
	int id;
	std::string nume;
	std::string cnp;
};



class Abonat :public Persoana {
public:
	Abonat();
	Abonat(const int id, const std::string& nume, const std::string& cnp, const std::string& nr_telefon, Abonament* Ab);
	Abonat(const Persoana& pers, const std::string& nr_telefon, Abonament* Ab);

	Abonat(const Abonat& other);

	Abonat& operator=(const Abonat& other);

	virtual ~Abonat();

	std::string getType();
	void getInfo() override;
	float getPret();

	friend std::istream& operator>>(std::istream& in, Abonat& abonat);
	friend std::ostream& operator<<(std::ostream& out, const Abonat& abonat);

private:
	std::string nr_telefon;
	Abonament* x;
};