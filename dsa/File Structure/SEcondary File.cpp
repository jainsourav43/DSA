#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
using namespace std;
struct student
{
	char roll[10];
	char name[10];
	char branch[10];
};
int search(int temp[][2],int k,int s,int e)
{
	//cout<<"WELCOME  k = "<<k<<endl;
	if(s<=e)
	{
	int mid=s+(e-s)/2;//cout<<"TEMP =  "<<temp[mid][0]<<endl;
	if(temp[mid][0]>k)
     return search(temp,k,s,mid-1);
	if(temp[mid][0]<k)
   return search(temp,k,mid+1,e);
   else if(temp[mid][0]==k)
   return temp[mid][1];
   }
   return -1;
}
int main()
{
	int i,j,k,n;
	cout<<"Enter the no of student   :  ";
	cin>>n;char ch[10],ch1[10],ch2[10];
	int k1,k2;
	student s[n];
	int temp[n][2];
	ofstream fout,fout1,fout2;
	fout.open("Student.txt");
	fout1.open("INDEXFILE.txt");
	fout2.open("Secondary.txt");
	for(i=0;i<n;i++)
	{
		temp[i][1]=fout.tellp();
		cout<<"Enter the name of student\n";
		cin>>s[i].name;
		fout<<s[i].name<<"|";
		fout2<<s[i].name<<"|";
		cout<<"enter the rollno.of student\n";
		
	//	cout<<"k1   ==="<<k1<<endl;
		
		cin>>s[i].roll;
		k1=atoi(s[i].roll);
		temp[i][0]=k1;
		fout<<s[i].roll<<"|";
		fout2<<s[i].roll<<"#";
		cout<<"Enter the branch of student\n";
		cin>>s[i].branch;
		fout<<s[i].branch<<"#";
	}
	fout2.close();
	fout.close();
	fout1.close();
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(temp[j][0]>temp[j+1][0])
			{
				swap(temp[j][0],temp[j+1][0]);
				swap(temp[j][1],temp[j+1][1]);
			}
		}
	}
	cout<<"Enter the name to search the data\n";
	cin>>ch;
	ifstream fin1,fin,fin2;
     fin2.open("Secondary.txt");
    for(j=0;j<n;j++)
     {
     //	cout<<"QQ\n";
     	fin2.getline(ch1,10,'|');
     	fin2.getline(ch2,10,'#');
     	if(strcmp(ch1,ch)==0)
     	{
     		k2=atoi(ch2);
     		int ans =search(temp,k2,0,i-1);
     		if(ans!=-1)
     		{
     			fin.open("Student.txt");
     			fin.seekg(ans,ios::beg);
     			fin.getline(ch2,10,'|');
     			cout<<ch2<<"   \n";
     			fin.getline(ch2,10,'|');
     			cout<<ch2<<"   \n";
     			fin.getline(ch2,10,'#');
     			cout<<ch2<<"   \n";
     			break;
			 }
		 }
	 }
	
}
