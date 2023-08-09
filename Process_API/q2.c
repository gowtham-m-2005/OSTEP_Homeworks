/*2. Write a program that opens a file (with the open() system call and then
calls fork() to create a new process. Can both the child and parent ac-
cess the file descriptor returned by open()? What happens when they are
writing to the file concurrently, i.e., at the same time?*/

/*read ssize_t as “signed size_t ”. ssize_t is able to represent the number -1 ,
which is returned by several system calls and library functions as a way to indicate error. 
For example, the read and write system calls

It's used to handle the possibility that a function might return an error condition,
typically represented by a negative value, while positive values represent the number of bytes read or written.*/

/*O_RDONLY	Opens the file in read-only mode.
O_WRONLY	Opens the file in write-only mode.
O_RDWR	Opens the file in read and write mode.
O_CREAT	Create a file if it doesn’t exist.
O_EXCL	Prevent creation if it already exists.
O_ APPEND	Opens the file and places the cursor at the end of the contents.
O_ASYNC	Enable input and output control by signal.
O_CLOEXEC	Enable close-on-exec mode on the open file.
O_NONBLOCK	Disables blocking of the file opened.
O_TMPFILE	Create an unnamed temporary file at the specified path.*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int my_file = open("q2_file.txt",O_RDWR);		//open(fd,mode)
	
	int child = fork();
	
	char buff[100];
	
	if(child == 0)
	{
		printf("Child Process\n");
	//	ssize_t bytes = read(my_file,buff,10);		//read(fd,buffer,bytes to be read)
		
		write(my_file,"JOJO",5);
		ssize_t bytes = read(my_file,buff,5);
		
		buff[bytes] = '\0';
		
		printf("%s\n",buff);
	}
	else
	{
		printf("Parent Process\n");
	//	ssize_t bytes = read(my_file,buff,10);
		
		write(my_file,"GOJO",5);
		ssize_t bytes = read(my_file,buff,5);
		
		buff[bytes] = '\0';
		
		printf("%s\n",buff);
	}
	close(my_file);
	return 0;
}


/*Since both the parent and child processes are running simultaneously, they might interfere with each other. The write() and read() operations from both processes can overlap, causing unpredictable results*/
