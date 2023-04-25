#include "clienti.h"
using namespace std;

int main()
{
	
	Abonament abonament,abonament2("spotify",15,1);
	Abonament_Premium abonament_premium,abonament_premium2("spotify",15,12,3);

	/*cin >> abonament;*/
	cin >> abonament_premium;

	/*cout << abonament2;
	cout << abonament_premium2;*/

	/*Abonament* abonament1p = new Abonament(abonament);*/
	Abonament* abonament2p = new Abonament(abonament2);
	Abonament_Premium* abonamentp1p = new Abonament_Premium(abonament_premium);
	Abonament_Premium* abonamentp2p = new Abonament_Premium(abonament_premium2);

	cout << endl << endl;

	Persoana persoana(134, "Suditu Darius-Cosmin", "5030903");

	Abonat abonat1(persoana, "0742", abonament2p),abonat2,abonat3(134,"Adrian","5092405","0724207",abonamentp2p);
	cout << "Adauga abonat: " << endl;
	cin >> abonat2;
	cout << endl << endl;

	Abonat* abonatp1 = new Abonat(abonat1);
	Abonat* abonatp2 = new Abonat(abonat2);
	Abonat* abonatp3 = new Abonat(abonat3);

	Clienti clienti;

	clienti.addClient(abonatp1);
	clienti.addClient(abonatp2);
	clienti.addClient(abonatp3);

	/*clienti.printList();*/

	int nrAbonatiPremium = clienti.nrAbonatiPremium();
	cout << "Numarul de abonati premium este de " << nrAbonatiPremium;

	int sumaTotala = clienti.getPretTotal();
	cout << endl << endl << "Suma totala incasata este de " << sumaTotala;


}