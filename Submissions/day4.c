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
	const int m =5;
	int *p=&m; //put location of n as value of p
	*p=6; //put 6 in the location p (which we have said is the location of n
	// intuitively, now n should be equal to 6 but n is a const
	// is it changed?
	printf("x = %d\n",m);
	printf("*p = %d\n",*p);
	//it is changed. paap.
	//computers are iiots
	//and if you're spending so much to study them
	//you're an idiot too
	printf("----------------------\n");
	const char *string = "Can't touch this";//at posofstring put this phrase
	string = "Can't touch this either"; //let string be this phrase
	printf("%s\n",string);
	// printf("%s\n",*(string));  GIVES SEGMENTATION ERROR 
	//even though cant touch this is inputted as a const at 
	//whatever location string is at
	//string can be given the value of cant touch this either
	//idiot comp 
	printf("----------------------\n");
	int *a;
	int i,n,val;
	n = 3;
	a = (int *) malloc(n*sizeof(int));
	
	//add data
	i = 0;
	scanf("%d",&val);

	while (val>0){
		a[i]=val;
		i++;
		if(i>=n){
			n=n*2;
			a = (int *) realloc(a,n*sizeof(int));
		}
		scanf("%d",&val); //what does this do?
	}

	//removing all excess memory alloc-ed to a
	n=i;
	a = realloc(a,n*sizeof(int)); 
	printf("THe inputted data:\n");
	//print data
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}

	printf("Done!\n");
	return 0;
}
