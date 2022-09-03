#include <bits/stdc++.h>
#include "myStack.h"
using namespace std;

// return precedence of operators
int precedence(char c)
{

    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixToPostfix(string str)
{

    Stack<char> st;

    string result;

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            result += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (st.Top() != '(')
            {
                result += st.Top();
                st.pop();
            }
            if (!st.isEmpty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.isEmpty() && precedence(str[i]) <= precedence(st.Top()))
            {
                if (c == '^' && st.Top() != '^')
                {
                    break;
                }
                else
                {
                    result += st.Top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }

    while (!st.isEmpty())
    {
        result += st.Top();
        st.pop();
    }

    return result;
}

int postfixEvaluation(string str)
{
    Stack<int> st;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            st.push(str[i] - '0');
        }
        else
        {

            int a = st.pop();
            int b = st.pop();

            switch (str[i])
            {
            case '+':
                st.push(a + b);
                break;
            case '-':
                st.push(b - a);
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(b / a);
                break;
            case '^':
                st.push(pow(b, a));
                break;
            default:
                break;
            }
        }
    }

    return st.Top();
}

/*
((4*2)+3) == 11
(7+(4*5))-(2+0) = 25
(4*(3+5))-(2+0) = 30
*/

int main()
{
    string exp = "2+(4/2)";
    string postfixStr = infixToPostfix(exp);

    int result = postfixEvaluation(postfixStr);
    cout << "postfix exp = " << postfixStr << endl;
    cout << "Result = " << result << endl;
    return 0;
}