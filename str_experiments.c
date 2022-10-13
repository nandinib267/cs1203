#include <stdio.h>
#include <stdlib.h>

int main(){
	char* string1 = "This is supposed to be an immutable string!";
	//string1[3] = "t";  -> segmentation error (core dumped)
	//printf("%s\n", string1);
	char string2[]="This should be mutable";
	printf("%s\n", string2);
	string2[3] = 't'; //have to use single quotes or t is interpreted as str
	printf("%s\n",string2);
	//EXPERIMENTS WITH CONST
	
	const int nume = 13;
	// const means everything about the var is constant
	// including its storage address and stored data
	int *ptr = &nume; //value at ptr should be address of nume
	//gives warning that const qualifier is discarded from pointer target type
	//means the const nature of nume is changed
	*ptr = 12; //you're essentially changing the storage address of nume here, i think


	printf("nume = %d \n",nume);
	printf("*ptr = %d \n", *ptr);
	// right now, nume has the value 12
	int *ptr2=15;
	&nume = *ptr2;
	printf("nume = %d \n",nume);
        printf("*ptr = %d \n", *ptr);

	return 0;
}
