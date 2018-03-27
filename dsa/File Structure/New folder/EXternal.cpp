#include<bits/stdc++.h>
using namespace std;
void mergefiles()
{
	cout<<"Calling\n";
		ifstream fout1,fout2;
		ofstream fout3,fout4;
		int a[3],b[3],i,size,k1,k2,c=0;
		fout1.open("a1.txt");
		fout2.open("a2.txt");
		fout3.open("b1.txt");
		fout4.open("b2.txt");
		while(!fout1.eof()&&!fout2.eof())
		{
			i=0;
			fout1>>k1;
			fout2>>k2;
			cout<<"lk1 ="<<k1<<"llk2 =  "<<k2<<" "<<endl;
		  if(c%2==0)
		  {
		  while(k1!=-1&&k2!=-1)
		  {
		  	if(k1>k2)
		  	{
		  		fout3<<k2<<" ";
		  		fout2>>k2;
				cout<<"mk2 ="<<k2<<" "<<endl;
			}
			else
			{
				fout3<<k1<<" ";
				fout1>>k1;	cout<<"nk1 ="<<k1<<" "<<endl;
			}
		  }
		  if(k2==-1&&k1!=-1)
		  while(k1!=-1)
		  {
		  	fout3<<k1<<" ";	cout<<" sp k1 ="<<k1<<" "<<endl;
		  	fout1>>k1;
		  }
		  if(k1==-1&&k2!=-1)
		  while(k2!=-1)
		  {
		  	fout3<<k2<<" ";
		  	fout2>>k2;cout<<"SPecial\n";
		  }
		  fout3<<-1<<" ";
	      }
	      else
	      {
			cout<<"ok1 ="<<k1<<"ok2 =  "<<k2<<" "<<endl;
	      	while(k1!=-1&&k2!=-1)
		   {
		  	if(k1>k2)
		  	{
		  		fout4<<k2<<" ";
		  		fout2>>k2;cout<<"pk2 ="<<k2<<" "<<endl;
			}
			else
			{
				fout4<<k1<<" ";
				fout1>>k1;cout<<"sk1 ="<<k1<<" "<<endl;
			}
		  }
		  //fout1>>k1;
		  if(k1!=-1&&k2==-1)
		  while(k1!=-1)
		  {
		  	fout4<<k1<<" ";
		  	fout1>>k1;cout<<"qk1 ="<<k1<<" "<<endl;
		  }
		  if(k2!=-1&&k1==-1)
		  while(k2!=-1)
		  {
		  	fout4<<k2<<" ";
		  	fout2>>k2;cout<<"rk2 = "<<k2<<" "<<endl;
		  }
		  fout4<<-1<<" ";
		  }
		  c++;
		}
		cout<<"SP = "<<k1<<" ";
		while(!fout1.eof())
		{
			if(c%2==0)
			{
				fout1>>k1;cout<<"Outside\n";	cout<<"SP 222= "<<k1<<" ";
				while(k1!=-1)
				{
					fout3<<k1<<" ";
					fout1>>k1;cout<<"tk1 ="<<k1<<" "<<endl;
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
					fout2>>k2;cout<<"uk2 ="<<k2<<" "<<endl;
				}
			}
			else
			{
			     fout2>>k2;
				while(k2!=-1)
				{
					fout4<<k2<<" ";cout<<"vk2 ="<<k2<<" "<<endl;
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
	makepartition();int k;
	ifstream fout1,fout2;
	//fout1.open("a1.txt");
	//fout2.open("a2.txt");
	int t=2;
	while(1)
	{
		mergefiles();
		//fout1.open("a1.txt");
		fout2.open("a2.txt");
		fout2>>k;
		fout2.close();
		if(k==-1)
		{
			break;
		}
	}
	return 0;
}
