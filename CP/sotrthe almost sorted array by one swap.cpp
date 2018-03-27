// C program to sort using one swap
#include<iostream>
#include<algorithm>
using namespace std;
 

 //This function sorts an array that can be sorted
 //by single swap
void sortByOneSwap(int arr[], int n)
{
    // Travers the given array from rightmost side
    for (int i = n-1; i > 0; i--)
    {
        // Check if arr[i] is not in order
        if (arr[i] < arr[i-1])
        {
            // Find the other element to be
            // swapped with arr[i]
            int j = i-1;
            while (j>=0 && arr[i] < arr[j])
                j--;
 
            // Swap the pair
            swap(arr[i], arr[j+1]);
            break;
        }
    }
}
 
// A utility function ot print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i=0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
/* Driver program to test insertion sort */
int main()
{
    int arr[] = {10, 30, 20, 40, 50, 60, 70};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, n);
 
    sortByOneSwap(arr, n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
 
    return 0;
}
