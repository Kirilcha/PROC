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



Kladez* InKlad(ifstream &ifst)   // количетво общее можно сюда присобачить
{
	Kladez *klad = new Kladez;
	int key;
	ifst >> key;        /// считываем ключ определяющий эл
	ifst.get();
	getline(ifst, klad->fraza);
	Kol_Sim(klad);
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
	ofst << '"' << a->fraza << '"' << " (Количество знаков препинания : " << a->kol << ")";

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



