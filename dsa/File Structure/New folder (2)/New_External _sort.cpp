#include<bits/stdc++.h>
using namespace std;
//int merge(int a[],int b[],ofstream  &fout)
//{
//	int i=0.int j=0
// while(a[i]!=INT_MAX&&b[j]!=INT_MAX&&i<3&&j<3)
// {
// 	if(a[i]<b[j])
// 	{
// 		fout<<a[i]<<" ";
// 		a[i]=INT_MAX;
// 		i++;
//	 }
//	 else if(a[i]>b[j])
//	 {
//	 	fout<<b[j]<<" ";
//	 	b[j]=INT_MAX;
//	 	j++;
//	 }
// }	
//    sort(a,a+3);	
//    sort(b,b+3);
//}
//void  merge()
//{
//	int i;
//	ifstream fout1,fout2;
//	ofstream fout3,fout4;
//	int size,k1,k2,c=0,ab[3];
//	fout1.open("a1.txt");
//	fout2.open("a2.txt");
//	fout3.open("b1.txt");
//	fout4.open("b2.txt");
//	int count1=0,count2=0,count3=0,count4=0,j;
//	while(!fout1.eof()&&!fout2.eof())
//	{
//		int a[3]={INT_MAX},b[3]={INT_MAX};
//	  i=0;j=0;
//	  fout1>>k1;
//	  fout2>>k2;
//	  while(1)
//	  {
//	  	if(c%2==0)
//	  	{	
//		 if(k1==-1 || k2==-1)
//		 {
//		 	int p=0;
//		 	while(p<4 && b[p]!=INT_MAX)
//		 	{
//		 		<<b[p++]<<' ';	
//			}
//			p=0;
//			while(p<4 && a[p]!=INT_MAX)
//		 	{
//		 		ofile<<a[p++]<<' ';	
//			}
//		 	break;
//		 }
//		 
//		 for(int i=0;i<4 && k1!=-1;i++)
//		 {
//		 	if(a[i]!=INT_MAX) continue;
//		 	a[i] = k1;
//		 	ifile1>>k1;
//		 }
//		 for(int i=0;i<4 && k2!=-1;i++)
//		 {
//		 	if(b[i]!=INT_MAX) continue;
//		 	b[i] = k2;
//		 	ifile2>>k2;
//		 }
//	    }
//	  else
//	  {
//	  	if(i<3)
//	  	{
//	  	fin>>a[i];
//	  	i++;
//  		fin>>b[j];
//    	j++;
//    	if(a[i-1]==-1&&b[i-1]==-1)
//    	{
//    		c++;
//    		break;
//		}
//	    }
//	    else
//	    {
//	    	check=merge(a,b,fout3);
//	    	i=0;j=0;
//		}
//	  }
//	  }		
//	}
//}
//void mergefiles()
//{
//	
//}
void mergefiles()
{
	    //cout<<"Calling\n";
		ifstream fout1,fout2;
		ofstream fout3,fout4;
		int a[3],b[3],i,size,k1,k2,c=0,ab[3];
		fout1.open("a1.txt");
		fout2.open("a2.txt");
		fout3.open("b1.txt");
		fout4.open("b2.txt");
		while(!fout1.eof()&&!fout2.eof())
		{
			i=0;
			fout1>>k1;
			fout2>>k2;	
		  if(c%2==0)
		  {
		  while(k1!=-1&&k2!=-1)
		  {
		  	if(k1>k2)
		  	{
		  		fout3<<k2<<" ";
		  		fout2>>k2;
			//	cout<<"mk2 ="<<k2<<" "<<endl;
			}
			else
			{
				fout3<<k1<<" ";
				fout1>>k1;//	cout<<"nk1 ="<<k1<<" "<<endl;
			}
		  }
		  if(k2==-1&&k1!=-1)
		  while(k1!=-1)
		  {
		  	fout3<<k1<<" ";	//cout<<" sp k1 ="<<k1<<" "<<endl;
		  	fout1>>k1;
		  }
		  if(k1==-1&&k2!=-1)
		  while(k2!=-1)
		  {
		  	fout3<<k2<<" ";
		  	fout2>>k2;//cout<<"SPecial\n";
		  }
		  fout3<<-1<<" ";
	      }
	      else
	      {
		//	cout<<"ok1 ="<<k1<<"ok2 =  "<<k2<<" "<<endl;
	      	while(k1!=-1&&k2!=-1)
		   {
		  	if(k1>k2)
		  	{
		  		fout4<<k2<<" ";
		  		fout2>>k2;//cout<<"pk2 ="<<k2<<" "<<endl;
			}
			else
			{
				fout4<<k1<<" ";
				fout1>>k1;//cout<<"sk1 ="<<k1<<" "<<endl;
			}
		  }
		  //fout1>>k1;
		  if(k1!=-1&&k2==-1)
		  while(k1!=-1)
		  {
		  	fout4<<k1<<" ";
		  	fout1>>k1;//cout<<"qk1 ="<<k1<<" "<<endl;
		  }
		  if(k2!=-1&&k1==-1)
		  while(k2!=-1)
		  {
		  	fout4<<k2<<" ";
		  	fout2>>k2;//cout<<"rk2 = "<<k2<<" "<<endl;
		  }
		  fout4<<-1<<" ";
		  }
		  c++;
		}
		//cout<<"SP = "<<k1<<" ";
		while(!fout1.eof())
		{
			if(c%2==0)
			{
				fout1>>k1;//cout<<"Outside\n";	cout<<"SP 222= "<<k1<<" ";
				while(k1!=-1)
				{
					fout3<<k1<<" ";
					fout1>>k1;//cout<<"tk1 ="<<k1<<" "<<endl;
				}
			}
			else
			{
			    fout1>>k1;
				while(k1!=-1)
				{
					fout4<<k1<<" ";
					fout1>>k1;cout<<"uk1 ="<<k1<<" "<<endl;
				
			}
		
		}
	}
		while(!fout2.eof())
		{
			if(c%2==0)
			{
				fout2>>k2;
				while(k2!=-1)
				{
					fout3<<k2<<" ";
					fout2>>k2;//cout<<"uk2 ="<<k2<<" "<<endl;
				}
			}
			else
			{
			     fout2>>k2;
				while(k2!=-1)
				{
					fout4<<k2<<" ";//cout<<"vk2 ="<<k2<<" "<<endl;
					fout2>>k2;
				}
			}
		}
		fout3.close();
		fout4.close();
		fout1.close();
		fout2.close();
		remove("a1.txt");
		remove("a2.txt");
		rename("b1.txt","a1.txt");
		rename("b2.txt","a2.txt");
}
void makepartition1()
{
	ifstream fout;
	fout.open("inputfile.txt");int k=0;
	ofstream fout1,fout2;
	fout1.open("a1.txt");
	fout2.open("a2.txt");
	int c=0,size,i,a[3],r[3];
	fout>>r[0]>>r[1]>>r[2];
	sort(r,r+3);
	fout1<<r[0]<<" ";
	//cout<<"jo ="<<r[0]<<endl;
	while(!fout.eof())
	{
		size=0;
		k=r[0];
		fout>>r[0];
	//	cout<<"mo ="<<r[0]<<endl;
		if(c%2==0)
		{
			if(r[0]<k)
			{
				fout1<<r[1]<<" ";
				fout1<<r[2]<<" ";
				if(!fout.eof())
				fout>>r[1];
				if(!fout.eof())
				fout>>r[2];
			//	cout<<"po  = "<<r[2]<<" "<<r[1]<<endl;
				sort(r,r+3);
				fout2<<r[0]<<" ";
				if(fout.eof())
				fout2<<-1<<" ";
				fout1<<-1<<" ";
				c++;
			}
			else
			{
			sort(r,r+3);
			fout1<<r[0]<<" ";
			if(fout.eof())
			{
		    fout1<<r[1]<<" "<<r[2]<<" ";
		    fout1<<-1<<" ";
		   }
		    }
		}
		else
		{
			if(r[0]<k)
			{
				fout2<<r[1]<<" ";
				fout2<<r[2]<<" ";
				fout>>r[1];
				fout>>r[2];	//cout<<"qo  = "<<r[2]<<" "<<r[1]<<endl;
				sort(r,r+3);
				fout1<<r[0]<<" ";
				if(fout.eof())
				fout1<<-1<<" ";
				fout2<<-1<<" ";
				c++;
			}
			else
			{
			sort(r,r+3);
			fout2<<r[0]<<" ";
			if(fout.eof())
			{
			fout2<<r[1]<<" "<<r[2]<<" ";
			fout2<<-1<<" ";
		    }
		    }
	    }
	}
	fout.close();
	fout1.close();
	fout2.close();
}
void makepartition()
{
	ifstream fout;
	fout.open("inputfile.txt");
	ofstream fout1,fout2;
	fout1.open("a1.txt");
	fout2.open("a2.txt");
	int c=0,size,i,a[3];
	while(!fout.eof())
	{
		size=0;
		for(i=0;i<3&&!fout.eof();i++)
		{
			fout>>a[i];
			size++;
			cout<<a[i]<<"  ";
		}
		if(c%2==0)
		{
			sort(a,a+size);
			for(i=0;i<size;i++)
			{
				fout1<<a[i]<<" ";
			}
			fout1<<-1<<" ";
		}
		else
		{
			sort(a,a+size);
			for(i=0;i<size;i++)
			{
				fout2<<a[i]<<" ";
			}
			fout2<<-1<<" ";
		}
		c++;
	}
	fout.close();
	fout1.close();
	fout2.close();
}
int main()
{
	remove("a1.txt");
	remove("a2.txt");
	remove("b1.txt");
	remove("b2.txt");
	makepartition1();
	int k;
	ifstream fout1,fout2;
	//fout1.open("a1.txt");
	//fout2.open("a2.txt");
	int t=2;
//	while(1)
//	{
//		mergefiles();
//		fout2.open("a2.txt");
//		fout2>>k;
//		fout2.close();
//		if(k==-1)
//		{
//			break;
//		}
//	}
	cout<<"CHECK FILE a1.txt for OUTPUT \n";
	return 0;
}
