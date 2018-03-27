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
long long  search(char key[],int nk,char k[][10],int[]);
int main()
{
    int i,j,k,n;
	cout<<"Enter the no of student   :  ";
	cin>>n;
	char key[n][10];
	int r[n];
	int nk=0,correct;
	student s[n];
	ofstream fout;
	fout.open("Student.txt");
	for(i=0;i<n;i++)
	{
		correct =fout.tellp();
		cout<<"Enter the name of student\n";
		cin>>s[i].name;
		fout<<s[i].name<<"|";
		cout<<"enter the rollno.of student\n";
		cin>>s[i].roll;
		fout<<s[i].roll<<"|";
		cout<<"Enter the branch of student\n";
		cin>>s[i].branch;
		fout<<s[i].branch<<"#";
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
		r[j+1]=correct;
		nk++;
	}
	for(j=0;j<nk;j++)
	{
		cout<<"R[j] = "<<r[j]<<"  ";
	}
	long long h;
	h=search(s[1].roll,nk,key,r);
	cout<<"H  =  "<<h<<endl;
}
long long  search(char key1[],int nk,char key[][10],int r[])
{
	int i=0;cout<<key1<<endl;
	cout<<"KEY  ="<<key[0]<<" "<<r[0]<<endl;
	for(i=0;i<nk;i++)
	{
		if(strcmp(key[i],key1)==0)
		return r[i];
		else if(strcmp(key[i],key1)>0)
		return -1;
	}
}
