// #include <iostream>
// #include <vector>

// using namespace std;

// const int MOD = 1e9 + 7;

// long long modInverse(long long a, long long m) {
//     long long m0 = m, t, q;
//     long long x0 = 0, x1 = 1;
//     if (m == 1) return 0;
//     while (a > 1) {
//         q = a / m;
//         t = m;
//         m = a % m, a = t;
//         t = x0;
//         x0 = x1 - q * x0;
//         x1 = t;
//     }
//     if (x1 < 0) x1 += m0;
//     return x1;
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<long long> a(n);
//         long long sum = 0;
//         for (int i = 0; i < n; i++) {
//             cin >> a[i];
//             sum = (sum + a[i]) % MOD;
//         }
//         long long P = (sum * sum) % MOD;
//         long long Q = (1LL * n * n) % MOD;
//         long long Q_inv = modInverse(Q, MOD);
//         long long result = (P * Q_inv) % MOD;
//         cout << result << endl;
//     }
//     return 0;
// }
/*
2008F - Sakurako's Box
By the statement, we need to find the value of this expresion ∑ni=0∑nj=i+1ai⋅ajn⋅(n−1)2. Let's find this two values separately. For the first, we can do it in several ways. We can see that this sum equal to ∑ni=0ai⋅(∑nj=i+1aj) and compute by prefix sum. Also, we can notice that it is equal to (∑ni=0ai)2−∑ni=0a2i2. Note, that for second approach you need to use division by modulo, i.e. 2−1=2p−2 for prime p. To compute n⋅(n−1)2, you can compute n⋅(n−1) by modulo and than use division by modulo for 2−1. Then, also using division by modulo you need to delete first value by second.
*/
#include <bits/stdc++.h>

using namespace std;
constexpr int mod=1e9+7;

/**
 * Calculates the binary exponentiation of a number `a` raised to the power of `b` modulo `mod`.
 *
 * @param a The base number.
 * @param b The exponent.
 * @return The result of `a^b % mod`.
 */
long long binpow(long long a,long long b)
{
    if(b==0)
    {
        return 1;
    }
    if(b%2)
    {
        return (a*binpow(a,b-1))%mod;
    }
    return binpow((a*a)%mod,b/2);
}

/**
 * Calculates the sum of squares of the elements in an array, and then computes the result of the expression (sum^2 - sum of squares) * (n*(n-1)/2)^-1 modulo MOD.
 *
 * @param n The size of the input array.
 * @param a The input array of long long integers.
 * @param MOD The modulo value to use in the calculations.
 * @return The result of the expression (sum^2 - sum of squares) * (n*(n-1)/2)^-1 modulo MOD.
 */
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long a[n],sum=0,sumsq=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];sum%=mod;
            sumsq+=a[i]*a[i];
            sumsq%=mod;
        }
        sum*=sum;sum%=mod;
        sum=(sum-sumsq+mod)%mod;
        sum=(sum*binpow(2,mod-2))%mod;
        long long cnt=n*(n-1)/2;cnt%=mod;
        cout<<(sum%mod)*binpow(cnt,mod-2)%mod<<endl;
    }
}