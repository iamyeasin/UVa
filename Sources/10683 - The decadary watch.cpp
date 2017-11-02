#include<stdio.h>

void s(){

    const long MS_DAY = 125;// const optimizes the time too
    constlong DS_DAY = 108;

    int cur_time, metric;
    int hh=0,mm=0,ss=0,cc=0;
    char t[9];

    while( gets(t) ){
        hh = (t[0]-'0')*10 + (t[1]-'0');
        mm = (t[2]-'0')*10 + (t[3]-'0');
        ss = (t[4]-'0')*10 + (t[5]-'0');
        cc = (t[6]-'0')*10 + (t[7]-'0');

        cur_time = (hh*3600 + mm*60 + ss ) * 100 + cc;
        metric = (cur_time * MS_DAY/DS_DAY);
        printf("%07d\n",metric);

    }

}

main(){
    s(); // This optimizes the time a bit

    return;
}

