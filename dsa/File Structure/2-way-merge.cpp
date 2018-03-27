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

void merge(ifstream &ifile1,ifstream &ifile2,ofstream &ofile,int &pos1,int &pos2,int &pos3)
{
	
	 if(pos1<0 || pos2<0 || pos3<0) return;
	 ifile1.seekg(pos1, ios::beg);
	 ifile2.seekg(pos2, ios::beg);
	 ofile.seekp(pos3, ios::beg);
	 int k1,k2;
	 ifile1>>k1;
	 ifile2>>k2;
	 while(k1!=-1 && k2!=-1)
	 {

		 if(ifile1.eof() || ifile2.eof()) break;
	 	 if(k1<k2)
		 {
		 	ofile<<k1<<' ';
		 	ifile1>>k1;
		 }	
		 else
		 {
		 	ofile<<k2<<' ';
		 	ifile2>>k2;
		 }
	 }
	 while(k1!=-1 && !ifile1.eof())
	 {
	 	ofile<<k1<<' ';
	 	ifile1>>k1;
	 }
	 while(k2!=-1 && !ifile2.eof())
	 {
	 	ofile<<k2<<' ';
	 	ifile2>>k2;
	 }
	 ofile<<-1<<' ';
	 pos1 = ifile1.tellg();
	 pos2 = ifile2.tellg();
	 pos3 = ofile.tellp();
	 
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
		count++;
		ifile1>>k1;
		ifile2>>k2;
		if(ifile1.eof() || ifile2.eof()) break;
		ifile1.seekg(p1,ios::beg);
		ifile2.seekg(p2,ios::beg);
		
		if(f==true)
			merge(ifile1,ifile2,ofile1,p1,p2,p3);
		
		else
			merge(ifile1,ifile2,ofile2,p1,p2,p4);
		
		f=f^true;
	}
	
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
	
	ifile1.close();
	ifile2.close();
	ofile1.close();
	ofile2.close();
	
	if(count<2) return;
	twoWayMerge(flag^true);
}

int main()
{
	ifstream dfile;
	dfile.open("DataFile.txt");
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

