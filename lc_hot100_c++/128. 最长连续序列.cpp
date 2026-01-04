#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        int res = 0;
        unordered_set<int> st;
        for (auto x : nums)
        {
            st.insert(x);
        }
        for (auto x : st)
        {
            if (st.find(x - 1) != st.end())
                continue;

            int y = x + 1;
            while (st.find(y) != st.end())
            {
                y++;
            }

            res = max(res, y - x);
        }

        return res;
    }
};