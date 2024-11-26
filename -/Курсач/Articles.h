
#include <iostream>
using namespace std;
const int MaxDigOfGenre = 25;
const int MaxDigOfName = 75;
const int MaxDigOfText = 750;
const int MaxDigOfAuthor = 75;


struct TArticle
{
    char ArticalName[MaxDigOfName] = "";       //Имя статьи
    char ArticalGenre[MaxDigOfGenre] = "";           //Жанр статьи
    char MainText[MaxDigOfText] = "";        //Тесkт статьи
    char ArticalAuthor[MaxDigOfAuthor] = "";       //Автор статьи
    int day = 1;
    int month = 1;
    int year = 2000;
};

void PrintArticleInfo(TArticle Article);
void PrintArticle(TArticle Article);
void ArticleSaveToFile(TArticle Artical, const char* cell);
void ArticleLoadFromFile(TArticle& Article, const char* cell);
void DemoArtical(TArticle* Articals);
void NewPath();
bool ArticalsToLoadLoad(TArticle* Articals, unsigned long long ArticalsAmount);
bool ArticalsToLoadSaver(unsigned long long ArticalsAmount);