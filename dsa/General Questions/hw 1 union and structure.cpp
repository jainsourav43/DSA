#include<iostream>
using namespace std;
union address
{
	int stno ;
	char mno[10];
};
struct stdi
{
	int rno;
   char name[20];
   union address add;
   int tag;
   float cgpa;
};
int main()
{
	int i,j,k;int n;
	cout<<"Enter the no. of students\n";
	cin>>n;
	struct stdi s[n];
	for(i=0;i<n;i++)
	{
		cout<<"Enter the roll of student\n";
		cin>>s[i].rno;
		cout<<"Enter the name of student \n";
		cin>>s[i].name;
		cout<<"Enter 1 for entering mob no. and two for st no.\n";
		cin>>j;
		s[i].tag=j;
		if(s[i].tag==1)
		{   
		    cout<<"Enter the street no.\n";
			cin>>s[i].add.stno;
		}
		else
		{
		    cout<<"Enter the mobile no.\n";
			cin>>s[i].add.mno;
		}
		cout<<"Enter the cgpa\n";
		cin>>s[i].cgpa;
	}
	for(i=0;i<n;i++)
	{
		cout<<"Roll no. of"<<i+1<< "th student is\n"<<s[i].rno<<endl;
		cout<<"Name of the student is \n"<<s[i].name<<endl;
		if(s[i].tag==1)
		{
			cout<<"street no. of student is \n"<<s[i].add.stno<<endl;
		}
		else
		{
		cout<<"Mobile no. of student is \n"<<s[i].add.mno<<endl;
		}
		cout<<"CGPA of student is \n"<<s[i].cgpa<<endl;
	}
	return 0;
}

