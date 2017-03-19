#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    stack<int> stack;
    long long N, result = 1;
    cin >> N;
    int h[N];
    for(auto i = 0; cin >> h[i]; i++) {
    }
    for(auto i = 0ll; i != N; i++) {
        while(!stack.empty() && h[i] < h[stack.top()]) {
            auto top = stack.top();
            stack.pop();
            if(stack.empty()) {
                result = max(result, h[top] * i);
            } else {
                result = max(result, h[top] * (i - stack.top() - 1));
            }
        }
        stack.emplace(i);
    }
    while(!stack.empty()) {
        auto top = stack.top();
        stack.pop();
        if(stack.empty()) {
            result = max(result, h[top] * N);
        } else {
            result = max(result, h[top] * (N - stack.top() - 1));
        }
    }
    cout << result;
    return 0;
}
