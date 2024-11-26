#include <iostream>
#include "Articles.h"
#include <fstream>
#include <stdlib.h>
using namespace std;

const int MaxFileNameLen = 0xFF; // 255
char FilePath[MaxFileNameLen] = "E:\\-\\ArtDir\\";
char ArticleFileName[MaxFileNameLen] = "Articles";// имя файла содержащего статьи
char ArticleToLoadTable[MaxFileNameLen] = "ATLT";


void PrintArticleInfo(TArticle Article)
{
    cout << "Name:" << Article.ArticalName << "\n"; // Сам вывод статьи имя статьи, жанр, сам текст и автор

    cout << "Genre:" << Article.ArticalGenre << "\n";

    cout << "Author:" << Article.ArticalAuthor << "\n";

    cout << "Date: " << Article.day << "." << Article.month << "." << Article.year << "\n";
}
void PrintArticle(TArticle Article)
{
    cout << "Name:" << Article.ArticalName << "\n"; // Сам вывод статьи имя статьи, жанр, сам текст и автор
    
    cout << "Genre:" << Article.ArticalGenre << "\n";

    cout << "Date: " << Article.day << "." << Article.month << "." << Article.year<<"\n";

    cout << "Main text:"<<Article.MainText << "\n";

    cout << "Author:" << Article.ArticalAuthor << "\n";
}
bool ArticalsToLoadSaver(unsigned long long ArticalsAmount)
{
    unsigned long long tmp = 0;
    unsigned long long CellAmount = 0;
    string Answer;
    char MyFileName[MaxFileNameLen] = "";
    char cell[10] = "";
    strcpy_s(MyFileName, FilePath);
    strcat_s(MyFileName, ArticleToLoadTable);
    strcat_s(MyFileName, ".dat");
    ofstream outFile;
    outFile.open(MyFileName, ios::binary);
    cout << "Do you want change Articles Auto-Loader Table?\n";
    cin >> Answer;
    if (Answer == "Yes")
    {
        cout << "How much Articles do you want to Load?\n";
        cin >> CellAmount;
        for (unsigned long long i = 0; i < CellAmount; i++) 
        {
            cout << "Enter cell number " << i << "\n";
            cin >> tmp;
            outFile << tmp << "\n";
        }
    }
    else 
    {
        if (Answer == "No")
        {
            return 1;
        }
        else 
        {
            cout << "ERROR: Incorrect answer (Yes/No)\n";
            ArticalsToLoadSaver(ArticalsAmount);
        }
    }
        outFile.close();
}
bool ArticalsToLoadLoad(TArticle* Articals,unsigned long long ArticalAmount)
{
    char MyFileName[MaxFileNameLen] = "";
    char cell[10] = "";
    strcpy_s(MyFileName, FilePath);
    strcat_s(MyFileName, ArticleToLoadTable);
    strcat_s(MyFileName, ".dat");
    ifstream inFile;
    unsigned long long counter = 0;
    inFile.open(MyFileName, ios::binary);
    if (inFile.is_open())
    {// если файл открыт
        while (!inFile.eof())
        {// пока не конец файла 
            if (counter == ArticalAmount)
            {
                inFile.close();
                return 0;
            }
            inFile >> cell;
            ArticleLoadFromFile(Articals[counter], cell);
            counter++;

        }
        inFile.close();
    }
}
void ArticleSaveToFile(TArticle Artical, const char* cell)
{
    char MyFileName[MaxFileNameLen] = "";
    strcpy_s(MyFileName, FilePath);
    strcat_s(MyFileName, ArticleFileName);
    strcat_s(MyFileName, cell);
    strcat_s(MyFileName, ".dat");
    //DEBUG!!! cout << MyFileName; 
    ofstream outFile;          // поток для записи
    outFile.open(MyFileName, ios::binary); // окрываем файл для записи
    outFile << "Name:" << Artical.ArticalName << "\n" << "Genre:" << Artical.ArticalGenre << "\n" << "Main_Text:" << Artical.MainText << "\n" << "Author:" << Artical.ArticalAuthor << "\n"<< "Date: " << Artical.day << " " << Artical.month << " " << Artical.year;
}
void ArticleLoadFromFile(TArticle& Artical, const char* cell)
{

    string Buffer;
    char MyFileName[MaxFileNameLen] = "";
    strcpy_s(MyFileName, FilePath);
    strcat_s(MyFileName, ArticleFileName);
    strcat_s(MyFileName, cell);
    strcat_s(MyFileName, ".dat");
    ifstream inFile;
    inFile.open(MyFileName, ios::binary);
    if (inFile.is_open())
    {// если файл открыт
        while (!inFile.eof())
        {// пока не конец файла            
            inFile >> Buffer;
            if (Buffer == "Name:")
            {
                while (Buffer != "Genre:") 
                {
                    inFile.getline(Artical.ArticalName, MaxDigOfName);
                    inFile >> Buffer;
                }
                if (Buffer == "Genre:") 
                {
                    while (Buffer != "Main_Text:") 
                    {
                        inFile.getline(Artical.ArticalGenre, MaxDigOfGenre);
                        inFile >> Buffer;
                    }
                    if (Buffer == "Main_Text:") 
                    {
                        while (Buffer != "Author:") 
                        {
                            inFile.getline(Artical.MainText, MaxDigOfText);
                            inFile >> Buffer;
                        }
                        if (Buffer == "Author:") 
                        {
                            while (Buffer != "Date:")
                            {
                                inFile.getline(Artical.ArticalAuthor, MaxDigOfAuthor);
                                inFile >> Buffer;
                            }
                            
                        }
                        if (Buffer == "Date:") 
                        {
                            inFile >> Artical.day;
                            inFile >> Artical.month;
                            inFile >> Artical.year;

                        }
                    }
                }
            }
        }
        inFile.close();
    }
}
void DemoArtical(TArticle* Articals)
{
    const int a = 1;
    //Первая статья!
    strcpy_s(Articals[0].ArticalName, " Very strange old man killed his wife!!");
    strcpy_s(Articals[0].ArticalGenre, " Criminal");
    strcpy_s(Articals[0].ArticalAuthor, " Vladislav Kuziakin");
    strcpy_s(Articals[0].MainText, " A 91-year-old man has been charged with the murder of his 92-year-old wife. Police are investigating John Woodbridge after Anne Woodbridge was found dead at a home in Weston-super-Mare on Monday morning. After appearing before Bristol Magistrates Court today he is now due to appear at Bristol Crown Court on March 17. In a statement, Avon and Somerset Police said: A man has been charged after an investigation into the death of a woman in Weston-super-Mare. Anne Woodbridge, 92, was found deceased at a residential address on the morning of Monday 30 January. John Woodbridge, of Ashcombe Road, has subsequently been charged with murder.");
    Articals[0].day = 3;
    Articals[0].month = 4;
    Articals[0].year = 2023;
}

void NewPath() 
{
    cout << "Enter new path please: ";
    cin >> FilePath;
}
