# Python 数据结构速查笔记

## 目录

- [1. 输入输出](#1-输入输出)
- [2. list (列表)](#2-list-列表)
- [3. tuple (元组)](#3-tuple-元组)
- [4. dict (字典)](#4-dict-字典)
- [5. set (集合)](#5-set-集合)
- [6. str (字符串)](#6-str-字符串)
- [7. collections 模块](#7-collections-模块)
- [8. heapq (堆)](#8-heapq-堆)
- [9. 常用内置函数](#9-常用内置函数)
- [10. 常见使用技巧](#10-常见使用技巧)

---

## 1. 输入输出

### 1.1 基本输入 - input()

```python
# 读取一行字符串
s = input()
print(s)

# 读取一行并去除首尾空格
s = input().strip()

# 读取整数
n = int(input())

# 读取浮点数
x = float(input())
```

### 1.2 读取多个值

```python
# 读取一行，空格分隔的多个字符串
a, b, c = input().split()

# 读取一行，空格分隔的多个整数
a, b, c = map(int, input().split())

# 读取一行，空格分隔的整数列表
nums = list(map(int, input().split()))

# 读取一行，逗号分隔的整数列表
nums = list(map(int, input().split(',')))
```

### 1.3 读取多行输入

```python
# 方式1: 已知行数
n = int(input())
lines = []
for i in range(n):
    line = input()
    lines.append(line)

# 方式2: 读取直到EOF
import sys
for line in sys.stdin:
    line = line.strip()
    print(line)

# 方式3: 一次性读取所有行
import sys
lines = sys.stdin.read().splitlines()

# 方式4: 读取所有行到列表
import sys
lines = [line.strip() for line in sys.stdin]
```

### 1.4 快速输入（竞赛常用）

```python
import sys
input = sys.stdin.readline  # 加速输入

# 使用示例
n = int(input())
nums = list(map(int, input().split()))
```

### 1.5 基本输出 - print()

```python
# 基本输出
print("Hello World")

# 输出变量
x = 10
print(x)

# 输出多个值（默认空格分隔）
a, b, c = 1, 2, 3
print(a, b, c)  # 输出: 1 2 3

# 自定义分隔符
print(a, b, c, sep=', ')  # 输出: 1, 2, 3

# 不换行输出
print("Hello", end=' ')
print("World")  # 输出: Hello World

# 格式化输出
name = "Alice"
age = 20
print(f"{name} is {age} years old")  # 输出: Alice is 20 years old
```

### 1.6 格式化输出

```python
# f-string (推荐，Python 3.6+)
x = 3.141592653
print(f"{x:.2f}")  # 输出: 3.14

# 输出宽度和对齐
num = 42
print(f"{num:5d}")   # 右对齐，宽度5: "   42"
print(f"{num:<5d}")  # 左对齐，宽度5: "42   "
print(f"{num:05d}")  # 补零，宽度5: "00042"

# format() 方法
print("{} + {} = {}".format(1, 2, 3))  # 输出: 1 + 2 = 3
print("{:.2f}".format(3.141592653))     # 输出: 3.14

# % 格式化（旧式）
print("%d + %d = %d" % (1, 2, 3))  # 输出: 1 + 2 = 3
print("%.2f" % 3.141592653)         # 输出: 3.14
```

### 1.7 输出列表和矩阵

```python
# 输出列表（空格分隔）
arr = [1, 2, 3, 4, 5]
print(' '.join(map(str, arr)))  # 输出: 1 2 3 4 5
print(*arr)  # 输出: 1 2 3 4 5

# 输出二维列表
matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
for row in matrix:
    print(' '.join(map(str, row)))
# 输出:
# 1 2 3
# 4 5 6
# 7 8 9
```

### 1.8 文件输入输出

```python
# 读取文件
with open('input.txt', 'r') as f:
    content = f.read()

# 逐行读取文件
with open('input.txt', 'r') as f:
    for line in f:
        line = line.strip()
        print(line)

# 写入文件
with open('output.txt', 'w') as f:
    f.write("Hello World\n")
    f.write("Line 2\n")

# 追加到文件
with open('output.txt', 'a') as f:
    f.write("Appended line\n")
```

---

## 2. list (列表)

**定义**: 动态数组，有序可变序列

### 2.1 初始化

```python
# 空列表
lst1 = []
lst2 = list()

# 带初值的列表
lst3 = [1, 2, 3, 4, 5]
lst4 = list(range(5))  # [0, 1, 2, 3, 4]

# 重复元素
lst5 = [0] * 5  # [0, 0, 0, 0, 0]

# 列表推导式
lst6 = [i * 2 for i in range(5)]  # [0, 2, 4, 6, 8]
lst7 = [i for i in range(10) if i % 2 == 0]  # [0, 2, 4, 6, 8]
```

### 2.2 append() - 尾部添加元素

```python
lst = [1, 2, 3]
lst.append(4)
lst.append(5)
# lst = [1, 2, 3, 4, 5]
```

### 2.3 insert() - 指定位置插入

```python
lst = [1, 2, 4, 5]
lst.insert(2, 3)  # 在索引2处插入3
# lst = [1, 2, 3, 4, 5]

lst.insert(0, 0)  # 在开头插入
# lst = [0, 1, 2, 3, 4, 5]
```

### 2.4 extend() - 扩展列表

```python
lst1 = [1, 2, 3]
lst2 = [4, 5, 6]
lst1.extend(lst2)
# lst1 = [1, 2, 3, 4, 5, 6]

# 也可以用 + 运算符
lst3 = [1, 2, 3] + [4, 5, 6]  # [1, 2, 3, 4, 5, 6]
```

### 2.5 pop() - 删除元素

```python
lst = [1, 2, 3, 4, 5]

# 删除并返回最后一个元素
x = lst.pop()  # x = 5, lst = [1, 2, 3, 4]

# 删除并返回指定索引的元素
y = lst.pop(1)  # y = 2, lst = [1, 3, 4]
```

### 2.6 remove() - 删除指定值

```python
lst = [1, 2, 3, 2, 4]
lst.remove(2)  # 删除第一个值为2的元素
# lst = [1, 3, 2, 4]
```

### 2.7 索引访问和切片

```python
lst = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

# 索引访问
print(lst[0])   # 0
print(lst[-1])  # 9 (倒数第一个)
print(lst[-2])  # 8 (倒数第二个)

# 切片 [start:end:step]
print(lst[2:5])    # [2, 3, 4]
print(lst[:3])     # [0, 1, 2]
print(lst[7:])     # [7, 8, 9]
print(lst[::2])    # [0, 2, 4, 6, 8] (步长为2)
print(lst[::-1])   # [9, 8, 7, 6, 5, 4, 3, 2, 1, 0] (反转)
```

### 2.8 sort() / sorted() - 排序

```python
lst = [3, 1, 4, 1, 5, 9, 2, 6]

# 原地排序（修改原列表）
lst.sort()
# lst = [1, 1, 2, 3, 4, 5, 6, 9]

# 降序排序
lst.sort(reverse=True)
# lst = [9, 6, 5, 4, 3, 2, 1, 1]

# 返回新列表（不修改原列表）
lst = [3, 1, 4, 1, 5, 9, 2, 6]
sorted_lst = sorted(lst)
# sorted_lst = [1, 1, 2, 3, 4, 5, 6, 9]
# lst 保持不变

# 自定义排序
lst = [(1, 2), (3, 1), (2, 3)]
lst.sort(key=lambda x: x[1])  # 按第二个元素排序
# lst = [(3, 1), (1, 2), (2, 3)]
```

### 2.9 reverse() - 反转

```python
lst = [1, 2, 3, 4, 5]
lst.reverse()
# lst = [5, 4, 3, 2, 1]

# 也可以用切片
lst2 = [1, 2, 3, 4, 5]
lst2 = lst2[::-1]
# lst2 = [5, 4, 3, 2, 1]
```

### 2.10 其他常用方法

```python
lst = [1, 2, 3, 2, 4, 2, 5]

# count() - 统计元素出现次数
print(lst.count(2))  # 3

# index() - 查找元素第一次出现的索引
print(lst.index(3))  # 2

# clear() - 清空列表
lst.clear()
# lst = []

# copy() - 浅拷贝
lst1 = [1, 2, 3]
lst2 = lst1.copy()

# in - 判断元素是否在列表中
print(2 in [1, 2, 3])  # True
print(4 in [1, 2, 3])  # False
```

### 2.11 二维列表

```python
# 创建 n*m 的二维列表
n, m = 3, 4
matrix = [[0] * m for i in range(n)]

# 错误方式（不要这样做）
# matrix = [[0] * m] * n  # 所有行会共享同一个列表

# 访问和修改
matrix[1][2] = 5
print(matrix[1][2])  # 5

# 遍历二维列表
for i in range(n):
    for j in range(m):
        print(matrix[i][j], end=' ')
    print()
```

---

## 3. tuple (元组)

**定义**: 不可变序列，一旦创建不能修改

### 3.1 初始化

```python
# 空元组
t1 = ()
t2 = tuple()

# 带元素的元组
t3 = (1, 2, 3)
t4 = 1, 2, 3  # 括号可省略
t5 = (1,)  # 单元素元组需要逗号

# 从列表创建
t6 = tuple([1, 2, 3])
```

### 3.2 访问元素

```python
t = (10, 20, 30, 40, 50)

# 索引访问
print(t[0])   # 10
print(t[-1])  # 50

# 切片
print(t[1:3])  # (20, 30)

# 遍历
for x in t:
    print(x)
```

### 3.3 元组操作

```python
t1 = (1, 2, 3)
t2 = (4, 5, 6)

# 拼接
t3 = t1 + t2  # (1, 2, 3, 4, 5, 6)

# 重复
t4 = t1 * 2  # (1, 2, 3, 1, 2, 3)

# count() - 统计元素出现次数
t = (1, 2, 3, 2, 4)
print(t.count(2))  # 2

# index() - 查找元素索引
print(t.index(3))  # 2

# in - 判断元素是否存在
print(2 in t)  # True
```

### 3.4 元组解包

```python
# 基本解包
t = (1, 2, 3)
a, b, c = t
# a = 1, b = 2, c = 3

# 交换变量
a, b = 1, 2
a, b = b, a  # a = 2, b = 1

# 扩展解包
t = (1, 2, 3, 4, 5)
a, *b, c = t
# a = 1, b = [2, 3, 4], c = 5
```

### 3.5 使用场景 - 函数返回多个值

```python
def get_info():
    return "Alice", 20, 85.5

name, age, score = get_info()
print(name, age, score)  # Alice 20 85.5
```

---

## 4. dict (字典)

**定义**: 键值对映射，无序可变

### 4.1 初始化

```python
# 空字典
d1 = {}
d2 = dict()

# 带初值的字典
d3 = {"apple": 5, "banana": 3, "orange": 7}
d4 = dict(apple=5, banana=3, orange=7)
d5 = dict([("apple", 5), ("banana", 3)])
```

### 4.2 访问和修改

```python
d = {"apple": 5, "banana": 3}

# 访问元素
print(d["apple"])  # 5

# get() - 安全访问（键不存在返回None或默认值）
print(d.get("orange"))      # None
print(d.get("orange", 0))   # 0

# 修改值
d["apple"] = 10

# 添加新键值对
d["orange"] = 7
```

### 4.3 删除元素

```python
d = {"apple": 5, "banana": 3, "orange": 7}

# del - 删除指定键
del d["banana"]
# d = {"apple": 5, "orange": 7}

# pop() - 删除并返回值
value = d.pop("apple")  # value = 5
# d = {"orange": 7}

# popitem() - 删除并返回最后一个键值对（Python 3.7+有序）
key, value = d.popitem()

# clear() - 清空字典
d.clear()
```

### 4.4 字典方法

```python
d = {"apple": 5, "banana": 3, "orange": 7}

# keys() - 获取所有键
keys = d.keys()
print(list(keys))  # ['apple', 'banana', 'orange']

# values() - 获取所有值
values = d.values()
print(list(values))  # [5, 3, 7]

# items() - 获取所有键值对
items = d.items()
print(list(items))  # [('apple', 5), ('banana', 3), ('orange', 7)]

# update() - 更新字典
d.update({"grape": 4, "apple": 8})
# d = {"apple": 8, "banana": 3, "orange": 7, "grape": 4}

# setdefault() - 获取值，不存在则设置默认值
value = d.setdefault("melon", 0)  # value = 0，并添加 "melon": 0
```

### 4.5 遍历字典

```python
d = {"apple": 5, "banana": 3, "orange": 7}

# 遍历键
for key in d:
    print(key)

# 遍历键值对
for key, value in d.items():
    print(f"{key}: {value}")

# 遍历值
for value in d.values():
    print(value)
```

### 4.6 字典推导式

```python
# 创建字典
d = {i: i**2 for i in range(5)}
# d = {0: 0, 1: 1, 2: 4, 3: 9, 4: 16}

# 过滤字典
d = {"a": 1, "b": 2, "c": 3, "d": 4}
d2 = {k: v for k, v in d.items() if v > 2}
# d2 = {"c": 3, "d": 4}
```

### 4.7 使用场景 - 统计频率

```python
# 统计单词频率
words = ["apple", "banana", "apple", "orange", "banana", "apple"]
freq = {}
for word in words:
    freq[word] = freq.get(word, 0) + 1

print(freq)
# {'apple': 3, 'banana': 2, 'orange': 1}

# 使用 defaultdict (更简洁)
from collections import defaultdict
freq = defaultdict(int)
for word in words:
    freq[word] += 1
```

---

## 5. set (集合)

**定义**: 无序不重复元素集

### 5.1 初始化

```python
# 空集合（注意：{}是空字典，不是空集合）
s1 = set()

# 带初值的集合
s2 = {1, 2, 3, 4, 5}
s3 = set([1, 2, 3, 2, 1])  # {1, 2, 3} 自动去重
```

### 5.2 add() / remove() - 添加和删除

```python
s = {1, 2, 3}

# 添加元素
s.add(4)
# s = {1, 2, 3, 4}

# 删除元素（元素不存在会报错）
s.remove(2)
# s = {1, 3, 4}

# discard() - 删除元素（元素不存在不报错）
s.discard(10)  # 不会报错

# pop() - 随机删除并返回一个元素
x = s.pop()
```

### 5.3 集合运算

```python
s1 = {1, 2, 3, 4, 5}
s2 = {4, 5, 6, 7, 8}

# 并集
print(s1 | s2)  # {1, 2, 3, 4, 5, 6, 7, 8}
print(s1.union(s2))

# 交集
print(s1 & s2)  # {4, 5}
print(s1.intersection(s2))

# 差集
print(s1 - s2)  # {1, 2, 3}
print(s1.difference(s2))

# 对称差集（在s1或s2中，但不在两者交集中）
print(s1 ^ s2)  # {1, 2, 3, 6, 7, 8}
print(s1.symmetric_difference(s2))
```

### 5.4 集合判断

```python
s1 = {1, 2, 3}
s2 = {1, 2, 3, 4, 5}

# 子集
print(s1.issubset(s2))  # True
print(s1 <= s2)         # True

# 超集
print(s2.issuperset(s1))  # True
print(s2 >= s1)           # True

# 是否有交集
print(s1.isdisjoint({4, 5, 6}))  # True (无交集)
```

### 5.5 其他方法

```python
s = {1, 2, 3, 4, 5}

# len() - 长度
print(len(s))  # 5

# in - 判断元素是否存在（O(1)时间复杂度）
print(3 in s)  # True
print(6 in s)  # False

# clear() - 清空集合
s.clear()
```

### 5.6 使用场景 - 去重

```python
nums = [1, 2, 3, 2, 4, 1, 5, 3]
unique_nums = list(set(nums))
# unique_nums = [1, 2, 3, 4, 5] (顺序可能不同)

# 保持顺序去重
seen = set()
result = []
for num in nums:
    if num not in seen:
        seen.add(num)
        result.append(num)
# result = [1, 2, 3, 4, 5]
```

---

## 6. str (字符串)

**定义**: 不可变字符序列

### 6.1 初始化

```python
s1 = "hello"
s2 = 'world'
s3 = """多行
字符串"""
s4 = str(123)  # "123"
```

### 6.2 字符串操作

```python
s = "hello world"

# 长度
print(len(s))  # 11

# 索引访问
print(s[0])   # 'h'
print(s[-1])  # 'd'

# 切片
print(s[0:5])   # "hello"
print(s[6:])    # "world"
print(s[::-1])  # "dlrow olleh" (反转)

# 拼接
s1 = "hello"
s2 = "world"
s3 = s1 + " " + s2  # "hello world"

# 重复
s = "ha" * 3  # "hahaha"
```

### 6.3 字符串方法

```python
s = "Hello World"

# upper() / lower() - 大小写转换
print(s.upper())  # "HELLO WORLD"
print(s.lower())  # "hello world"

# strip() - 去除首尾空白
s2 = "  hello  "
print(s2.strip())   # "hello"
print(s2.lstrip())  # "hello  "
print(s2.rstrip())  # "  hello"

# split() - 分割字符串
s3 = "apple,banana,orange"
print(s3.split(','))  # ['apple', 'banana', 'orange']

s4 = "hello world"
print(s4.split())  # ['hello', 'world']

# join() - 连接字符串
words = ['hello', 'world']
print(' '.join(words))  # "hello world"
print(','.join(words))  # "hello,world"
```

### 6.4 查找和替换

```python
s = "hello world"

# find() - 查找子串位置（找不到返回-1）
print(s.find("world"))  # 6
print(s.find("python")) # -1

# index() - 查找子串位置（找不到抛出异常）
print(s.index("world"))  # 6

# replace() - 替换子串
print(s.replace("world", "python"))  # "hello python"

# count() - 统计子串出现次数
s2 = "banana"
print(s2.count("a"))  # 3
```

### 6.5 字符串判断

```python
# isdigit() - 是否全是数字
print("123".isdigit())    # True
print("12.3".isdigit())   # False

# isalpha() - 是否全是字母
print("abc".isalpha())    # True
print("abc123".isalpha()) # False

# isalnum() - 是否全是字母或数字
print("abc123".isalnum()) # True
print("abc-123".isalnum())# False

# startswith() / endswith() - 开头/结尾判断
s = "hello.py"
print(s.startswith("hello"))  # True
print(s.endswith(".py"))      # True
```

### 6.6 格式化字符串

```python
name = "Alice"
age = 20
score = 85.5

# f-string (推荐)
print(f"{name} is {age} years old")
print(f"Score: {score:.2f}")  # Score: 85.50

# format()
print("{} is {} years old".format(name, age))
print("{0} scored {2:.2f}, {0} is {1}".format(name, age, score))

# % 格式化
print("%s is %d years old" % (name, age))
```

### 6.7 字符串与列表转换

```python
# 字符串转列表
s = "hello"
lst = list(s)  # ['h', 'e', 'l', 'l', 'o']

# 列表转字符串
lst = ['h', 'e', 'l', 'l', 'o']
s = ''.join(lst)  # "hello"

# 分割成列表
s = "apple,banana,orange"
words = s.split(',')  # ['apple', 'banana', 'orange']
```

---

## 7. collections 模块

### 7.1 Counter - 计数器

```python
from collections import Counter

# 统计元素出现次数
nums = [1, 2, 3, 2, 1, 3, 1]
counter = Counter(nums)
print(counter)  # Counter({1: 3, 2: 2, 3: 2})

# 访问计数
print(counter[1])  # 3
print(counter[4])  # 0 (不存在返回0)

# most_common() - 最常见的元素
print(counter.most_common(2))  # [(1, 3), (2, 2)]

# 统计字符串
s = "hello world"
char_counter = Counter(s)
print(char_counter)  # Counter({'l': 3, 'o': 2, ...})
```

### 7.2 defaultdict - 默认字典

**导入**: `from collections import defaultdict`

**定义**: 字典的子类，提供默认值，避免 KeyError

#### 7.2.1 基本用法

```python
from collections import defaultdict

# int 作为默认值（默认为0）
d = defaultdict(int)
d['a'] += 1
d['b'] += 2
print(d)  # defaultdict(<class 'int'>, {'a': 1, 'b': 2})
print(d['c'])  # 0 (不存在的键返回默认值0)

# list 作为默认值（默认为空列表）
d = defaultdict(list)
d['fruits'].append('apple')
d['fruits'].append('banana')
d['vegetables'].append('carrot')
print(d)  # defaultdict(<class 'list'>, {'fruits': ['apple', 'banana'], 'vegetables': ['carrot']})

# set 作为默认值（默认为空集合）
d = defaultdict(set)
d['A'].add(1)
d['A'].add(2)
d['B'].add(3)
print(d)  # defaultdict(<class 'set'>, {'A': {1, 2}, 'B': {3}})
```

#### 7.2.2 使用 lambda 自定义默认值

```python
from collections import defaultdict

# 默认值为固定数字
d = defaultdict(lambda: 100)
print(d['missing'])  # 100

# 默认值为字符串
d = defaultdict(lambda: "N/A")
print(d['name'])  # N/A

# 默认值为列表（带初始元素）
d = defaultdict(lambda: [0, 0])
d['scores'][0] = 85
print(d['scores'])  # [85, 0]
```

#### 7.2.3 常见使用场景

```python
from collections import defaultdict

# 场景1: 统计频率
words = ["apple", "banana", "apple", "orange", "banana", "apple"]
freq = defaultdict(int)
for word in words:
    freq[word] += 1
print(dict(freq))  # {'apple': 3, 'banana': 2, 'orange': 1}

# 场景2: 分组
students = [("Alice", "A"), ("Bob", "B"), ("Charlie", "A"), ("David", "B")]
groups = defaultdict(list)
for name, grade in students:
    groups[grade].append(name)
print(dict(groups))  # {'A': ['Alice', 'Charlie'], 'B': ['Bob', 'David']}

# 场景3: 构建图的邻接表
edges = [(1, 2), (1, 3), (2, 3), (3, 4)]
graph = defaultdict(list)
for u, v in edges:
    graph[u].append(v)
print(dict(graph))  # {1: [2, 3], 2: [3], 3: [4]}

# 场景4: 累加值
transactions = [("Alice", 100), ("Bob", 50), ("Alice", 200), ("Bob", 75)]
balances = defaultdict(int)
for name, amount in transactions:
    balances[name] += amount
print(dict(balances))  # {'Alice': 300, 'Bob': 125}
```

#### 7.2.4 嵌套 defaultdict

```python
from collections import defaultdict

# 二维字典
matrix = defaultdict(lambda: defaultdict(int))
matrix[0][0] = 1
matrix[0][1] = 2
matrix[1][0] = 3
print(matrix[0][0])  # 1
print(matrix[2][2])  # 0 (自动创建)

# 多级分组
data = [
    ("Alice", "Math", 85),
    ("Alice", "English", 90),
    ("Bob", "Math", 78),
    ("Bob", "English", 88)
]
grades = defaultdict(lambda: defaultdict(int))
for name, subject, score in data:
    grades[name][subject] = score

print(dict(grades))
# {'Alice': {'Math': 85, 'English': 90}, 'Bob': {'Math': 78, 'English': 88}}
```

#### 7.2.5 defaultdict vs 普通 dict

```python
from collections import defaultdict

# 普通字典
d1 = {}
# d1['key'] += 1  # KeyError!
d1['key'] = d1.get('key', 0) + 1  # 需要用 get()

# defaultdict
d2 = defaultdict(int)
d2['key'] += 1  # 直接使用，不会报错

# 转换为普通字典
d3 = dict(d2)
print(type(d3))  # <class 'dict'>
```

#### 7.2.6 实用示例 - 字母异位词分组

```python
from collections import defaultdict

def groupAnagrams(strs):
    groups = defaultdict(list)
    for s in strs:
        # 排序后的字符串作为键
        key = ''.join(sorted(s))
        groups[key].append(s)
    return list(groups.values())

words = ["eat", "tea", "tan", "ate", "nat", "bat"]
print(groupAnagrams(words))
# [['eat', 'tea', 'ate'], ['tan', 'nat'], ['bat']]
```

#### 7.2.7 实用示例 - 树结构

```python
from collections import defaultdict

def build_tree():
    # 自动创建嵌套结构
    tree = lambda: defaultdict(tree)
    users = tree()

    users['Alice']['age'] = 25
    users['Alice']['city'] = 'NYC'
    users['Bob']['age'] = 30
    users['Bob']['hobbies']['sports'].append('soccer')

    return users

users = build_tree()
print(dict(users))
```

### 7.3 deque - 双端队列

```python
from collections import deque

# 初始化
dq = deque([1, 2, 3])

# 两端添加
dq.append(4)      # 右端添加: deque([1, 2, 3, 4])
dq.appendleft(0)  # 左端添加: deque([0, 1, 2, 3, 4])

# 两端删除
dq.pop()       # 右端删除，返回4
dq.popleft()   # 左端删除，返回0

# rotate() - 旋转
dq = deque([1, 2, 3, 4, 5])
dq.rotate(2)   # 向右旋转2位: deque([4, 5, 1, 2, 3])
dq.rotate(-1)  # 向左旋转1位: deque([5, 1, 2, 3, 4])

# 使用场景 - 滑动窗口
from collections import deque
def maxSlidingWindow(nums, k):
    dq = deque()
    result = []
    for i, num in enumerate(nums):
        # 维护单调队列
        while dq and nums[dq[-1]] < num:
            dq.pop()
        dq.append(i)

        # 移除超出窗口的元素
        if dq[0] <= i - k:
            dq.popleft()

        if i >= k - 1:
            result.append(nums[dq[0]])
    return result
```

### 7.4 OrderedDict - 有序字典

```python
from collections import OrderedDict

# 记住插入顺序（Python 3.7+ 普通dict也有序）
d = OrderedDict()
d['a'] = 1
d['b'] = 2
d['c'] = 3
print(d)  # OrderedDict([('a', 1), ('b', 2), ('c', 3)])

# move_to_end() - 移动到末尾
d.move_to_end('a')
print(d)  # OrderedDict([('b', 2), ('c', 3), ('a', 1)])
```

---

## 8. heapq (堆)

**模块**: `import heapq`

**定义**: 最小堆实现

### 8.1 基本操作

```python
import heapq

# 创建堆
heap = []

# heappush() - 插入元素
heapq.heappush(heap, 3)
heapq.heappush(heap, 1)
heapq.heappush(heap, 4)
heapq.heappush(heap, 2)
print(heap)  # [1, 2, 4, 3]

# heappop() - 弹出最小元素
min_val = heapq.heappop(heap)  # 1
print(heap)  # [2, 3, 4]

# 访问最小元素（不删除）
print(heap[0])  # 2
```

### 8.2 heapify() - 将列表转为堆

```python
import heapq

nums = [3, 1, 4, 1, 5, 9, 2, 6]
heapq.heapify(nums)  # 原地转换为最小堆
print(nums)  # [1, 1, 2, 3, 5, 9, 4, 6]
```

### 8.3 nsmallest() / nlargest() - 最小/最大的n个元素

```python
import heapq

nums = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3]

# 最小的3个元素
print(heapq.nsmallest(3, nums))  # [1, 1, 2]

# 最大的3个元素
print(heapq.nlargest(3, nums))   # [9, 6, 5]

# 对复杂对象使用key
students = [("Alice", 85), ("Bob", 92), ("Charlie", 78)]
print(heapq.nlargest(2, students, key=lambda x: x[1]))
# [('Bob', 92), ('Alice', 85)]
```

### 8.4 最大堆实现

```python
import heapq

# Python heapq是最小堆，实现最大堆需要取负数
max_heap = []
heapq.heappush(max_heap, -3)
heapq.heappush(max_heap, -1)
heapq.heappush(max_heap, -4)

# 弹出最大元素
max_val = -heapq.heappop(max_heap)  # 4
print(max_val)
```

### 8.5 使用场景 - Top K 问题

```python
import heapq

def findKthLargest(nums, k):
    # 维护大小为k的最小堆
    heap = nums[:k]
    heapq.heapify(heap)

    for num in nums[k:]:
        if num > heap[0]:
            heapq.heapreplace(heap, num)  # pop + push

    return heap[0]

nums = [3, 2, 1, 5, 6, 4]
print(findKthLargest(nums, 2))  # 5
```

### 8.6 使用场景 - 合并K个有序列表

```python
import heapq

def mergeKLists(lists):
    heap = []
    result = []

    # 初始化堆
    for i, lst in enumerate(lists):
        if lst:
            heapq.heappush(heap, (lst[0], i, 0))  # (值, 列表索引, 元素索引)

    while heap:
        val, list_idx, elem_idx = heapq.heappop(heap)
        result.append(val)

        # 添加下一个元素
        if elem_idx + 1 < len(lists[list_idx]):
            next_val = lists[list_idx][elem_idx + 1]
            heapq.heappush(heap, (next_val, list_idx, elem_idx + 1))

    return result

lists = [[1, 4, 5], [1, 3, 4], [2, 6]]
print(mergeKLists(lists))  # [1, 1, 2, 3, 4, 4, 5, 6]
```

---

## 9. 常用内置函数

### 9.1 len() - 长度

```python
print(len([1, 2, 3]))        # 3
print(len("hello"))          # 5
print(len({"a": 1, "b": 2})) # 2
```

### 9.2 sum() / min() / max()

```python
nums = [1, 2, 3, 4, 5]

print(sum(nums))  # 15
print(min(nums))  # 1
print(max(nums))  # 5

# 指定起始值
print(sum(nums, 10))  # 25 (10 + 15)

# 字符串比较
print(max(["apple", "banana", "cherry"]))  # "cherry"
```

### 9.3 sorted() - 排序

```python
nums = [3, 1, 4, 1, 5, 9, 2, 6]

# 升序
print(sorted(nums))  # [1, 1, 2, 3, 4, 5, 6, 9]

# 降序
print(sorted(nums, reverse=True))  # [9, 6, 5, 4, 3, 2, 1, 1]

# 自定义排序
words = ["apple", "pie", "a", "cherry"]
print(sorted(words, key=len))  # ['a', 'pie', 'apple', 'cherry']

# 多级排序
students = [("Alice", 20), ("Bob", 18), ("Charlie", 20)]
print(sorted(students, key=lambda x: (x[1], x[0])))
# [('Bob', 18), ('Alice', 20), ('Charlie', 20)]
```

### 9.4 reversed() - 反转

```python
nums = [1, 2, 3, 4, 5]

# 返回迭代器
print(list(reversed(nums)))  # [5, 4, 3, 2, 1]

# 反转字符串
s = "hello"
print(''.join(reversed(s)))  # "olleh"
```

### 9.5 enumerate() - 枚举

```python
fruits = ["apple", "banana", "orange"]

# 获取索引和值
for i, fruit in enumerate(fruits):
    print(f"{i}: {fruit}")
# 0: apple
# 1: banana
# 2: orange

# 指定起始索引
for i, fruit in enumerate(fruits, start=1):
    print(f"{i}: {fruit}")
# 1: apple
# 2: banana
# 3: orange
```

### 9.6 zip() - 打包

```python
names = ["Alice", "Bob", "Charlie"]
ages = [20, 18, 22]

# 打包成元组
for name, age in zip(names, ages):
    print(f"{name}: {age}")
# Alice: 20
# Bob: 18
# Charlie: 22

# 转换为列表
print(list(zip(names, ages)))
# [('Alice', 20), ('Bob', 18), ('Charlie', 22)]

# 解包
pairs = [('Alice', 20), ('Bob', 18)]
names, ages = zip(*pairs)
print(names)  # ('Alice', 'Bob')
print(ages)   # (20, 18)
```

### 9.7 map() - 映射

```python
# 将函数应用到每个元素
nums = [1, 2, 3, 4, 5]
squared = list(map(lambda x: x**2, nums))
print(squared)  # [1, 4, 9, 16, 25]

# 多个可迭代对象
a = [1, 2, 3]
b = [4, 5, 6]
result = list(map(lambda x, y: x + y, a, b))
print(result)  # [5, 7, 9]

# 类型转换
strs = ["1", "2", "3"]
nums = list(map(int, strs))
print(nums)  # [1, 2, 3]
```

### 9.8 filter() - 过滤

```python
nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# 过滤偶数
even = list(filter(lambda x: x % 2 == 0, nums))
print(even)  # [2, 4, 6, 8, 10]

# 过滤空字符串
words = ["hello", "", "world", "", "python"]
filtered = list(filter(None, words))  # None 会过滤掉假值
print(filtered)  # ['hello', 'world', 'python']
```

### 9.9 all() / any()

```python
# all() - 所有元素为True才返回True
print(all([True, True, True]))   # True
print(all([True, False, True]))  # False
print(all([1, 2, 3]))            # True
print(all([1, 0, 3]))            # False

# any() - 任一元素为True就返回True
print(any([False, False, False])) # False
print(any([False, True, False]))  # True
print(any([0, 0, 1]))             # True

# 使用场景
nums = [2, 4, 6, 8]
print(all(x % 2 == 0 for x in nums))  # True (都是偶数)
```

### 9.10 range()

```python
# range(stop)
for i in range(5):
    print(i, end=' ')  # 0 1 2 3 4

# range(start, stop)
for i in range(2, 7):
    print(i, end=' ')  # 2 3 4 5 6

# range(start, stop, step)
for i in range(0, 10, 2):
    print(i, end=' ')  # 0 2 4 6 8

# 倒序
for i in range(5, 0, -1):
    print(i, end=' ')  # 5 4 3 2 1
```

---

## 10. 常见使用技巧

### 10.1 列表推导式

```python
# 基本形式
squares = [x**2 for x in range(10)]
# [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]

# 带条件
even_squares = [x**2 for x in range(10) if x % 2 == 0]
# [0, 4, 16, 36, 64]

# 嵌套循环
matrix = [[i+j for j in range(3)] for i in range(3)]
# [[0, 1, 2], [1, 2, 3], [2, 3, 4]]

# 展平二维列表
matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
flat = [x for row in matrix for x in row]
# [1, 2, 3, 4, 5, 6, 7, 8, 9]
```

### 10.2 字典和集合推导式

```python
# 字典推导式
d = {x: x**2 for x in range(5)}
# {0: 0, 1: 1, 2: 4, 3: 9, 4: 16}

# 集合推导式
s = {x % 3 for x in range(10)}
# {0, 1, 2}
```

### 10.3 三元表达式

```python
x = 5
result = "positive" if x > 0 else "non-positive"
print(result)  # positive

# 嵌套三元
x = 0
result = "positive" if x > 0 else ("zero" if x == 0 else "negative")
print(result)  # zero
```

### 10.4 解包和交换

```python
# 交换变量
a, b = 1, 2
a, b = b, a  # a=2, b=1

# 多变量赋值
x, y, z = 1, 2, 3

# 扩展解包
a, *b, c = [1, 2, 3, 4, 5]
# a=1, b=[2, 3, 4], c=5
```

### 10.5 with 语句

```python
# 自动关闭文件
with open('file.txt', 'r') as f:
    content = f.read()

# 多个资源
with open('input.txt', 'r') as fin, open('output.txt', 'w') as fout:
    for line in fin:
        fout.write(line)
```

### 10.6 lambda 函数

```python
# 简单函数
add = lambda x, y: x + y
print(add(2, 3))  # 5

# 在sorted中使用
students = [("Alice", 85), ("Bob", 92), ("Charlie", 78)]
students.sort(key=lambda x: x[1], reverse=True)
print(students)  # [('Bob', 92), ('Alice', 85), ('Charlie', 78)]

# 在map中使用
nums = [1, 2, 3, 4, 5]
squared = list(map(lambda x: x**2, nums))
```

### 10.7 切片技巧

```python
lst = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

# 每隔一个元素取一次
print(lst[::2])   # [0, 2, 4, 6, 8]

# 倒序
print(lst[::-1])  # [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]

# 复制列表
lst2 = lst[:]

# 删除元素
lst[2:5] = []  # 删除索引2到4的元素
```

### 10.8 字符串处理技巧

```python
# 判断回文
s = "racecar"
is_palindrome = s == s[::-1]  # True

# 移除标点符号
import string
text = "Hello, World!"
cleaned = ''.join(c for c in text if c not in string.punctuation)
# "Hello World"

# 统计单词
text = "hello world hello python"
words = text.split()
from collections import Counter
word_count = Counter(words)
```

### 10.9 常用算法模板

```python
# 二分查找
def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

# 双指针
def two_sum_sorted(arr, target):
    left, right = 0, len(arr) - 1
    while left < right:
        s = arr[left] + arr[right]
        if s == target:
            return [left, right]
        elif s < target:
            left += 1
        else:
            right -= 1
    return []

# 滑动窗口
def max_sum_subarray(arr, k):
    window_sum = sum(arr[:k])
    max_sum = window_sum

    for i in range(k, len(arr)):
        window_sum += arr[i] - arr[i-k]
        max_sum = max(max_sum, window_sum)

    return max_sum
```

### 10.10 性能优化技巧

```python
# 使用 in 测试成员资格时，set比list快
# 不好
lst = [1, 2, 3, 4, 5]
if 3 in lst:  # O(n)
    pass

# 好
s = {1, 2, 3, 4, 5}
if 3 in s:  # O(1)
    pass

# 使用列表推导式代替循环
# 不好
result = []
for i in range(10):
    result.append(i**2)

# 好
result = [i**2 for i in range(10)]

# 使用join连接字符串
# 不好
s = ""
for word in words:
    s += word  # O(n^2)

# 好
s = "".join(words)  # O(n)
```

---

**最后更新**: 2026年2月7日
