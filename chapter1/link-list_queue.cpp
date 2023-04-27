#include <bits/stdc++.h>
using namespace std;
template<typename T>
struct Node 
{
    T item;
    Node<T> *next;
};
template<typename T>
class linkqueue
{
    private:
        Node<T> *first = nullptr;
        Node<T> *last = nullptr;

    public:
        bool isEmpty()
        {
            return first == nullptr;
        }
        void enqueue(T item)
        {
            Node<T> *oldlast = last;
            last = new Node<T>;
            last->item = item;
            last->next = NULL;
            if (isEmpty())
                first = last;
            else
                oldlast->next = last;
        }
        T dequeue()
        {
            T item = first->item;
            first = first->next;
            if (isEmpty())
                last = NULL;
            return item;
        }
};
int main()
{
    linkqueue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    return 0;
}
