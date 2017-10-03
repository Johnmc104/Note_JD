#include <stdio.h> 

void main() 
{ 
	int m,n;


	printf("Please input two int numbers: "); 
	scanf("%d%d",&m,&n); 

	while(n!=0) 
	{ 
		int r=n; 
		n=m%n; 
		m=r; 
	}
 
	printf("GCD=%d\n",m); 
	getchar(); 
} 
