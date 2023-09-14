/*
Given a str which is a valid sentence without any spaces between the words and a dictionary of valid English words,
find all possible number of ways to break the sentence in individual dictionary words.

Input:
dictionary = { i, like, sam, sung, samsung, mobile}
str = "ilikesamsungmobile"

Output: 2
i like sam sung mobile
i like samsung mobile
*/

#include <iostream>

using namespace std;

int wordBreak(string s, vector<string>& wordDict, int start_idx) {
    // Base condition
    if (start_idx >= s.length()) {
        return 1;
    }
    // check if element is present in wordDict,
    int total_ways = 0;
    string temp_str = "";
    for (int i = start_idx; i < s.length(); i++) {
        temp_str += s[i];
        auto word_in_dict = find(wordDict.begin(), wordDict.end(), temp_str);

        // Element found in word Dict
        if (word_in_dict != wordDict.end()) {
            total_ways += wordBreak(s, wordDict, i + 1);
        }
    }
    return total_ways;
}

int main(int argc, char const* argv[]) {
    vector<string> dictionary = {"i", "love", "sam", "sung", "samsung"};
    string str = "ilovesamsung";

    cout << wordBreak(str, dictionary, 0) << endl;

    return 0;
}
