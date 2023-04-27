#include <bits/stdc++.h>
using namespace std;
//以下是使用可变数组实现的队列
class ResizeArrayQueue
{
    private:
        int *q;
        int head, tail;
        int length;
    public:
        ResizeArrayQueue(int n)
        {
            q = new int[n];
            head = tail = 0;
            length = n;
        }
        ~ResizeArrayQueue()
        {
            delete [] q;
        }
        void enqueue(int x)
        {
            if (tail == length)
            {
                if (head == 0)
                {
                    cout << "Queue is full!" << endl;
                    return;
                }
                for (int i = head; i < tail; i++)
                    q[i - head] = q[i];
                tail -= head;
                head = 0;
            }
            q[tail++] = x;
        }
        int dequeue()
        {
            if (head == tail)
            {
                cout << "Queue is empty!" << endl;
                return -1;
            }
            return q[head++];
        }
        bool isEmpty()
        {
            return head == tail;
        }
        int size()
        {
            return tail - head;
        }
};
int main()
{
    ResizeArrayQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    return 0;
}
