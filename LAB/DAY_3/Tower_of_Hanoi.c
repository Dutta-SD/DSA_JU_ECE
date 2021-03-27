
# include <stdio.h>
# include <stdlib.h>

void towerOfHanoi(int n, char from, char to, char aux){
	if (n == 1)	{
		printf("Move disk 1 from  %c to %c\n", from, to);
		return;
	}
	towerOfHanoi(n - 1, from, aux, to);
	printf("Move disk %d from  %c to %c\n", n, from, to);
	towerOfHanoi(n - 1, aux, to, from);
}

int main(){
	int n;
    printf("Enter the number of disks [Input preferably less than 10] : ");
    scanf("%d", &n);
	towerOfHanoi(n, 'A', 'C', 'B'); 
	return 0;
}