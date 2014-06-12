#ifndef GM_Analytics_h

#define GM_Analytics_h

#include"Global_Variable.h"
#include"GM_imformation.h"
#include<iostream>
using namespace std;

//------------------Grammer Analytics class-----------//
class GM_Analytics
{
public:
    GM_Analytics();
    ~GM_Analytics();
    int TransferToACTION(const char a);
    int TransferToGOTO(char a);
    void LR_Analytics();
    void GM_display(char a, char b, char c);
};

GM_Analytics::GM_Analytics(){}

GM_Analytics::~GM_Analytics(){}

int GM_Analytics::TransferToACTION(const char a)
{
  switch(a)
  {
  case'i': return 0;
  case'+': return 1;
  case'-': return 2;
  case'*': return 3;
  case'/': return 4;
  case'(': return 5;
  case')': return 6;
  case';': return 7;
  }
}

int GM_Analytics::TransferToGOTO(char a)
{
  switch(a)
    {
    case'E': return 0;
    case'T': return 1;
    case'F': return 2;
    }
}

void GM_Analytics::LR_Analytics()
{
    int d = 0,x = 0;
    Stack *s = (struct Stack*)malloc(sizeof(Stack)); //*************
    s->top = 0;
    s->data[s->top] = 0;
    char a = GetTheReserved_ALL[d++];
    GM_Analytics R1;
    x = R1.TransferToACTION(a);                //new Grammer Analytics object R1

    /*
    Stack *ssd = (struct Stack*)malloc(sizeof(Stack));
    ssd->top = 0;
    ssd->data[ssd->top] = 'a';
    int lo;
    char tp[1000];
    memset(tp, 0, sizeof(char)*1000);
    */
    
    while(1)
    {
        int k = s->data[s->top];
        if ( ACTION[k][x] > 0 && ACTION[k][x] != 100)
        {
            Push(s,ACTION[k][x]);                       //transfer a
            //Push(ssd,a);                              //Tracking the Grammer analytics stack
            a = GetTheReserved_ALL[d++];
            x = R1.TransferToACTION(a);
        }
        else if ( ACTION[k][x] < 0)
        {
            int temp = abs(ACTION[k][x]) - 1;
            int b = ExtGraNum[temp];
            for (int i = 0; i < b; i++)
            {
                Pop(s,1);
                //tp[lo++] = Pop(ssd,'a');
            }
            int t = s->data[s->top];
            int temp2 = R1.TransferToGOTO(ExtGra[temp][0]);
            Push(s,GOTO[t][temp2]);                      //transfer A
            //Push(ssd,ExtGra[temp][0]);
            
            cout<<ExtGra[temp]<<endl;
        }
        else if (ACTION[k][x] == 100)break;
        else abort();
     }
}



//------------------Grammer Analysis class-----------//

#endif