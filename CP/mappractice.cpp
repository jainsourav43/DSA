#include<iostream>
#include<vector>
//#include<pair>
 typedef vector<int> vi; 
 typedef vector<vi> vvi; 
 typedef pair<int,int> ii; 
 #define sz(a) int((a).size()) 
 #define pb push_back 
 #define all(c) (c).begin(),(c).end() 
 #define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
 #define present(c,x) ((c).find(x) != (c).end()) 
 #define cpresent(c,x) (find(all(c),x) != (c).end()) 
using namespace std;
#define tr(container ,it) for(typeof(container.begin())  it=container.begin(); it!=container.end();it++ )
#include<map>
#include<set>
//-----------------------------------------------------------------------------------------------------
/*
Graph is considered to be stored as adjacent vertices list.
Also we considered graph undirected.
 
vvi is vector< vector<int> >
W[v] is the list of vertices adjacent to v
*/
 
 int N; // number of vertices
 vvi W; // lists of adjacent vertices
   
   
 bool check_graph_connected_bfs() { 
      int start_vertex = 0; 
      vi V(N, false); 
      queue<int> Q; 
      Q.push(start_vertex); 
      V[start_vertex] = true; 
      while(!Q.empty()) { 
           int i = Q.front(); 
           // get the tail element from queue
           Q.pop(); 
           tr(W[i], it) { 
                if(!V[*it]) { 
                     V[*it] = true; 
                     Q.push(*it); 
                } 
           } 
      } 
      return (find(all(V), 0) == V.end()); 
 }  
//-----------------------------------------------------------------------------------------
/*
Reminder from Part 1:
typedef vector<int> vi;
typedef vector<vi> vvi;
*/

 int N; // number of vertices 
 vvi W; // graph 
 vi V; // V is a visited flag 
 
 void dfs(int i) { 
       if(!V[i]) { 
       
            V[i] = true; 
            for_each(all(W[i]), dfs); 
       } 
 } 
  
 bool check_graph_connected_dfs() { 
       int start_vertex = 0; 
       V = vi(N, false); 
       dfs(start_vertex); 
       return (find(all(V), 0) == V.end()); 
 } 
 //-------------------------------------------------------------------------------------------------------------------
void f(const map<string, int>& M) { 
      //if(M["the meaning"] == 42) { // Error! Cannot use [] on const map objects! 
      //} 
      if(M.find("the meaning") != M.end() && M.find("the meaning")->second == 42) { // Correct 
           cout << "Don't Panic!" << endl; 
      } 
 } 
int main()
{
	
		set<int> s; 

	 for(int i = 1; i <= 100; i++) { 
	      s.insert(100-i); // Insert 100 elements, [1..100] 
	 } 
	 for(typeof(s.begin()) it1 =s.begin();it1!=s.end();it1++)
	 {
	 	cout<<*it1<<" ";
	 }
	 cout<<endl;
 map<string, int> M; 
 M["Top"] = 1; 
 M["Coder"] = 2; 
 M["SRM"] = 10; 
//---------------------------------------------------------------------------------------------

 //-------------------------------------------------------------------------------------------------------
 int x = M["Top"] + M["Coder"]; 
 cout<<"x = "<<x <<endl;
 //M.erase("SRM") ;
 int r=0;
// typeof(M.begin())it; 
 tr(M, it) { 
      r = it->second; 
      
      cout<<r<<endl;
 } 
// if(M.find("SRM") != M.end()) { 
//      M.erase(M.find("SRM")); // or even M.erase("SRM") 
// } 
}
