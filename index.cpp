#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cstring>
#include <stdio.h>
#include <io.h>
#include <conio.h> //��� getch()
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
	
   cout << "����� ���������� � ���������� CinemaBrowse" << endl;
   for(;;) {
    int choice = menu_select(); 
    switch(choice) 	{
     case 1: 
		 do {
			ptr_fl = AddStruct(ptr_fl, amount);
			setData(ptr_fl, amount);

			amount++;

			cout << "���������� ���� ������? �/� ";
			 YesNo = getch();
		} while (YesNo != '�' && YesNo != '�');
     break;
      case 2: 
		  cout << "�������� �����? �/�" << endl;
	      YesNo = getch();
	      if (YesNo == '�' || YesNo == '�') {  
					ptr_fl = AddStruct(ptr_fl, amount);
					setData(ptr_fl, amount);
					amount++;
					cout << "���������" << endl; 
		  }
	  break;		 
      case 3: 
		  cout << "������� �����: �� - ������� ����� ������, ��� - 0" << endl;
	      cin >> NumF;
		  cin.get();
	      if (NumF) {
					ptr_fl = deleteFl(ptr_fl, NumF-1, amount);
					amount--;
					cout << "������ � ������ �������" << endl;
		  }
      break;
	   case 4:
		 cout << "�������������� �������� � ������: ������� �����" << endl;
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
		  cout << "����� ������: ������� �������� " << endl;
		  gets_s(search);
		  searchName(ptr_fl, search, amount);
	  break;
	  	case 9:
		  cout << "����� ������: ������� ��� ������� " << endl;
		  gets_s(search); 
		  searchYear(ptr_fl, search, amount);
	  break;
	  case 10:
			cout << "����� ������ �����: " << endl;
			searchOldest(ptr_fl, amount);
			break; 
	  case 11:
		  cout << "����� � ����� ������� ���������: " << endl;
		  searchRating(ptr_fl, amount);
		  break;

	  case 12:
		  cout << "���������� ������� �� ��������� " << endl;
		  sortName(ptr_fl, amount);
		  cout << "�������������" << endl;
	  break;
	    case 13:
		  cout << "���������� ������� �� ���� ������� " << endl;
		  sortYear(ptr_fl, amount);
		  cout << "�������������" << endl;
	  break;
		case 14: 
			cout << "���������� ������� �� ����������������� (�� �����������) " << endl;
			sortTime(ptr_fl, amount);
			cout << "�������������" << endl;
		break;
		case 15: 
			cout << "���������� ������� �� �������� (�� ��������)" << endl;
			sortRating(ptr_fl, amount);
			cout << "�������������" << endl;
		break; 
		case 16: 
			cout << "���������� ������� �� ���� ���������� (�� ����� � ������)"<< endl;
			sortAdding (ptr_fl, amount);
			cout << "�������������" << endl;
		break;
		case 17:
			cout << "�������� ����� �� ������� ��������������� �������"<< endl;
			unView(ptr_fl, amount);
			cout << "���� ������" << endl;
		break;
	  case 0: 
		  delete[] ptr_fl;
		  exit(0);
      }
	}
}



