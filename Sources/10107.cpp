#include<bits/stdc++.h>

using namespace std;

int main()
{

    //freopen("C:\\Users\\Yeasin\\Desktop\\input.txt","rt",stdin);
    //freopen("C:\\Users\\Yeasin\\Desktop\\output.txt","wt",stdout);

    long  input[10000];

    int i=0;
    while(cin>>input[i])
    {
        sort(input,input+i+1);
        if(i == 0)
        {
            printf("%d\n",input[0]);
            i++;
            continue;
        }

        if(i&1)
        {
            int ind = i/2;
            int sum = (input[ind]+input[ind+1])/2;

            cout<<sum<<endl;
        }
        else
        {
            int ind = i/2;
            cout<<input[ind]<<endl;
        }


        i++;
    }


    return 0;
}
