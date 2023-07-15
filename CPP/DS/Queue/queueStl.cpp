#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[]) {
    queue<int> que;
    que.push(10);
    que.push(20);
    que.push(30);
    que.push(40);
    que.push(50);

    while (!que.empty()) {
        cout << que.front() << "\t";
        que.pop();
    }
    cout << endl;

    return 0;
}
