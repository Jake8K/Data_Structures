#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
	int id;
	char name[40];
};

void printStudent(struct student s)
{
	printf("Student name is %s\n", s.name);
	printf("Student id is %d\n\n", s.id);
}

void initStudent(int id, char *name, struct student *s)
{
	s->id = id;
	strcpy(s->name, name); /* string function from string.h */
}

int main (int argc, const char * argv[]) {
	
	int numStudents = 3;

	struct student *myStudents = malloc(numStudents * sizeof(struct student));
	
	/* assert that malloc is successfull  ... assert(myStudents != 0 */

	initStudent(25, "Joe",  &myStudents[0]);
	initStudent(65, "Mary", &myStudents[1]);
	initStudent(36, "Kate", &myStudents[2]);
	
	printStudent(myStudents[0]);
	printStudent(myStudents[1]);
	printStudent(myStudents[2]);
		
	free(myStudents);
}
