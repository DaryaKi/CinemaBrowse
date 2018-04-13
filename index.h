#ifndef INDEX_H
#define INDEX_H

struct Duration {
	unsigned int hours;
	unsigned int minutes;
};

struct Date {
	unsigned short date: 5;
	unsigned short month: 4;
	unsigned short year: 7;
};

struct Film {
	char name[30];
	char country[15];
	char genre [10];
	char view;
	int year;
	float rating;
	Duration time;
	Date today;
};

Film* AddStruct(Film*, const int);
void setData(Film*, const int);
void showData(const Film*, const int);
void searchName(Film*, char*, int);
void searchYear(Film*, char*, int);
void searchOldest(Film*, int);
void searchRating (Film*, int);
void sortName(Film*, int);
void sortYear(Film*, int); 
void sortTime (Film*, int);
void sortRating(Film*, int);
void sortAdding(Film*, int);
void unView (Film*, int);
Film* deleteFl(Film*, int, int);
Film* load(Film*, int&);
void save(Film*, const int); 
int menu_select(void);

#endif