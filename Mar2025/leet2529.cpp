// 2529. Maximum Count of Positive Integer and Negative Integer
class Solution {
  public:
   int maximumCount(vector<int>& nums) {
     return max(ranges::count_if(nums, [](int num) { return num > 0; }),
                ranges::count_if(nums, [](int num) { return num < 0; }));
   }
 };