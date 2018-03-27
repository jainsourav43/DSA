//Extendible Hashing
#include<bits/stdc++.h>
#define null NULL
using namespace std;
typedef
struct bucket
{
	int keys[4];
	int count=0;
	int d1;//local depth
}*bptr;
int d;
bptr directory[100];
////////////////////////////////////////////////////////////////////////////////////////
int findindex(int key)
{
	int i,in=0,len;
	char temp[50];
	itoa(key,temp,2);
	len=strlen(temp);
	//cout<<"temp = "<<temp<<endl;
	for(i=0;i<d;i++)
	{
		if(temp[len-1-i]=='0')
		{
			in=in+0;//do nothing 
		}
		else if(temp[len-1-i]=='1')
		{
			in=in+pow(2,i);//adding to reach to the particular index
		}
	}
	return in;
}
//////////////////////////////////////////////////////////////////////////////////////////
void contract1()
{
	d--;
	for(int i=0;i<pow(2,d);i++)
	{
		directory[i]->d1--;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////
void combine(int in,int b[],int key,int imp)
{
	    int j=0,check=1,i;
		for( i=0;i<=4;i++)
		//cout<<"b[i] = "<<b[i]<<"  ";
		sort(b,b+5);
		cout<<endl;
    for(i=0;i<=4;i++)
	{
		if(b[i]!=key)
		{
		directory[in]->keys[j]=b[i];
		j++;
		
	    }
	}
	directory[in]->count=4;
	directory[imp]=directory[in];int p=pow(2,d-1);
	for(i=0;i<pow(2,d-1);i++)
	{
		if(directory[i]==directory[i+p])
		{
			check=1;
		}
		else
		{
			check=0;
			break;
		}
	}
	if(check==1&&d>1)
	{
		contract1();//Contracting the directory after combining the buckets
	}
}
///////////////////////////////////////////////////////////////////////////////////////
void contract(int in,int b[],int key)
{
	int i,in1[4+1],dupli[4+1],dc;
	sort(b,b+5);
	for(i=0;i<=4;i++)
	{
		if(b[i]!=key)
		directory[in]->keys[i]=b[i];
	}
	directory[in]->count=4;
	d=d-1;
}
/////////////////////////////////////////////////////////////////////////////////////////
void deleteit(int key)
{
	int in,b[5],i,j;
	in=findindex(key);
	int p=pow(2,d-1);
	if(in>=p)
	{
	//	cout<<"if1\n";
		if((directory[in-p]->count+directory[in]->count-1<=4&&directory[in-p]!=directory[in])&&directory[in]->d1-1<d-1)
		{//cout<<"ifif 1\n";
			for(i=0;i<directory[in]->count;i++)
			{
				b[i]=directory[in]->keys[i];
			}
			for(i=0;i<directory[in-p]->count;i++)
			{
				b[i+directory[in]->count-1]=directory[in-p]->keys[i];
			}
		  contract(in,b,key);	
		}
		else if((directory[in-p]->count+directory[in]->count-1<=4&&directory[in-p]!=directory[in])&&directory[in]->d1-1<d)
		{//cout<<"elseif1 \n"; 
			for(i=0;i<directory[in]->count;i++)
			{
				b[i]=directory[in]->keys[i];
			}
			for(i=0;i<directory[in-p]->count;i++)
			{
				b[i+directory[in]->count]=directory[in-p]->keys[i];
			}
			combine(in,b,key,in-p);
		}
		else
		{//cout<<"Else1\n";
			for(i=0;i<directory[in]->count;i++)
			{
				if(directory[in]->keys[i]!=key)
				{
					continue;
				}
				else
				{
					for(j=i;j<directory[in]->count-1;j++)
					{
						directory[in]->keys[j]=directory[in]->keys[j+1];
					}
				}
			}
			directory[in]->count--;
		}
	}
	else 
	{//cout<<"Else2\n";
		if((directory[in+p]->count+directory[in]->count-1<=4&&directory[in+p]!=directory[in])&&directory[in]->d1-1<d-1)
		{//cout<<"if2\n";
			for(i=0;i<directory[in]->count;i++)
			{
				b[i]=directory[in]->keys[i];
			}
			for(i=0;i<directory[in-p]->count;i++)
			{
				b[i+directory[in]->count-1]=directory[in-p]->keys[i];
			}
		   contract(in,b,key);	
		}
		else if((directory[in+p]->count+directory[in]->count-1<=4&&directory[in+p]!=directory[in])&&directory[in]->d1-1<d)
		{//cout<<"Else if2\n";
			for(i=0;i<directory[in]->count;i++)
			{
				b[i]=directory[in]->keys[i];
			}
			for(i=0;i<directory[in+p]->count;i++)
			{
				b[i+directory[in]->count]=directory[in+p]->keys[i];
			}
			combine(in,b,key,in+p);
		}
		else
		{cout<<"Else2\n";
			for(i=0;i<directory[in]->count;i++)
			{
				if(directory[in]->keys[i]!=key)
				{
					continue;
				}
				else
				{
					for(j=i;j<directory[in]->count-1;j++)
					{
						directory[in]->keys[j]=directory[in]->keys[j+1];
					}
				}
			}
			directory[in]->count--;
		}
	}
}
////////////////////////////////////////////////////////////////////////
void expand(int in,int key)
{
	int i,in1[4+1],dupli[4+1],dc;
	d=d+1;
	int p=pow(2,d-1);
	//cout<<"in ="<<in<<endl;
	for(i=pow(2,d-1)-1;i>=0;i--)
	{
		//cout<<"i+P ="<<i+p<<endl;
		directory[i+p]=directory[i];
	}
	for(i=0;i<directory[in]->count;i++)
	{
		in1[i]=findindex(directory[in]->keys[i]);
		dupli[i]=directory[in]->keys[i];
	}
	in1[directory[in]->count]=findindex(key);
	dupli[directory[in]->count]=key;
	dc=directory[in]->count;
	directory[in]->count=0;
	directory[in+p]=new bucket;
	//cout<<"In +p ="<<in+p<<endl;
	directory[in+p]->d1=d;
	directory[in]->d1=d;
	for(i=0;i<dc+1;i++)
	{
		if(directory[in1[i]]->count<4)
		{
		directory[in1[i]]->keys[directory[in1[i]]->count]=dupli[i];
		directory[in1[i]]->count++;
	    }
	   else
	   {
	   	expand(in1[i],dupli[i]);//Recursively Calling expand in case where every key is going to the same bucket
	   }
	}
}
///////////////////////////////////////////////////////////////////////////////////
void split(int in,int key)
{
	int i,in1[4+1],dupli[4+1],dc;	
	int p=pow(2,d-1);
    if(in>=pow(2,d-1))
    p=0-pow(2,d-1);
	directory[in+p]=new bucket;
	directory[in+p]->d1=directory[in]->d1+1;
	directory[in]->d1++;
	for(i=0;i<directory[in]->count;i++)
	{
		in1[i]=findindex(directory[in]->keys[i]);
		//cout<<"IN1[] = "<<in1[i]<<"  ";
		dupli[i]=directory[in]->keys[i];
		//cout<<"Dupli[] = "<<dupli[i]<<"  ";
	}cout<<endl;
	in1[directory[in]->count]=findindex(key);
	dupli[directory[in]->count]=key;
	dc=directory[in]->count;
	directory[in]->count=0;
	for(i=0;i<dc+1;i++)
	{
		if(directory[in1[i]]->count<4)
		{//cout<<"IN of of rtyy  = "<<in1[i]<<"   ";
		directory[in1[i]]->keys[directory[in1[i]]->count]=dupli[i];
		directory[in1[i]]->count++;
		
	   }
	   else
	   {
	   	expand(in1[i],dupli[i]);//Recursively Calling expand in case where every key is going to the same bucket
	   }
	}
}
///////////////////////////////////////////////////////////////////////////////////
void insert(int key)
{
	char temp[20];
	int in=0,i,len;
	in=findindex(key);
	//cout<<"Index = "<<in<<endl;
     if(directory[in]->count<4)
	{//cout<<"if \n";
		directory[in]->keys[directory[in]->count]=key;
		directory[in]->count++;
	}
	else  if(directory[in]->d1<d)
	{//cout<<"Else if \n";
		split(in,key);//Calling split in then case where the local depth is less thann the global depth
	}
	else if(directory[in]->d1==d)
	{//cout<<"Else if2 \n";
		expand(in,key);//calling expand where local depth is equal to GLobal depth
		//cout<<"back\n"; 
	}
}
///////////////////////////////////////////////////////////////////////////
void print()
{
	int i,j;
	for(i=0;i<pow(2,d);i++)
	{
		if(directory[i]!=null)
		{
			cout<<"( ";int p=pow(2,d-1);
//			if(i>=pow(2,d-1)&&directory[i]==directory[i-p])
//			continue;
			for(j=0;j<directory[i]->count;j++)
			{
				cout<<directory[i]->keys[j]<<",";
			}
			cout<<" )";
			cout<<endl;
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	int i,k=1,j,l;
	cout<<"Enter the initial value of d  (i.e. d=1)\n";
	cin>>d;
	bptr b1=new bucket;
	b1->d1=1;
	for(i=0;i<pow(2,d);i++)
	{
		directory[i]=b1;
	}
	b1->d1=0;k=1;
	while(k!=-1)
	{
	cout<<"Enter the Key to insert else -1\n";
	cin>>k;
	if(k!=-1)
	insert(k);
	print();
	k++;
    }
    
    k=1;
    while(k!=-1)
    {
    cout<<"Enter the Key to Delete else -1\n";
	cin>>k;
	if(k!=-1)
	deleteit(k);
	 print();	
	}
    return 0;
}
