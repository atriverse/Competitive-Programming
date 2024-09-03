#include<bits/stdc++.h> 
using namespace std;
#define ll long long

/**
 * Finds the number of right triangles that can be formed using the given points.
 * The points are stored in two sets, one for points with y=1 and one for points with y=0.
 * The function iterates through the points with y=0 and checks if there are any points with y=1 that can form a right triangle with the current point.
 * It also checks if there are any points with y=0 that can form a right triangle with the current point and the point to its left or right.
 * The function then iterates through the points with y=1 and performs a similar check.
 * The total number of right triangles is stored in the `ans` variable and returned.
 */
void fn() {
    int n; cin >> n;
    set<int> one;
    set<int> zero;
    for (int i = 0; i < n; ++i) {
        int x, y;cin >> x >> y;
        if(y == 1) one.insert(x);
        else zero.insert(x);
    }
    ll ans = 0;
    for (int i : zero) {
        if (one.count(i)) {ans += one.size() - 1;}
        if(one.count(i - 1) && one.count(i + 1)) { ans += 1;}
    }
    for (int i : one) {
        if (zero.count(i)) {ans += zero.size() - 1;}
        if(zero.count(i - 1) && zero.count(i + 1)) { ans += 1;}
    }
    cout << ans << endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        fn();
    }
    return 0;
}
// 3
// 5
// 1 0
// 1 1
// 3 0
// 5 0
// 2 1
// 3
// 0 0
// 1 0
// 3 0
// 9
// 1 0
// 2 0
// 3 0
// 4 0
// 5 0
// 2 1
// 7 1
// 8 1
// 9 1

/*
Editorial:

Initially, the obvious case one might first consider is an upright right triangle (specifically, the triangle with one of its sides parallel to the y-axis). This side can only be made with two points in the form (x,0) and (x,1). We only need to search third point. Turns out, the third point can be any other unused vertex! If the third point has y=0, then it will be an upright triangle, but if the third point has y=1, it will simply be upside down.

One of the other case is in the form of (x,0),(x+1,1),(x+2,0). Let's see why this is a right triangle. Recall that in right triangle, the sum of the squares of two of the sides must equal to the square of the third side. The length between the first and the second point is 2–√ because it is the diagonal of 1 by 1 unit block. Similarily, the second and third point also has length 2–√. Obviously, the length between the first and third point is 2. Since we have 2–√2+2–√2=22, this is certainly a right triangle. Of course, we can flip the y values of each point and it will still be a valid right triangle, just upside down.
*/