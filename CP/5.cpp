#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll  long long int
#define X first
#define Y second
using namespace std;
string s[55];
int n;
bool vis[55][55],flag;
ll ans,mod=1e9+7;
void dft(int x,int y,char val)
{
    if(x<0||y<0||x>=n||y>=n) return;
cout<<x<<" "<<y<<s[x][y]<<endl;
    if(vis[x][y]) return;
    if(s[x][y]!='?'&&s[x][y]!=val) {if(s[x][y]!='.')flag=0;return;}
    s[x][y]=val;
cout<<x<<" "<<y<<val<<endl<<endl;
    vis[x][y]=1;
    dft(x+1,y,val);
    dft(x,y+1,val);
    dft(x-1,y,val);
    dft(x,y-1,val);
}
void dft1(int x,int y)
{
    if(x<0||y<0||x>=n||y>=n) return;
    if(s[x][y]!='?'||vis[x][y]) {return;}
    vis[x][y]=1;
    s[x][y]='O';
    dft1(x+1,y);
    dft1(x,y+1);
    dft1(x-1,y);
    dft1(x,y-1);
}
int main()
{
    int t,k,i,j,c,m;
    int q;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=1;flag=1;
        for(i=0;i<n;i++) cin>>s[i];
        j=n;
        for(i=0;i<n&&j==n;i++)
            {for(j=0;j<n;j++)
                {if(s[i][j]!='?'&&s[i][j]!='.'&&s[i][j]!='G')
            {
                if(i-1>=0)  {if(s[i-1][j]!='.'&&s[i-1][j]!=s[i][j]&&s[i-1][j]!='?') break; }
                if(j-1>=0)  {if(s[i][j-1]!='.'&&s[i][j-1]!=s[i][j]&&s[i][j-1]!='?') break; }
                if(i+1<n)   {if(s[i+1][j]!='.'&&s[i+1][j]!=s[i][j]&&s[i+1][j]!='?') break; }
                if(j+1<n)   {if(s[i][j+1]!='.'&&s[i][j+1]!=s[i][j]&&s[i][j+1]!='?') break; }
            }
            else if(s[i][j]=='G')
            {
                if(i-1>=0)  {if(s[i-1][j]!='.') break; } //else break;
                if(j-1>=0)  {if(s[i][j-1]!='.') break; }// else break;
                if(i+1<n)   {if(s[i+1][j]!='.') break; } //else break;
                if(j+1<n)   {if(s[i][j+1]!='.') break; } //else break;
            }}
            if(j!=n) break;}
 
        if(i!=n) {cout<<0<<endl;continue;}
        for(i=0;i<n;i++) for(j=0;j<n;j++) vis[i][j]=0;
 
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            if(s[i][j]!='.'&&s[i][j]!='?'&&!vis[i][j])
            {dft(i,j,s[i][j]);/*cout<<i<<" "<<j<<endl;*/}
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(s[i][j]=='?')
            {dft1(i,j);
                int c1=0,c2=0;
                if(i-1>=0)  {c1++;if(s[i-1][j]=='.') c2++;}
                if(j-1>=0)  {c1++;if(s[i][j-1]=='.') c2++;}
                if(i+1<n)   {c1++;if(s[i+1][j]=='.') c2++;}
                if(j+1<n)   {c1++;if(s[i][j+1]=='.') c2++;}
                if(c1==c2) ans=(ans*3LL)%mod;
                else {ans=(ans*2LL)%mod;}
            }
            //
        /*    j=n;
        for(i=0;i<n&&j==n;i++)
            {for(j=0;j<n;j++)
                {if(s[i][j]!='?'&&s[i][j]!='.'&&s[i][j]!='G')
            {
                if(i-1>=0)  {if(s[i-1][j]!='.'&&s[i-1][j]!=s[i][j]&&s[i-1][j]!='?') break; }
                if(j-1>=0)  {if(s[i][j-1]!='.'&&s[i][j-1]!=s[i][j]&&s[i][j-1]!='?') break; }
                if(i+1<n)   {if(s[i+1][j]!='.'&&s[i+1][j]!=s[i][j]&&s[i+1][j]!='?') break; }
                if(j+1<n)   {if(s[i][j+1]!='.'&&s[i][j+1]!=s[i][j]&&s[i][j+1]!='?') break; }
            }
            else if(s[i][j]=='G')
            {
                if(i-1>=0)  {if(s[i-1][j]!='.') break; } //else break;
                if(j-1>=0)  {if(s[i][j-1]!='.') break; }// else break;
                if(i+1<n)   {if(s[i+1][j]!='.') break; } //else break;
                if(j+1<n)   {if(s[i][j+1]!='.') break; } //else break;
            }}
            if(j!=n) break;}
            }*/
        if(flag==0) {cout<<0<<endl;continue;}
            //
            cout<<ans<<endl;
    }
    return 0;
 
}

