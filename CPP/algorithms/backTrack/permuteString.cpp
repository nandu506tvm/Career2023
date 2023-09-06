#include <iostream>
#include <string>

using namespace std;

vector<string> permutations;

void permuteString(string &s, int start_idx) {
    if (start_idx == s.size()) {
        permutations.push_back(s);
    }

    for (int i = start_idx; i < s.size(); i++) {
        swap(s[start_idx], s[i]);
        permuteString(s, start_idx + 1);
        swap(s[start_idx], s[i]);
    }
}

int main(int argc, char const *argv[]) {
    string s = "abc";
    permuteString(s, 0);

    for (auto element : permutations) {
        cout << element << "\t";
    }
    cout << endl;

    return 0;
}
