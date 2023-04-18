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
    }//��p���ڵķ��������д����ֵ����Ϊq��ֵ
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
    }//�ҵ�i�ĸ��ڵ�

    bool connected(int p, int q)
    {
        return root(p) == root(q);
    }

    void union_(int p, int q)
    {
        int i = root(p);
        int j = root(q);
        id[i] = j;
    }//��p�ĸ��ڵ��ֵ��Ϊq�ĸ��ڵ��ֵ
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
        }//��¼ÿ�����ڵ�����Ӧ�ķ����Ĵ�С
    }
    int root(int i)
    {
        while (i != id[i])
        {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }//�ҵ�i�ĸ��ڵ㣬·��ѹ��

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
    }//��С���ĸ��ڵ����ӵ������ĸ��ڵ�
};
