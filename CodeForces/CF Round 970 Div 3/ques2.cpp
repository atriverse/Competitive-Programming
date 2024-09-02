#include <bits/stdc++.h>
#include <math.h>
using namespace std;

void f(string s, int n)
{
    double x = sqrt(n);
    if (x - floor(x) == 0)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                count += 1;
            }
        }
        if ((4 * int(x) - 4) == count)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        f(s, n);
    }
    return 0;
}
/*
2008B - Square or Not
Assume that string was created from the beautiful binary matrix with size r×c.

If r≤2 or c≤2, then the whole matrix consists of '1'. This means that the string will have only one character and this is the only case such happening. So, if the whole string is constructed out of '1', we print "Yes" only if the size of the string is 4, since only r=c=2 is a good matrix for us.

Otherwise, we have at least one '0' in the string. Let's look at what is the index of the first '0'. If it has index r+1, since the whole first line and the first character of the first line equal to '1', so now, we have a fixed value of r (index of the first '0' minus 1) and the answer is "Yes" only if r is the square root of n.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int id=0;
        while(id<n&&s[id]=='1')
        {
            id++;
        }
        if(id==n)
        {
            if(n==4)
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
        else
        {
            if((id-1)*(id-1)==n)
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}
*/