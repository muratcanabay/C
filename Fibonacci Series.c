#include <stdlib.h>
#include <stdio.h>


long int fibonacci(int n){

	if(n==1 || n==2)
		return 1;
	else if(n<=0){
		return -1;
	}
	else
		return (fibonacci(n-1)+fibonacci(n-2));
}

int main(){

	long int x;
	printf("\nEnter the number that you want to find fibonacci sequence:");
	scanf("\n%ld",&x);
	
	printf("\nThe Fibonacci series:%ld\n",fibonacci(x));

	return 0;

}