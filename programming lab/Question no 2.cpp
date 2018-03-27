#include<bits/stdc++.h>
using namespace std;
class operators
{
	private:
	int count[5];
	public :
    int getcount1()
    {
    	return count[0];
	}
	 int getcount2()
    {
    	return count[1];
	}
	 int getcount3()
    {
    	return count[2];
	}
	 int getcount4()
    {
    	return count[3];
	}
	 int getcount5()
    {
    	return count[4];
	}
	operators()
	{
		count[0]=0;
		count[1]=0;
		count[2]=0;
		count[3]=0;
		count[4]=0;
	}
	void set(int j)
	{
		for(int i=0;i<5;i++)
		{
			count[i]=j;
		}
	}
	void countopr(fstream &fout)
	{
		char opr;
		while(!fout.eof())
		{
			fout>>opr;
			if(opr=='=')
			{
				count[0]++;
			}
			else if(opr=='!')
			{
				count[1]++;
			}
			else if(opr=='|')
			{
				count[2]++;
			}
			else if(opr=='&')
			{
				count[3]++;
			}
			else if(opr=='>')
			{
				count[4]++;
			}
		}
		int max=0,in=0;
		for(int i=0;i<5;i++)
		{
			if(count[i]>max)
			{
				max=count[i];
				in =i;
			}
		}
		cout<<"The max no of times appear the operator at   "<<in<<  "  th index of opr \n";
		cout<<"Max = "<<max<<endl;
	}
};
int main()
{
	fstream fin;
	fin.open("ram.cpp");
	operators obj1;
	obj1.countopr(fin);
}

