#include <bits/stdc++.h>
 using namespace std;
typedef long long int ll;
 
#define MOD 1000000007ll
#define all(v) v.begin() , v.end()
#define for0(i,n) for(__typeof(n) i = 0; i < n ; i++)  
#define forc(c,it) for(__typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define outc(c) for(__typeof(c.begin()) it = c.begin(); it != c.end(); it++) {cout<<*it<<" ";}
#define pb     push_back
#define allr(v) v.rbegin(), v.rend()
#define mp     make_pair
#define MAX 100005
#define INF LLONG_MAX
template <typename T> T mod(T a, T b) {return (a < b ? a : a % b);}
 
int t, siz1, siz2, ans, x, y;
string s1, s2;
int a[30], b[30];
 
int main()
{

 
  cin>>t;
 
  while(t--)
  {
  	cin>>s1>>s2;
  	siz1 = s1.size();
  	siz2 = s2.size();
  	ans = INT_MAX;
 
  	for(int i = 0 ; i < 30 ; i++)
  	{
  		a[i] = -1;
  		b[i] = -1;
  	}
 
  	for(int i = 0 ; i < siz1 ; i++)
  		a[s1[i] - 'A'] = max(a[s1[i] - 'A'] , min(i , siz1 - i - 1));
 
  	for(int i = 0 ; i < siz2 ; i++)
  		b[s2[i] - 'A'] = max(b[s2[i] - 'A'] , min(i , siz2 - i - 1));
 
// for(int i=0;i<26;i++)
// cout<<"a = "<<a[i]<<endl;
// for(int i=0;i<26;i++)
// cout<<"b = "<<b[i]<<endl;
  	for(int i = 0 ; i < 26 ; i++)
  	{
  		if(a[i] == -1 || b[i] == -1)
  			continue;
 
  		x = siz1 - a[i] - 1;
  		y = siz2 - b[i] - 1;
 
  		ans = min(ans , abs(x - y) + abs(x- b[i]) + abs(y - a[i]) + abs(a[i] - b[i])); 
 
  	}
 
  	printf("%d\n" , ans); 	
  }
 
return 0;
 
}  
