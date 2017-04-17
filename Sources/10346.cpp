#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N,K,total,x,y;

    while(scanf("%d %d",&N,&K) != EOF)
    {
        total = N;
        while(N >= K)
        {
            x = (N%K); // as a example 58 / 15 for this i will get 3 ..and rest of the will be 13. So again for 3 and 13 I will get 16

            N /= K; // for 16 I will get i will get one more cigs. so total 58+3+1 = 62
            total += N;
            if(x != 0) // I just added the rest number if there is no external number then I didn't add .
            {
                N += x;
            }

        }
        cout<<total<<endl;

    }



    return 0;
}
