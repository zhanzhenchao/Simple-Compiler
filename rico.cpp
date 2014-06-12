#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<fstream>
#include"Stack.h"
#include"Lexical.h"
#include"GM_Analytics.h"
#include"Global_Variable.h"

using namespace std;

int main()
{
    Lexical lex1;

    /*
      //----This part is for ifstream----//
    int j = 0;
    int k = 0;
    char rico[1000];
    ifstream ifile("file_test.cpp");
    while (!ifile)
    {
        cout<<"open error!"<<endl;
        exit(1);
    }
    string s;
    while (ifile >> s)
    {
        int i = 0;
        while ( i != s.length())
          rico[j++] = s[i++];
    }
    rico[j] = '\0';
     //----This part is for ifstream----//
    */

    
    int p = 0,q = 0;
    char ch;
    while (ch != '#')
    {
        cin.get(ch);
        record[q++] = ch;
    }
    record[q] = '\0';
    
    while ( p!= q)
    {
        //cout<<record[k];
        lex1.analytics(p);
        p++;
    }
    //cout<<GetTheReserved_ALL<<endl;
    //test:get the characters after Lexical operation
    GM_Analytics A;
    A.LR_Analytics();
}
