//#pragma once
//#include <string>
//#include <vector>
//#include <memory>
//using namespace std;
//class Abonament
//{
//public:
//	Abonament();
//
//	Abonament(const string& nume_ab, const float& pret_ab, const int& per);
//
//	Abonament(const Abonament& other);
//
//	//string getName() const;
//	//string getPrice() const;
//	//string getPeriod() const;
//
//	Abonament& operator=(const Abonament& other);
//
//	virtual string Type();
//
//	virtual void getInfo();
//
//	virtual float getPret();
//
//	~Abonament();
//
//	friend ostream& operator<<(ostream& os, const Abonament& abonament);
//
//	friend istream& operator>> (istream& in, Abonament& abonament);
//	
//
//
//protected:
//	string nume_abonament;
//	float pret;
//	int perioada;
//};
//
//
//
//class Abonament_Premium : public Abonament
//{
//public:
//	Abonament_Premium();
//
//	Abonament_Premium(const string& nume_ab, const float& pret_ab, const int& per, const int& reducere);
//
//	Abonament_Premium(const Abonament_Premium& other);
//
//	Abonament_Premium& operator=(const Abonament_Premium& other);
//
//	string Type() override;
//	void getInfo() override;
//	float getPret() override;
//
//	~Abonament_Premium();
//
//	friend ostream& operator<<(ostream& os, const Abonament_Premium& abonament);
//
//	friend istream& operator>> (istream& in, Abonament_Premium& abonament);
//
//
//private:
//	int reducere;
//};
//
//
//
//
//
//class Persoana
//{
//public:
//	Persoana();
//
//	Persoana(const int& ID, const string& name, const string& CNP);
//
//	Persoana(const Persoana& other);
//
//
//	Persoana& operator=(const Persoana& other);
//
//	virtual void getInfo();
//
//	
//	~Persoana();
//
//	friend ostream& operator<<(ostream& os, const Persoana& pers);
//
//	friend istream& operator>> (istream& in, Persoana& pers);
//
//
//protected:
//	int id;
//	string nume;
//	string cnp;
//};
//
//
//
//class Abonat:public Persoana {
//public:
//	Abonat();
//	Abonat(const int id, const string& nume, const string& cnp, const string& nr_telefon, Abonament* Ab);
//	string getType();
//	void getInfo() override;
//	float getPret();
//private:
//	string nr_telefon;
//	Abonament* x;
//};
//
//class Clienti
//{
//public:
//	Clienti();
//
//	void addClient(Abonat* pab);
//
//	void printList() const;
//
//	int nrAbonatiPremium();
//
//	float getPretTotal();
//
//	
//
//protected:
//	vector<Abonat*> list;
//
//};