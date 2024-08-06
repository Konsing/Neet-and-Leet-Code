/* Question 6 : Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']'
determine if the input string is valid.An input string is valid if: 
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order. */

#include <stack>
#include <string>
#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

bool isValid(const string &s){
    stack<char> opens;
    unordered_map<char, char> parens = {
        {')', '('},
        {'}', '{'},
        {']', '['},
    };

    for(auto const& c : s){
        if(parens.find(c) != parens.end()){ // If closing bracket
            if(opens.empty() || opens.top() != parens[c]){
                return false;
            }
            opens.pop();
        } else { // If opening bracket
            opens.push(c);
        }
    }
    return opens.empty();
}

int main(){
    string s = "{[()]}";
    bool result = isValid(s);
    // Expected output: true
    cout << "Is the string valid? " << (result ? "true" : "false") << endl;
    return 0;
}
