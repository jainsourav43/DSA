#include <iostream>
#include <algorithm>

using namespace std;


long long int knapSack( int S, int N, long long int wei[], long long int val[] ) {
	int i, w;
	long long int K[ N + 1 ][ S + 1 ];

	for ( i = 0; i <= N; ++i ) {
		for ( w = 0; w <= S; ++w ) {
			if ( i == 0 || w == 0 ) {
				K[ i ][ w ] = 0;
			}
			else if ( wei[ i - 1 ] <= w ) {
				K[ i ][ w ] = max( val[ i - 1 ] + K[ i - 1 ][ w - wei[ i - 1 ] ], K[ i - 1 ][ w ] );
			}
			else {
				K[ i ][ w ] = K[ i - 1 ][ w ];
			}
		}
	}
	return K[ N ][ S ];
}

int main() {
	int S, N, i;
    cin>>N>>S;
	long long int wei[ N + 1 ], val[ N + 1 ],sum=0;
	for ( i = 0; i < N; ++i ) {
	cin>>wei[i]>>val[i];
		sum+=wei[i];
	}
    //for(i=1;i<=sum;i++)
    cout<<knapSack( S, N, wei, val ) <<endl;

	
	return 0;
}
