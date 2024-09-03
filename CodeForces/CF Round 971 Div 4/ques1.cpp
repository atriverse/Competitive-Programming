#include<bits/stdc++.h>
using namespace std;

// No logic used blind solution
int f(int a, int b){
    int c=INT_MAX;
    for (int i = a; i <= b; i++)
    {
        c=min(c,((i-a)+(b-i)));
    }
    return c;
}

// Simple maths
int f1(int a, int b){
    //ans=(c−a)+(b−c)==b-a
    //Means c does not matter at all answer will always be b-a
    return b-a;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<f(a,b)<<endl;
        cout<<f(a,b)<<endl;
    }
    return 0;
}

/*
Editorial:
We choose c between a and b (a≤c≤b). The distance is (c−a)+(b−c)=b−a. Note that the distance does not depend on the the position c at all.
*/