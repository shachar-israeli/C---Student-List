
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
#include "studlist.h"


#define SIZE 30
#define nsCode "ns"
#define ngCode "ng"
#define niCode "ni"
#define wsCode "ws"
#define paCode "pa"
#define saCode "sa"
#define endCode "end"

#define NOT_EXIST -1 


int index = -1;


void ns(Stud list[])
{
	int id;

	printf("Please insert Student`s id:\n");     // get ID
	scanf("%d", &id);
	int flag = searchById(list, id);    // get the right place in the Stud list
	if (flag == NOT_EXIST)
	{

		index++;                           // index of how many Stud are used
		Stud a;
		a.id = id;

		// initialise our Student
		list[index].id = id;
		list[index].averegeGrades = 0;
		list[index].averegeincome = 0;

		list[index].indexGrades = 0;
		list[index].indexIncomes = 0;
		list[index].sumGrades = 0;
		list[index].sumIncomes = 0;

		list[index].gradesNodeHead = NULL;         // start the linked list to null
		list[index].incomeNodeHead = NULL;


		printf("new Student has been created!\nwhat are you willing to do?\n");

	}
	else
		printf("DOUBLESTUD!!\n");


}



void ng(Stud list[])             // new grade to the list
{
	int id;
	char sub[20];
	int grade;
	printf("enter id:\n");
	scanf("%d", &id);
	int i = searchById(list, id);

	if (i == NOT_EXIST)
	{
		printf("NA\n");
		end(list);

	}
	printf("insert sub name\n");


	scanf("%s", sub);
	printf("insert grade\n");
	scanf("%d", &grade);

	grades newGradetemp;    // temp grade just for sending to the fon.
	newGradetemp.grade = grade;
	strcpy(newGradetemp.subName, sub);

	AddToList(&newGradetemp, &list[i].gradesNodeHead, createNewGrade, getNextGrade, setNextGrade, compareGrades);

	// get the new grade in the sorted way to the list.


	list[i].indexGrades++;       // how many grades are in the list.
	list[i].sumGrades += (float)grade;    // sum of all the grades
	list[i].averegeGrades = (float)(list[i].sumGrades / list[i].indexGrades);    // updating the averege

	printf("what are you willing to do?\n");


}

void ni(Stud list[])  //  ni = new income. 
{
	int id;
	char workPlace[20];
	float cash;
	printf("enter id:\n");    // get data from user
	scanf("%d", &id);
	int i = searchById(list, id);

	if (i == NOT_EXIST)
	{
		printf("NA\n");             // if the student not found in the list
		end(list);

	}
	printf("insert work place \n");
	scanf("%s", workPlace);
	printf("insert the income\n");
	scanf("%f", &cash);

	income newIncomeTemp;
	newIncomeTemp.cash = cash;
	strcpy(newIncomeTemp.workPlaceName, workPlace);

	AddToList(&newIncomeTemp, &list[i].incomeNodeHead, createNewIncome, getNextIncome, setNextIncome, compareIncomes);
	// get the new grade in the sorted way to the list.
	list[i].indexIncomes++;   //  // how many grades are in the list.
	list[i].sumIncomes += (float)cash;
	list[i].averegeincome = (float)(list[i].sumIncomes / list[i].indexIncomes);    // update the average

	printf("\nwhat are you willing to do?\n");
}


void* createNewGrade(void* content)        // inside content the fon get the grade and string to built the node
{
	grades* newItem = (grades*)malloc(sizeof(grades));
	assert(newItem != NULL);

	newItem->grade = ((grades*)content)->grade;
	strcpy(newItem->subName, ((grades*)content)->subName);
	newItem->next = NULL;

	return newItem;    // will be the new grade node to add

}


void* createNewIncome(void* content)      // inside content the fon get the grade and string to built the node
{
	income* newItem = (income*)malloc(sizeof(income));
	assert(newItem != NULL);

	newItem->cash = ((income*)content)->cash;
	strcpy(newItem->workPlaceName, ((income*)content)->workPlaceName);
	newItem->next = NULL;

	return newItem;      // will be the new node to add

}


