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



<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
Kladez* InKlad(ifstream &ifst)   // ��������� ����� ����� ���� �����������
=======
Kladez* InKlad(ifstream &ifst) 
>>>>>>> master
=======
Kladez* InKlad(ifstream &ifst)   // ��������� ����� ����� ���� �����������
>>>>>>> 2-1-5
{
	Kladez *klad = new Kladez;
	char od[] = "afor";
	char dv[] = "posl";
	char gg[] = "zagad";
	char prov[10];
	ifst.getline(prov, 10, '\n');
	int key = 4;
	if ((_stricmp(od, prov) == 0) || (prov[0] == '1'))
=======
int Kol_Sim(Kladez* a)
{
	char s[] = ".,?!;:-'\"";
	a->kol = 0;
	for (int i = 0; i < 8; i++)
>>>>>>> 2-1-4
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
<<<<<<< HEAD
	if ((_stricmp(gg, prov) == 0) || (prov[0] == '3'))
	{
		key = 3;
	}
	getline(ifst, klad->fraza);
=======
	return a->kol;
}


>>>>>>> 2-1-4

Kladez* InKlad(ifstream &ifst)   // ��������� ����� ����� ���� �����������
{
	Kladez *klad = new Kladez;
	int key;
	ifst >> key;        /// ��������� ���� ������������ ��
	ifst.get();
	getline(ifst, klad->fraza);
	Kol_Sim(klad);
	switch (key)  // � �����������, �� ����, ��� � �����, ���� � ������� ����� ������ 
	{
	case 1:
		klad->key = Kladez::key::AFORIZM;
		readAf(klad->afor, ifst);  // ���������� � �������(��) ���������� ������
		break;
	case 2:
		klad->key = Kladez::key::POSL_P;
		readPosl(klad->poslov, ifst);
<<<<<<< HEAD
		break;
=======
		return klad;
	case 3:
		klad->key = Kladez::key::ZAGADKI;
		readZagad(klad->zagad, ifst);
		return klad;
<<<<<<< HEAD
>>>>>>> master
=======
	case 3:
		klad->key = Kladez::key::ZAGADKI;
		readZagad(klad->zagad, ifst);
		return klad;
>>>>>>> 2-1-4
	default:    // ��� ���������� -> ��� ������
		return 0;
	}
	ifst >> klad->ocenka;
	ifst.get();
	return klad;
}



void OutKlad(Kladez* a, ofstream &ofst)        // � ���
{
<<<<<<< HEAD
<<<<<<< HEAD
	ofst << '"' << a->fraza << '"';
=======

<<<<<<< HEAD
	char s[] = ".,?!:-'\"";
	int Kol = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < a->fraza.size(); j++)
		{
			if (s[i] == a->fraza[j])
			{
				if (a->fraza[j] == '.' && a->fraza[j + 1] == '.' && a->fraza[j - 1] == '.')
				{
					Kol -= 2;
				}
				Kol++;
			}
		}
	}
	ofst << '"' << a->fraza << '"' << "\n (���������� ������ ���������� : " << Kol << ")";


=======

	ofst << '"' << a->fraza << '"'; 
>>>>>>> master
=======
	ofst << '"' << a->fraza << '"' << " (���������� ������ ���������� : " << a->kol << ")";

>>>>>>> 2-1-4
	switch (a->key)
	{
	case Kladez::key::AFORIZM:OutAf(a->afor, ofst);
		break;
	case Kladez::key::POSL_P:OutPosl(a->poslov, ofst);
		break;
	case Kladez::key::ZAGADKI:OutZagad(a->zagad, ofst);
		break;
	default:
		ofst << "������!" << endl;
	}
<<<<<<< HEAD
	if (a->ocenka > 10 || a->ocenka < 0)
	{
		ofst << "������ �� ������������� 10 ������� �����!" << endl;
	}
	else
	{
		ofst << "������������ ������ ��������� �� �������������� ����� = " << a->ocenka << endl;
	}
}
=======
}



>>>>>>> 2-1-4
