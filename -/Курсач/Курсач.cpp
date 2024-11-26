// Мой курсач!! Кто удалит - тот плохой человек!!!
#define _CRT_SECURE_NO_WARNINGS
#include "Articles.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

long long unsigned ArticalsAmount = 13;


TArticle* Articals = new TArticle[ArticalsAmount]; // Долбанный динамический структуромассив, это ж... полная!!
char cell[10] = "";


enum TMenuCommand
{
	tmcmdNone = 0,
	tmcmdPrintArticlesTable = 1,
};
int MainMenu()
{
	int Choice = 0;
	do
	{
		system("cls");
		cout << "Newspaper App!\n";
		cout << "1. Print articles table (Higher = Newer)\n";
		cout << "2. \n";
		cout << "3. \n";
		cout << "4. \n";
		cout << "5. \n";
		cout << "6. \n";
		cout << "7. \n";
		cout << "8. \n";
		cout << "9. Enter a new path for files\n";
		cout << "15. Close Newspaper App\n";
		

		cout << "Select menu[1..15]: ";
		cin >> Choice;
		if (Choice == 15) break;
	} while ((Choice < 1) || (Choice > 15));
	return Choice;
}

void RunCommand(TMenuCommand choice)
{
	char tmpStr[20] = "";
	long long int tmpID = -1;
	unsigned long long Amount = 0;
	switch (choice)
	{
	case tmcmdPrintArticlesTable:
	{
		cout << "How many articles print?";
		cin >> Amount;
		for (unsigned long long i = Amount - 1; i > 0; i--)
		{
			PrintArticleInfo(Articals[i]);
		}
		break;
		}
	}
}






int main()
{
	cout << "Program Info: \nVersion: 1.1\nAricals amount: " << ArticalsAmount << "\n\n\n\n";
	ArticalsToLoadLoad(Articals, ArticalsAmount); //Авто подкачка из оперативной из файлов наши статьи
	int Choice = 0;

	unsigned long long Amount = 0;
	cout << "How many articles print?\n";
	cin >> Amount;
	for (unsigned long long i = Amount-1; i > 0; i--)
	{
		PrintArticleInfo(Articals[i]);
	}

	/*
	do // основное и вложенные меню программы
	{
		Choice = MainMenu();
		RunCommand((TMenuCommand)Choice); // (TMenuCommand)Choice приводим тип int к типу TMenuCommand
		if (Choice == 15) break;
	} while (true);
	cout << "GoodBye!\n";

	//PrintArticle(Articals[0]);
	//ArticleLoadFromFile(Articals[0], "0");
	//PrintArticleTable(Articals, ArticalsAmount);

	*/
	cout << "\b\b";
}
