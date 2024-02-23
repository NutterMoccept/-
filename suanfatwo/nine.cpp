//单链表  有问题
#include <iostream>
#include <cstdio>

using namespace std;

const int N = 100010;

// head 表示头结点的下标
// e[i] 表示节点i的值
// ne[i] 表示节点i的next指针是多少
//  idx 存储当前已经用到了哪个点
int head, e[N], ne[N], idx;
//初始化
void init()
{
    head = -1; //等于-1表示指向空
    idx = 0;
}

//将x插到头结点
void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}
//将x插到下标是k的点后面
void add(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

//将下标是k的点后面的删掉
void remove(int k)
{
    ne[k] = ne[ne[k]]; //指向下一个的下一个
}

int main()
{
    int m;
    cin >> m;

    init();
    while (m--)
    {
        int k, x;
        char op;

        cin >> op;
        if (op == 'H')
        {
            cin >> x;
            add_to_head(x);
        }
        else if (op == 'D')
        {
            cin >> k;
            if (!k)
                head = ne[head];
            else
                remove(k - 1);
        }
        else
        {
            cin >> k >> x;
            add(k - 1, x);
        }
        for (int i = head; i != -1; i = ne[i])
            cout << e[i] << ' ';
        cout << endl;
        return 0;
    }
}