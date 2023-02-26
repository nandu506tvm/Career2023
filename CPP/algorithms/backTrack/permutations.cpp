#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> answer;

void findPermutations(vector <int> &num, int index) {
    
    // Base condition
    if (num.size() == index) {
        answer.push_back(num);
        return;
    }

    // Calculation
    for (int i=index; i<num.size(); i++) {
        swap(num[index], num[i]);
        findPermutations(num, index+1);

        //Backtrack
        swap(num[index], num[i]);
    }
    return;
}

int main(int argc, char const *argv[]) {

    vector <int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    findPermutations(num, 0);


    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j] << " ";
        }    
        cout << endl;
    }

    return 0;
}

