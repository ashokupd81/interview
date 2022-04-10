#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int getlength(char *s)
{
	int i;
	for(i=0; s[i]!='\0'; i++);
	return i;
}


int main()
{
	char str[]="cab";
	int i , j , k, l, limit;
	l = getlength(str);
	printf("%d", l);
	limit = pow(2, l);
	printf("%d\n", limit);
	for(i=1; i<=limit-1; i++)
	{ 
    char substr[l+1];
		k=0;
		for(j=0; j<l; j++)
		{
			if( i & ( 1 << j))
			{
				printf("i = %d, j = %d\n", i, j);
				substr[k++]=str[j];
			}
		}
		substr[k++] = '\0';
		printf("%s\n",substr);
}
}

/*
gcc allSub.c -lm

i = 1, j = 0
c
i = 2, j = 1
a
i = 3, j = 0
i = 3, j = 1
ca
i = 4, j = 2
b
i = 5, j = 0
i = 5, j = 2
cb
i = 6, j = 1
i = 6, j = 2
ab
i = 7, j = 0
i = 7, j = 1
i = 7, j = 2
cab

*/
