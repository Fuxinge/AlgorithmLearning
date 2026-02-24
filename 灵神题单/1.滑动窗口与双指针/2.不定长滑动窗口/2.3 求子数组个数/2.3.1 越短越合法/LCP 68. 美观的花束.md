```python
class Solution:
    def beautifulBouquet(self, nums: List[int], k: int) -> int:
        n,res,j,mp = len(nums),0,0,defaultdict(int)

        for i in range(n):
            mp[nums[i]] += 1
            while j <= i and mp[nums[i]] > k:
                mp[nums[j]] -= 1
                j = j + 1
            res += i - j + 1

        return res
```
