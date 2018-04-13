#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cstring>
#include <stdio.h>
#include <io.h>
#include <conio.h> //для getch()
#include "index.h"
using namespace std;


void main() {
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	Film* ptr_fl = 0;
	int amount = 0, NumF = 0;
	char search[30];
	char YesNo;
	int year;
	
   cout << "Добро пожаловать в приложение CinemaBrowse" << endl;
   for(;;) {
    int choice = menu_select(); 
    switch(choice) 	{
     case 1: 
		 do {
			ptr_fl = AddStruct(ptr_fl, amount);
			setData(ptr_fl, amount);

			amount++;

			cout << "Продолжить ввод данных? Д/Н ";
			 YesNo = getch();
		} while (YesNo != 'Н' && YesNo != 'н');
     break;
      case 2: 
		  cout << "Добавить фильм? Д/Н" << endl;
	      YesNo = getch();
	      if (YesNo == 'Д' || YesNo == 'д') {  
					ptr_fl = AddStruct(ptr_fl, amount);
					setData(ptr_fl, amount);
					amount++;
					cout << "Добавлено" << endl; 
		  }
	  break;		 
      case 3: 
		  cout << "Удалить фильм: Да - введите номер фильма, Нет - 0" << endl;
	      cin >> NumF;
		  cin.get();
	      if (NumF) {
					ptr_fl = deleteFl(ptr_fl, NumF-1, amount);
					amount--;
					cout << "Запись о фильме удалена" << endl;
		  }
      break;
	   case 4:
		 cout << "Редактирование сведений о фильме: введите номер" << endl;
		 cin >> NumF;
		 cin.get();
		 setData(ptr_fl, NumF-1);
	  break;
	  case 5: 
		  save(ptr_fl, amount);
      break;
      case 6: 
		  ptr_fl = load(ptr_fl, amount);
	  break;
	  case 7: 
		  showData(ptr_fl, amount);
		  break;
		case 8:
		  cout << "Поиск фильма: введите название " << endl;
		  gets_s(search);
		  searchName(ptr_fl, search, amount);
	  break;
	  	case 9:
		  cout << "Поиск фильма: введите год выпуска " << endl;
		  gets_s(search); 
		  searchYear(ptr_fl, search, amount);
	  break;
	  case 10:
			cout << "Самый старый фильм: " << endl;
			searchOldest(ptr_fl, amount);
			break; 
	  case 11:
		  cout << "Фильм с самым высоким рейтингом: " << endl;
		  searchRating(ptr_fl, amount);
		  break;

	  case 12:
		  cout << "Сортировка фильмов по названиям " << endl;
		  sortName(ptr_fl, amount);
		  cout << "Отсортировано" << endl;
	  break;
	    case 13:
		  cout << "Сортировка фильмов по году выпуска " << endl;
		  sortYear(ptr_fl, amount);
		  cout << "Отсортировано" << endl;
	  break;
		case 14: 
			cout << "Сортировка фильмов по продолжительности (по возрастанию) " << endl;
			sortTime(ptr_fl, amount);
			cout << "Отсортировано" << endl;
		break;
		case 15: 
			cout << "Сортировка фильмов по рейтингу (по убыванию)" << endl;
			sortRating(ptr_fl, amount);
			cout << "Отсортировано" << endl;
		break; 
		case 16: 
			cout << "Сортировка фильмов по дате добавления (от новых к старым)"<< endl;
			sortAdding (ptr_fl, amount);
			cout << "Отсортировано" << endl;
		break;
		case 17:
			cout << "Создание файла со списком непросмотренных фильмов"<< endl;
			unView(ptr_fl, amount);
			cout << "Файл создан" << endl;
		break;
	  case 0: 
		  delete[] ptr_fl;
		  exit(0);
      }
	}
}



