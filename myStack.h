#include <bits/stdc++.h>
using namespace std;

template <typename N>
class Node
{

public:
    N value;
    Node *next;
    Node *prev;

    Node(N val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};

template <typename S>
class Stack
{
    Node<S> *head;
    Node<S> *top;
    int count = 0;

public:
    Stack()
    {
        head = NULL;
        top = NULL;
    }
    // PUSH
    void push(S val)
    {
        Node<S> *newNode = new Node<S>(val);

        if (head == NULL)
        {
            head = top = newNode;
            count++;
            return;
        }

        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        count++;
    }

    // POP
    S pop()
    {
        Node<S> *delNode;
        delNode = top;
        S chk;

        if (head == NULL) // If there is no value on the stack
        {
            cout << "Stack Underflow" << endl;
            return chk;
        }

        if (top == head) // if there is only one element
        {
            head = top = NULL;
        }
        else // else there is more then one element
        {
            top = delNode->prev;
            top->next = NULL;
        }
        chk = delNode->value;
        delete delNode;
        count--;
        return chk;
    }

    // is empty ??
    bool isEmpty()
    {

        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // SIZE
    int size()
    {
        return count;
    }

    // TOP
    S Top()
    {
        S chk;
        if (head == NULL) // If there is no value on the stack
        {
            cout << "Stack Underflow | There is no element in Top" << endl;
        }
        else
        {
            chk = top->value;
        }
        return chk;
    }
};
