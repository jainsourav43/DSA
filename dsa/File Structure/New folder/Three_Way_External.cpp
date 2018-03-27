#include<bits/stdc++.h>
using namespace std;
void mergefiles()
{
	    cout<<"Calling\n";
		ifstream fout1,fout2,fout6;
		ofstream fout3,fout4,fout5;
		int a[3],b[3],i,size,k1,k2,c=0,k3,check1,check2,check3;
		fout1.open("a1.txt");
		fout2.open("a2.txt");
		fout6.open("a3.txt");
		fout3.open("b1.txt");
		fout4.open("b2.txt");
		fout5.open("b3.txt");
		while(!fout1.eof()&&!fout2.eof()&&!fout6.eof())
		{
			i=0;
			fout1>>k1;
			fout2>>k2;
			fout6>>k3;
	    	if(fout1.eof()&&fout2.eof()&&fout6.eof())break;	
			check1=0;check2=0;check3=0;
			cout<<"lk1 ="<<k1<<"llk2 =  "<<k2<<" "<<" k3 = "<<k3<<endl;
		  if(c%3==0)
		  {
		  while(check1==0||check2==0||check3==0)
		  { cout<<"check1,check2,check3= "<<check1<<"  "<<check2<<"  "<<check3<<"  ";	
		  	cout<<"IN1\n";
		  	if(k2<k1&&k2<k3)
		  	{
		  		fout3<<k2<<" ";
		  		cout<<"K2= "<<k2<<endl;
		  		if(check1==0)
		  		fout2>>k2;
		  		else
		  		k2=INT_MAX;
		  		if(k2==-1)
		  		{ 
		  		check1=1;
				k2=INT_MAX;
				}
		  		if(fout1.eof()&&fout2.eof()&&fout6.eof())break;
				if(check1&&check2&&check3)break;
				}
			else if(k1<k2&&k1<k3)
			{
				fout3<<k1<<" ";cout<<"K1= "<<k1<<endl;
				if(check2==0)
				fout1>>k1;
				else
				k1=INT_MAX;
				if(k1==-1)
				{
		     	k1=INT_MAX;
				check2=1;	}
				if(check1&&check2&&check3)break;if(fout1.eof()&&fout2.eof()&&fout6.eof())break;	//cout<<"nk1 ="<<k1<<" "<<endl;
			}
			else if(k3<k1&&k3<k2)
			{
				fout3<<k3<<" ";cout<<"K3= "<<k3<<endl;
				if(check3==0)
				fout6>>k3;
				else
				k3=INT_MAX;
				if(k3==-1)
				{
				check3=1;
				k3=INT_MAX;	
				}
				if(check1&&check2&&check3)break;if(fout1.eof()&&fout2.eof()&&fout6.eof())break;
			}
		  }
		  fout3<<-1<<" ";
	    }
	      else if(c%3==1)
	      {
			while(check1==0||check2==0||check3==0)
		  {
		  	cout<<"IN2\n";
		  	if(k2<k1&&k2<k3)
		  	{
		  		fout4<<k2<<" ";cout<<"K2= "<<k2<<endl;
		  		if(check1==0)
		  		fout2>>k2;
		  		else
		  		k2=INT_MAX;
		  			if(k2==-1)
		  		{
				 
		  		check1=1;	k2=INT_MAX;}if(check1&&check2&&check3)break;if(fout1.eof()&&fout2.eof()&&fout6.eof())break;
				//cout<<"mk2 ="<<k2<<" "<<endl;
			}
			else if(k1<k2&&k1<k3)
			{
				fout4<<k1<<" ";cout<<"K1= "<<k1<<endl;
				if(check2==0)
				fout1>>k1;
				else
				k1=INT_MAX;
			if(k1==-1)
			{
			k1=INT_MAX;
			check2=1;	
			}
			if(check1&&check2&&check3)break;if(fout1.eof()&&fout2.eof()&&fout6.eof())break;	//cout<<"nk1 ="<<k1<<" "<<endl;
			}
			else if(k3<k1&&k3<k2)
			{
				fout4<<k3<<" ";cout<<"K3= "<<k3<<endl;
				if(check3==0)
				fout6>>k3;
				else
				k3=INT_MAX;
					if(k3==-1)
				{
			
				check3=1;
				k3=INT_MAX;	}if(check1&&check2&&check3)break;if(fout1.eof()&&fout2.eof()&&fout6.eof())break;
			}
		  }
		  fout4<<-1<<" ";
		}
		else if(c%3==2)
		{
		
			 while(check1==0||check2==0||check3==0)
     		{		cout<<"In3\n";  
			 cout<<"check1,check2,check3= "<<check1<<"  "<<check2<<"  "<<check3<<"  ";	
		  	if(k2<k1&&k2<k3)
		  	{
		  		fout5<<k2<<" ";cout<<"K2= "<<k2<<endl;
		  		if(check1==0)
		  		fout2>>k2;
		  		else
		  		k2=INT_MAX;
		  	if(k2==-1)
		  		{
		  		check1=1;	k2=INT_MAX;}if(check1&&check2&&check3)break;if(fout1.eof()&&fout2.eof()&&fout6.eof())break;
				//cout<<"mk2 ="<<k2<<" "<<endl;
			}
			else if(k1<k2&&k1<k3)
			{
				fout5<<k1<<" ";cout<<"K1= "<<k1<<endl;
				if(check2==0)
				fout1>>k1;
				else
				k1=INT_MAX;
					if(k1==-1)
				{
			k1=INT_MAX;
				check2=1;	}if(check1&&check2&&check3)break;if(fout1.eof()&&fout2.eof()&&fout6.eof())break;	//cout<<"nk1 ="<<k1<<" "<<endl;
			}
			else if(k3<k1&&k3<k2)
			{
				fout5<<k3<<" ";cout<<"K3= "<<k3<<endl;
				if(check3==0)
				fout6>>k3;
				else
				k3=INT_MAX;
				if(k3==-1)
				{
			
				check3=1;
				k3=INT_MAX;	}if(check1&&check2&&check3)break;if(fout1.eof()&&fout2.eof()&&fout6.eof())break;
			}
		  }
		  fout5<<-1<<" ";
		}
		c++;
	}
		cout<<"SP = "<<k1<<" ";
		while(!fout1.eof())
		{cout<<"CGV\n";
			if(c%3==0)
			{
				fout1>>k1;cout<<"Outside\n";	cout<<"SP 222= "<<k1<<" ";
				while(k1!=-1)
				{
					fout3<<k1<<" ";
					fout1>>k1;cout<<"tk1 ="<<k1<<" "<<endl;
				}
			}
			else if(c%3==1)
			{
			    fout1>>k1;
				while(k1!=-1)
				{
					fout4<<k1<<" ";
					fout1>>k1;cout<<"uk1 ="<<k1<<" "<<endl;	
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
		{cout<<"Xomocm\n";
			if(c%3==0)
			{
				fout2>>k2;
				while(k2!=-1)
				{
					fout3<<k2<<" ";
					fout2>>k2;cout<<"uk2 ="<<k2<<" "<<endl;
				}
			}
			else if(c%3==1)
			{
			     fout2>>k2;
				while(k2!=-1)
				{
					fout4<<k2<<" ";cout<<"vk2 ="<<k2<<" "<<endl;
					fout2>>k2;
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
		while(!fout6.eof())
		{cout<<"OIII\n";
			if(c%3==0)
			{
				fout6>>k2;
				while(k2!=-1)
				{
					fout3<<k2<<" ";
					fout6>>k2;cout<<"uk2 ="<<k2<<" "<<endl;
				}
			}
			else if(c%3==1)
			{
			     fout6>>k2;
				while(k2!=-1)
				{
					fout4<<k2<<" ";cout<<"vk2 ="<<k2<<" "<<endl;
					fout6>>k2;
				}
			}
			else
			{
				 fout6>>k2;
				while(k2!=-1)
				{
					fout5<<k2<<" ";cout<<"vk2 ="<<k2<<" "<<endl;
					fout6>>k2;
				}
			}
		}
		fout3.close();
		fout4.close();
		fout1.close();
		fout2.close();
		fout6.close();
		fout5.close();
		remove("a1.txt");
		remove("a2.txt");
		remove("a3.txt");
		rename("b1.txt","a1.txt");
		rename("b2.txt","a2.txt");
		rename("b3.txt","a3.txt");
}

void makepartition()
{
	ifstream fout;
	fout.open("inputfile.txt");
	ofstream fout1,fout2,fout3;
	fout1.open("a1.txt");
	fout2.open("a2.txt");
	fout3.open("a3.txt");
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
		if(c%3==0)
		{
			sort(a,a+size);
			for(i=0;i<size;i++)
			{
				fout1<<a[i]<<" ";
			}
			fout1<<-1<<" ";
		}
		else if(c%3==1)
		{
			sort(a,a+size);
			for(i=0;i<size;i++)
			{
				fout2<<a[i]<<" ";
			}
			fout2<<-1<<" ";
		}
		else if(c%3==2)
		{
			sort(a,a+size);
			for(i=0;i<size;i++)
			{
				fout3<<a[i]<<" ";
			}
			fout3<<-1<<" ";
		}
		c++;
	}
	fout.close();
	fout1.close();
	fout2.close();
	fout3.close();
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
		if(fout2.eof())
		{
			break;
		}fout2.close();
	}
	return 0;
}	
