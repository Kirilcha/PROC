#include <string.h>
#include <stdio.h>
#include <locale.h>
#include "Klad.h"
#include "List.h"
#include "Aforizm.h"
#include "Posl_Pogov.h"
#include <fstream>
#include "Zagadki.h"


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
	char tr[] = "zagad";
	char prov[10];
	ifst.getline(prov, 10, '\n');
	int key = 3;
	if ((_stricmp(od, prov) == 0) || (prov[0] == '1'))
	{
		key = 1;
	}
	if ((_stricmp(dv, prov) == 0) || (prov[0] == '2'))
	{
		key = 2;
	}
	if ((_stricmp(tr, prov) == 0) || (prov[0] == '3'))
	{
		key = 3;
	}

	getline(ifst, klad->fraza);

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
	case 3:
		klad->key = Kladez::key::ZAGADKI;
		readZagad(klad->zagad, ifst);
		return klad;
	default:  
		exit;
	}

}

void OutKlad(Kladez* a, ofstream &ofst)      
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

void MultiMethod(List **b, ofstream &ofst)
{
	ofst << "Мультиметод." << endl;
	while ((*b)->next != NULL)
	{
		switch ((*b)->a.key)
		{
			case Kladez::AFORIZM:
			{
				switch ((*b)->next->a.key)
				{
					case Kladez::AFORIZM:
					{
						ofst << "Афоризм и Афоризм." << endl;
						break;
					}
					case Kladez::POSL_P:
					{
						ofst << "Афоризм и Пословица." << endl;
						break;
					}
					case Kladez::ZAGADKI:
					{
						ofst << "Афоризм и Загадка." << endl;
						break;
					}
					default:
						ofst << "Афоризм и левый тип." << endl;
				}
				break;
			}
			case Kladez::POSL_P:
			{
								   switch ((*b)->next->a.key)
								   {
								   case Kladez::AFORIZM:
								   {
														   ofst << "Пословица и Афоризм." << endl;
														   break;
								   }
								   case Kladez::POSL_P:
								   {
														  ofst << "Пословица и Пословица." << endl;
														  break;
								   }
								   case Kladez::ZAGADKI:
								   {
														   ofst << "Пословица и Загадка." << endl;
														   break;
								   }
								   default:
									   ofst << "Пословица и левый тип." << endl;
								   }
								   break;
			}
			case Kladez::ZAGADKI:
			{

									switch ((*b)->next->a.key)
									{
									case Kladez::AFORIZM:
									{
															ofst << "Загадка и Афоризм." << endl;
															break;
									}
									case Kladez::POSL_P:
									{
														   ofst << "Загадка и Пословица." << endl;
														   break;
									}
									case Kladez::ZAGADKI:
									{
															ofst << "Загадка и Загадка." << endl;
															break;
									}
									default:
										ofst << "Загадка и левый тип." << endl;
									}
									break;
			}
			default:
				ofst << "Левый тип." << endl;
			}
		OutKlad(&(*b)->a, ofst);
		OutKlad(&(*b)->next->a, ofst);
		(*b) = (*b)->next;
	}
}
