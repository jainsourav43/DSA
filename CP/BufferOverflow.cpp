#include<iostream>
#include<string.h>
using namespace std ;
char* func(char *str)
{
	int auth=0;
	char buff[4];
	strcpy(buff,str);
	if(auth){
		cout<<"Overflow \n";
	}
	return str;
 } 
int main()
{
	int i=5,j=45;
	char *str,*mystr="Sourav!";
	
	str=func(mystr);
	cout<<str<<endl;
	cout<<"i = j = "<<i<<" "<<j<<endl;
}
