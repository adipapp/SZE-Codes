#include <stdio.h>;

void main(){
	//printf("Hello World!");
	//getchar();

	int i = 100;
	while (i >= 40)
	{
		printf("%d - %d   ", i, i+1);
		i -= 20;
	}

	getchar();
	printf("\n");

	for (i = 100; i >= 40 ; i-=20)
	{
		printf("%d - %d   ", i, i + 1);
	}
	getchar();
}