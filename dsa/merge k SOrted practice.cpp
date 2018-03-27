#include<iostream>
#include<iostream>
using namespace std;
int size=0;
struct heap
{
	int el;
	int in;
	int jn;
};
heap h[500];
//void perculatedown1(int j)
//{
//
//	if(size>=2*j+1)
//	{
//		if(h[j]>h[2*j+1]||h[j]>h[2*j])
//		{
//			if(h[j]>h[2*j+1]&&h[j]>h[2*j])
//			{
//				if(h[2*j]>h[2*j+1])
//				{
//					swap(h[j],h[2*j+1]);
//					perculatedown(2*j+1);
//				}
//				else
//				{
//					swap(h[j],h[2*j]);
//					perculatedown(2*j);
//				}
//			}
//			else if(h[j]>h[2*j+1])
//			{
//				swap(h[j],h[2*j+1]);
//				perculatedown(2*j+1);
//			}
//			else
//			{
//				swap(h[j],h[2*j]);
//				perculatedown(2*j);
//			}
//		}
//	}
//	else if(size>=2*j)
//	{
//		if(h[j]>h[2*j])
//		{
//			swap(h[j],h[2*j]);
//			perculatedown(2*j);
//		}
//	}
//}

void perculatedown(int j)
{
	int temp1=INT_MAX,temp2=INT_MAX;
	if(size>=2*j&&h[j].el>h[2*j].el)
	temp1=h[2*j].el;
	if(size>=2*j+1&&h[j].el>h[2*j+1].el)
	temp2=h[2*j+1].el;
	if(temp1<temp2)
	{
		swap(h[j],h[2*j]);
		perculatedown(2*j);
	}
	else if(temp1>temp2)
	{
		swap(h[j],h[2*j+1]);
		perculatedown(2*j+1);
	}
	
}
void perculateup(int j)
{
		//cout<<"perculate down\n";
	if(j>1)
	{
		if(h[j/2].el>h[j].el)
		{
			swap(h[j/2],h[j]);	
			perculateup(j/2);
		}
	
	}
}
void insert(heap key)
{
	size++;
	h[size]=key;
	perculateup(size);
	
}

heap getmin()
{
	//cout<<h[1]<<endl;
	heap temp=h[1];
	h[1]=h[size];
	size--;
	perculatedown(1);
	return temp;
}
int *mergeKArrays(int a[][3],int k)
{
	int i;
	heap temp;
	int n=10;
	for(i=0;i<k;i++)
	{
		temp.el=a[i][0];
		temp.in=i;
		temp.jn=1;
		insert(temp);
	}
	int output[n*k+1];
	int count=n*k;
	heap temp2;
	for(i=0;i<count;i++)
	{
		temp=getmin();
		output[i]=temp.el;
		if(temp.jn<n)
		{
			temp2.el=a[temp.in][temp.jn];
			temp2.in=temp.in;
			temp2.jn=temp.jn+1;
			
		}
		else
		{
			temp2.el=INT_MAX;
			temp2.in=temp.in;
			temp2.jn=temp.jn+1;
			
		}
		insert(temp2);
		
		
	}
	
	
	return output;
}
int main()
{
	int key;
	while(1)
	{
		cout<<"Enter the keyto insert else -1\n";
		cin>>key;
		if(key==-1) break;
		insert(key);
	}
	cout<<"Heap sort\n";
	while(size>=1)
	{
		
		getmin();
	}
	
}
