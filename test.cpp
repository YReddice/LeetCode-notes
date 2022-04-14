class Solution {
public:
    bool backspaceCompare(string s, string t) {
        std::stack<char> stack1,stack2;
        for (int i=0;i<s.size();i++){
            if (s[i] == '#'){
                if (!stack1.empty()){
                    stack1.pop();
                }
            }
            else{
                stack1.push(s[i]);
            }
        }
        for (int i=0;i<t.size();i++)
            if (t[i] == '#'){
                if (!stack2.empty()){
                    stack2.pop();
                }
            }
            else{
                stack2.push(t[i]);
            }
        }
        while(!stack1.empty() && !stack2.empty()){
            if (stack1.pop() != stack2.pop()){
                return false;
            }
        }
        if (!stack1.empty() || !stack2.empty()){
            return false;
        }
        else{
            return true;
        }
            
    }
};