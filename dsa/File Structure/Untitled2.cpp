#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct student
{
	char roll[10];
	char name[10];
	char branch[10];
};
int main()
{
	int i,j,n;long long k;
	cout<<"Enter the no of student   :  ";
	cin>>n;char buffer[40];
	char key[n][10];
	int r[n];
	int nk=0;
	student s[n];
	ofstream fout;
	fout.open("Student.txt");
	for(i=0;i<n;i++)
	{
		cout<<"Enter the name of student\n";
		cin>>s[i].name;strcpy(buffer,s[i].name);
		fout<<s[i].name<<"|";strcat(buffer,"|");
		cout<<"enter the roll no.of student\n";
		cin>>s[i].roll;strcat(buffer,s[i].roll);
		fout<<s[i].roll<<"|";strcat(buffer,"|");
		cout<<"Enter the branch of student\n";
		cin>>s[i].branch;strcat(buffer,s[i].branch);
		fout<<s[i].branch<<"#";strcat(buffer,"#");
		k=strlen(buffer);
		for(j=nk-1;j>=0;j--)
		{
			if(strcmp(s[i].roll,key[j])>0)
			{
				break;
			}
			strcpy(key[j+1],key[j]);
			r[j+1]=r[j];
		}
		strcpy(key[j+1],s[i].roll);
		r[j+1]=(fout.tellp())-k;
		nk++;
		
	}
	fout.close();
	for(j=0;j<nk;j++)
	{
		cout<<"R[j]"<<r[j]<<"  ";
	}
	
}
