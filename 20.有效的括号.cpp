#include<stack>
#include<string>
using namespace std;

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 == 1){
            return false;
        }
        stack<char> judge;
        for(int i=0; i<s.length(); ++i){
            if(s[i] == '(' ||s[i] == '[' ||s[i] == '{' ){
                judge.push(s[i]);
            }
            else{
                if(judge.empty()){
                    return false;
                }

                if((s[i] == ')' && judge.top() == '(') || (s[i] == ']' && judge.top() == '[') || (s[i] == '}' && judge.top() == '{')){
                    judge.pop();
                } else{
                    return false;
                }
            }
            
        }
        return judge.empty();
    }
};
// @lc code=end

