/*
len 10 hoile wide hoy 6
len 1 hoile wide hoy 6/10 ja = 3/5

ekhon length er koge 3/5 gun korle wide pamu
len theika wide bad dile pamu baash. ar baassh re dui dia vag korle pamu radius
Red area hoibo = pi*r*r
green are hoibo = (l*r) - Red

*/

#include<bits/stdc++.h>
#define pi acos(-1) // given in description

using namespace std;

int main()
{
    int len;
    double green,red,wide,rad;
    int kase;
    scanf("%d",&kase);

    while(kase--)
    {
        scanf("%d",&len);
        wide = ((len*1.00)*3.00)/5.00;
        rad = (len-wide)/2.00;

        //cout<<len<<" "<<wide<<" "<<rad<<endl;


        red = (pi*(rad*rad));

        green = (len*wide)-(red);

        printf("%0.2lf %0.2lf\n",red,green);
    }


    return 0;
}
