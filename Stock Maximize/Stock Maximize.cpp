#include <iostream>
using namespace std;

int main() {
    int T;
    for(cin >> T; T > 0; T--) {
        int N;
        cin >> N;
        int WOT[N];
        for(auto i = 0; i != N; i++) {
            cin >> WOT[i];
        }
        int dp[N];
        dp[N - 1] = WOT[N - 1];
        for(auto i = N - 2; i >= 0; i--) {
            dp[i] = max(dp[i + 1], WOT[i]);
        }
        auto profit = 0ll;
        for(auto i = 0; i != N; i++) {
            profit += dp[i] - WOT[i];
        }
        cout << profit << endl;
    }
    return 0;
}
