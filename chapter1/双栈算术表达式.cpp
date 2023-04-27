#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<string> ops = stack<string>();
    stack<double> vals = stack<double>();
    string s;
    while (cin >> s) {
        if (s == "(") {
            continue;
        } else if (s == "+" || s == "-" || s == "*" || s == "/") {
            ops.push(s);
        } else if (s == ")") {
            string op = ops.top();
            ops.pop();
            double v = vals.top();
            vals.pop();
            if (op == "+") {
                v = vals.top() + v;
            } else if (op == "-") {
                v = vals.top() - v;
            } else if (op == "*") {
                v = vals.top() * v;
            } else if (op == "/") {
                v = vals.top() / v;
            }
            vals.pop();
            vals.push(v);
        } else {
            vals.push(stod(s));
        }
    }
    cout << vals.top() << endl;
}
