#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int n, temp1, result;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        cin >> temp1;
        a.push_back(temp1);
    }
    cin >> result;
    map<int, int> b;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> c(a[i], i);
        if (b.find(result - a[i]) != b.end())
        {
            cout << b.find(result - a[i])->second << "," << i << endl;
            break;
        }
        b.insert(c);
    }
    system("pause");
    return 0;
}