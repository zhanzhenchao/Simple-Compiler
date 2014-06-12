#ifndef Lexical_h

#define Lexical_h

#include"Global_Variable.h"


//-----------------Lexical Analysis class-----------//
class Lexical
{
public:
    Lexical()
    {
        memset(track, 0, sizeof(char)*20);
    };
    ~Lexical(){};
    void analytics(int num);
private:
    void DisIni(char a[],int b);
    void GetTheReserved(int b);
    char ch,track[20];
};

void Lexical::DisIni(char a[],int b)
{
    int c = 0;
    if (*a != '\0')                    //eliminate NULL Element
    {
        GetTheReserved(b);
        /*
        if ( *a >= '0' && *a <= '9')
        {
            while (a[c++] != '\0')
            {
                SaveR[rc] = a;
            }
            //cout<<atoi(SaveR[rc].data())<<endl;                 //record the character what we are input;
        }
        rc++;
        */
        memset(track, 0, sizeof(char)*20);  //initialize the track
        count = 0;
    }
}

void Lexical::GetTheReserved(int b)
{
    switch(b)
    {
        case 1: GetTheReserved_ALL[countALL++] = 'r';break;
        case 2: GetTheReserved_ALL[countALL++] = 'w';break;
        case 3: GetTheReserved_ALL[countALL++] = 'i';break;
        case 4: GetTheReserved_ALL[countALL++] = 'n';break;
        case 5: GetTheReserved_ALL[countALL++] = '=';break;
        case 6: GetTheReserved_ALL[countALL++] = '<';break;
        case 7: GetTheReserved_ALL[countALL++] = '>';break;
        case 8: GetTheReserved_ALL[countALL++] = ';';break;
        case 9: GetTheReserved_ALL[countALL++] = '(';break;
        case 10: GetTheReserved_ALL[countALL++] = ')';break;
        case 11: GetTheReserved_ALL[countALL++] = '{';break;
        case 12: GetTheReserved_ALL[countALL++] = '}';break;
        case 13: GetTheReserved_ALL[countALL++] = '+';break;
        case 14: GetTheReserved_ALL[countALL++] = '-';break;
        case 15: GetTheReserved_ALL[countALL++] = '*';break;
        case 16: GetTheReserved_ALL[countALL++] = '/';break;
        case 17: GetTheReserved_ALL[countALL++] = '#';break;
        default:abort();
    }
}

void Lexical::analytics(int num)
{
    ch = record[num];
    //cout<<ch<<endl;
    if ((ch>='a' && ch<='z')||(ch>='A' && ch <='Z'))//Reserved words and ident
    {
        track[count++] = ch;
        symbol = 3;
        for (int i = 0; i < 2; i++)
            if ((strcmp(track,Reserved[i])==0))
            {
                symbol = i+1;
                break;
            }
    }
    else if (ch>='0' && ch<='9')
    {
        track[count++] = ch;
        symbol = 3;
    }
    else
    {
        DisIni(track,symbol);
        switch(ch)
        {
            case'=':
                track[count++] = ch;symbol = 5;DisIni(track,symbol);break;
            case'<':
                track[count++] = ch;symbol = 6;DisIni(track,symbol); break;
            case'>':
                track[count++] = ch;symbol = 7;DisIni(track,symbol); break;
            case';':
                track[count++] = ch;symbol = 8;DisIni(track,symbol); break;
            case'(':
                track[count++] = ch;symbol = 9;DisIni(track,symbol); break;
            case')':
                track[count++] = ch;symbol = 10;DisIni(track,symbol); break;
            case'{':
                track[count++] = ch;symbol = 11;DisIni(track,symbol); break;
            case'}':
                track[count++] = ch;symbol = 12;DisIni(track,symbol); break;
            case'+':
                track[count++] = ch;symbol = 13;DisIni(track,symbol); break;
            case'-':
                track[count++] = ch;symbol = 14;DisIni(track,symbol); break;
            case'*':
                track[count++] = ch;symbol = 15;DisIni(track,symbol); break;
            case'/':
                track[count++] = ch;symbol = 16;DisIni(track,symbol); break;
            case' ':
                DisIni(track,symbol);break;
            case'#':
                track[count++] = ch;symbol = 17;DisIni(track,symbol);break;
        }
    }
}

 //-----------------Lexical Analysis class-----------//

#endif