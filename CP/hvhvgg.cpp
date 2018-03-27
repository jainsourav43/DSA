#include<bits/stdc++.h>
using namespace std;

bool comp(char x,char y)
{
	return x>y;
}
string largestNumber(const vector<int> &a) {
    
    int i=0;
    int b[a.size()][18];
    string str[a.size()];
   char intstr[18];
    for(i=0;i<a.size();i++)
    {
         itoa(a[i],intstr,10);
         str[i].append(intstr);
    }
    //for(i=0;i<a.size();i++)
    //{
       // sort(str.begin(),str.end(),comp);
    //}
  //  cout<<"str[0],str[1] ="<<str[0]<<" "<<str[1]<<endl;
    ///cout<<(str[0]>str[0+1])<<endl;
    string temp1,temp2;
    for(int j=0;j<a.size()-1;j++)
    for(i=0;i<a.size()-1-j;i++)
    {
    	temp1=str[i]+str[i+1];
    	temp2=str[i+1]+str[i];
    	if(temp1<temp2)
    	{
    		string temp=str[i];
    		str[i]=str[i+1];
    		str[i+1]=temp;
    		
    		
		}
	}
//	cout<<"str[0],str[1] ="<<str[0]<<" "<<str[1]<<endl;
	string result;
	for(i=0;i<a.size();i++)
	if((i>0&&str[i]!="0"&&str[i-1]!="0")|| i==0)
	result.append(str[i]);
    return result;
}
int main()
{
	int n;
	cin>>n;
	vector<int> a(n,0);
	int i;
//	string c="89",b="8";
//	cout<<(c>b)<<endl;
	for(i=0;i<n;i++) cin>>a[i];
	string st=largestNumber(a);
	cout<<st<<endl;
}
