#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class status {
public:
    string str;
    int cnt;

    status(string a, int b)
    {
        str = a;
        cnt = b;
    }
};

int check(string a, string b)
{
    int c = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
            c++;
    }
    return c;
}

int main()
{
    int visited[50] = { 0 };
    int answer = 0;
    int flag = 0;
    int cnt = 0;
    string begin = "abc";
    string target = "dog";
    vector<string> words = { "abb","abd","dog" };
    for (int i = 0; i < words.size(); i++)
    {
        if (target == words[i])
            flag = 1;
    }
    if (flag == 0)
        return 0;

    queue<status> queue;

    status start(begin, 0);
    queue.push(start);

    while (!queue.empty())
    {
        string cur = queue.front().str;
        cnt = queue.front().cnt;
        queue.pop();
        if (cur == target)
        {
            flag = 0;
            break;
        }

        for (int i = 0; i < words.size(); i++)
        {
            if (visited[i] != 1 && check(cur, words[i]) == 1)
            {
                visited[i] = 1;
                status next(words[i], cnt + 1);
                queue.push(next);
            }
        }
    }

    if (flag == 0)
        cout << cnt;
    else
        cout << 0;
}