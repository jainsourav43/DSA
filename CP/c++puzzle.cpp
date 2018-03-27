#include<iostream>
using namespace std;
int &f()
{
static 	int x;
	return x;
}
int main()
{
	f()=10;
	cout<<f()<<endl;
}
//accessing private without  friend function
class Test
{
private:
    int data;
public:
    Test() { data = 0; }
    int getData() { return data; }
};
 
int main()
{
    Test t;
    int* ptr = (int*)&t;
    *ptr = 10;
    cout << t.getData();
    return 0;
}
// A class whose object can only be dynamically created
class Test
{
private:
    ~Test() { cout << "Destroying Object\n"; }
public:
     Test() { cout << "Object Created\n"; }
friend void destructTest(Test* );
};
 
// Only this function can destruct objects of Test
void destructTest(Test* ptr)
{
    delete ptr;
    cout << "Object Destroyed\n";
}
 
int main()
{
    /* Uncommenting following following line would cause compiler error */
    // Test t1;
 
    // create an object
    Test *ptr = new Test;
 
    // destruct the object to avoid memory leak
    destructTest(ptr);
 
    return 0;
}

//print string with empty main



#include <iostream>
using namespace std;
 
class MyClass
{
public:
    MyClass()
    {
        cout << "GeeksforGeeks";
    }
}m;
 
int main()
{
 
}
#include <iostream>
using namespace std;
 
/* Apply the constructor attribute to myStartupFun() so that it
   is executed before main() */
void myStartupFun (void) __attribute__ ((constructor));
 
/* implementation of myStartupFun */
void myStartupFun (void)
{
    cout << "GeeksforGeeks";
}
 
int main ()
{
 
}


//Following is a C++ program that prints 1 to 100 without loop and without recursion.

#include <iostream>
using namespace std;
 
template<int N>
class PrintOneToN
{
public:
    static void print()
    {
        PrintOneToN<N-1>::print();  // Note that this is not recursion
        cout << N << endl;
    }
};
 
template<>
class PrintOneToN<1>
{
public:
    static void print()
    {
        cout << 1 << endl;
    }
};
int main()
{
    const int N = 100;
    PrintOneToN<N>::print();
    return 0;
}

//another method
#include<iostream>
using namespace std;
 
class A
{
public:
    static int a;
    A()
    {  cout<<a++<<endl;  }
};
 
int A::a = 1;
 
int main()
{
    int N = 100;
    A obj[N];
    return 0;
}

#include <iostream>
using namespace std;
 
// Objects of Test can not be dynamically allocated
class Test
{
    // Notice this, new operator function is private
    void* operator new(size_t size);
    int x;
public:
    Test()          { x = 9; cout << "Constructor is called\n"; }
    void display()  { cout << "x = " << x << "\n";  }
    ~Test()         { cout << "Destructor is executed\n"; }
};
 
int main()
{
    // Uncommenting following line would cause a compile time error.
    // Test* obj=new Test();
    Test t;          // Ok, object is allocated at compile time
    t.display();
    return 0;
} // object goes out of scope, destructor will be called


//sum of digits in a single statement
int sumDigits(int no)
{
  return no == 0 ? 0 : no%10 + sumDigits(no/10) ;
}
 
int main(void)
{
  printf("%d", sumDigits(1352));
  getchar();
  return 0;
}


# include<stdio.h>
int main()
{
  int n = 687;
  printf(" %d ", getSum(n));
 
  getchar();
  return 0;
}
 
/* Function to get sum of digits */
int getSum(int n)
{
    int sum;
    /*Single line that calculates sum*/
    for(sum=0; n > 0; sum+=n%10,n/=10);
    return sum;
}
//*************************************************************IMPORTANT***********************************************************
// we can write URLS in c++ because it will treat that as a goto label and the two back slaces of url will act as a start of comment
//*************************************************************IMPORTANT***********************************************************
//SWAP IN ONE LINE
(x ^= y), (y ^= x), (x ^= y);
//


//*************************************************************IMPORTANT***********************************************************

//Initializer list: This type is used to access the values in a C++ initialization list. Here the objects of this type are automatically constructed by the compiler from initialization list declarations, which is a list of comma-separated elements enclosed in braces.
#include<iostream>
 
template<typename T>
void printList(std::initializer_list<T> text)
{
    for (const auto & value: text)
        std::cout << value << " ";
}
 
// Driver program
int main()
{
    // Initialization list
    printList( {"One", "Two", "Three"} );
    return 0;
}

