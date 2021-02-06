#include <stdio.h>
#include <stdlib.h>

void print(char **a, int size) {
	for(int i=1;i<size;i++) {
		printf("%s",a[i]);
	}
	putchar('\n');
}

void perm(char **a, int j, int size) {
	
	if(j==size) {
		print(a, size);
	}

	for(int i=j;i<size;i++) {
		char *tmp=a[j];
		a[j]=a[i];
		a[i]=tmp;

		perm(a,j+1,size);
		
		a[i]=a[j];
		a[j]=tmp;
	}
}

int main(int argc, char *argv[]) {
	if(argc<2) {
		fputs("usage: permut item1 item2 item3...\n",stderr);
		exit(1);
	}

	perm(argv, 1, argc);
}
