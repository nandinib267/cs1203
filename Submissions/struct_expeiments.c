#include <stdio.h>
#include <stdlib.h>

struct Employee{
	int empNumber;
	int salary;
};

int main(){
	// direct reference to structure: use .
	struct Employee Emp1;
	Emp1.empNumber = 12202;
	Emp1.salary = 1000000;

	//Using a pointer to the structure: use ->
	struct Employee* ptr = malloc(sizeof(struct Employee));
	ptr->empNumber = 12203;
	ptr->salary = 1000003;
	// declaring it as Employee* ptr means ptr is a pointer holding values
	// of Employee types
	// if it was declared as struct Employee ptr
	// the computer would not have known that ptr is supposed to be a pointer
	// it would the work like direct referencing


	//printing Emp1 data (used direct referencing)
	printf("Employee 1: Employee Number: %d\n",Emp1.empNumber);
	printf("Salary: %d\n",Emp1.salary);

	//printing Emp2 data (used pointer referencing)
	printf("Employee 2: Employee Number: %d\n",ptr->empNumber);
	printf("Salary: %d\n",(*ptr).salary);
	//(*ptr).salary works because it *ptr is the value at ptr 
	//the value at ptr is a structure of Employee type so the . thing works
	return 0;
}
