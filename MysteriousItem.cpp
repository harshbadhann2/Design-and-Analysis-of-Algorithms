#include <iostream>
#include <cmath>
using namespace std;
bool canFit(long long side, long long N, long long H, long long W) {
    long long rows = side / H;
    long long cols = side / W;
    return (rows * cols) >= N;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long N, H, W;
        cin >> N >> H >> W;
        long long low = max(H, W);
        long long high = N * max(H, W); 
        long long result = high;

        while (low <= high) {
            long long mid = (low + high) / 2;
            if (canFit(mid, N, H, W)) {
                result = mid;   // Update result
                high = mid - 1; 
            } else {
                low = mid + 1;  // Try for larger square
            }
        }


        cout << result << endl;
    }

    return 0;
}