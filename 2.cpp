#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> num1;
    list<int> num2;
    list<int> result;
    int n1, n2;
    int temp;
    cin >> n1 >> n2;
    for (int i = 0; i < n1; i++)
    {
        cin >> temp;
        num1.push_back(temp);
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> temp;
        num2.push_back(temp);
    }
    int length1 = num1.size();
    int length2 = num2.size();
    if (length1 > length2)
    {
        for (int j = 0; j < length1 - length2; j++)
        {
            num2.push_back(0);
        }
    }
    else if (length2 > length1)
    {
        for (int j = 0; j < length2 - length1; j++)
        {
            num1.push_back(0);
        }
    }

    int m = max(length1, length2);
    list<int>::iterator it1 = num1.begin();
    list<int>::iterator it2 = num2.begin();

    for (int l = 0; l < m; l++)
    {
        temp = *it1 + *it2;
        result.push_back(temp);
        it1++;
        it2++;
    }
    list<int>::iterator r3 = result.begin();

    while (r3 != result.end())
    {
        if (*r3 >= 10)
        {
            temp = *r3 % 10;
            *r3 = temp;
            if (++r3 == result.end())
            {
                result.push_back(1);
                r3--;
            }
            else
            {
                *r3 += 1;
                r3--;
            }
        }
        r3++;
    }

    r3 = result.begin();
    while (r3 != result.end())
    {
        cout << *r3 << " ";
        r3++;
    }
    cout << endl;
    system("pause");
    return 0;
}