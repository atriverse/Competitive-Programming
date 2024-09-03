#include <bits/stdc++.h>

using namespace std;

bool f(int a, int b)
{
    // Total sum of all elements without signs
    int totalSum = a + 2 * b;

    // If the total sum is odd, it's impossible to make it zero
    if (totalSum % 2 != 0)
    {
        return false;
    }

    // The target sum we need to achieve with positive signs
    int targetSum = totalSum / 2;

    // Check if we can achieve the target sum using ones and twos
    for (int i = 0; i <= a; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if (i + 2 * j == targetSum)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (f(a, b))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}

/*
2008A - Sakurako's Exam

First of all, this task is the same as: "divide an array into two arrays with equal sum". So, obviously, we need to check if the sum of all elements is even which implies that the number of ones is even. Then, we can out half of 2s in one array and the other half in another, but if number of 2s is odd, then one array will have a greater sum then another, so we need to put two 1s there.

So, if we don't have two ones while the number of 2s is odd then the answer is "NO". Also, if sum is odd, the answer is also "NO". In all other cases, the answer is "YES".

#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int cnt1,cnt2;
        cin>>cnt1>>cnt2;
        if(cnt1%2)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            if(cnt2%2==0)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                if(cnt1==0)
                {
                    cout<<"NO"<<endl;
                }
                else
                {
                    cout<<"YES"<<endl;
                }
            }
        }
    }
}
*/