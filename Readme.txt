Student List | ReadMe

Authored by Shachar Israeli
203713094
04/12/2017
 
==Description==
 
In this program the user create student list and add info about them.
the main information of the student is his ID,Grades, Income.


Program DATABASE:


struct of list of students that contain sub databases:

1. grades = represent a grade.
every grade contains subject name , the grades in numbers , and a pointer to the next grade.
2. income = represent a singel income.
every income contains a work place name , the income in numbers, and a pointer to the next income.
3. id = represent the student id.
4. averageGrades = represent the average of all grades of single student.
5. averageincome = represent the average of all incomes of single student

the stud struct also contains 4 guid info that helps to save and count the average grade and the average icome.

functions:

-------------------------------------

There is 5 main function:

1.ns - this method creates a new student and insert him in a list. (max 30 students)
in case that the student is allradey exist -  error will appear.(DOUBBLESTUD)
2.ng - this method creates a new grade for an already existed student.
in case that the studnt is not exist the user will get  error. the new grade is inserted in sorted way to the link list.
3.ni - creates a new income for an allready existed student.
 in case that the studnt is not exist the user will get an error  the new income is inserted in sorted way to the link list .
4.ws - this method gives you the option to see information about students just by his id.if the student isnt exsist the user will get an error.
the information will apears only if the user insert it befor.
5.pa - this method prints the list of student . it will print the id , the grades and the income of the student(only if existed)
6.sa - this method will sort the array by user choise. the user can choose between sort the array by average grades or sort it by id.( d or i)
both of the sorts can be up or down. ('a' or 'd')



* there is also functions that i use for "private" functions to make the main functions work*


==Program Files==
studlist.c- the file contain only functions
studlist.h- an header file ,contain structs,declerations of functions.
main.c- contain the main only.


==How to compile?==
open the 3 files in a new project and run it  with "MICROSOFT VISUAL STUDIO" . 
run. 
to finish the program type the key "end"

==Input:==

the user needs to insert a "code" depends on hes will:
the codes are:

"ns"- Create a new student.
"ng"-Create a new grade for an existed studnet.
"ni" - Create new income for an existed studenet.
"ws" - Watch student- this option shows you the information about one specific student.
"pa"- Print array - prints the student`s list .
"sa"- sort array - in this option you can choose how to sort the student list, ths user has 2 option: by avarege grades , or by id.

 end - when the user insert 'end' the function end called. this function delete all the mallocs arr and nodes and quit the program.

* the user can insert other codes but the program will do nothing.

==Output:==

there is 2 main outputs in this program:

"ws"  -  watch student. print details of specific student. print id, grade list and income list
"pa"  - print all  the students in the list. if the user will call the function sa- the list will be ordered by id  or by average grades.


