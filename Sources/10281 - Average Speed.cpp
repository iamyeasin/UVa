#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;


int main(){
//    freopen("in.txt", "rt" , stdin);

    char line[1234];
    int hh=0,mm=0,ss=0,vel=0;
    int phh=0,pmm=0,pss=0,pvel=0;
    double path=0.0,time=0.0,ftime=0.00;

    gets(line);
    int sz = strlen(line);
    if(sz<=8){
        pf("%s 0.00 km\n",line);
    }
    else{
        sscanf(line, "%d:%d:%d %d",&phh,&pmm,&pss,&pvel);
    }

    while(gets(line)){
        if(!line)return 0;
        sz = strlen(line);

        if(sz > 8) {
            vel = pvel;
            sscanf(line , "%d:%d:%d %d",&hh,&mm,&ss,&pvel);
            time = ((hh-phh) * 3600.00) + (((mm - pmm)*60.000) + (ss-pss));
            path += ((time * vel)/3600.00);

        }
        else {
            sscanf(line ,"%d:%d:%d", &hh,&mm,&ss);
            time = ((hh-phh) * 3600.00) + (((mm - pmm)*60.000) + (ss-pss));
            path += ((time * pvel)/3600.00);

            pf("%s %0.2lf km\n",line,path);
        }
        phh = hh, pmm = mm, pss = ss;
    }



    return 0;
}
