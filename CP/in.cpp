#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:int power(string a);
	
};
int Solution::power(string a) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string temp;
    int mynum,tem,ans=0,i,carry;
    int len=a.length();
    if(a=="1"||(a.at(len-1)-'0')%2)
	{
		return 0;
	}
    while(1)
    {   
        temp="";
        carry=0;
        for(i=0;i<len;i++)
        {
        	mynum=a.at(i)-'0';
        	if(i==0&&a.at(i)=='1'&&len>1)
        	{
        		mynum=(a.at(i)-'0')*10+(a.at(i+1)-'0');
        		
        		temp=temp+to_string(mynum/2);
        		if(mynum%2)
        		carry=1;
        		i++;
			}
        	else if((mynum)%2)
        	{
        		mynum=carry*10+mynum;
        		temp=temp+to_string(mynum/2);
        		carry=1;
			}
			else
			{
				mynum=carry*10+mynum;
				temp=temp+to_string(mynum/2);
				carry=0;
			}
		}
	//	cout<<"new ="<<temp<<endl;
		len=temp.length();
		if(temp=="1")
		return 1;
		if((temp.at(len-1)-'0')%2)
		{
			ans=2;
			return 0;
			break;
		}
		a=temp;
		
	}    
return 1;
}
int main()
{
	Solution s;
	cout<<"emte n"<<endl;
	string n;cin>>n;
	cout<<s.power(n);
}
