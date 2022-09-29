#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	int x = 2;
	int y = 9;
	printf("x = %d, y= %d \n", x, y);
	printf("But now \n");
	x=(y=2)*3;
	printf("x = %d, y = %d \n",x,y);
	printf("----------------------\n");
	char str[] = "Hey";
	printf("%s\n",str);
	printf("%c\n",*(str+1));
	printf("----------------------\n");
	const int n =5;
	int *p=&n; //put location of n as value of p
	*p=6; //put 6 in the location p (which we have said is the location of n
	// intuitively, now n should be equal to 6 but n is a const
	// is it changed?
	printf("x = %d\n",n);
	printf("*p = %d\n",*p);
	//it is changed. paap.
	//computers are idiots
	//and if you're spending so much to study them
	//you're an idiot too
	printf("----------------------\n");
	const char *string = "Can't touch this";//at pos string put this phrase
	string = "Can't touch this either"; //let string be this phrase
	printf("%s\n",string);
	// printf("%s\n",*(string));  GIVES SEGMENTATION ERROR 

}
