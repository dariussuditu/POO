//#include "Header.h"
//#include <iostream>
//
//
//Abonament::Abonament() {}
//
//Abonament::Abonament(const string& nume_ab, const float& pret_ab, const int& per)
//	:nume_abonament(nume_ab), pret(pret_ab), perioada(per)
//{
//
//}
//
//Abonament::Abonament(const Abonament& other)
//{
//	nume_abonament = other.nume_abonament;
//	pret = other.pret;
//	perioada = other.perioada;
//
//}
//
//
//Abonament& Abonament::operator=(const Abonament& other)
//{
//	nume_abonament = other.nume_abonament;
//	pret = other.pret;
//	perioada = other.perioada;
//	return *this;
//}
//
//string Abonament::Type() {
//	return "standard";
//}
//
//void Abonament::getInfo()
//{
//	cout << "Abonamentul este de tip standard si se numeste " << nume_abonament << endl << "Pretul acestuia este de " << pret <<" lei"<<endl << "Iar perioada contractului este de " << perioada<<" luni";
//}
//
//float Abonament::getPret()
//{
//	return pret * perioada;
//}
//
//
//Abonament::~Abonament()
//{
//
//}
//
//ostream& operator<<(ostream& os, const Abonament& ab)
//{
//	os << "Abonamentul este " << ab.nume_abonament << endl << "Pretul este de " << ab.pret << endl << "Perioada este de " << ab.perioada << endl;
//	return os;
//}
//
//istream& operator>>(istream& in, Abonament& ab)
//{
//	in >> ab.nume_abonament >> ab.pret >> ab.perioada;
//	return in;
//}
//
//
//
//Abonament_Premium::Abonament_Premium() {}
//
//Abonament_Premium::Abonament_Premium(const string& nume_ab, const float& pret_ab, const int& per, const int& red)
//	:Abonament(nume_ab, pret_ab, per), reducere(red)
//
//{
//
//
//}
//
//Abonament_Premium::Abonament_Premium(const Abonament_Premium& other)
//{
//	nume_abonament = other.nume_abonament;
//	pret = other.pret;
//	perioada = other.perioada;
//	reducere = other.reducere;
//
//}
//
//Abonament_Premium& Abonament_Premium::operator=(const Abonament_Premium& other)
//{
//	nume_abonament = other.nume_abonament;
//	pret = other.pret;
//	perioada = other.perioada;
//	reducere = other.reducere;
//	return *this;
//}
//
//string Abonament_Premium::Type() {
//	return "premium";
//}
//
//void Abonament_Premium::getInfo()
//{
//	cout << "Abonamentul este de tip premium si se numeste " << nume_abonament << endl << "Pretul acestuia este de " << pret << " lei" << endl << "Iar perioada contractului este de " << perioada << " luni"<<endl<<"Reducerea data de abonamentul premium este de "<<reducere<<" lei";
//}
//
//float Abonament_Premium::getPret()
//{
//	return (pret-reducere)*perioada;
//}
//
//Abonament_Premium::~Abonament_Premium()
//{
//
//}
//
//ostream& operator<<(ostream& os, const Abonament_Premium& ab)
//{
//	os << "Abonamentul este " << ab.nume_abonament << endl << "Pretul este de " << ab.pret << endl << "Perioada este de " << ab.perioada << "Iar reducerea caracteristica abonametului premium este de " << ab.reducere << endl;
//	return os;
//}
//
//istream& operator>>(istream& in, Abonament_Premium& ab)
//{
//	in >> ab.nume_abonament >> ab.pret >> ab.perioada >> ab.reducere;
//	return in;
//}
//
//
//
//
//Persoana::Persoana() {}
//
//Persoana::Persoana(const int& ID, const string& name, const string& CNP)
//	:id(ID), nume(name), cnp(CNP)
//{
//
//
//}
//
//Persoana::Persoana(const Persoana& other)
//{
//	id = other.id;
//	nume = other.nume;
//	cnp = other.cnp;
//
//}
//
//Persoana& Persoana::operator=(const Persoana& other)
//{
//	id = other.id;
//	nume = other.nume;
//	cnp = other.cnp;
//	return *this;
//}
//
//void Persoana::getInfo()
//{
//	cout<<"ID-ul este " << id << endl << "Numele este " << nume << endl << "CNP-ul este " << cnp << endl;
//}
//
//Persoana::~Persoana()
//{
//
//}
//
//ostream& operator<<(ostream& os, const Persoana& pers)
//{
//	os << "ID-ul este " << pers.id << endl << "Numele este " << pers.nume << endl << "CNP-ul este " << pers.cnp << endl;
//	return os;
//}
//
//istream& operator>>(istream& in, Persoana& pers)
//{
//	in >> pers.id >> pers.nume >> pers.cnp;
//	return in;
//}
//
//
//
//Abonat::Abonat() {}
//Abonat::Abonat(const int id, const string& nume, const string& cnp, const string& nr_telefon, Abonament* Ab)
//	:Persoana(id, nume, cnp), nr_telefon(nr_telefon), x(Ab)
//{
//
//}
//string Abonat::getType()
//{
//	Abonament_Premium* premium_abonament = dynamic_cast<Abonament_Premium*>(x);
//	if (premium_abonament)
//		return "premium";
//	else
//		return "standard";
//}
//
//
//void Abonat::getInfo()
//{
//	Persoana(id, nume, cnp).getInfo();
//	cout << endl << "Numarul de telefon este " << endl << "Iar Abonamentul este de tip " << endl;
//	x->getInfo();
//}
//
//float Abonat::getPret()
//{
//	return x->getPret();
//}
//
//
//
//Clienti::Clienti() {}
//
//void Clienti::addClient(Abonat* pab)
//{
//	list.push_back(pab);
//	return;
//}
//
//void Clienti::printList() const
//{
//	for (int i = 0; i < list.size(); i++)
//	{
//		list[i]->getInfo();
//	}
//
//}
//
//int Clienti::nrAbonatiPremium()
//{
//	int nr = 0;
//	for (int i = 0; i < list.size(); i++)
//	{
//		if (list[i]->getType() == "premium")
//			nr++;
//	}
//	return nr;
//}
//
//float Clienti::getPretTotal()
//{
//	float t = 0;
//	for (int i = 0; i < list.size(); i++)
//	{
//		t = t + list[i]->getPret();
//	}
//	return t;
//}
//
