/*1. Write a program that calls fork(). Before calling fork(), have the main
process access a variable (e.g., x) and set its value to something (e.g., 100).
What value is the variable in the child process? What happens to the variable when both the child and parent change the value of x?*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	int x = 100;
	
	printf("X in Parent before Child Creation : %d\n",x);
	
	int child = fork();		//Creating a child process
	
	
	if(child == 0)
	{
		printf("\nThis is the Child Process\n");
		x = x+50;
	}
	else
	{
		printf("\nThis is the Parent Process\n");
		x+= 100;
	}
	
	printf("The Value of X after the change by %d : %d \n",getpid(),x);
	return 0;
}
