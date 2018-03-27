#include<iostream>
using namespace std;
int h[500],size=0;
void perculatedown1(int j)
{

	if(size>=2*j+1)
	{
		if(h[j]>h[2*j+1]||h[j]>h[2*j])
		{
			if(h[j]>h[2*j+1]&&h[j]>h[2*j])
			{
				if(h[2*j]>h[2*j+1])
				{
					swap(h[j],h[2*j+1]);
					perculatedown(2*j+1);
				}
				else
				{
					swap(h[j],h[2*j]);
					perculatedown(2*j);
				}
			}
			else if(h[j]>h[2*j+1])
			{
				swap(h[j],h[2*j+1]);
				perculatedown(2*j+1);
			}
			else
			{
				swap(h[j],h[2*j]);
				perculatedown(2*j);
			}
		}
	}
	else if(size>=2*j)
	{
		if(h[j]>h[2*j])
		{
			swap(h[j],h[2*j]);
			perculatedown(2*j);
		}
	}
}

void perculatedown(int j)
{
	int temp1=INT_MAX,temp2=INT_MAX;
	if(size>=2*j&&h[j]>h[2*j])
	temp1=h[2*j];
	if(size>=2*j+1&&h[j]>h[2*j+1])
	temp2=h[2*j+1];
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
		if(h[j/2]>h[j])
		{
			swap(h[j/2],h[j]);	
		}
		perculateup(j/2);
	}
}
void insert(int key)
{
	size++;
	h[size]=key;
	perculateup(size);
	
}

void getmin()
{
	cout<<h[1]<<endl;
	h[1]=h[size];
	size--;
	perculatedown(1);
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
