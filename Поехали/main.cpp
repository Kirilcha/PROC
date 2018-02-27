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
<<<<<<< HEAD
void OutRect(List **begin, ofstream &ofst);
=======
void Sort(List **begin);
>>>>>>> 2-1-4

int main()
{
	setlocale(LC_ALL, "Russian");

	ifstream in;
	in.open("1.txt");
	if (!in.is_open())
	{
		cout << "Îרטבךא ס פאיכמל";
		return -1;
	}

	ofstream out;
	out.open("2.txt");
	if (!out.is_open())
	{
		cout << "Îרטבךא ס פאיכמל";
		return -1;
	}

	cout << "Start" << endl;

	List* begin;

	Init(&begin);
	InList(&begin, in);
<<<<<<< HEAD
	OutRect(&begin, out);
	//OutList(&begin, out);
=======
	Sort(&begin);
	OutList(&begin, out);
>>>>>>> 2-1-4
	Free(&begin, out);
	cout << endl << "Stop" << endl;

	in.close();
	out.close();

	_getch();
	return 0;
}