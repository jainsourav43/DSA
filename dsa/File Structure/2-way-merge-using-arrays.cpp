#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

void initialize(int A[4])
{
	for(int i=0;i<4;i++)
		A[i] = INT_MAX;
}

void put(ofstream &file, int A[4], int pos)
{
	file.seekp(pos,ios::beg);
	for(int i=0;i<4;i++)
	{
		if(A[i] == INT_MAX) break;
		file<<A[i]<<' ';
	}
	file<<-1<<' ';
}

void make_partitions(ifstream &dfile, ofstream &fileA, ofstream &fileB)
{
	int A[4];
	bool f = true;
	initialize(A);
	int k=0;
	dfile>>k;
	while(k!=-1)
	{
		for(int i=0;i<4 && k!=-1;i++)
		{
			A[i] = k;
			dfile>>k;
		}
		sort(A,A+4);
		if(f==true)
		{
			put(fileA , A, fileA.tellp());
			f = false;
		}
		else
		{
			put(fileB , A, fileB.tellp());
			f = true;
		}
		initialize(A);
	}
}

void mergeArrays(int a[4],int b[4],ofstream& ofile)
{
	int i=0,j=0;
	for(i=0,j=0;i<4 && j<4;)
	{
		if(a[i]==INT_MAX || b[j]==INT_MAX) break;
		if(a[i]<b[j])
		{
			ofile<<a[i]<<' ';
			a[i] = INT_MAX;
			i++;
		}
		else
		{
			ofile<<b[j]<<' ';
			b[j] = INT_MAX;
			j++;
		}
	}
	sort(a,a+4);
	sort(b,b+4);

}

void merge(ifstream &ifile1,ifstream &ifile2,ofstream &ofile)
{
	 int k1,k2;
	 int a[4],b[4];
	 initialize(a);
	 initialize(b);
	 ifile1>>k1;
	 ifile2>>k2;
	 while(1)
	 {
			
		 if(k1==-1 || k2==-1)
		 {
		 	int p=0;
		 	while(p<4 && b[p]!=INT_MAX)
		 	{
		 		ofile<<b[p++]<<' ';	
			}
			p=0;
			while(p<4 && a[p]!=INT_MAX)
		 	{
		 		ofile<<a[p++]<<' ';	
			}
		 	break;
		 }
		 
		 for(int i=0;i<4 && k1!=-1;i++)
		 {
		 	if(a[i]!=INT_MAX) continue;
		 	a[i] = k1;
		 	ifile1>>k1;
		 }
		 for(int i=0;i<4 && k2!=-1;i++)
		 {
		 	if(b[i]!=INT_MAX) continue;
		 	b[i] = k2;
		 	ifile2>>k2;
		 }
		 mergeArrays(a,b,ofile);
	 }
	 
	 while(k1!=-1)
	 {
	 	ofile<<k1<<' ';
	 	ifile1>>k1;
	 }
	 while(k2!=-1)
	 {
	 	ofile<<k2<<' ';
	 	ifile2>>k2;
	 }
	 ofile<<-1<<' ';
}

bool isEmpty(ofstream& ofile)
{
	ofile.seekp(0,ios::end);
	if(ofile.tellp()==0) return true;
	else return false;
}

void twoWayMerge(bool flag)
{
	ifstream ifile1,ifile2;
	ofstream ofile1,ofile2;
	if(flag==true)
	{
		ifile1.open("A.txt");
		ifile2.open("B.txt");
		ofile1.open("C.txt",ios::trunc);
		ofile2.open("D.txt",ios::trunc);
	}
	else
	{
		ifile1.open("C.txt");
		ifile2.open("D.txt");
		ofile1.open("A.txt",ios::trunc);
		ofile2.open("B.txt",ios::trunc);
	}
	int count=0,p1=ifile1.tellg(),p2=ifile2.tellg(),p3=0,p4=0,k1,k2;
	bool f=true;
	while(1)
	{
		p1 = ifile1.tellg();
		p2 = ifile2.tellg();
		ifile1>>k1;
		ifile2>>k2;
		if(ifile1.eof() || ifile2.eof()) break;
		ifile1.seekg(p1,ios::beg);
		ifile2.seekg(p2,ios::beg);
		
		if(f==true)
			merge(ifile1,ifile2,ofile1);
		
		else
			merge(ifile1,ifile2,ofile2);
		
		f=f^true;
		count++;
	}
	if(!ifile1.eof() || !ifile2.eof()) count++;
	while(!ifile1.eof())
	{
		if(f==true) ofile1<<k1<<' ';
		else ofile2<<k1<<' ';
		ifile1>>k1;	
	}
	
	while(!ifile2.eof())
	{
		if(f==true) ofile1<<k2<<' ';
		else ofile2<<k2<<' ';
		
		ifile2>>k2;
	}
	
	if(isEmpty(ofile1) || isEmpty(ofile2)) return;
	
	ifile1.close();
	ifile2.close();
	ofile1.close();
	ofile2.close();
	
	twoWayMerge(flag^true);
}

int main()
{
	ifstream dfile;
	dfile.open("DataFile2.txt");
	ofstream fileA,fileB;
	fileA.open("A.txt");
	fileB.open("B.txt");
	make_partitions(dfile,fileA,fileB);
	
	dfile.close();
	fileA.close();
	fileB.close();

	int flag = true;
	twoWayMerge(flag);
	ofstream ofile1,ofile2;
	if(flag==false)
	{
		ofile1.open("A.txt",ios::trunc);
		ofile2.open("B.txt",ios::trunc);
	}
	else
	{
		ofile1.open("C.txt",ios::trunc);
		ofile2.open("D.txt",ios::trunc);	
	}
	ofile1.clear();
	ofile2.clear();
	ofile1.close();
	ofile2.close();

	return 0;
}

