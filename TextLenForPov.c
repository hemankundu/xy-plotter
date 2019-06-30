#include<stdio.h>
main()
{
	char text[500];
	int i;
	printf("Paste a line: ");
	gets(text);
	for(i=0;text[i]!='\0';i++);
	printf("TextLength= %d ,assign this value to n",i);
	getchar();
}
