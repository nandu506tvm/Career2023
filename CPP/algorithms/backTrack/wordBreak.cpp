/*
Given a string s and a dictionary of strings wordDict,
return true if s can be segmented into a space-separated
sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Input Format:
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
*/

#include <iostream>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict, string& out_str, int start_idx) {
    // Base condition
    if (start_idx >= s.length()) {
        cout << out_str << endl;
        return true;
    }

    // check if element is present in wordDict,
    string temp_str = "";
    for (int i = start_idx; i < s.length(); i++) {
        temp_str += s[i];
        auto word_in_dict = find(wordDict.begin(), wordDict.end(), temp_str);

        // Element found in word Dict
        if (word_in_dict != wordDict.end()) {
            out_str += temp_str;
            out_str += " ";
            // Asssum recurion will solve the rest
            if (wordBreak(s, wordDict, out_str, i + 1)) {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char const* argv[]) {
    vector<string> dictionary = {"i", "love", "sam", "sung", "samsung"};
    string str = "ilovesamsung";
    string out_str = "";

    cout << wordBreak(str, dictionary, out_str, 0) << endl;

    return 0;
}
