# include <stdio.h>
# include <stdlib.h>

void towerOfHanoi(int diskNumber, char from, char to, char aux){
	if (diskNumber == 1)	{
		printf("Move disk 1 from  %c to %c\n", from, to);
		return;
	}
	towerOfHanoi(diskNumber - 1, from, aux, to);
	printf("Move disk %d from  %c to %c\n", diskNumber, from, to);
	towerOfHanoi(diskNumber - 1, aux, to, from);
}

int main(){
	int n;
    printf("Enter the number of disks [Input preferably less than 10] : ");
    scanf("%d", &n);
	towerOfHanoi(n, 'A', 'C', 'B'); 
	return 0;
}