#include "Klad.h"
#include "List.h"
#include <fstream>

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
void Free(List **begin, ofstream &ofst)       //  ����������� ������ (��� ����� ������ ��������)
=======
void Free(List **begin, ofstream &ofst)       /////  ����������� ������ (��� ����� ������ ��������)
>>>>>>> master
=======
void Free(List **begin, ofstream &ofst)       // ����������� ������ (��� ����� ������ ��������)
>>>>>>> master
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
void InList(List **begin, ifstream &ifst)    /////// ��� ��    
=======
void InList(List **begin, ifstream &ifst)   
>>>>>>> master
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
