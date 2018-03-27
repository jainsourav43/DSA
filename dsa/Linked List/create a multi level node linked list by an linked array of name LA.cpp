#include<iostream>
using namespace std;
int j=0;
typedef
struct mnode
{
	union u
	{
		char d;
		mnode *dptr;
	}data;
	int tag;
	struct mnode *next;
} *mptr;
struct LA
{
	char ch;
	mptr *ptr;
};
int main()
{
	
}

