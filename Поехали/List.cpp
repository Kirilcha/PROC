#include "Klad.h"
#include "List.h"
#include <fstream>
#include <iostream>

using namespace std;

void OutKlad(Kladez* a, ofstream &ofst);
Kladez* InKlad(ifstream &ifst);

void Init(List **begin)        //////// ������������� 
{
	*begin = NULL;
	*begin = new List;
	(*begin)->next = NULL;
}

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
void Free(List **begin, ofstream &ofst)       //  ����������� ������ (��� ����� ������ ��������)
=======
void Free(List **begin, ofstream &ofst)       /////  ����������� ������ (��� ����� ������ ��������)
>>>>>>> master
=======
void Free(List **begin, ofstream &ofst)       // ����������� ������ (��� ����� ������ ��������)
>>>>>>> master
=======
void Free(List **begin, ofstream &ofst)       /////  ����������� ������ (��� ����� ������ ��������)
>>>>>>> 2-1-5
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
	ofst << "��������� ����������!" << endl;
}

<<<<<<< HEAD
<<<<<<< HEAD
void InList(List **begin, ifstream &ifst)    /////// ��� ��    
=======
void InList(List **begin, ifstream &ifst)   
>>>>>>> master
=======
void InList(List **begin, ifstream &ifst)    /////// ��� ��    
>>>>>>> 2-1-5
{
	int kol = 0;
	List *end = *begin;

	while (!ifst.eof())
	{
		if (kol == 0)
		{
			(*begin)->a = (*InKlad(ifst));   // ��������� ������ �����
			(*begin)->next = NULL;
			kol++;
		}
		else
		{
<<<<<<< HEAD
			end->next = new List; // ��������� �������� ������ ��� ����� ��
=======
			end->next = new List; // ��������� �������� ������ ��� ����� �������
>>>>>>> master
			end = end->next;  // ��������� ���� �� 
			end->a = (*InKlad(ifst));
			end->next = NULL;
			kol++;
		}
	}
}


void OutList(List **b, ofstream &ofst)      // � ���
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
	ofst << "��������� ��������! " << endl;
	ofst << "���������� ����: " << kol << endl;
	while (p)
	{
		ofst << i << ": ";
<<<<<<< HEAD
		OutKlad(&(p)->a, ofst);     
=======
		OutKlad(&(p)->a, ofst);     // p->a � �������������� � ��������� �������� ���������� 
>>>>>>> master
		p = p->next;
		i++;
	}
}


void OutRect(List **begin, ofstream &ofst) 
{
	List *a = (*begin);
	int i =1;
	ofst << "������ ��������!" << endl;
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
