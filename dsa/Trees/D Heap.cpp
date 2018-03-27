#include<iostream>
#define max 100
using namespace std;
int g,d;
void swap(int &k1,int &k2)
{
	int temp;
	temp=k1;
	k1=k2;
	k2=temp;
}
void insert(int h[],int k,int &s)
{
	int i,j;
	if(s<max)
	{
    s++;
    h[s]=k;
    j=s;
    while(j>1&&h[(j+d-2)/d]>h[j])
    {
    	//if(h[(j+(d-2))/d]>h[j])
    	//{
    		swap(h[(j+d-2)/d],h[j]);	
    //	}
    	j=(j+d-2)/d;
    }
   }
}
void heapsort(int h[],int &s)
{
	int min,in,i;
	if(s>=1)
	{
	cout<<h[1]<<"  ";
	h[1]=h[s];
	int j=1;
	s--;
	if(s>=j+1)
	{
		while(d*j+2-d<=s)
		{
		min=h[d*j+2-d];in=d*j+2-d;
		for(i=d*j+2-d;i<d*j+2&&i<=s;i++)
		{
			if(min>h[i])
			{
				min=h[i];
				in=i;
			}
			
		}
		if(h[j]<min)
		{
			break;
		}
		swap(h[j],h[in]);
		j=in;
	    }
	}
		//perculatedown(h,s,j);
			heapsort(h,s);
	}

}
int main()
{
	cout<<"Please enter the Dimension of the heap otherwise Fuckoff :   ";
	cin>>d;
	int h[max],i;
	int s=0,k=1,j;
	while(k!=-1)
	{
	cout<<"Enter the  number to enter  else -1\n";
	cin>>k;
	if(k!=-1)
	{ 
	insert(h,k,s); 
    }
    }
    for(int i=1;i<=s;i++)
    {
    	cout<<h[i]<<"   ";
	}cout<<endl;
	cout<<"Heapsort \n";
    heapsort(h,s);
} 
