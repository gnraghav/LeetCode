// // 271 - Encode and Decode Strings

// String Encode and Decode

// Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

// Please implement encode and decode

// Example 1:

// Input: ["neet","code","love","you"]

// Output:["neet","code","love","you"]

// Example 2:

// Input: ["we","say",":","yes"]

// Output: ["we","say",":","yes"]

class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for (auto i: strs) {
            res+=i+"-";
        }
        return res;
    }

    vector<string> decode(string s) {
        cout << s;
        vector<string> res;
        string temp = "";
        for (auto i=0;i<s.size();i++) {
            if (s[i] == '-') {
                res.push_back(temp);
                temp = "";
            }
            if (s[i] !='-') {
                 temp +=s[i];
            }
        }
        return res;
    }
};
