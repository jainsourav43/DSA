/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of the class is as follows 
class LRUCache
{
public:
    LRUCache(int );
    int get(int );
    void set(int , int );
};*/
int a[104];
queue<int> q;
int sz=0;
/*You are required to complete below methods */
/*Inititalize an LRU cache with size N */
LRUCache::LRUCache(int N)
{
    while(!q.empty())
    q.pop();
    sz=N;
    for(int i=0;i<=100;i++)
    a[i]=-1;
     //Your code here
}
/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y) 
{
    if(a[x]!=-1){
    a[x]=y;
    queue<int> temp;
    while(!q.empty())
    {
        if(x==q.front()){
        q.pop();
        continue;
        }
        temp.push(q.front());
        q.pop();
    }
    
    while(!temp.empty())
    {
        q.push(temp.front());
        temp.pop();
    }
    q.push(x);
    return ;
    }
    if(q.size()==sz){
    a[q.front()]=-1;
    q.pop();
    }
    a[x]=y;
    q.push(x);
     //Your code here
}
/*Returns the value of the key x if 
present else returns -1 */
int LRUCache::get(int x)
{
   // if(x==29)
//    cout<<" <"<<q.front()<<"> ";
    //cout<<x<<" ";
    if(a[x]==-1)return -1;
    queue<int> temp;
    while(!q.empty())
    {
        if(x==q.front()){
        q.pop();
        continue;
        }
        temp.push(q.front());
        q.pop();
    }
    
    while(!temp.empty())
    {
        q.push(temp.front());
        temp.pop();
    }
    q.push(x);
    
    return a[x];
    //Your code here
}
