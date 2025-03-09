// 3208. Alternating Groups II
#include <vector>
class Solution {
public:
    int numberOfAlternatingGroups(std::vector<int>& colors, int k) {
        int n = colors.size();
        int ans = 0;
        int cnt = 0;

        for (int i = 0; i < n * 2; ++i) {
            if (i > 0 && colors[i % n] == colors[(i - 1) % n]) {
                cnt = 1;
            } else {
                ++cnt;
            }
            if (i >= n && cnt >= k) {
                ++ans;
            }
        }
        return ans;
    }
};