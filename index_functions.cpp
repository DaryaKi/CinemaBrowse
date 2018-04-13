#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cstring>
#include <stdio.h>
#include <io.h>
#include <conio.h> //��� getch()
#include "index.h"
using namespace std;

Film* AddStruct(Film* Fl, const int num) {
	if (Fl == 0)
		Fl = new Film[num + 1]; // ��������� ������ ��� ������ ���������
	else 	{
		Film* tempFl = new Film[num + 1];

		for (int i = 0; i < num; i++) 
			tempFl[i] = Fl[i]; // �������� �� ��������� ������

		delete [] Fl;
		Fl = tempFl;	
	}			
	return Fl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setData(Film* Fl, const int num) {
	int i; //��������� ���������� ��� ����� ������ � ����
	    
		cout << "��������: " << endl;
		gets_s(Fl[num].name);

		cout << "������: " << endl;
		gets_s(Fl[num].country);

		cout << "����: " << endl;
		gets_s(Fl[num].genre);

		cout << "���: " << endl;
		cin >>  Fl[num].year;
		cin.get(); 

		cout << "�������: " << endl;
		cin >>  Fl[num].rating;
		cin.get(); 

		cout << "������ (�����������/�������������). ������� + ��� -" << endl;
		cin >> Fl[num].view;
		cin.get();

		cout << "����������������� ������: /n";

		cout << "�����: "<< endl;
		cin >> Fl[num].time.hours;
	
		cout << "�����: "<< endl;
		cin >> Fl[num].time.minutes;

		cin.get(); 
		cout << endl;	

		cout <<"������� " << endl;
		cout <<"����: " << endl;
		cin >> i; Fl[num].today.date = i; 
		cin.get(); 
		cout << endl;	

		cout <<"�����: " << endl;
		cin >> i; Fl[num].today.month = i; 
		cin.get(); 
		cout << endl;	

		cout <<"��� (� ������� 0 - 99): " << endl;
		cin >> i; Fl[num].today.year = i; 
		cin.get(); 
		cout << endl;	
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void showData(const Film* Fl, const int num) {
	system("cls");
	
	cout << left << "�  "<< setw(20) << left << "��������" << setw(15) <<  "������" << setw(10) << "����" << setw(10) 
		<< "�������" << setw(3) << "��� " << setw(5) << "����������������� ";
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
		 cout << "����� �" << i+1 << endl;  
		 k++;
	}
	if (k==0) cout << "������ �� �������" << endl;
	else cout << "������� �������: " << k << endl;
}
void searchYear(Film* F, char* b, int num) {
	int k=0;
	int a = atoi(b);
	for(int i = 0; i < num; i++)
	if (F[i].year == a) 
	{ 
		cout << "����� �" << i+1 << endl;  
		k++;
	} 
	if (k==0) cout << "������ �� �������" << endl;
	else cout << "������� �������: " << k << endl;
}

void searchOldest(Film* Fl, int num) {
	Film oldest; 
	int year = Fl[0].year;
	for (int i = 0; i<num; i++) 
		if (Fl[i].year < year){
			year = Fl[i].year;
			oldest = Fl[i];
		}
	cout << oldest.name << " " << year << "�."<< "\n";
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
void sortAdding (Film* Fl, int num) { //�� ���� ���������� �� ����� � ������
long i, j;
Film x;
bool exit = false;
bool equility = false; //���� ���������� �����, �� ����� ����� ������ ���������� 

//�� ����
for (i = 0; (i<num)&&(!exit); i++) { // i - ����� �������
		exit = true;
		for(j = num-1; j > i; j--) { // ���������� ���� �������
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
//�� ������
if (equility) {
for (i = 0; (i<num)&&(!exit); i++) { // i - ����� �������
		exit = true;
		for(j = num-1; j > i; j--) { // ���������� ���� �������
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
//�� ���
if (equility) {
for (i = 0; (i<num)&&(!exit); i++) { // i - ����� �������
		exit = true;
		for(j = num-1; j > i; j--) { // ���������� ���� �������
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
  for(i = 0; (i < num) && (!exit); i++) { // i - ����� �������
		exit = true;
		for(j = num-1; j > i; j--) { // ���������� ���� �������
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

	for (i = 0; (i<num)&&(!exit); i++) { // i - ����� �������
		exit = true;
		for(j = num-1; j > i; j--) { // ���������� ���� �������
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
  cout << "������� ��� ����� ��� ���������� ������ (����� ��� ����������,\n �� ����� ��������)\n" << endl;
  cout << "���� ������ ����� ���, ����� ������ ����� ����" << endl;
  cout << "���� ������ ������������ ���, ������ ���� ����� ��������" << endl;
  FilesList();
  gets_s(filename);

  CheckFileName(filename);

  if((fp = fopen(filename, "wb")) == NULL) {
    cout <<"������ ��� �������� �����.\n";
    return;
  }
  if(fwrite(Fl, sizeof(Film), num, fp) != num) {
    cout <<"������ ��� ������ �����.\n";
	return;
  }	
  cout <<"���� ��������\n";
  fclose(fp);
}
void FilesList() {
   cout << "������ ������������ ������" << endl;
 
   //��������������� ��������� � �����������
   struct _finddata_t c_file; //��������� �� ���������� � �����
   intptr_t hFile;//���������� �������� ������������� ����������; intptr_t �������� �������� ������������� memsize-����� � �������� ��������� ������� � ���� ��������� � ������������� �� ����������� ���������.
   
   if( (hFile = _findfirst( "*.lib", &c_file )) == -1L ) //����� � ������� ���������� ����� � ������ "*.lib". �������������� ������� ���������� ����� ���������� � ����������� ���������� c_file, ������ �� ����� ����� ���������.
      printf ("No *.lib files in current directory!\n");
   else {
      printf("����		����_�����  %19c ������\n", ' ');
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
        if (p) *p=NULL; //������� ����� ������ ����������.
	    strcat (filename,".LIB");
    }
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Film* load(Film *loadFile, int &N) {
  FILE  *fp;
  int i;
  char filename[80];
  
  FilesList();
  cout << "������� ��� ����� ��� �������� ������ (����� ��� ����������,\n�� ����� ��������)" << endl;
  gets_s(filename);

  CheckFileName(filename);

  if((fp = fopen(filename, "rb")) == NULL) { 
	  cout <<"������ ��� �������� �����.\n";
	 return 0;
  }	 
   
  if(fseek(fp, 0, SEEK_END)) { 
	  cout << "������ ���������������� � �����" << endl; 
	  return 0;
  }
  N = ftell(fp)/sizeof(Film);

  loadFile = AddStruct(loadFile, N);

  if(fseek(fp, 0, SEEK_SET)) { 
	  cout << "������ ���������������� � �����" << endl;
      return 0;
  }

  for(i = 0; i < N; i++)
    if(fread(&loadFile[i], sizeof(Film), 1, fp) != 1) {
         if(feof(fp)) {
		   cout <<"������ ��� ������ �����\n";
		   return 0;
		 }
    }
 cout << "���� ��������" << endl;
 fclose(fp);
 return loadFile;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void unView (Film* Fl, int num) {
	int k = 0; //������� ��������������� �������
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

  cout << "\n1.  ������ ������ � ������\n";
  cout << "2.  �������� ����� �����\n";
  cout << "3.  ������� �����\n"; 
  cout << "4.  �������� ������ � ������\n";
  cout << "5.  ��������� ������ � ����\n";
  cout << "6.  ��������� ������ �� �����\n";
  cout << "7.  ������� ������ �������\n";
  cout << "8.  ����� ������ �� ��������\n";
  cout << "9.  ����� ������ �� ���� �������\n";
  cout << "10.  ����� ������ ������� ������\n";
  cout << "11.  ����� ������ � ����� ������� ���������\n";
  cout << "12.  ���������� ������� �� ��������\n";
  cout << "13.  ���������� ������� �� ���� �������\n"; 
  cout << "14.  ���������� ������� �� ����������������� (�� �����������)\n";
  cout << "15.  ���������� ������� �� �������� (�� ��������)\n";
  cout << "16.  ���������� ������� �� ���� ���������� � ���������� (�� ����� ������� � ������)\n";
  cout << "17.  �������� ����� �� ������� ��������������� �������\n";
    
  do {
    cout <<"\n������� ����� ������� ������: ";
    gets_s(s);
    c = atoi(s);
  } while(c < 0 || c > 18);
  return c;
}
