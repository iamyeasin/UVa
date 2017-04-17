/*HINTS : Sequence n*(n-1)/2+1*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    long n;
    while(scanf("%ld",&n) != EOF)
    {
        if(n<0) break;
        //long an = ((n*(n+1))/2)+1;
        long ans = (n*(n+1));
        ans =ans>>1;

        printf("%ld\n",ans+1);
    }

    return 0;
}
