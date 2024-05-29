//Time complexity - O(N^2)
class Solution {
public:
    void addOne(string &s){
        int i = s.length() - 1;

        while(i >= 0 && s[i] != '0'){
            s[i] = '0';
            i--;
        }

        if(i < 0) s = '1' + s;
        else s[i] = '1';
    }
    int numSteps(string s) {
        int operations = 0;

        while(s.length() > 1){
            int n = s.length();

            if(s[n-1] == '0') s.pop_back();
            else addOne(s);
             
            operations++;
        }
        return operations;
    }
};
//Optimal Approach O(N)
int numSteps(string s) {
        int operations = 0,  n = s.length(), carry = 0;

        for(int i = n-1; i >= 1; i--){
            if(((s[i] - '0') + carry) % 2 == 1 ){//Odd
                operations += 2;
                carry = 1;
            }else operations++;//Even
        }
        return operations + carry; //For Balancing last missing operation
    }