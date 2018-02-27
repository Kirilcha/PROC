#include "Klad.h"
#include "List.h"
#include <fstream>
#include <iostream>

using namespace std;

void OutKlad(Kladez* a, ofstream &ofst);
Kladez* InKlad(ifstream &ifst);

void Init(List **begin)        //////// инициализация 
{
	*begin = NULL;
	*begin = new List;
	(*begin)->next = NULL;
}

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
void Free(List **begin, ofstream &ofst)       //  освобождаем память (для этого начало передаем)
=======
void Free(List **begin, ofstream &ofst)       /////  освобождаем память (для этого начало передаем)
>>>>>>> master
=======
void Free(List **begin, ofstream &ofst)       // освобождаем память (для этого начало передаем)
>>>>>>> master
=======
void Free(List **begin, ofstream &ofst)       /////  освобождаем память (для этого начало передаем)
>>>>>>> 2-1-5
=======
void Free(List **begin, ofstream &ofst)       //  освобождаем память (для этого начало передаем)
>>>>>>> 2-1-4
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

<<<<<<< HEAD
<<<<<<< HEAD
void InList(List **begin, ifstream &ifst)    /////// или же    
=======
void InList(List **begin, ifstream &ifst)   
>>>>>>> master
=======
void InList(List **begin, ifstream &ifst)    /////// или же    
>>>>>>> 2-1-5
{
	int kol = 0;
	List *end = *begin;

	while (!ifst.eof())
	{
		if (kol == 0)
		{
			(*begin)->a = (*InKlad(ifst));   // считывает первую цифру
			(*begin)->next = NULL;
			kol++;
		}
		else
		{
<<<<<<< HEAD
			end->next = new List; // указатель выделяет память под новый эл
=======
			end->next = new List; // указатель выделяет память под новый элемент
>>>>>>> master
			end = end->next;  // равняется след эл 
			end->a = (*InKlad(ifst));
			end->next = NULL;
			kol++;
		}
	}
}


void OutList(List **b, ofstream &ofst)      // в док
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
	ofst << "Количество фраз: " << kol << endl;
	while (p)
	{
		ofst << i << ": ";
<<<<<<< HEAD
<<<<<<< HEAD
		OutKlad(&(p)->a, ofst);     
=======
		OutKlad(&(p)->a, ofst);     // p->a я разъименовываю и отправляю значение переменной 
>>>>>>> master
=======
		OutKlad(&(p)->a, ofst);     // p->a я разыменовываю и отправляю значение переменной 
>>>>>>> 2-1-4
		p = p->next;
		i++;
	}
}

<<<<<<< HEAD

void OutRect(List **begin, ofstream &ofst) 
{
	List *a = (*begin);
	int i =1;
	ofst << "Только Афоризмы!" << endl;
	while (a)
	{
		ofst << i << ": ";
		if (a->a.key == Kladez::AFORIZM)
			OutKlad(&(a)->a, ofst);
		else
			ofst <<"- " << endl;
		a = a->next;
		i++;
	}
}
=======
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
				   cout << "Ошибка!" << endl;
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

>>>>>>> 2-1-4
