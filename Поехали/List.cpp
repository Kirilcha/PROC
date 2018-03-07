#include "Klad.h"
#include "List.h"
#include <fstream>
#include <iostream>
#include <conio.h>

using namespace std;

void OutKlad(Kladez* a, ofstream &ofst);
Kladez* InKlad(ifstream &ifst);

void Init(List **begin)      
{
	*begin = NULL;
	*begin = new List;
	(*begin)->next = NULL;
}

void Free(List **begin, ofstream &ofst)     
{
	if (*begin == 0)
		return;
	List *p = *begin;
	List *t;

	while (p)
	{
		t = p;
		p = p->next;
		delete t;
	}
	*begin = NULL;
	ofst << "Контейнер освобожден!" << endl;
}

void InList(List **begin, ifstream &ifst)   
{
	int kol = 0;
	List *end = *begin;

	while (!ifst.eof())
	{
		if (kol == 0)
		{
			(*begin)->a = (*InKlad(ifst));  
			(*begin)->next = NULL;
			kol++;
		}
		else
		{
			end->next = new List; 
			end = end->next; 
			end->a = (*InKlad(ifst));
			end->next = NULL;
			kol++;
		}
	}
}


void OutList(List **b, ofstream &ofst)     
{
	List *p = *b;
	int i = 1;
	int  kol = 0;
	while (p)
	{
		kol++;
		p = p->next;
	}
	p = *b;
	ofst << "Контейнер заполнен! " << endl;
	ofst << "Колличество фраз: " << kol << endl;
	while (p)
	{
		ofst << i << ": ";
		OutKlad(&(p)->a, ofst);      
		p = p->next;
		i++;
	}
}

bool prov(Kladez a, Kladez b)
{
	return a.fraza < b.fraza;
}

void Sort(List **begin)
{
	char p;
	bool proverka;
	cout << "\nКак отсортировать? По возрастанию (>) или убыванию (<): ";
	cin >> p;
	switch (p)
	{
		case '>':
		{
					proverka = 0;
					break;
		}
	
		case '<':
		{
					proverka = 1;
					break;
		}
		default:
		{
			   cout << "Ошибка ввода данных \nРабота программы завершена некорректно" << endl;
			   _getch();
		}
	}
	Kladez t3;
	List* t1;
	List * t2;
	
	for (t1 = (*begin); t1; t1 = t1->next)
	{
		for (t2 = (*begin); t2; t2 = t2->next)
		{
			if (prov(t1->a, t2->a) - proverka)
			{
				t3 = t1->a;
				t1->a = t2->a;
				t2->a = t3;
			}
		}
	}
}
