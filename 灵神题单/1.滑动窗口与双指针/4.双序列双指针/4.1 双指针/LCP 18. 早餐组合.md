```python
class Solution:
    def breakfastNumber(self, staple: List[int], drinks: List[int], x: int) -> int:
        mod = int(1e9 + 7)
        res = 0
        n,m = len(staple),len(drinks)
        staple.sort()
        for c in drinks:
            max_cost =  x - c
            pos = bisect_right(staple,max_cost)
            print(c,max_cost,x,pos)
            res = (res + pos) % mod
        return res

```