int compareGrades(void* a, void* b)     // return 1 if a > b  . to use in geniry fon
{
	int first = ((grades*)a)->grade;
	int sec = ((grades*)b)->grade;

	if (first > sec)
		return 1;
	return 0;

}

int compareIncomes(void* a, void* b)  // return 1 if a > b  . to use in geniry fon
{
	float first = ((income*)a)->cash;
	float sec = ((income*)b)->cash;

	if (first > sec)
		return 1;
	return 0;

}

void* getNextGrade(void* head)            // getters and setters to the  linked list.
{
	return (((grades*)head)->next);
}

void* getNextIncome(void* head)
{
	return ((income*)(head))->next;
}

void setNextGrade(void* node, void* nextNode)
{
	((grades*)node)->next = nextNode;

}

void setNextIncome(void* node, void* nextNode)
{

	((income*)node)->next = nextNode;

}


void AddToList(void *data, void **list, void* (*createNode)(void* data), void* (*getNext)(void*), void(*setNext)(void* node, void* data), int(*compare)(void *a1, void *a2))
{
	void* nodeToAdd = createNode(data);          // genery to add to the list. works with fon to the grade and to the income
	void* headlist = *list;

	if (headlist == NULL)        // if head is null = the new now will be the head
		*list = nodeToAdd;

	


	else if (compare(headlist, nodeToAdd) == 1)   // in case the new node should be the head( node< head)
	{
		setNext(nodeToAdd, headlist);
		*list = nodeToAdd;
	}
	else
	{
		void* tempHead = headlist;
		while (getNext(tempHead) != NULL && compare(nodeToAdd, getNext(tempHead)) == 1)    // untill node<temp
		{

			tempHead = getNext(tempHead);

		}
		setNext(nodeToAdd, getNext(tempHead));
		setNext(tempHead, nodeToAdd);

	}
}


void printincomeGenery(void* head)    // print the grade list linked 
{
	if (((income*)(head)) == NULL)    // if null do nothing
		return;
	else
	{
		if (((income*)(head))->next == NULL)           // dont print the , in the end of the list
			printf("%s %f ", ((income*)(head))->workPlaceName, ((income*)(head))->cash);
		else
			printf("%s %f, ", ((income*)(head))->workPlaceName, ((income*)(head))->cash);
	}
}


void printGradeGenery(void* head)    // print the grade list linked
{
	if (((grades*)(head)) == NULL)
		return;              // list = null do nothing
	else
	{

		if (((grades*)(head))->next == NULL)            //  // dont print the , in the end of the list
			printf("%s %d ", ((grades*)(head))->subName, ((grades*)(head))->grade);
		else
			printf("%s %d, ", ((grades*)(head))->subName, ((grades*)(head))->grade);
	}
}


void print_list(void* head, void* (*getnext)(void*), void(*printnode)(void*))
{
	void* temp = head;         // genery. use the right fon to print both of the lists.

	while (temp != NULL) 
	{
		printnode(temp);
		temp = getnext(temp);
	}
}


int searchById(Stud list[SIZE], int id)       // return the right place of the stud list. 
{
	for (int i = 0; i <= index; i++)
	{
		if (list[i].id == id)
			return i;
	}

	return NOT_EXIST;    // if the id is not on the list return -1

}




void ws(Stud list[])      // wanted student
{

	int id;
	printf("insert id:\n");
	scanf("%d", &id);
	int i = searchById(list, id);

	if (i == NOT_EXIST)
	{
		printf("NA\n");        // couldnt find the student
		end(list);

	}
	else
	{
		printf("Student`s id: %d\n", id);        // print detailes of this student
		print_list(list[i].gradesNodeHead, getNextGrade, printGradeGenery);
		printf("\n");
		print_list(list[i].incomeNodeHead, getNextIncome, printincomeGenery);
		printf("\nwhat are you willing to do?\n");
	}

}


