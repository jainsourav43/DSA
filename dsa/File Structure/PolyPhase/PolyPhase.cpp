#include<bits/stdc++.h>
using namespace std;
int findmin(int a,int b,int c)
{
	if(a==-1)
	a=10000;
	if(b==-1)
	b=1000;
	if(c==-1)
	c=1000;
	if(a<b&&a<c)
	{
		return a;
	}
	else if(b<a&&b<c)
	{
		return b;
	}
	else if(c<a&&c<b)
	{
		return c;
	}
}
void merge(int a[],int b[],int c[],ofstream &fout)
{
	cout<<"CALLING\n";
	int i=0;int j=0;int k=0,mi;
	while(a[i]!=-1||b[j]!=-1||c[k]!=-1)
	{
		mi=findmin(a[i],b[j],c[k]);
		fout<<mi<<" ";
		if(mi==a[i])
		{
			i++;
		}
		else if(mi==b[j])
		{
			j++;
		}
		else if (mi==c[k])
		{
		    k++;
		}
	}
}
int polyphase(ifstream &fin1,ifstream &fin2,ifstream &fin3)
{
	ofstream fout1;int check=0;
	fout1.open("f4.txt");
	int a[40],b[40],c[40],i,j,k;
	while(!fin1.eof()&&!fin2.eof()&&!fin3.eof())
	{
	    check=0;
		i=0;j=0;k=0;
		while(!fin1.eof())
		{
		fin1>>a[i];
		i++;	
		if(!fin1.eof())
		check=1;
		if(a[i-1]==-1)
		{
			break;
		}
	    }
	    while(1&&!fin2.eof())
	    {
		fin2>>b[j];
		j++;
		if(!fin2.eof())	
		check=1;
		if(b[j-1]==-1)
		break;
	    }
	    while(1&&!fin3.eof())
	    {
		fin3>>c[k];
		k++;	
		if(!fin3.eof())
		check=1;
		if(c[k-1]==-1)
		{
			break;
		}
	    }
	    if(check==1)
	    {
	    merge(a,b,c,fout1);
	    fout1<<-1<<" ";
	    }
	}
	fout1.close();
	if(fin1.eof())
	{	
	    fin1.close();
	    remove("f1.txt");
		rename("f4.txt","f1.txt");
		return 1;
	
	}
	if(fin2.eof())     
	{	
	    fin2.close();
	    remove("f2.txt");
		rename("f4.txt","f2.txt");
	    return 2;
	}
	if(fin3.eof())
	{
		cout<<"Entwrr\n";
		fin3.close();
		remove("f3.txt");
		rename("f4.txt","f3.txt");
        return 3;
	}
}
int main()
{
	int i;
	ifstream fin1,fin2,fin3;
	fin1.open("f1.txt");
	fin2.open("f2.txt");
	fin3.open("f3.txt");
	int t=2;
	ofstream fout;
	while(1)
    {
    	int check =polyphase(fin1,fin2,fin3);
    	if(fin1.eof()&&fin2.eof())
    	break;
    	if(check==1)
    	{
    		fin1.open("f1.txt");
		}
		if(check==2)
    	{
    		fin2.open("f2.txt");
		}
		if(check==3)
    	{
    		fin3.open("f3.txt");
		}
	}
}
