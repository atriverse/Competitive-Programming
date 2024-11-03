#include <iostream>
using namespace std;

int main() {
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    
    int damaged = 0;
    
    // Check each dragon from 1 to d
    for(int i = 1; i <= d; i++) {
        // If dragon number is divisible by any of k,l,m,n
        // then it got damaged
        if(i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0) {
            damaged++;
        }
    }
    
    cout << damaged << endl;
    return 0;
}
