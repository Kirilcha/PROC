#include "Klad.h"
#include "Aforizm.h"
#include "Posl_Pogov.h"
#include <fstream>

using namespace std;


void OutPosl(Poslovica_P &posl, ofstream &ofst);
void readPosl(Poslovica_P &posl, ifstream &ifst);
void readAf(Aforizm &afor, ifstream &ifst);
void OutAf(Aforizm &aftor, ofstream &ofst);



int Kol_Sim(Kladez* a)
{
	char s[] = ".,?!;:-'\"";
	a->kol = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < a->fraza.size(); j++)
		{
			if (s[i] == a->fraza[j])
			{
				if (a->fraza[j] == '.' && a->fraza[j + 1] == '.' && a->fraza[j - 1] == '.')
				{
					a->kol -= 2;
				}
				a->kol++;
			}
		}
	}
	return a->kol;
}



Kladez* InKlad(ifstream &ifst)
{
	Kladez *klad = new Kladez;
	int key;
	ifst >> key;
	ifst.get();
	getline(ifst, klad->fraza);
	Kol_Sim(klad);
	switch (key) 
	{
	case 1:
		klad->key = Kladez::key::AFORIZM;
		readAf(klad->afor, ifst);
		return klad; 
	case 2:
		klad->key = Kladez::key::POSL_P;
		readPosl(klad->poslov, ifst);
		return klad;
	default: 
		exit;
	}

}



void OutKlad(Kladez* a, ofstream &ofst) 
{
	ofst << '"' << a->fraza << '"' << " (Количество знаков препинания : " << a->kol << ")";

	switch (a->key)
	{
	case Kladez::key::AFORIZM:OutAf(a->afor, ofst);
		break;
	case Kladez::key::POSL_P:OutPosl(a->poslov, ofst);
		break;
	default:
		ofst << "Ошибка!" << endl;
	}
}



