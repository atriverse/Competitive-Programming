#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    
    // Store coordinates in array
    int coords[3] = {x1, x2, x3};
    
    // Sort the coordinates
    sort(coords, coords + 3);
    
    // The optimal meeting point is at the median (middle point)
    // Total distance is distance from leftmost to median plus distance from rightmost to median
    int total_distance = (coords[2] - coords[1]) + (coords[1] - coords[0]);
    
    cout << total_distance << endl;
    
    return 0;
}
