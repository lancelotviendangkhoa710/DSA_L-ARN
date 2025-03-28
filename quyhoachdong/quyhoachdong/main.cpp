//Bài Toán trên ta dùng phương pháp quy hoạch động

#include <iostream>
#include <vector>

using namespace std;

int coinChangeWays(int N, int M) {
   
    vector<int> dp(N + 1, 0);
    dp[0] = 1;

    
    for (int coin = 1; coin <= M; ++coin) {
        for (int i = coin; i <= N; ++i) {
            dp[i] += dp[i - coin];  
        }
    }

    return dp[N];  
}

int main() {
    int N, M;
    cout << "Nhap so tien can doi: ";
    cin >> N;
    cout << "Nhap so luong menh gia: ";
    cin >> M;

    cout << "So cach doi " << N << " dong là: " << coinChangeWays(N, M) << endl;

    return 0;
}
