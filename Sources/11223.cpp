///Used Stringstream & cpp String data type.
///Occurs WA in char by char reading.
///StringStream is awesome! it tokenize the line of string

#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("C:\\Users\\Yeasin\\Desktop\\input.txt","rt",stdin);
    //freopen("C:\\Users\\Yeasin\\Desktop\\output.txt","wt",stdout);


    map <string, string > mp;

    mp[".-"] = 'A';
    mp["-..."] ='B';
    mp["-.-."] ='C';
    mp["-.."] ='D';
    mp["."] ='E';
    mp["..-."] ='F';
    mp["--."] ='G';
    mp["...."] ='H';
    mp[".."] ='I';
    mp[".---"] ='J';
    mp["-.-"] ='K';
    mp[".-.."] ='L';
    mp["--"] ='M';
    mp["-."] ='N';
    mp["---"] ='O';
    mp[".--."] ='P';
    mp["--.-"] ='Q';
    mp[".-."] ='R';
    mp["..."] ='S';
    mp["-"] ='T';
    mp["..-"] ='U';
    mp["...-"] ='V';
    mp[".--"] ='W';
    mp["-..-"] ='X';
    mp["-.--"] ='Y';
    mp["--.."] ='Z';
    mp["-----"] ='0';
    mp[".----"] ='1';
    mp["..---"] ='2';
    mp["...--"] ='3';
    mp["....-"] ='4';
    mp["....."] ='5';
    mp["-...."] ='6';
    mp["--..."] ='7';
    mp["---.."] ='8';
    mp["----."] ='9';
    mp[".-.-.-"] ='.';
    mp["--..--"] =',';
    mp["..--.."] ='?';
    mp[".----."] ='\'';
    mp["-.-.--"] ='!';
    mp["-..-."] ='/';
    mp["-.--."] ='(';
    mp["-.--.-"] =')';
    mp[".-..."] ='&';
    mp["---..."] = ':';
    mp["-.-.-."] = ';';
    mp["-...-"] = '=';
    mp[".-.-."] = '+';
    mp["-....-"] = '-';
    mp["..--.-"] = '_';
    mp[".-..-."] = '"';
    mp[".--.-."] = '@';

    string s1,s2,words,nline,line;

    int kase;
    cin>>kase;
    getchar();

    for(int i=1; i<=kase; i++)
    {
        nline = ""; ///Khali ekta string
        getline(cin,line); /// Pura string ta input nilam
        stringstream iS(line); /// pura string input nia oitar vitore abar loop calamu. word gula alada korar liga
        int sp=0; /// Jeisob position e space ase oishob position e space jog kormu notun string e

        while(iS >> words) /// word input kortasi
        {
            nline += mp[words]; /// notun string e word concat kortasi
            sp += words.size()+1; /// space er position bair korlam ekta word input newar por

            while(sp < line.size() && line[sp] == ' ')/// first condition e check korsi je space ki sesh line er cheye choto naki
                                        ///second condition e check korsi je jodi oi position e space thake taile space jog korte abar
                                            ///porer position e jaite.jodi oikhaneo space thake taile notun string er loge space jog korte
            {
                nline += ' ';
                sp++;
            }
        }

        printf("Message #%d\n",i); /// Ehon khali print koro thats all.
        cout<<nline<<endl; /// Sob kisu milaia notun string eita

        if(i != kase)
        {
            printf("\n");
        }

    }


    return 0;
}
