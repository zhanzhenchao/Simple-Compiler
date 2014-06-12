#ifndef Stack_h

#define Stack_h

//-----------Stack---------//
struct Stack
{
    int data[30];
    int top;
};

bool StackEmpty(Stack *s)
{
    if (s->top == 0)
        return false;
    else return false;
}

template <class T>
void Push(Stack *s, T x)
{
    s->top++;
    s->data[s->top] = x;
}

template <class T>
T Pop(Stack *s,T a)
{
    if (StackEmpty(s))
        abort();
    else return s->data[s->top--];
}


#endif
//-----------Stack---------//
