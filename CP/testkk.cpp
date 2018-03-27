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
