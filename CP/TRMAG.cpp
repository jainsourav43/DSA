#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
bool marked[2005];
double memo[1005][2];
int leaves;
int R;
void init(int p,int l)
{
	int i,j;
	for(i=0;i<p+5;i++)marked[i]=0;
	for(i=0;i<l+5;i++)
		for(j=0;j<2;j++)
			memo[i][j]=0.0;
}
inline void Input(int &N)
{
	int ch,sign=1;
	N=0;
 
	while((ch<'0' || ch>'9') && ch!=EOF)
		ch=getchar();
 
	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');
 
	N*=sign;
	return;
}
int main() 
{
	int t;
	Input(t);
	int pages,in,tmp,removal,neg,removed,leaf,i;
	double p;
	bool y;
	while(t--)
	{
		
		Input(pages);
		leaves=(pages+1)>>1;
		init(pages,leaves);
		neg=0;
		if((pages&1))marked[pages+1]=1;
		
		Input(in);
		
		for(i=0;i<in;i++)
		{
			Input(tmp);
			neg+=tmp;
			marked[tmp]=1;
		}
		
		Input(R);
		y=false;
		if(leaves-R<R){R=leaves-R;y=true;}
		for(removed=R+2;removed>=0;removed--)
		{
			for(leaf=leaves+2;leaf>=0;leaf--)
			{
				
				if(R-removed>0&&R-removed<=leaves-leaf)
				{
					p=(R-removed)*1.0/(leaves-leaf);
					removal=0;
					if(!marked[(leaf<<1)+1])removal+=(leaf<<1)+1;
					if(!marked[(leaf<<1)+2])removal+=(leaf<<1)+2;
					memo[leaf][0]=(1-p)*memo[leaf+1][0]+p*(memo[leaf+1][1]+removal);
				}
			}
			for(i=0;i<=leaves+2;i++)
				memo[i][1]=memo[i][0];
		}
		
	if(y)printf("%.4f\n",(memo[0][0]));
	else
	{ int sum=pages*(pages+1);
		sum=sum>>1;
		sum-=neg;
		printf("%.4f\n",(sum-memo[0][0]));
 
	}
} } 