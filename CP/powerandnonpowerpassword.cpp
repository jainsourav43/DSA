#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
ll LIMIT = 3141LL * 3141LL * 3141LL * 3141LL * 3141LL;

int multi[61];

ll pw_3[1000000];
ll pw_g[61][50000];
ll lim[61];

/* power(a, b) by using pre-calculations */
ll pw(ll a, ll b){
  if(b==2) return a*a;
  if(b==3) return pw_3[a];
  return pw_g[b][a];
}

/* return the number of A^B <= n (A, B >= 2) */
int solve_power(ll n){
  int i, k, res = 0;
  int a, b, c;

  /* binary search for all B = i */
  /* This is a bit slow approach, because this loop run around 60 times */
  /* But it is enough for the time limit */
  /* The faster method will be provided from the setter :) */
  REP(i,2,61) if(multi[i]){ /* multi is used for avoiding multiple counts */
    a = 1; b = lim[i];
    while(a<b){
      c = (a+b+1)/2;
      if(pw(c,i) <= n) a=c; else b=c-1;
    }
    if(a==1) break;
    res += (a-1)*multi[i];
  }
  
  return res;
}

/* return the number of steps in binary search by Chef, for finding A[n] */
/* just simulation */
int solve_non_power(ll n){
  int i, j;
  ll a, b, c;
  int res = 0;

  for(b=1;;){
    b *= 2; res++;
    if(b==n) return res;
    if(n<b){a=b/2; break;}
  }

  for(;;){
    c = (a+b)/2;
    res++;
    if(c==n) return res;
    if(c>n) b=c; else a=c;
  }

  return -1;

}

int main(){
  int N, i, j, k, t;
  int res;
  ll in;
  ll s1, s2;

  /* calculate multi */
  rep(i,60) multi[i] = 1;
  REP(i,2,60) for(j=2*i;j<60;j+=i) multi[j] -= multi[i];

  /* pre-calc for power(i,j) for j>=3 */
  rep(j,1000000) pw_3[j] = (ll)j*j*j;
  rep(j,50000) pw_g[4][j] = pw_3[j] * j;
  REP(i,5,60) rep(j,50000){
    if(pw_g[i-1][j] * (double)j > 1e18) pw_g[i][j] = 1000000000000000000LL;
    else                                pw_g[i][j] = pw_g[i-1][j] * j;
  }

  /* limit for upperbound of binary search in solve_power() */
  rep(i,61) lim[i] = (ll) pow(1e18, 1.0/i);

  assert( scanf("%d",&N)==1 );
  assert( 1<=N && N<=314159 );
  rep(t,N){
    assert( scanf("%lld",&in)==1 );
    assert( 0<=in && in<=LIMIT );

    s1 = solve_power(in);
    s2 = solve_power(in-1);

    if(s1!=s2) res = s1; /* in = A^B */
    else       res = solve_non_power(in-s1+1); /* in != A^B */

    if(t) putchar(' ');
    printf("%d",res);
  }
  puts("");

  return 0;
}
