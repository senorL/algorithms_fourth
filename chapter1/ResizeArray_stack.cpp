#include <bits/stdc++.h>
using namespace std;
//以下是一个可变数组实现的栈
class LinkStack
{
    private:
        string *s = new string[1];
        int n;
        int capacity = 1;

    public:
        void push(string item)
        {
            if (n == capacity) 
                resize(2 * capacity);
            s[n++] = item;
        }
        void resize(int cap) 
        {
            string *copy = new string[cap];
            for (int i = 0; i < n; i++)
                copy[i] = s[i];
            delete[] s;
            s = copy;
            capacity = cap;
        }
        string pop()
        {
            string item = s[--n];
            if (n > 0 && n == capacity / 4)
                resize(capacity / 2);
            return item;
        }
        bool empty()
        {
            return n == 0;
        }
};
int main() 
{
    LinkStack link;
    string s;
    while (cin >> s)
    {
        if (s == "-")
            cout << link.pop() << " ";
        else
            link.push(s);
    }
    cout << endl;
        return 0;
}
