#include <iostream>
#include<cstring>
using namespace std;

// Function to remove all occurrences of "AB" and "C" 
// from the string
void remove(char* str)
{
	// i maintains position of current char in the input string
	// k maintains the next free position in output string
	int i = 0, k = 0;
	int n=strlen(str);
	// do till we reach the end of the string
	while(i<n)
	{
		// if current char is 'B' and previous char (need not 
		// be adjacent) was 'A', increment i and decrement k
		if(str[i]!='B'&&str[i]!='C')
		{
			str[k++]=str[i++];
		}
		else if(str[i]=='B')
		{
			if(k>0&&str[k-1]=='A')
			{
				k--;
				i++;
			}
			else
			{
				str[k++]=str[i++];
			}
		}
		else
		{
			i++;
		}
	}

	// null-terminate the string
	str[k] = '\0';
}

int main()
{
	char str[] = "ABCACBCAABB";
	
	remove(str);
	cout << "String after removal of \"AB\" and \"C\" is \"" << str << "\"";

	return 0;
}

