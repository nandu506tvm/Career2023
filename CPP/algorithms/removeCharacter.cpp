#include <iostream>
#include <string>

using namespace std;

void removeCharacter(string &str, int startIndex,  int endIndex, string &result) {

    // Base case
    if (startIndex == endIndex) return;

    // Assume recursion will solve for 'n-1' character
    removeCharacter(str, startIndex+1, endIndex, result);

    // Final calculation
    if (str[startIndex] != 'a') {
        result = str[startIndex] + result;
    }
}

int main(int argc, char const *argv[]) {

    string str = "baccadaef";
    string result = "";

    removeCharacter(str, 0, str.length(), result);

    cout << result << endl;

    return 0;
}

