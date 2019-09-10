
/*
ex2:

In this program the user create student list and add info about them.
the main information of the student is his ID,Grades, Income.

we use linked list to save the data and also sort functions to sort the students.

Name: Shachar Israeli
ID: 203713094
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <assert.h>

#define SIZE 30
#define nsCode "ns"
#define ngCode "ng"
#define niCode "ni"
#define wsCode "ws"
#define paCode "pa"
#define saCode "sa"
#define endCode "end"

#define NOT_EXIST -1 

//grades struct
typedef struct
{
	int grade;
	char subName[20];
	struct grades* next;

}grades;

// income struct

typedef struct 
{
	float cash;
	char workPlaceName[20];
	struct income* next;

}income;


//student struct

typedef struct
{
	int id;
	float averegeGrades;
	float averegeincome;
	income* incomeNodeHead;
	grades* gradesNodeHead;

	float sumGrades;
	int indexGrades;
	float sumIncomes;
	int indexIncomes;

}Stud;


//income function

void* createNewIncome(void* content);
int compareIncomes(void* a, void* b);
void* getNextIncome(void* head);
void setNextIncome(void* node, void* nextNode);
void printincomeGenery(void* head);



//grades function
int compareGrades(void* a, void* b);
void* createNewGrade(void* content);
void* getNextGrade(void* head);
void setNextGrade(void* node, void* nextNode);
void printGradeGenery(void* head);



//general functions

void AddToList(void *data, void **list, void* (*createNode)(void* data), void* (*getNext)(void*), void(*setNext)(void* node, void* data), int(*compare)(void *a1, void *a2));

void print_list(void* head, void* (*getnext)(void*), void(*printnode)(void*));

int searchById(Stud list[SIZE], int id);

//Stud function

void ns(Stud list[]);
void ws(Stud list[]);
void pa(Stud list[]);
void sa(Stud list[]);
void end(Stud list[]);
void ng(Stud list[]);
void ni(Stud list[]);

void freeGradeNode(grades* headlist); 
void freeIncomeNode(income* headlist);

//merge function

int cmpAscendingId(const Stud *s1, const Stud *s2);
int cmpDescendingId(const Stud *s1, const Stud *s2);
int cmpAscendingAvGrades(const Stud *s1, const Stud *s2);
int cmpDescendingAvGrades(const Stud *s1, const Stud *s2);

void merge(Stud arr[], int l, int mid, int r, void*(*cmp)(void* a, void*b));
void mergeSort(Stud arr[], int l, int r, void*(*cmp)(void* a, void*b));




