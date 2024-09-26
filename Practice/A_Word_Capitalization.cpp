#include<bits/stdc++.h>
using namespace std;

/**
 * Reads a string from the user, capitalizes the first character, and prints the modified string.
 */
int main()
{
    string s;
    cin>>s;
    s[0]=toupper(s[0]);
    cout<<s;
    return 0;
}