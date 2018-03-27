#include<algorithm>
#include<vector>
#include<iostream>
#include<stdio.h>
#define ll long long
using namespace std;
typedef
struct link
{
	int data;
	link* next;
}
*lptr;
typedef
struct doub
{
	lptr first;
	lptr rare;
	bool enable;
}
*tptr;
struct check
{
	ll index;
	ll val;
};
void add_end(lptr& l,int key)
{
	l=new link;
	l->next=NULL;
	l->data=key;
}
bool wayto(const check &l,const check &r)
{
	return l.val>r.val;
}
int main()
{
	int n;
	int t;
	scanf("%d",&t);
	while(t--){
	scanf("%d",&n);
	vector <check> elements(n);
	doub *array=new doub[n];
	for(vector<check>::size_type i = 0;i<n;i++)
	{
		scanf("%lld",&elements[i].val);
		elements[i].index=i;
		array[i].first=array[i].rare=NULL;
	}
	for(vector<check>::size_type i = 0;i<n;i++)
	{
		array[i].enable=true;
	}

	sort(elements.begin(),elements.end(),wayto);

	for(ll i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d ",&a,&b);
		if(array[a-1].first)
			{
				add_end(array[a-1].rare->next,b-1);
				array[a-1].rare=array[a-1].rare->next;
			}
		else
		{
			add_end(array[a-1].rare,b-1);
			array[a-1].first=array[a-1].rare;
		}

		if(array[b-1].first)
		{
			add_end(array[b-1].rare->next,a-1);
			array[b-1].rare=array[b-1].rare->next;
		}
		else
		{
			add_end(array[b-1].rare,a-1);
			array[b-1].first=array[b-1].rare;
		}

	}
	for(ll i=0;i<n;i++)
	{
		lptr temp=array[i].first;
		while(temp)
		{
			array[temp->data].enable=false;
			temp=temp->next;
		}
		array[i].enable=false;

		vector<check>:: size_type j=0;

		for(j=0;j<n;j++ )
		{
			if(array[elements[j].index].enable)
			{
				cout<<elements[j].index+1<<endl;
				break;
			}
		}
		if(j==n)
			cout<<"0 "<<endl;
		temp=array[i].first;
		while(temp)
		{
			array[temp->data].enable=true;
			temp=temp->next;
		}
		array[i].enable=true;
	}
	cout<<"\n";
	}
	return 0;
}





