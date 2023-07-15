/*******************************************************************************
 *                                                                             *
 * The span of the stock's price today is defined as the maximum number  of    *
 * consecutive days (starting from today and going backwards) for which the    *
 * price of the stock was less than or equal to today's price.                 *
 *                                                                             *
 * *****************************************************************************/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Brute force solution - O(n^2)
vector<int> stockSpanner(vector<int> &stock_prices) {
    int length = stock_prices.size();
    int count = 0;
    vector<int> result;

    for (int i = 0; i < length; i++) {
        count = 0;
        for (int j = i; j >= 0; j--) {
            if (stock_prices[j] <= stock_prices[i]) {
                count++;
            } else
                break;
        }
        result.push_back(count);
    }
    return result;
}

/**********************************************************************************************
 *
 * This function uses 'monotonic stack'
 *
 * A stack is called a monotonic stack if all the elements starting from the
 * bottom of the stack is either in increasing or in decreasing order.
 *
 * Monotonic increasing stack - pop stack top element till top is less than
 * element to be added Monotonic decreasing stack - pop stack top element till
 * top is greater than element to add Time complexity: O(n)
 *
 * Alg: Stock span = (Present element index) - (Prev greater element index)
 * Logic: From prev greater element till present element will be the span for
 * present element. For finding prev greater element use monotonic decreasing
 * stack
 * ********************************************************************************************/

vector<int> stockSpanner2(vector<int> stock_prices) {
    vector<int> result;
    stack<int> stck;
    int length = stock_prices.size();
    int prev_greater_index = 0;

    // Push the first element to stack and update result
    stck.push(0);
    result.push_back(1);

    // Implement monotonic decreasing stack - previous greater element
    for (int array_index = 1; array_index < length; array_index++) {
        int current_price = stock_prices[array_index];
        while ((!stck.empty()) and
               (stock_prices[stck.top()] <= current_price)) {
            stck.pop();
        }
        // If stack is empty there is no previous greater
        if (stck.empty()) {
            result.push_back(array_index + 1);
        }
        // Previous greater is present
        else {
            prev_greater_index = stck.top();
            result.push_back(array_index - prev_greater_index);
        }
        // pushing to stack is common to if/else
        stck.push(array_index);
    }

    return result;
}

void printVector(const vector<int> &stock_span) {
    for (auto element : stock_span) {
        cout << element << "\t";
    }
    cout << endl;
}

// Driver Code
int main(int argc, char const *argv[]) {
    vector<int> stock_prices = {100, 80, 60, 70, 60, 75, 85, 300};
    vector<int> stock_spans = stockSpanner(stock_prices);
    vector<int> stock_spans2 = stockSpanner2(stock_prices);

    printVector(stock_spans);
    printVector(stock_spans2);

    return 0;
}
