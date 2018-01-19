#include <string.h>
#include <stdio.h>
#include <locale.h>
#include "Klad.h"
#include "Aforizm.h"
#include "Zagadki.h"
#include "Posl_Pogov.h"
#include <fstream>

using namespace std;


void OutPosl(Poslovica_P &posl, ofstream &ofst);
void readPosl(Poslovica_P &posl, ifstream &ifst);
void readAf(Aforizm &afor, ifstream &ifst);
void OutAf(Aforizm &aftor, ofstream &ofst);
void readZagad(Zagadki &zagad, ifstream &ifst);
void OutZagad(Zagadki &zagad, ofstream &ofst);



Kladez* InKlad(ifstream &ifst) 
{
	Kladez *klad = new Kladez;
	char od[] = "afor";
	char dv[] = "posl";
	char gg[] = "zagad";
	char prov[10];
	ifst.getline(prov, 10, '\n');
	int key = 4;
	if ((_stricmp(od, prov) == 0) || (prov[0] == '1'))
	{
		key = 1;
	}
	if ((_stricmp(dv, prov) == 0) || (prov[0] == '2'))
	{
		key = 2;
	}
	if ((_stricmp(gg, prov) == 0) || (prov[0] == '3'))
	{
		key = 3;
	}
	getline(ifst, klad->fraza);

	switch (key)  // в зависимости, от того, что в ключе, туда и отпраит новые данные 
	{
	case 1:
		klad->key = Kladez::key::AFORIZM;
		readAf(klad->afor, ifst);  // отправляем в функцию(АФ) полученные данные
		return klad; // возвращаем полученный эл
	case 2:
		klad->key = Kladez::key::POSL_P;
		readPosl(klad->poslov, ifst);
		return klad;
	case 3:
		klad->key = Kladez::key::ZAGADKI;
		readZagad(klad->zagad, ifst);
		return klad;
	default:    // нет совпадений -> нет записи
		exit;
	}

}

void OutKlad(Kladez* a, ofstream &ofst)        // в док
{


	ofst << '"' << a->fraza << '"'; 
	switch (a->key)
	{
	case Kladez::key::AFORIZM:OutAf(a->afor, ofst);
		break;
	case Kladez::key::POSL_P:OutPosl(a->poslov, ofst);
		break;
	case Kladez::key::ZAGADKI:OutZagad(a->zagad, ofst);
		break;
	default:
		ofst << "Ошибка!" << endl;
	}
}