#include<iostream>
using namespace std;

struct leafNode{
	string str;
};

typedef struct branchNode{
	union NodePtr{
		branchNode** branch_ptr;
		leafNode* leaf_ptr;
	} np;
	int tag;
	branchNode* parent;
	int count;
} *TPTR;

int n;

void initialize(TPTR *ptr)
{
	
	for(int i=0;i<=n;i++)
		ptr[i]=NULL;
}

TPTR createNew(TPTR &T,int tag)
{
	if(tag==1)
	{
		T->tag = 1;
		T->np.branch_ptr = new TPTR[n+1];
		initialize(T->np.branch_ptr);
	}	
	else
	{
		T->tag = 0;
		T->np.leaf_ptr = new leafNode;
	}
	return T;
}

int findIndex(string str,int i,char* cs)
{
	if(i>=str.length()) return n;
	char ch = str[i];
	for(int j=0;j<n;j++)
	{
		if(cs[j]==ch)
		return j;
	}
}

string getStr(TPTR T)
{
	if(T->tag==0)
	return T->np.leaf_ptr->str;
	for(int i=0;i<=n;i++)
	{
		if(T->np.branch_ptr[i]!=NULL)
		return getStr(T->np.branch_ptr[i]);
	}
}

int numOfSameChars(string s1,string s2)
{
	for(int i=0;i<s1.length()&&i<s2.length();i++)
	{
		if(s1[i]!=s2[i])
		return i;
	}
	
	return min(s1.length(),s2.length());
}

void insert(TPTR &trie,string s,int ind,char* cs)
{
	if(trie->np.branch_ptr[ind]==NULL)
	{
		trie->np.branch_ptr[ind] = new branchNode;
		TPTR tmp = new branchNode;
		tmp = createNew(trie->np.branch_ptr[ind],0);
		tmp->np.leaf_ptr->str = s;
	}
	else
	{
		TPTR child = trie->np.branch_ptr[ind];
		if(child->tag==0)
		{
			string ostr = child->np.leaf_ptr->str;
			int k = numOfSameChars(s,child->np.leaf_ptr->str);
			TPTR tmp = new branchNode;
			tmp = createNew(child,1);
			tmp->count=k+1;
			
			int i1=findIndex(s,k,cs);
			TPTR newChild = tmp->np.branch_ptr[i1];
			tmp->np.branch_ptr[i1] = new branchNode;
			newChild = createNew(tmp->np.branch_ptr[i1],0);
			newChild->np.leaf_ptr->str = s;
			
			int i2=findIndex(ostr,k,cs);
			tmp->np.branch_ptr[i2] = new branchNode;
			TPTR t2 = createNew(tmp->np.branch_ptr[i2],0);
			t2->np.leaf_ptr->str = ostr;
		}
		else
		{
			string tmpstr = getStr(child);
			int k = numOfSameChars(s,tmpstr);
			if(k>=child->count-1)
			{
				insert(child,s,findIndex(s,k,cs),cs);
			}
			else
			{
				TPTR tmp = new branchNode;
				trie->np.branch_ptr[ind] = new branchNode;
				tmp = createNew(trie->np.branch_ptr[ind],1);
				tmp->count = k+1;
				int i1=findIndex(s,k,cs);
				tmp->np.branch_ptr[i1] = new branchNode;
				TPTR newChild = tmp->np.branch_ptr[i1];
				newChild = createNew(tmp->np.branch_ptr[i1],0);
				newChild->np.leaf_ptr->str = s;
				
				int i2=findIndex(tmpstr,k,cs);
				tmp->np.branch_ptr[i2] = child;
				
			}
		}
	}
}

void repair(TPTR &T)
{
	int count=0;
	TPTR tmp;
	for(int i=0;i<=n;i++)
	{
		if(T->np.branch_ptr[i]!=NULL)
		{
			count++;
			tmp = T->np.branch_ptr[i];
		}	
	}	
	if(count==1&&T->parent)
	{
		int i=0;
		for(i=0;i<=n;i++)
		{
			if(T->parent->np.branch_ptr[i]==T)
			break;
		}
		T->parent->np.branch_ptr[i] = tmp;
		repair(T->parent);
	}
}

void remove(TPTR &trie,string s,int ind,int i,char* cs)
{
	if(trie->np.branch_ptr[ind]->tag==0)
	{
		TPTR tmp = trie->np.branch_ptr[ind];
		trie->np.branch_ptr[ind] = NULL;
		delete tmp;
		repair(trie);
	}
	else
	{
		remove(trie->np.branch_ptr[ind],s,findIndex(s,i+1,cs),i+1,cs);
	}
	
}

void print(TPTR T)
{
	if(T->tag==0)
	{
		cout<<T->np.leaf_ptr->str<<endl;
	}
	else
	for(int i=0;i<=n;i++)
	{
		if(T->np.branch_ptr[i]!=NULL)
		{
			T->np.branch_ptr[i]->parent = T;
			print(T->np.branch_ptr[i]);
		}
	}
}

int main()
{
	cout<<"Enter the number of characters: ";
	cin>>n;
	cout<<"\nEnter the character set: ";
	char* cs = new char[n];
	for(int i=0;i<n;i++)
	{
		cin>>cs[i];
	}
	
	
	TPTR trie = new branchNode;
	trie->parent=NULL;
	trie->tag = 1;
	trie->np.branch_ptr = new TPTR[n+1];
	initialize(trie->np.branch_ptr);
	trie->count=1;
	int ch=1;	
	string str;
	cout<<"\nEnter the string to be inserted: ";
	cin>>str;
	while(str!="-")
	{
		if(ch==1)
		insert(trie,str,findIndex(str,0,cs),cs);
		else
		remove(trie,str,findIndex(str,0,cs),0,cs);
		
		print(trie);
		cout<<"\nEnter 1 to insert \nEnter 2 to delete: "<<endl;
		cin>>ch;
		if(ch==1)
		{
			cout<<"\nEnter the string to be inserted: ";
			cin>>str;
		}
		else
		{
			cout<<"\nEnter the string to be deleted: ";
			cin>>str;
		}
	}
	
	return 0;
}
