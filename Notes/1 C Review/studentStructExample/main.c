#include <stdio.h>
#include <string.h>


struct student {
	int id;
	char name[40];
};

int c = 8; /* global variable*/



void printStudent(struct student s)
{
	int c = 10; /* This is a local variable named c */
	printf("Name of student is %s\n", s.name);
	printf("Id of student is %d\n", s.id);
	printf("Inside printStudent, c = %d\n\n", c);
	
}


int main (int argc, const char * argv[]) {

	struct student joe;
	joe.id = 25;
	strcpy(joe.name, "Joe");
	
	//printf("Name of student is %s\n", joe.name);
	//printf("Id of student is %d\n\n", joe.id);
	printStudent(joe);
	
	struct student mary;
	strcpy(mary.name,"Mary");
	mary.id = 65;
	//printf("Name of student is %s\n", mary.name);
	//printf("Id of student is %d\n\n", mary.id);
	printStudent(mary);


	struct student kate;
	strcpy(kate.name,"Kate");
	kate.id = 73;
	//printf("Name of student is %s\n", kate.name);
	//printf("Id of student is %d\n\n", kate.id);
	printStudent(kate);

	printf("In main, the value of c = %d\n",c);
	
    return 0;
}
