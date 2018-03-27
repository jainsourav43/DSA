#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
 #define all(c) c.begin(), c.end()
 #define tr(container, it)  for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
#define cpresent(container, element) (find(all(container),element) != container.end()) 
 #define present(container, element) (container.find(element) != container.end()) 
//(Remember that all(c) stands for “c.begin(), c.end()”)
//  void f(const vector<int>& v) { 
//      int r = 0; 
//      tr(v, it) { 
//           r += (*it)*(*it); 
//      } 
//      return r; 
// } 
 
 //here c is the name of the vector or whatever container u are using 
using namespace std;

//void f(const vector<int>& v) { 
//      int r = 0; 
//      // Traverse the vector using const_iterator 
//      for(vector<int>::const_iterator it = v.begin(); it != v.end(); it++) { 
//           r += (*it)*(*it); 
//      } 
//      return r; 
// } 

 void some_function(const vector<int>& v) { // OK 
      // ... 
 } 
 ///if we want  tochnage the content of the vector in the function
int modify_vector(vector<int>& v) { // Correct 
      v[0]++; 
 } 
 
int  main()
{
	//vector<int> v2(v.begin(), v.begin() + (v.size()/2)); 
	pair<string, pair<int,int> > P; 
 	string s = P.first; // extract string 
 	int x = P.second.first; // extract first int 
 	int y = P.second.second; // extract second int 
	int i,j;
	cout<<"enter the number\n";
	cin>>i;
	//stack<int> s;
	 //for(vector<int>::iterator it = v.begin(); it != v.end(); it++) { 
     // *it++; // Increment the value iterator is pointing to 
 //} 
	
	int a=1,b=1;
	typeof(a+b) x1 =a+b;
	vector<int >v;
	int is=v.size();
	cout<<"size is = "<<is<<endl;
	int n=10;
	for(i=0;i<n;i++)
	v.push_back(i+1);
	 is=v.size();
	cout<<"size is = "<<is<<endl;
	v.resize(50);
	 is=v.size();
	cout<<"size is = "<<is<<endl;
	int N=5, M=5; 
	//v.insert()
 // ... 
 vector< vector<int> > Matrix(N, vector<int>(M, -1)); 
  is=Matrix.size();
	cout<<"size is = "<<is<<endl;
	//int X[10]={2,1,3,5,4,8,7,6,9,10};
		vector<int> X; 
	for(int j=0;j<10;j++)
	X.push_back(j*j+1);

	sort(X.rbegin(), X.rend());
	for(vector<int>:: iterator it=X.begin();it!=X.end();it++)
	cout<<*it<<" ";
   int f=	(find(X.begin(),X.end(),10)-X.begin());
   cout<<"f=  "<<f<<endl;
  cout<< X.at(5)<<endl;
  vector<int> ::iterator it1;
  it1=X.begin();
  //reverse(it1+2, it1+6);
	if(find(X.begin(),X.end(),10)!=X.end())
	{
		cout<<"found\n";
	}
	else
	{
		cout<<"not found\n";
	}
	X.insert(it1+4,100);
	X.erase(it1+4);
	X.erase(it1+4,it1+6);
	for(vector<int>:: iterator it=X.begin();it!=X.end();it++)
	cout<<*it<<" ";
	set<int> s; 

	 for(int i = 1; i <= 100; i++) { 
	      s.insert(i); // Insert 100 elements, [1..100] 
	 } 
	
	 s.insert(42); // does nothing, 42 already exists in set 
	
	 for(int i = 2; i <= 100; i += 2) { 
	      s.erase(i); // Erase even values 
	 } 
	
	 int n = int(s.size());
	  // Calculate the sum of elements in set 
	 set<int> S; 
	 // ... 
	 int r = 0; 
	 for(set<int>::const_iterator it = S.begin(); it != S.end(); it++) { 
	      r += *it; 
	 } 
	 set<int> s; 
	 // ... 
	 if(s.find(42) != s.end()) { 
	      // 42 presents in set 
	 } 
	 else { 
	      // 42 not presents in set 
	 } 
		 if(s.count(42) != 0) { 
      // … 
 		}
//	  set< pair<string, pair< int, vector<int> > > SS; 
//      int total = 0; 
//      tr(SS, it) { 
//      total += it->second.first; 
 } 
	  set<int> s; 
 // .. 

 set<int>::iterator it1, it2; 
 it1 = s.find(10); 
 it2 = s.find(100); 
 // Will work if it1 and it2 are valid iterators, i.e. values 10 and 100 present in set. 
 s.erase(it1, it2); // Note that 10 will be deleted, but 100 will remain in the container 
	//cout<<X[i]<<" ";
//--------------------------------------------------------
	 
	 int data[5] = { 5, 1, 4, 2, 3 }; 
 	 set<int> S(data, data+5); 
 
 //-----------------------------------------------------
 //for sort and dupliate removal
 vector<int> v; 
 // … 
 set<int> s(all(v)); 
 vector<int> v2(all(s)); 
 //----------------------------------------------
  map<string, int> M; 
 M["Top"] = 1; 
 M["Coder"] = 2; 
 M["SRM"] = 10; 

 int x = M["Top"] + M["Coder"]; 

 if(M.find("SRM") != M.end()) { 
      M.erase(M.find("SRM")); // or even M.erase("SRM") 
 } 
 //------------------------------------------------------------------------
 
//	int p=v.begin();
	//cout<<v.begin();
//	s.push(i);
//    s.pop();
//    s.size();
	
}