void pa(Stud list[])
{
	if (index == NOT_EXIST)
		printf("No Students to show\n");      // dont go out from the project. just print error.
	else 
	{
		printf("----------------\n");       // just do a border from 1 stu to another
		for (int i = 0; i <= index; i++)
		{
			printf("Student`s id: %d\n", list[i].id);
			print_list(list[i].gradesNodeHead, getNextGrade, printGradeGenery);
			printf("\n");
			print_list(list[i].incomeNodeHead, getNextIncome, printincomeGenery);   
			printf("\n----------------\n");
		}



	}
}

void freeGradeNode(grades* headlist)        // free all grade list. 
{

	if (headlist == NULL)
		return;
	freeGradeNode(headlist->next);         // first go to the last node and then start to free the list
	free(headlist);
	
}


void freeIncomeNode(income* headlist)      // free the income list
{

	if (headlist == NULL)
		return;
	freeIncomeNode(headlist->next);   // first go the the last node and then start to free the list
	free(headlist);


}



int cmpAscendingId(const Stud *s1, const Stud *s2)   //  going up. first < second
{
	if (s1->id < s2->id)
		return 1;
	return 0;

}

int cmpDescendingId(const Stud *s1, const Stud *s2) // going down first > sec
{
	if (s1->id > s2->id)
		return 1;
	return 0;

}

int cmpAscendingAvGrades(const Stud *s1, const Stud *s2)
{
	if (s1->averegeGrades < s2->averegeGrades)     // cheacks if average grades of Student s1 if greater the s2 .if it is retrun 1;
		return 1;
	return 0;

}

int cmpDescendingAvGrades(const Stud *s1, const Stud *s2)   // going down first > second
{
	if (s1->averegeGrades > s2->averegeGrades)
		return 1;
	return 0;
}


void merge(Stud arr[], int l, int mid, int r, void*(*cmp)(void* a, void*b))    // MERGE sort
{   // genery. use the compare fon to work on id and grade in 1 fon
	int i, j, k;
	int sizeL = mid - l + 1;
	int sizeR = r - mid;

	/* create temp arrays */
	Stud* L = (Stud*)malloc(sizeL * sizeof(Stud));   // make  temp L arr
	assert(L != NULL);
	Stud* R = (Stud*)malloc(sizeR * sizeof(Stud));  // make temp R arr
	assert(R != NULL);
	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < sizeL; i++)
		L[i] = arr[l + i];
	for (j = 0; j < sizeR; j++)
		R[j] = arr[mid + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray


	while (i < sizeL && j < sizeR)
	{
		int answer = cmp(&L[i], &R[j]);

		if (answer == 1)
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < sizeL)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < sizeR)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	free(L);      // delete the temp arr
	free(R);


}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */

void mergeSort(Stud arr[], int l, int r, void*(*cmp)(void* a, void*b))
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int mid = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, mid, cmp);         //cmp is the compre to the genery sory
		mergeSort(arr, mid + 1, r, cmp);

		merge(arr, l, mid, r, cmp);
	}
}


void sa(Stud list[])     // SORT ALL 
{
	char answerIOrG[2];
	char answerAsOrDe[2];
	printf("Sort Student - how do you want to sort ? 'i' for id , 'g' for grades \n");
	scanf("%s", &answerIOrG);
	printf("ascending or decending?  'a' for ascending, 'd' for decending\n");
	scanf("%s", &answerAsOrDe);

	if (strcmp(answerIOrG, "g") == 0)                     // choose the right fon to use the genery sort
	{
		if (strcmp(answerAsOrDe, "a") == 0)
			mergeSort(list, 0, index, cmpAscendingAvGrades);
		else
			mergeSort(list, 0, index, cmpDescendingAvGrades);

	}
	else                            // send also the compere fon 
	{
		if (strcmp(answerAsOrDe, "a") == 0)
			mergeSort(list, 0, index, cmpAscendingId);
		else
			mergeSort(list, 0, index, cmpDescendingId);
	}

	printf("what are you willing to do?\n");
}

void end(Stud list[])    // call it with finish and when wrong id in ng\ni
{
	if (index == NOT_EXIST)
		exit(1);

	for (int i = 0; i <= index; i++)
	{
		freeGradeNode(list[i].gradesNodeHead);         // free all the linked list of all the Students.
		freeIncomeNode(list[i].incomeNodeHead);

	}
	exit(1);

}
