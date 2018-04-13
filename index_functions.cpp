#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cstring>
#include <stdio.h>
#include <io.h>
#include <conio.h> //для getch()
#include "index.h"
using namespace std;

Film* AddStruct(Film* Fl, const int num) {
	if (Fl == 0)
		Fl = new Film[num + 1]; // выделение памяти для первой структуры
	else 	{
		Film* tempFl = new Film[num + 1];

		for (int i = 0; i < num; i++) 
			tempFl[i] = Fl[i]; // копируем во временный объект

		delete [] Fl;
		Fl = tempFl;	
	}			
	return Fl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setData(Film* Fl, const int num) {
	int i; //временная переменная для ввода данных о дате
	    
		cout << "Название: " << endl;
		gets_s(Fl[num].name);

		cout << "Страна: " << endl;
		gets_s(Fl[num].country);

		cout << "Жанр: " << endl;
		gets_s(Fl[num].genre);

		cout << "Год: " << endl;
		cin >>  Fl[num].year;
		cin.get(); 

		cout << "Рейтинг: " << endl;
		cin >>  Fl[num].rating;
		cin.get(); 

		cout << "Статус (просмотрено/непросмотрено). Введите + или -" << endl;
		cin >> Fl[num].view;
		cin.get();

		cout << "Продолжительность фильма: /n";

		cout << "часов: "<< endl;
		cin >> Fl[num].time.hours;
	
		cout << "минут: "<< endl;
		cin >> Fl[num].time.minutes;

		cin.get(); 
		cout << endl;	

		cout <<"Сегодня " << endl;
		cout <<"Дата: " << endl;
		cin >> i; Fl[num].today.date = i; 
		cin.get(); 
		cout << endl;	

		cout <<"Месяц: " << endl;
		cin >> i; Fl[num].today.month = i; 
		cin.get(); 
		cout << endl;	

		cout <<"Год (в формате 0 - 99): " << endl;
		cin >> i; Fl[num].today.year = i; 
		cin.get(); 
		cout << endl;	
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void showData(const Film* Fl, const int num) {
	system("cls");
	
	cout << left << "№  "<< setw(20) << left << "Название" << setw(15) <<  "Страна" << setw(10) << "Жанр" << setw(10) 
		<< "Рейтинг" << setw(3) << "Год " << setw(5) << "Продолжительность ";
	cout << "================================================================================" << endl;
	
		for (int i = 0; i < num; i++) {
		cout <<  i + 1;
		if (i+1<10) cout << "   ";  else cout << "  ";
		cout << setw(20) << left << Fl[i].name <<  setw(15) << Fl[i].country << setw(10) << Fl[i].genre << 
			setw(10) << Fl[i].rating << setw(3) << Fl[i].year << "     " << Fl[i].time.hours << ":" << Fl[i].time.minutes << endl;
	
		}
		}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void searchName(Film* F, char* b, int num) {
	int k=0;
	for(int i = 0; i < num; i++) 
	if (!strcmp(F[i].name, b)) 
	 {
		 cout << "Фильм №" << i+1 << endl;  
		 k++;
	}
	if (k==0) cout << "Фильмы не найдены" << endl;
	else cout << "Найдено фильмов: " << k << endl;
}
void searchYear(Film* F, char* b, int num) {
	int k=0;
	int a = atoi(b);
	for(int i = 0; i < num; i++)
	if (F[i].year == a) 
	{ 
		cout << "Фильм №" << i+1 << endl;  
		k++;
	} 
	if (k==0) cout << "Фильмы не найдены" << endl;
	else cout << "Найдено фильмов: " << k << endl;
}

void searchOldest(Film* Fl, int num) {
	Film oldest; 
	int year = Fl[0].year;
	for (int i = 0; i<num; i++) 
		if (Fl[i].year < year){
			year = Fl[i].year;
			oldest = Fl[i];
		}
	cout << oldest.name << " " << year << "г."<< "\n";
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void searchRating(Film* Fl, int num) {
	Film high_rating;
	float rating = 0;
	for (int i = 0; i<num; i++) 
		if (Fl[i].rating > rating){
			rating = Fl[i].rating;
			high_rating = Fl[i];
		}
	cout << high_rating.name << " (" << high_rating.rating << ")"<< "\n";
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void sortAdding (Film* Fl, int num) { //по дате добавления от новых к старым
long i, j;
Film x;
bool exit = false;
bool equility = false; //если показатели равны, то можно будет дальше сравнивать 

//по году
for (i = 0; (i<num)&&(!exit); i++) { // i - номер прохода
		exit = true;
		for(j = num-1; j > i; j--) { // внутренний цикл прохода
				int a = Fl[j-1].today.year; 
				int b = Fl[j].today.year;
				if(a<b)
					{ x = Fl[j-1]; 
					Fl[j-1] = Fl[j]; 
					Fl[j] = x; 
					exit = false;
					equility = false;
				}
				else if (a == b) equility = true;
		}
  }
//по месяцу
if (equility) {
for (i = 0; (i<num)&&(!exit); i++) { // i - номер прохода
		exit = true;
		for(j = num-1; j > i; j--) { // внутренний цикл прохода
				int a = Fl[j-1].today.month; 
				int b = Fl[j].today.month;
				if(a<b)
					{ x = Fl[j-1]; 
					Fl[j-1] = Fl[j]; 
					Fl[j] = x; 
					exit = false;
					equility = false;
				}
				else if (a == b) equility = true;
		}
  }
}
//по дню
if (equility) {
for (i = 0; (i<num)&&(!exit); i++) { // i - номер прохода
		exit = true;
		for(j = num-1; j > i; j--) { // внутренний цикл прохода
				int a = Fl[j-1].today.date; 
				int b = Fl[j].today.date;
				if(a<b)
					{ x = Fl[j-1]; 
					Fl[j-1] = Fl[j]; 
					Fl[j] = x; 
					exit = false;}
		}
  }
}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void sortName(Film* Fl, int num) {
long i, j;
 bool exit = false;   
  for(i = 0; (i < num) && (!exit); i++) { // i - номер прохода
		exit = true;
		for(j = num-1; j > i; j--) { // внутренний цикл прохода
				if(strcmp(Fl[j-1].name,Fl[j].name) > 0)
					{ 
						swap (Fl[j-1].name, Fl[j].name);
						exit = false;
				}
		}
  }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void sortYear (Film* Fl, int num) {
	long i, j;
	Film x;
	bool exit = false;

	for (i = 0; (i<num)&&(!exit); i++) { // i - номер прохода
		exit = true;
		for(j = num-1; j > i; j--) { // внутренний цикл прохода
				int a = Fl[j-1].year; 
				int b = Fl[j].year;
				if(a<b)
					{ x = Fl[j-1]; 
					Fl[j-1] = Fl[j]; 
					Fl[j] = x; 
					exit = false;
				}
		}
  }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void sortTime (Film* Fl, int num) {
	long i, j;
	Film x;
	bool exit = false;
	for (i = 0; (i<num) && (!exit); i++){
		exit = true;
		for (j = num-1; j>i; j--) {
			if (Fl[j-1].time.hours < Fl[j].time.hours) {
				swap (Fl[j-1], Fl[j]);
				exit = false;
			}
			else if ((Fl[j-1].time.hours == Fl[j].time.hours) && (Fl[j-1].time.minutes < Fl[j].time.minutes)) 
				{
				swap (Fl[j-1], Fl[j]);
				exit = false;
			}
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void sortRating (Film* Fl, int num) {
	long i, j;
	Film x;
	bool exit = false;

	for (i = 0; (i<num) && (!exit); i++){
		exit = true;
		for (j = num-1; j>i; j--) {
			if (Fl[j-1].rating < Fl[j].rating) {
				x = Fl[j-1];
				Fl[j-1] = Fl[j];
				Fl[j] = x;
				exit = false;
			}
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Film* deleteFl(Film* Fl, int N, int size) {
	if (size == 1) 
		Fl = NULL;
	else  {
	  Film* tempFl = new Film[size - 1];
	  for (int i = 0; i < N; i++)
			tempFl[i] = Fl[i];
	  for (int i = N; i < size-1; i++)
			tempFl[i] = Fl[i+1];
	  delete [] Fl;
		Fl = tempFl; 
	}
	return Fl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void save(Film* Fl, const int num) {
  FILE  *fp;
  int i;
  char filename[80];
  void FilesList();
  void CheckFileName(char *);
  cout << "Введите имя файла для сохранения данных (можно без расширения,\n на любом регистре)\n" << endl;
  cout << "Если задано новое имя, будет создан новый файл" << endl;
  cout << "Если задано существующее имя, старый файл будет обновлен" << endl;
  FilesList();
  gets_s(filename);

  CheckFileName(filename);

  if((fp = fopen(filename, "wb")) == NULL) {
    cout <<"Ошибка при открытии файла.\n";
    return;
  }
  if(fwrite(Fl, sizeof(Film), num, fp) != num) {
    cout <<"Ошибка при записи файла.\n";
	return;
  }	
  cout <<"Файл сохранен\n";
  fclose(fp);
}
void FilesList() {
   cout << "Список существующих файлов" << endl;
 
   //Вспомогательные структуры и дескрипторы
   struct _finddata_t c_file; //структура со сведениями о файле
   intptr_t hFile;//объявление знаковой целочисленной переменной; intptr_t является знаковым целочисленным memsize-типом и способен безопасно хранить в себе указатель в независимости от разрядности платформы.
   
   if( (hFile = _findfirst( "*.lib", &c_file )) == -1L ) //поиск в текущей директории файла с маской "*.lib". Характеристики первого найденного файла помещаются в структурную переменную c_file, откуда их потом можно прочитать.
      printf ("No *.lib files in current directory!\n");
   else {
      printf("ФАЙЛ		ДАТА_ВРЕМЯ  %19c РАЗМЕР\n", ' ');
      printf("------------------------------------------------------\n");
      do {
		  char buffer[30];
		  ctime_s( buffer, _countof(buffer), &c_file.time_write );
         printf( "%-18s	%.24s  %9ld\n",
            c_file.name, buffer, c_file.size );
      } while( _findnext( hFile, &c_file ) == 0 );
   }
    _findclose( hFile );
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void CheckFileName(char *filename) {
  char *p;
  strupr(filename);
  p = strstr (filename,".LIB");
	if (!p)  {
		p = strchr (filename,'.');
        if (p) *p=NULL; //Удалить любое другое расширение.
	    strcat (filename,".LIB");
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Film* load(Film *loadFile, int &N) {
  FILE  *fp;
  int i;
  char filename[80];
  
  FilesList();
  cout << "Введите имя файла для загрузки данных (можно без расширения,\nна любом регистре)" << endl;
  gets_s(filename);

  CheckFileName(filename);

  if((fp = fopen(filename, "rb")) == NULL) { 
	  cout <<"Ошибка при открытии файла.\n";
	 return 0;
  }	 
   
  if(fseek(fp, 0, SEEK_END)) { 
	  cout << "Ошибка позиционирования в файле" << endl; 
	  return 0;
  }
  N = ftell(fp)/sizeof(Film);

  loadFile = AddStruct(loadFile, N);

  if(fseek(fp, 0, SEEK_SET)) { 
	  cout << "Ошибка позиционирования в файле" << endl;
      return 0;
  }

  for(i = 0; i < N; i++)
    if(fread(&loadFile[i], sizeof(Film), 1, fp) != 1) {
         if(feof(fp)) {
		   cout <<"Ошибка при чтении файла\n";
		   return 0;
		 }
    }
 cout << "Файл прочитан" << endl;
 fclose(fp);
 return loadFile;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void unView (Film* Fl, int num) {
	int k = 0; //счетчик непросмотренных фильмов
	for (int i = 0; i<num; i++) 
		if (Fl[i].view == '-') k++;
	Film* unv = new Film[k];
	for (int i = 0, j = 0; i<num; i++) 
		if (Fl[i].view == '-') {
			unv[j] = Fl[i];
			j++;
		}
	save(unv, k);
	delete [] unv;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int menu_select(void) {
  char s[80];
  int c;

  cout << "\n1.  Ввести данные о фильме\n";
  cout << "2.  Добавить новый фильм\n";
  cout << "3.  Удалить фильм\n"; 
  cout << "4.  Изменить данные о фильме\n";
  cout << "5.  Сохранить данные в файл\n";
  cout << "6.  Загрузить данные из файла\n";
  cout << "7.  Вывести список фильмов\n";
  cout << "8.  Поиск фильма по названию\n";
  cout << "9.  Поиск фильма по году выпуска\n";
  cout << "10.  Поиск самого старого фильма\n";
  cout << "11.  Поиск фильма с самым высоким рейтингом\n";
  cout << "12.  Сортировка фильмов по названию\n";
  cout << "13.  Сортировка фильмов по году выпуска\n"; 
  cout << "14.  Сортировка фильмов по продолжительности (по возрастанию)\n";
  cout << "15.  Сортировка фильмов по рейтингу (по убыванию)\n";
  cout << "16.  Сортировка фильмов по дате добавления в фильмотеку (от новых записей к старым)\n";
  cout << "17.  Создание файла со списком непросмотренных фильмов\n";
    
  do {
    cout <<"\nВведите номер нужного пункта: ";
    gets_s(s);
    c = atoi(s);
  } while(c < 0 || c > 18);
  return c;
}
