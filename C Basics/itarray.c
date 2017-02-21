#include <stdio.h>

int i = 0;
int count = 0;

int a[] = {1,3,4,5,6,7,8,9};
int b[] = {1,2,3,4,5,6,7,8,10};

int main(int argc, char const *argv[])
{

	for (int i = 0; i < sizeof a / sizeof a[0]; ++i) {
		if (a[i] == b[i]){
			printf("%d ist gleich %d\n", a[i], b[i]);
		}
		else{
			printf("%d und %d sind ungleich\n", a[i], b[i]);
		}
	}			

	printf("Arbeit getan!\n");	

}