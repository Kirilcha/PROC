#include <string.h>
#include <stdio.h>
#include <locale.h>
#include "Klad.h"
#include "List.h"
#include "Aforizm.h"
#include "Posl_Pogov.h"
#include <fstream>


using namespace std;


void OutPosl(Poslovica_P &posl, ofstream &ofst);
void readPosl(Poslovica_P &posl, ifstream &ifst);
void readAf(Aforizm &afor, ifstream &ifst);
void OutAf(Aforizm &aftor, ofstream &ofst);



Kladez* InKlad(ifstream &ifst) 
{
	Kladez *klad = new Kladez;
	char od[] = "afor";
	char dv[] = "posl";
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
	default:
		ofst << "������!" << endl;
	}
}

void MultiMethod(List **b, ofstream &ofst)
{
	ofst << "�����������." << endl;
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
						ofst << "������� � �������." << endl;
						break;
					}
					case Kladez::POSL_P:
					{
						ofst << "������� � ���������." << endl;
						break;
					}
					default:
						ofst << "����� ���." << endl;
				}
				break;
			}
			case Kladez::POSL_P:
			{
				switch ((*b)->next->a.key)
				{
					case Kladez::AFORIZM:
					{
						ofst << "��������� � �������." << endl;
						break;
					}
					case Kladez::POSL_P:
					{
						ofst << "��������� � ���������." << endl;
						break;
					}
					default:
						ofst << "����� ���." << endl;
				}
				break;
			}
			default:
				ofst << "����� ���." << endl;
		}
		OutKlad(&(*b)->a, ofst);
		OutKlad(&(*b)->next->a, ofst);
		(*b) = (*b)->next;
	}
}
