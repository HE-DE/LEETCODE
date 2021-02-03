#include <iostream>
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
    for (int j = 0; j < n - 1; j++)
    {
        for (int k = j + 1; k < n; k++)
        {
            temp1 = a[j] + a[k];
            if (temp1 == result)
            {
                cout << j << "," << k << endl;
                break;
            }
        }
    }
    system("pause");
    return 0;
}