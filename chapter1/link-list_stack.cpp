#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct Node
{
    T item;
    Node<T>* next;
};
template <typename T>
class LinkStack
{
    private:
        Node<T>* first = NULL;
    public:
        bool isEmpty()
        {
            return first == NULL;
        }
        void push(T item)
        {
            Node<T>* oldfirst = first;
            first = new Node<T>();
            first->item = item;
            first->next = oldfirst;
        }
        T pop()
        {
            T item = first->item;
            first = first->next;
            return item;
        }
};
int main() 
{
    LinkStack<int> link;
    int s;
    while(cin >> s)
    {
        link.push(s);
        link.pop();
    }
    cout << link.isEmpty() << endl;
    return 0;
}
