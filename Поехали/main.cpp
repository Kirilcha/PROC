#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstdio>
#include "List.h"

using namespace std;

void Init(List **begin);
void Free(List **begin, ofstream &ofst);
void InList(List **begin, ifstream &ifst);
void OutList(List **b, ofstream &ofst);
void Sort(List **begin);

int main()
{
	setlocale(LC_ALL, "Russian");

	ifstream in;
	in.open("1.txt");
	if (!in.is_open())
	{
		cout << "������ � ������� ������";
		return -1;
	}

	ofstream out;
	out.open("2.txt");
	if (!out.is_open())
	{
		cout << "������ � �������� ������";
		return -1;
	}

	cout << "���������� ������" << endl;

	List* begin;

	Init(&begin);
	InList(&begin, in);
	Sort(&begin);
	OutList(&begin, out);
	Free(&begin, out);
	cout << endl << "������ ������" << endl;

	in.close();
	out.close();
		cout << "\n������ ��������� ��������� ���������" << endl;
	_getch();
	return 0;
}