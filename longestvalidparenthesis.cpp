#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;
        st.push(-1); // initially push -1 to the stack because if there is ) then we can not pop our stack if it is empty

        int cnt = 0;

        for (int i = 0; i < s.size(); i++) {

            // if it is open parenthesis then push that index to the stack
            if (s[i] == '(') st.push(i);

            // if it is close then pop the stack
            // and check it is empty or not if it is empty then push current value to it because if there is another ) then we can not pop our stack if it is empty
            // if it is not empty then find the length between the (current index i and stack top index) and store the max value in ans
            else {
                st.pop();

                if (st.empty()) st.push(i);

                else
                    cnt = max(cnt, i - st.top());
            }
        }

        return cnt;
    }
};

int main() {
    Solution sol;

    // Test cases
    cout << sol.longestValidParentheses("(()") << endl;
    cout << sol.longestValidParentheses(")()()") << endl;
    cout << sol.longestValidParentheses("") << endl;
    cout << sol.longestValidParentheses("()(())") << endl;
    cout << sol.longestValidParentheses("(()(((()") << endl;
    cout << sol.longestValidParentheses("()(())") << endl;

    return 0;
}