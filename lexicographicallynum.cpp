#include <bits/stdc++.h>
using namespace std;

class lexicographicallynum
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> v;
        int count = 1;

        for (int i = 0; i < n; i++)
        {
            v.push_back(count);
            if (count * 10 <= n)
                count *= 10;
            else
            {
                if (count >= n)
                    count /= 10;
                count++;
                while (count % 10 == 0)
                {
                    count /= 10;
                }
            }
        }
        return v;
    }
};

int main()
{
    int n = 102;
    lexicographicallynum obj;
    vector<int> res = obj.lexicalOrder(n);
    cout << "Lexicogrphically numbers: ";

    for (const int &num : res)
    {

        cout << num <<" ";
    }

    return 0;
}