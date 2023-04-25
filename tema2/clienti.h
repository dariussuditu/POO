#pragma once
#include "abonament.h"
#include "persoana.h"
#include <vector>


class Clienti
{
public:
	Clienti();

	void addClient(Abonat* pab);

	void printList() const;

	int nrAbonatiPremium();

	float getPretTotal();

	virtual ~Clienti();

	Clienti(const Clienti& client);

	Clienti& operator=(const Clienti& client);

	friend std::istream& operator>>(std::istream& in, Clienti& client);

	friend std::ostream& operator<<(std::ostream& out, const Clienti& client);

private:
	std::vector<Abonat*> list;

};