#include <bits/stdc++.h>
using namespace std;

class minPriorityQ
{

private:
    vector<int> v;
    int leftChild(int i)
    {
        return (i * 2) + 1;
    }
    int rightChild(int i)
    {
        return (i * 2) + 2;
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    void heapify(int start)
    {
        int leftIdx = leftChild(start);
        int rightIdx = rightChild(start);

        int smallest = start;
        if (leftIdx < v.size() && v[leftIdx] < v[smallest])
        {
            smallest = leftIdx;
        }
        if (rightIdx < v.size() && v[rightIdx] < v[smallest])
        {
            smallest = rightIdx;
        }

        if (start != smallest)
        {
            swap(v[start], v[smallest]);
            heapify(smallest);
        }
    }

public:
    void Push(int val)
    {
        v.push_back(val);

        int currentIdx = v.size() - 1;
        while (v[currentIdx] < v[parent(currentIdx)])
        {
            swap(v[currentIdx], v[parent(currentIdx)]);
            currentIdx = parent(currentIdx);
        }
    }
    int Top()
    {
        return v[0];
    }
    void Pop()
    {
        v[0] = v[v.size() - 1];
        v.pop_back();
        heapify(0);
    }
    bool Empty()
    {
        return v.size() == 0;
    }
};

int main()
{
    minPriorityQ pq;
    pq.Push(5);
    pq.Push(10);
    pq.Push(1);
    pq.Push(3);
    pq.Push(15);
    pq.Push(7);

    while (!pq.Empty())
    {
        int v = pq.Top();
        pq.Pop();
        cout << v << " ";
    }
    cout << endl;

    return 0;
}