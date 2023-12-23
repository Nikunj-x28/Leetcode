#include<string>
#include<cmath>
using namespace std;
class Solution {
public:
    string nearestPalindromic(string s) {
        // for any number it has 5 possible candidates for closest palindrome
        // e.g 23456
        // either one digit less -> 9999
        // either one digit more -> 10001
        // same digit -> its best to only change the digits from the right 
        // as that will lead to smaller amount of change.
        // 3 more subcases
        // 1) 234 + 32  (for even like 2345 it will be 23 + 32)
        // 2) 23 3+ 32  (decrease mid by 1) for cases like 29802 -> 29792 is closest
        // 3) 23 5+ 32  (increase mid by 1) for cases like 21899 -> 21912 is closest

        int n=s.size();
        long long arr[5]={0};   // array to hold all cases
        // case 1 all 9s
        arr[0]=pow(10,s.size()-1)-1;

        //case 2 one digit more
        arr[4]=pow(10,s.size());
        arr[4]++;

        // case 3
        string temp=s;
        for(int i=0;i<n/2;i++) temp[n-1-i]=temp[i];
        // temp is now palindromic 
        // so it is exactly like case 3.1
        arr[2]=stoll(temp);

        // extract half of string i.e 234 in our example as an integer
        int temp1=stoll(s.substr(0,(n+1)/2));

        // case 3.2
        string one=to_string(temp1-1);
        //case 3.3
        string two=to_string(temp1+1);

        //complete the strings
        for(int i=n/2-1;i>=0;i--) 
        {
           one.push_back(one[i]);
           two.push_back(two[i]);
        }
        // convert back to number
        arr[1]=stoll(one),arr[3]=stoll(two);

        // all cases done now convert original string to number and compare
        long long num=stoll(s);
        long long res=LLONG_MAX;
        string ans;
        for(auto &it:arr){
            if(it==num) continue;
            if(abs(num-it)<res){
                res=abs(num-it);
                ans=to_string(it);
            }
        }
        return ans;
    }
};
