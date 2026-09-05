class Solution {
public:

    string encode(vector<string>& strs) {
        string code = "";
        for (const string &str: strs) {
            code += to_string(str.size()) + '#' + str;
        }
        // cout << code << endl;
        return code;
    }

    vector<string> decode(string s) {
        int i = 0, n = s.size();
        vector<string> res;
        while (i < n) {
            int j = i;
            int currLen = 0;
            while (j < n && s[j] != '#') {
                currLen *= 10;
                currLen += s[j] - '0';
                j++;
            }
            j++;
            string curr = "";
            if (j < n) curr = s.substr(j, currLen);
            j += currLen;
            res.push_back(curr);
            i = j;
        }
        return res;
    }
};
