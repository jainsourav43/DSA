#include<stdio.h>
void execve(char *name,char** name1,char *n)
{
	printf("%s",name);
}
int main()
{
	char *name[2];
	name[0]="/bin/sh";
	name[1]=NULL;
		execve(name[0],name,NULL);
}
