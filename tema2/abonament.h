#pragma once
#include <string>
#include <iostream>
#include <memory>


class Abonament
{
public:
	Abonament();

	Abonament(const std::string& nume_ab, const float& pret_ab, const int& per);

	Abonament(const Abonament& other);


	Abonament& operator=(const Abonament& other);

	virtual std::string Type();

	virtual void getInfo();

	virtual float getPret();

	virtual ~Abonament();

	friend std::ostream& operator<<(std::ostream& os, const Abonament& abonament);

	friend std::istream& operator>> (std::istream& in, Abonament& abonament);



protected:
	std::string nume_abonament;
	float pret;
	int perioada;
};



class Abonament_Premium : public Abonament
{
public:
	Abonament_Premium();

	Abonament_Premium(const std::string& nume_ab, const float& pret_ab, const int& per, const int& reducere);

	Abonament_Premium(const Abonament_Premium& other);

	Abonament_Premium& operator=(const Abonament_Premium& other);

	std::string Type() override;
	void getInfo() override;
	float getPret() override;

	virtual ~Abonament_Premium();

	friend std::ostream& operator<<(std::ostream& os, const Abonament_Premium& abonament);

	friend std::istream& operator>> (std::istream& in, Abonament_Premium& abonament);


private:
	int reducere;
};