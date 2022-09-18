#include <bits/stdc++.h>
#include "myQueue.h"
using namespace std;

int main()
{
    Queue<int> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int chk;
        cin >> chk;
        q.push(chk);
    }

    // while (!q.empty())
    // {
    //     cout << q.pop() << " ";
    // }
    // cout << endl;

    if (!q.empty())
    {
        cout << "Front element: " << q.Front() << endl;
    }
    if (!q.empty())
    {
        cout << "Back element: " << q.Back() << endl;
    }

    return 0;
}