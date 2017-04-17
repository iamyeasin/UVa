#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#define pi 3.1416

using namespace std;

int main()
{
    int kase,T=0,i,j,k;
    double Ax,Ay,Ox,Oy,Bx,By,AB,OB,OA,theta,calc,radian,arc,eps=1e-10;

    scanf("%d",&kase);
    while(kase--)
    {
        scanf("%lf %lf %lf %lf %lf %lf",&Ox,&Oy,&Ax,&Ay,&Bx,&By);
        OA = sqrt(((Ax-Ox)*(Ax-Ox)) + ((Ay-Oy)*(Ay-Oy)));
        OB = sqrt(((Bx-Ox)*(Bx-Ox)) + ((By-Oy)*(By-Oy)));
        AB = sqrt(((Ax-Bx)*(Ax-Bx)) + ((Ay-By)*(Ay-By)));

        calc = ((OA*OA)+(OB*OB)-(AB*AB))/(2*OA*OB);
        theta = acos(calc);
        radian = 180/pi*theta; // Making it radian

        arc = (radian*2*pi*OA)/360;

        printf("Case %d: %0.8lf\n",++T,arc+eps);
    }




    return 0;
}


