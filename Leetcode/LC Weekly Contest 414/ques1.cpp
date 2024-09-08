/*
Convert Date to Binary

You are given a string date representing a Gregorian calendar date in the yyyy-mm-dd format.

date can be written in its binary representation obtained by converting year, month, and day to their binary representations without any leading zeroes and writing them down in year-month-day format.

Return the binary representation of date.

 

Example 1:

Input: date = "2080-02-29"

Output: "100000100000-10-11101"

Explanation:

100000100000, 10, and 11101 are the binary representations of 2080, 02, and 29 respectively.

Example 2:

Input: date = "1900-01-01"

Output: "11101101100-1-1"

Explanation:

11101101100, 1, and 1 are the binary representations of 1900, 1, and 1 respectively.

 

Constraints:

date.length == 10
date[4] == date[7] == '-', and all other date[i]'s are digits.
The input is generated such that date represents a valid Gregorian calendar date between Jan 1st, 1900 and Dec 31st, 2100 (both inclusive).
*/
//Competitive Programming\Leetcode\LC Weekly Contest 414\ques1.cpp

/*
The main logic flow is as follows:

    -> The date string is split into year, month, and day.
    -> Each part is converted to an integer.
    -> Each integer is converted to its binary representation.
    -> The binary representations are combined into a single string.
*/

#include<bits/stdc++.h> 
using namespace std;

#define ull unsigned long long int
class Solution {
public:
    /**
     * Converts a decimal integer to its binary string representation.
     *
     * @param n The decimal integer to be converted.
     * @return The binary string representation of the input integer.
     */
    string decimalToBinary(int n)
    {
        //finding the binary form of the number and 
        //converting it to string. 
        string s = bitset<64> (n).to_string();
        
        //Finding the first occurrence of "1"
        //to strip off the leading zeroes.
        const auto loc1 = s.find('1');
        
        if(loc1 != string::npos)
            return s.substr(loc1);
        
        return "0";
    }

    /**
     * Converts a date string in the format "YYYY-MM-DD" to its binary representation.
     *
     * @param date The date string to be converted.
     * @return The binary representation of the input date.
     */
    string convertDateToBinary(string date) {
        string year,mon,da;
        year=date.substr(0,4);
        mon=date.substr(5,2);
        da=date.substr(8,2);
        year=decimalToBinary(stoi(year));
        mon=decimalToBinary(stoi(mon));
        da=decimalToBinary(stoi(da));
        return year+"-"+mon+"-"+da;
    }
};

int main(){
    Solution s;
    cout<<s.convertDateToBinary("2080-02-29");
    return 0;
}