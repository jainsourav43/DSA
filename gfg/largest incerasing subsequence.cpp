// A naive C/C++ based recursive implementation of LIS problem
#include<stdio.h>
#include<stdlib.h>
 
// Recursive implementation for calculating the LIS
int _lis(int arr[], int n, int *max_lis_length)
{
    // Base case
    if (n == 1)
        return 1;
 
    int current_lis_length = 1;
    for (int i=0; i<n-1; i++)
    {
        // Recursively calculate the length of the LIS
        // ending at arr[i]
        int subproblem_lis_length = _lis(arr, i, max_lis_length);
 
        // Check if appending arr[n-1] to the LIS
        // ending at arr[i] gives us an LIS ending at
        // arr[n-1] which is longer than the previously
        // calculated LIS ending at arr[n-1] 
        if (arr[i] < arr[n-1] &&
            current_lis_length < (1+subproblem_lis_length))
            current_lis_length = 1+subproblem_lis_length;
    }
 
    // Check if currently calculated LIS ending at
    // arr[n-1] is longer than the previously calculated
    // LIS and update max_lis_length accordingly 
    if (*max_lis_length < current_lis_length)
        *max_lis_length = current_lis_length;
 
    return current_lis_length;
}
 
// The wrapper function for _lis()
int lis(int arr[], int n)
{
    int max_lis_length = 1; // stores the final LIS
 
    // max_lis_length is passed as a reference below 
    // so that it can maintain its value
    // between the recursive calls 
    _lis( arr, n, &max_lis_length );
 
    return max_lis_length;
}
 
// Driver program to test the functions above
int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of LIS is %d\n", lis( arr, n ));
    return 0;
}






















/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Dynamic Programming C/C++ implementation of LIS problem */
#include<stdio.h>
#include<stdlib.h>
 
/* lis() returns the length of the longest increasing
  subsequence in arr[] of size n */
int lis( int arr[], int n )
{
    int *lis, i, j, max = 0;
    lis = (int*) malloc ( sizeof( int ) * n );
 
    /* Initialize LIS values for all indexes */
    for (i = 0; i < n; i++ )
        lis[i] = 1;
 
    /* Compute optimized LIS values in bottom up manner */
    for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ ) 
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
 
    /* Pick maximum of all LIS values */
    for (i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];
 
    /* Free memory to avoid memory leak */
    free(lis);
 
    return max;
}
 
/* Driver program to test above function */
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of lis is %d\n", lis( arr, n ) );
    return 0;
}
