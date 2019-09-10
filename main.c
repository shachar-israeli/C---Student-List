
/*
ex2:

In this program the user create Student list and add info about them.
the main information of the Student is his ID,Grades, Income.

we use linked list to save the data and also sort functions to sort the Students.

Name: Shachar Israeli
ID: 203713094
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <assert.h>
#include "studlist.h"

int main()
{

	Stud list[SIZE];           
	
	printf("what are you willing to do?\n");

	while (1)            // untill get the end command
	{
		char code[4];

		scanf("%s", &code);

		if (strcmp(code, nsCode) == 0)     
			// check the scan if it 1 of the saved code. if yes go to the right fon
		{
			ns(list);

		}
		else if (strcmp(code, ngCode) == 0)
		{
			ng(list);
		}

		else if (strcmp(code, niCode) == 0)
		{
			ni(list);
		}


		else if (strcmp(code, wsCode) == 0)
		{
			ws(list);

		}

		else if (strcmp(code, paCode) == 0)
		{
			pa(list);

		}
		else if (strcmp(code, saCode) == 0)
		{
			sa(list);

		}

		else if (strcmp(code, endCode) == 0)
		{
			end(list);           // free all the malloc and quit the program

		}
	}
}