/* 
NOTE : THIS CODE USES CALL STACK, ANOTHER CODE IS PRROVIDED LATER
*/

# include <stdio.h>
# include <stdlib.h>
# include <execinfo.h>
# define BT_BUFFER_SIZE 2048

/*

Call Stack - whenever a function is called, to know the current
control, C maintains a call stack that is which function the program
is currently in.

In this program we print the current stack call using
execinfo library. 

THIS IS A LINUX ONLY(IE GCC ONLY) IMPLEMENTATION.

*/

/* 
printCallStack - Prints the call stack 
 */
void printCallStack(){
	int numPointers;
	void *buffer[BT_BUFFER_SIZE];
	char **functionCalls;
	int j;

	printf("\n");
	numPointers = backtrace(buffer, BT_BUFFER_SIZE);
	printf("\n CALL STACK HAS %d FUNCTIONS\n", numPointers);

	functionCalls = backtrace_symbols(buffer, numPointers);
	if (functionCalls == NULL) {
		printf("EMPTY STACK\n\n");
		exit(EXIT_FAILURE);
	}

	for (j = 0; j < numPointers; j++)
		printf("\t%s\n", functionCalls[j]);

	printf("\n");
	free(functionCalls);
}

/* Tower of Hanoi using Recursion and Stack Calling */
void towerOfHanoi(int diskNumber, char from, char to, char aux, int printStackTrace){
	if(printStackTrace) printCallStack();
	printf("\n CURRENT ARGS [ SOURCE : %c , AUX : %c, DESTINATION : %c]\n", from, aux, to);
	if (diskNumber == 1)	{
		printf("Move disk 1 from  %c to %c\n", from, to);
		return;
	}
	towerOfHanoi(diskNumber - 1, from, aux, to, printStackTrace);
	printf("Move disk %d from  %c to %c\n", diskNumber, from, to);
	towerOfHanoi(diskNumber - 1, aux, to, from, printStackTrace);
}

int main(){
	int n;
	int printStackTrace;
	printf("Do we need to print the call stack? Enter your choice 1[YES] or 0[NO] : ");
	scanf("%d", &printStackTrace);
    printf("Enter the number of disks [Input preferably less than 10] : ");
    scanf("%d", &n);
	towerOfHanoi(n, 'A', 'C', 'B', printStackTrace); 
	return 0;
}