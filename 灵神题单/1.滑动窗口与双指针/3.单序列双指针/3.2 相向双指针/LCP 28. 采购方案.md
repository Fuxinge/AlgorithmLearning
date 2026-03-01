```python
class Solution:
    def purchasePlans(self, nums: List[int], target: int) -> int:
        N = 1e9 + 7
        n = len(nums)
        nums.sort()
        res = 0
        i = 0
        j = n - 1
        while i < j :
            if nums[i] + nums[j] <= target:
                res += j - i
                res = res % N
                i += 1
            else :
                j -= 1

        return int(res % N )
```
