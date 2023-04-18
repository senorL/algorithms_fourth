#include <bits/stdc++.h>
using namespace std;
class QuickFindUF
{
private:
    vector<int> id;

public:
    QuickFindUF(int n)
    {
        for (int i = 0; i < n; i++)
        {
            id.push_back(i);
        }
    }

    bool connected(int p, int q)
    {
        return id[p] == id[q];
    }

    void union_(int p, int q)
    {
        int pid = id[p];
        int qid = id[q];
        for (int i = 0; i < id.size(); i++)
        {
            if (id[i] == pid)
                id[i] = qid;
        }
    }//将p所在的分量的所有触点的值都改为q的值
};

class QuickUnionUF
{
private:
    vector<int> id;

public:
    QuickUnionUF(int n)
    {
        for (int i = 0; i < n; i++)
        {
            id.push_back(i);
        }
    }
    int root(int i)
    {
        while (i != id[i])
            i = id[i];
        return i;
    }//找到i的根节点

    bool connected(int p, int q)
    {
        return root(p) == root(q);
    }

    void union_(int p, int q)
    {
        int i = root(p);
        int j = root(q);
        id[i] = j;
    }//将p的根节点的值改为q的根节点的值
};

class ImprovementQuickUnionUF
{
private:
    vector<int> id;
    vector<int> sz;

public:
    ImprovementQuickUnionUF(int n)
    {
        for (int i = 0; i < n; i++)
        {
            id.push_back(i);
        }
        for (int i = 0; i < n; i++)
        {
            sz.push_back(1);
        }//记录每个根节点所对应的分量的大小
    }
    int root(int i)
    {
        while (i != id[i])
        {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }//找到i的根节点，路径压缩

    bool connected(int p, int q)
    {
        return root(p) == root(q);
    }

    void union_(int p, int q)
    {
        int i = root(p);
        int j = root(q);
        if (i == j)
            return;
        if (sz[i] < sz[j])
        {
            id[i] = j;
            sz[i] += sz[j];
        }
        else
        {
            id[j] = i;
            sz[j] += sz[i];
        }
    }//将小树的根节点连接到大树的根节点
};
