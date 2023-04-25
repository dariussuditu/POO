#include "clienti.h"

Clienti::Clienti() {}

Clienti::Clienti(const Clienti& client)
{
	*this = client;
}

void Clienti::addClient(Abonat* pab)
{
	list.push_back(pab);
	return;
}

void Clienti::printList() const
{
	for (int i = 0; i < list.size(); i++)
	{
		list[i]->getInfo();
		std::cout << std::endl << std::endl;
	}

}

int Clienti::nrAbonatiPremium()
{
	int nr = 0;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->getType() == "premium")
			nr++;
	}
	return nr;
}

float Clienti::getPretTotal()
{
	float t = 0;
	for (int i = 0; i < list.size(); i++)
	{
		t = t + list[i]->getPret();
	}
	return t;
}

Clienti::~Clienti()
{
		for (int i = 0; i < list.size(); i++)
			delete list[i];

}

Clienti& Clienti::operator=(const Clienti& client)
{
	this->list =client.list;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Clienti& client)
{
	for (int i = 0; i < client.list.size(); i++)
	{
		out << "Abonatul " << i << std::endl;
		client.list[i]->getInfo();
		out << std::endl<<std::endl;
	}
	return out;
}