#include <bits/stdc++.h>
#include "myStack.h"
using namespace std;

int precisionCalc(char c)
{

    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
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

string infixToPrefix(string chk)
{

    reverse(chk.begin(), chk.end());

    Stack<char> st;

    string result;

    for (int i = 0; i < chk.length(); i++)
    {
        char c = chk[i];
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            result += c;
        }
        else if (c == ')')
        {
            st.push(c);
        }
        else if (c == '(')
        {
            while (!st.isEmpty() && st.Top() != ')')
            {
                result += st.pop();
            }
            if (!st.isEmpty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.isEmpty() && precisionCalc(st.Top()) >= precisionCalc(chk[i]))
            {
                if (c == '^' && st.Top() != '^')
                {
                    break;
                }
                result += st.pop();
            }
            st.push(chk[i]);
        }
    }

    while (!st.isEmpty())
    {
        result += st.pop();
    }

    reverse(result.begin(), result.end());

    return result;
}

int prefixEvaluation(string chk)
{

    Stack<int> st;

    for (int i = chk.length() - 1; i >= 0; i--)
    {
        if (chk[i] >= '0' && chk[i] <= '9')
        {
            st.push(chk[i] - '0');
        }
        else
        {
            int a = st.pop();
            int b = st.pop();

            switch (chk[i])
            {
            case '+':
                st.push(a + b);
                break;
            case '-':
                st.push(a - b);
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
                st.push(a / b);
                break;
            case '^':
                st.push(pow(a, b));
                break;
            default:
                break;
            }
        }
    }

    return st.Top();
}

/*
Test case:

1. (4*2)+3 = 11
2. (7+(4*5))-(2+0) = 25

*/

int main()
{
    string infix = "2^2^3";
    string prefix;
    prefix = infixToPrefix(infix);

    cout << "Prefix = " << prefix << endl;
    cout << "Result = " << prefixEvaluation(prefix) << endl;

    return 0;
}