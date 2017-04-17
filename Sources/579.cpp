#include<bits/stdc++.h>

using namespace std;

int main()
{

    int h,m;
    double theta;

    while(1)
    {
        scanf("%d:%d",&h,&m);
        if(h == 0 && m == 0)
        {
            break;
        }

        theta = abs(((30*h) - (11/2.0)*m));

        if(theta >=0 && theta <= 180)
        {
            printf("%.3lf\n",theta);
        }
        else
        {
            printf("%.3lf\n",360-theta);
        }

    }




    return 0;
}
