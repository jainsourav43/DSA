#include<iostream>
#include<queue>
using namespace std;
struct tsort;
struct list{
	struct tsort* id;
	struct list* next;
} ;
typedef struct tsort{
	int key;
	int count;
	struct tsort* next;
	struct list* trail;
	
} *TPTR;
void createList(TPTR &T,int k)
{
	T = new struct tsort;
	T->key = k;
	cout<<"\nEnter count for "<<k<<": ";
	cin>>T->count;
	T->next = NULL;
	cout<<"\nEnter key: ";
	cin>>k;
	if(k!=-1)
	createList(T->next,k);
	
}

TPTR search(TPTR T,int k)
{
	while(T!=NULL)
	{
		if(T->key==k)
		{
			return T;
		}
		T=T->next;
	}
	return NULL;
}

void inputTrail(TPTR R,TPTR &T)
{
	if(T!=NULL)
	{
		cout<<"\nEnter id for "<<T->key<<": (-1 to stop) ";
		int k;
		cin>>k;
		T->trail = new struct list;
		if(k!=-1)
		{
			T->trail->id = search(R,k);
			T->trail->next = NULL;
		
		struct list* tmp = T->trail;
		while(1)
		{
			cout<<"\nEnter next id for "<<T->key<<": (-1 to stop) ";
			cin>>k;
			if(k==-1)
			break;
			tmp->next = new struct list;
			tmp = tmp->next;
			tmp->id = search(R,k);
			tmp->next = NULL;
		}
		}
		else
		T->trail = NULL;
		inputTrail(R,T->next);
	}
}
queue<TPTR> q;

bool checkCount(TPTR T)
{
	while(T)
	{
		if(T->count>=0)
		return false;
	}
	return true;
}

queue<TPTR> Q;
void traverse(TPTR T)
{
	TPTR tmp = T;
	TPTR N = new struct tsort;
	N->key = -1;
	N->count = -1;
	while(tmp)
	{
		if(tmp->count==0)
		q.push(tmp);
		tmp = tmp->next;
	}
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		cout<<tmp->key<<" ";
		struct list* trl = tmp->trail;
		while(trl)
		{
			trl->id->count--;
			if(trl->id->count==0)
			{
			q.push(trl->id);
			}
			trl = trl->next;
		}
	}
}

int main()
{
	TPTR T = NULL;
	int k;
	cout<<"Enter key: ";
	cin>>k;
	T = new struct tsort;
	T->key = k;
	cout<<"\nEnter count for "<<k<<": ";
	cin>>T->count;
	T->next = NULL;
	cout<<"Enter key: ";
	cin>>k;
	createList(T->next,k);
	TPTR R = new struct tsort;
	R = T;
	inputTrail(R,T);
	traverse(T);
	return 0;
}
