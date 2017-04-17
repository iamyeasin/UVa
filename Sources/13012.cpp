#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int ans[6],counter = 0;
        for(int i=0; i<5; i++)
        {
            scanf("%d",&ans[i]);
            if(n == ans[i])
                counter++;
        }
        cout<<counter<<endl;
    }

    return 0;
}
