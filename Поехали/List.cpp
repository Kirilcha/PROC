#include "Klad.h"
#include "List.h"
#include <fstream>

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
					default:
						ofst << "Левый тип." << endl;
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
					default:
						ofst << "Левый тип." << endl;
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

