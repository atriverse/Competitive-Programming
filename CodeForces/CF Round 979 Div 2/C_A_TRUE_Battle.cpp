#include <iostream>
#include <string>
#include <vector>

using namespace std;

void aliceWins(const string& booleans) {
    int n = booleans.size();
    int aliceWins = 0;
    for (int i = 0; i < n; i++)
    {
        if (booleans[i] == '1')
        {
            if (i==0 || i==n-1 || (i>0 && booleans[i-1] == '1') || (i<n-1 && booleans[i+1] == '1'))
            {
                aliceWins=1;
                break;
            }
            
        }
        
    }
    string ans=(aliceWins)?"YES":"NO";
    cout<<ans<<endl;
    
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string booleans;
        cin >> booleans;

        aliceWins(booleans);
    }

    return 0;
}
