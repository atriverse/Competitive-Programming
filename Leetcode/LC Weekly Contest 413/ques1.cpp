/*
Check if two chessboard squares have the same color

You are given two strings, coordinate1 and coordinate2, representing the coordinates of a square on an 8 x 8 chessboard.

Below is the chessboard for reference.

8  1 0 1 0 1 0 1 0
7  0 1 0 1 0 1 0 1
6  1 0 1 0 1 0 1 0
5  0 1 0 1 0 1 0 1
4  1 0 1 0 1 0 1 0     where 1==white, 0==black
3  0 1 0 1 0 1 0 1
2  1 0 1 0 1 0 1 0
1  0 1 0 1 0 1 0 1
   a b c d e f g h

Return true if these two squares have the same color and false otherwise.

The coordinate will always represent a valid chessboard square. The coordinate will always have the letter first (indicating its column), and the number second (indicating its row).

Example 1:

Input: coordinate1 = "a1", coordinate2 = "c3"

Output: true

Explanation:

Both squares are black.

Example 2:

Input: coordinate1 = "a1", coordinate2 = "h3"

Output: false

Explanation:

Square "a1" is black and "h3" is white.

Constraints:

coordinate1.length == coordinate2.length == 2
'a' <= coordinate1[0], coordinate2[0] <= 'h'
'1' <= coordinate1[1], coordinate2[1] <= '8'
*/
#include<bits/stdc++.h>

using namespace std;    
class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        char arr1[8]={'a','b','c','d','e','f','g','h'};
        char arr2[8]={'1','2','3','4','5','6','7','8'};
        int indc1=0,indc2=0;
        int indc11=0,indc22=0;
        for(int i=0;i<8;i++){
            if(coordinate1[0]==arr1[i]){                
                indc1=i;//0
            }
            if(coordinate2[0]==arr1[i]){
                indc2=i;//7
            }
            if(coordinate1[1]==arr2[i]){
                indc11=i;//0
            }
            if(coordinate2[1]==arr2[i]){
                indc22=i;//2
            }
        }
        if( (indc1+indc11)%2==0 && (indc2+indc22)%2==0)
        {
            return true;
        }
        else if ((indc1+indc11)%2!=0 && (indc2+indc22)%2!=0)
        {
            return true;
        }
        else{
            return false;
        }

        
    }
};

int main(){
    Solution s;
    string coordinate1="a1";
    string coordinate2="c3";
    cout<<s.checkTwoChessboards(coordinate1,coordinate2);
    return 0;
}