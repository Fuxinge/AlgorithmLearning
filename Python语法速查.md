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
- [11. 面向对象编程](#11-面向对象编程)

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

**导入**: `from collections import deque`

**定义**: 双端队列，支持从两端高效添加和删除元素，时间复杂度 O(1)

#### 7.3.1 初始化

```python
from collections import deque

# 空双端队列
dq1 = deque()

# 从列表初始化
dq2 = deque([1, 2, 3, 4, 5])

# 指定最大长度（满了会自动删除另一端的元素）
dq3 = deque([1, 2, 3], maxlen=3)
dq3.append(4)  # deque([2, 3, 4], maxlen=3)，自动删除了1

# 从字符串初始化
dq4 = deque("hello")  # deque(['h', 'e', 'l', 'l', 'o'])
```

#### 7.3.2 添加元素

```python
from collections import deque

dq = deque([2, 3, 4])

# append() - 右端添加
dq.append(5)
# deque([2, 3, 4, 5])

# appendleft() - 左端添加
dq.appendleft(1)
# deque([1, 2, 3, 4, 5])

# extend() - 右端批量添加
dq.extend([6, 7])
# deque([1, 2, 3, 4, 5, 6, 7])

# extendleft() - 左端批量添加（注意顺序是反的）
dq.extendleft([0, -1])
# deque([-1, 0, 1, 2, 3, 4, 5, 6, 7])
```

#### 7.3.3 删除元素

```python
from collections import deque

dq = deque([1, 2, 3, 4, 5])

# pop() - 删除并返回右端元素
x = dq.pop()  # x = 5
# dq = deque([1, 2, 3, 4])

# popleft() - 删除并返回左端元素
y = dq.popleft()  # y = 1
# dq = deque([2, 3, 4])

# remove() - 删除第一个匹配的元素
dq = deque([1, 2, 3, 2, 4])
dq.remove(2)  # 删除第一个2
# deque([1, 3, 2, 4])

# clear() - 清空
dq.clear()
# deque([])
```

#### 7.3.4 访问和搜索

```python
from collections import deque

dq = deque([1, 2, 3, 4, 5])

# 索引访问
print(dq[0])   # 1 (左端)
print(dq[-1])  # 5 (右端)
print(dq[2])   # 3

# 修改元素
dq[1] = 10
# deque([1, 10, 3, 4, 5])

# count() - 统计元素出现次数
dq = deque([1, 2, 3, 2, 4, 2])
print(dq.count(2))  # 3

# index() - 查找元素第一次出现的索引
print(dq.index(3))  # 2

# in - 判断元素是否存在
print(3 in dq)  # True
```

#### 7.3.5 旋转操作

```python
from collections import deque

dq = deque([1, 2, 3, 4, 5])

# rotate(n) - 向右旋转n位
dq.rotate(2)
print(dq)  # deque([4, 5, 1, 2, 3])

# rotate(-n) - 向左旋转n位
dq.rotate(-1)
print(dq)  # deque([5, 1, 2, 3, 4])

# 完整循环
dq = deque([1, 2, 3, 4, 5])
dq.rotate(1)   # deque([5, 1, 2, 3, 4])
dq.rotate(-1)  # deque([1, 2, 3, 4, 5]) 回到原位
```

#### 7.3.6 其他操作

```python
from collections import deque

dq = deque([1, 2, 3, 4, 5])

# len() - 长度
print(len(dq))  # 5

# reverse() - 反转
dq.reverse()
print(dq)  # deque([5, 4, 3, 2, 1])

# copy() - 浅拷贝
dq2 = dq.copy()

# 转换为列表
lst = list(dq)
print(lst)  # [5, 4, 3, 2, 1]

# 遍历
for x in dq:
    print(x)
```

#### 7.3.7 maxlen 限制长度

```python
from collections import deque

# 创建最大长度为3的队列
dq = deque(maxlen=3)

dq.append(1)  # deque([1], maxlen=3)
dq.append(2)  # deque([1, 2], maxlen=3)
dq.append(3)  # deque([1, 2, 3], maxlen=3)
dq.append(4)  # deque([2, 3, 4], maxlen=3) - 自动删除最左边的1

# 从左边添加
dq.appendleft(0)  # deque([0, 2, 3], maxlen=3) - 自动删除最右边的4

# 用途：保持最近的N个元素
recent_values = deque(maxlen=5)
for i in range(10):
    recent_values.append(i)
print(recent_values)  # deque([5, 6, 7, 8, 9], maxlen=5)
```

#### 7.3.8 deque vs list 性能对比

```python
from collections import deque

# deque 的优势：两端操作都是 O(1)
dq = deque([1, 2, 3])
dq.appendleft(0)  # O(1)
dq.popleft()      # O(1)

# list 在左端操作是 O(n)
lst = [1, 2, 3]
lst.insert(0, 0)  # O(n) - 需要移动所有元素
lst.pop(0)        # O(n) - 需要移动所有元素

# list 的优势：随机访问
lst[100]  # O(1)

# deque 的随机访问稍慢
dq[100]  # O(n) - 需要从两端开始查找
```

#### 7.3.9 使用场景 - 滑动窗口最大值

```python
from collections import deque

def maxSlidingWindow(nums, k):
    """滑动窗口最大值 - 单调队列"""
    dq = deque()  # 存储索引
    result = []

    for i, num in enumerate(nums):
        # 维护单调递减队列
        while dq and nums[dq[-1]] < num:
            dq.pop()
        dq.append(i)

        # 移除超出窗口的元素
        if dq[0] <= i - k:
            dq.popleft()

        # 记录窗口最大值
        if i >= k - 1:
            result.append(nums[dq[0]])

    return result

nums = [1, 3, -1, -3, 5, 3, 6, 7]
k = 3
print(maxSlidingWindow(nums, k))  # [3, 3, 5, 5, 6, 7]
```

#### 7.3.10 使用场景 - BFS（广度优先搜索）

```python
from collections import deque

def bfs(graph, start):
    """图的BFS遍历"""
    visited = set([start])
    queue = deque([start])
    result = []

    while queue:
        node = queue.popleft()
        result.append(node)

        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

    return result

graph = {
    0: [1, 2],
    1: [0, 3, 4],
    2: [0, 4],
    3: [1],
    4: [1, 2]
}
print(bfs(graph, 0))  # [0, 1, 2, 3, 4]
```

#### 7.3.11 使用场景 - 回文检查

```python
from collections import deque

def is_palindrome(s):
    """检查是否为回文"""
    dq = deque(s.lower())

    while len(dq) > 1:
        if dq.popleft() != dq.pop():
            return False
    return True

print(is_palindrome("racecar"))  # True
print(is_palindrome("hello"))    # False
```

#### 7.3.12 使用场景 - 最近使用记录（LRU缓存）

```python
from collections import deque

class RecentCounter:
    """记录最近3000ms内的请求"""
    def __init__(self):
        self.requests = deque()

    def ping(self, t):
        self.requests.append(t)
        # 移除3000ms之前的请求
        while self.requests[0] < t - 3000:
            self.requests.popleft()
        return len(self.requests)

counter = RecentCounter()
print(counter.ping(1))     # 1
print(counter.ping(100))   # 2
print(counter.ping(3001))  # 3
print(counter.ping(3002))  # 3 (请求1被移除)
```

#### 7.3.13 使用场景 - 循环缓冲区

```python
from collections import deque

class CircularBuffer:
    """固定大小的循环缓冲区"""
    def __init__(self, size):
        self.buffer = deque(maxlen=size)

    def add(self, item):
        self.buffer.append(item)

    def get_all(self):
        return list(self.buffer)

# 保持最近5条日志
log_buffer = CircularBuffer(5)
for i in range(10):
    log_buffer.add(f"Log {i}")

print(log_buffer.get_all())  # ['Log 5', 'Log 6', 'Log 7', 'Log 8', 'Log 9']
```

### 7.4 OrderedDict - 有序字典

**导入**: `from collections import OrderedDict`

**定义**: 记住键值对插入顺序的字典（Python 3.7+ 普通dict也保持插入顺序）

#### 7.4.1 初始化

```python
from collections import OrderedDict

# 空 OrderedDict
d1 = OrderedDict()

# 从键值对列表初始化
d2 = OrderedDict([('a', 1), ('b', 2), ('c', 3)])

# 从关键字参数初始化（注意：参数顺序可能不保证）
d3 = OrderedDict(a=1, b=2, c=3)

# 从普通字典初始化（保持原字典顺序）
regular_dict = {'a': 1, 'b': 2, 'c': 3}
d4 = OrderedDict(regular_dict)
```

#### 7.4.2 基本操作

```python
from collections import OrderedDict

d = OrderedDict()
d['a'] = 1
d['b'] = 2
d['c'] = 3
print(d)  # OrderedDict([('a', 1), ('b', 2), ('c', 3)])

# 访问元素
print(d['a'])  # 1

# 修改元素（位置不变）
d['a'] = 10
print(d)  # OrderedDict([('a', 10), ('b', 2), ('c', 3)])

# 删除元素
del d['b']
print(d)  # OrderedDict([('a', 10), ('c', 3)])

# 重新插入（会添加到末尾）
d['b'] = 2
print(d)  # OrderedDict([('a', 10), ('c', 3), ('b', 2)])
```

#### 7.4.3 move_to_end() - 移动到末尾或开头

```python
from collections import OrderedDict

d = OrderedDict([('a', 1), ('b', 2), ('c', 3), ('d', 4)])

# 移动到末尾（默认 last=True）
d.move_to_end('a')
print(d)  # OrderedDict([('b', 2), ('c', 3), ('d', 4), ('a', 1)])

# 移动到开头（last=False）
d.move_to_end('d', last=False)
print(d)  # OrderedDict([('d', 4), ('b', 2), ('c', 3), ('a', 1)])

# 连续移动
d.move_to_end('b')
d.move_to_end('c')
print(d)  # OrderedDict([('d', 4), ('a', 1), ('b', 2), ('c', 3)])
```

#### 7.4.4 popitem() - 按顺序删除

```python
from collections import OrderedDict

d = OrderedDict([('a', 1), ('b', 2), ('c', 3), ('d', 4)])

# 删除并返回最后一个元素（LIFO，last=True）
key, value = d.popitem()
print(f"Removed: {key}={value}")  # Removed: d=4
print(d)  # OrderedDict([('a', 1), ('b', 2), ('c', 3)])

# 删除并返回第一个元素（FIFO，last=False）
key, value = d.popitem(last=False)
print(f"Removed: {key}={value}")  # Removed: a=1
print(d)  # OrderedDict([('b', 2), ('c', 3)])
```

#### 7.4.5 遍历（保持顺序）

```python
from collections import OrderedDict

d = OrderedDict([('first', 1), ('second', 2), ('third', 3)])

# 遍历键（按插入顺序）
for key in d:
    print(key, end=' ')  # first second third

print()

# 遍历键值对
for key, value in d.items():
    print(f"{key}: {value}")
# first: 1
# second: 2
# third: 3

# 反向遍历
for key in reversed(d):
    print(key, end=' ')  # third second first
```

#### 7.4.6 相等性比较

```python
from collections import OrderedDict

# OrderedDict 比较时考虑顺序
d1 = OrderedDict([('a', 1), ('b', 2)])
d2 = OrderedDict([('b', 2), ('a', 1)])
print(d1 == d2)  # False（顺序不同）

# 普通字典比较不考虑顺序
dict1 = {'a': 1, 'b': 2}
dict2 = {'b': 2, 'a': 1}
print(dict1 == dict2)  # True

# OrderedDict 与普通字典比较（不考虑顺序）
d3 = OrderedDict([('a', 1), ('b', 2)])
dict3 = {'b': 2, 'a': 1}
print(d3 == dict3)  # True（值相同即可）
```

#### 7.4.7 OrderedDict vs dict (Python 3.7+)

```python
from collections import OrderedDict

# Python 3.7+ 普通dict也保持插入顺序
regular_dict = {}
regular_dict['a'] = 1
regular_dict['b'] = 2
regular_dict['c'] = 3
print(regular_dict)  # {'a': 1, 'b': 2, 'c': 3}

# OrderedDict 的优势：
# 1. move_to_end() 方法
od = OrderedDict([('a', 1), ('b', 2), ('c', 3)])
od.move_to_end('a')  # 普通dict没有这个方法

# 2. popitem(last=False) 可以从开头删除
od.popitem(last=False)  # 普通dict的popitem()只能从末尾删除

# 3. 相等性比较考虑顺序
od1 = OrderedDict([('a', 1), ('b', 2)])
od2 = OrderedDict([('b', 2), ('a', 1)])
print(od1 == od2)  # False

# 4. reversed() 更高效
for key in reversed(od):
    print(key)
```

#### 7.4.8 使用场景 - LRU 缓存（最近最少使用）

```python
from collections import OrderedDict

class LRUCache:
    """最近最少使用缓存"""
    def __init__(self, capacity):
        self.cache = OrderedDict()
        self.capacity = capacity

    def get(self, key):
        if key not in self.cache:
            return -1
        # 移到末尾表示最近使用
        self.cache.move_to_end(key)
        return self.cache[key]

    def put(self, key, value):
        if key in self.cache:
            # 更新值并移到末尾
            self.cache.move_to_end(key)
        self.cache[key] = value

        # 超过容量，删除最旧的（第一个）
        if len(self.cache) > self.capacity:
            self.cache.popitem(last=False)

# 使用示例
cache = LRUCache(2)
cache.put(1, 1)
cache.put(2, 2)
print(cache.get(1))    # 1
cache.put(3, 3)        # 删除键 2
print(cache.get(2))    # -1 (未找到)
cache.put(4, 4)        # 删除键 1
print(cache.get(1))    # -1 (未找到)
print(cache.get(3))    # 3
print(cache.get(4))    # 4
```

#### 7.4.9 使用场景 - 保持插入顺序的计数器

```python
from collections import OrderedDict

def count_in_order(items):
    """按首次出现的顺序统计频率"""
    counter = OrderedDict()
    for item in items:
        counter[item] = counter.get(item, 0) + 1
    return counter

words = ['apple', 'banana', 'apple', 'cherry', 'banana', 'apple']
result = count_in_order(words)
print(result)
# OrderedDict([('apple', 3), ('banana', 2), ('cherry', 1)])

# 按首次出现顺序遍历
for word, count in result.items():
    print(f"{word}: {count}")
# apple: 3
# banana: 2
# cherry: 1
```

#### 7.4.10 使用场景 - 配置文件（保持顺序）

```python
from collections import OrderedDict

class Config:
    """保持配置项顺序的配置类"""
    def __init__(self):
        self.settings = OrderedDict()

    def set(self, key, value):
        self.settings[key] = value

    def get(self, key, default=None):
        return self.settings.get(key, default)

    def save(self, filename):
        """保存配置（保持顺序）"""
        with open(filename, 'w') as f:
            for key, value in self.settings.items():
                f.write(f"{key}={value}\n")

config = Config()
config.set('host', 'localhost')
config.set('port', 8080)
config.set('debug', True)
config.set('timeout', 30)

# 按插入顺序输出
for key, value in config.settings.items():
    print(f"{key} = {value}")
# host = localhost
# port = 8080
# debug = True
# timeout = 30
```

#### 7.4.11 使用场景 - 任务队列（优先级 + 顺序）

```python
from collections import OrderedDict

class TaskQueue:
    """带优先级的任务队列（相同优先级按添加顺序）"""
    def __init__(self):
        self.tasks = OrderedDict()

    def add_task(self, task_id, priority):
        self.tasks[task_id] = priority

    def get_next_task(self):
        """获取最高优先级的任务（优先级相同取最早添加的）"""
        if not self.tasks:
            return None

        # 找到最高优先级
        max_priority = max(self.tasks.values())

        # 找到第一个该优先级的任务
        for task_id, priority in self.tasks.items():
            if priority == max_priority:
                self.tasks.pop(task_id)
                return task_id

    def get_all_tasks(self):
        return list(self.tasks.items())

queue = TaskQueue()
queue.add_task('task1', 1)
queue.add_task('task2', 3)
queue.add_task('task3', 3)
queue.add_task('task4', 2)

print(queue.get_next_task())  # task2 (优先级3，最早添加)
print(queue.get_next_task())  # task3 (优先级3)
print(queue.get_next_task())  # task4 (优先级2)
print(queue.get_all_tasks())  # [('task1', 1)]
```

#### 7.4.12 使用场景 - 最近访问记录

```python
from collections import OrderedDict

class RecentlyViewed:
    """最近浏览记录（去重，保持最新顺序）"""
    def __init__(self, max_size=10):
        self.items = OrderedDict()
        self.max_size = max_size

    def view(self, item):
        """浏览项目"""
        if item in self.items:
            # 如果已存在，移到末尾
            self.items.move_to_end(item)
        else:
            # 新项目添加到末尾
            self.items[item] = True
            # 超过最大数量，删除最旧的
            if len(self.items) > self.max_size:
                self.items.popitem(last=False)

    def get_history(self):
        """获取浏览历史（从新到旧）"""
        return list(reversed(self.items.keys()))

history = RecentlyViewed(max_size=5)
pages = ['home', 'products', 'about', 'home', 'contact', 'products', 'blog']

for page in pages:
    history.view(page)

print(history.get_history())
# ['blog', 'products', 'contact', 'home', 'about']
```

#### 7.4.13 实用技巧 - 字典排序

```python
from collections import OrderedDict

# 按键排序
d = {'banana': 3, 'apple': 5, 'cherry': 2}
sorted_by_key = OrderedDict(sorted(d.items()))
print(sorted_by_key)
# OrderedDict([('apple', 5), ('banana', 3), ('cherry', 2)])

# 按值排序
sorted_by_value = OrderedDict(sorted(d.items(), key=lambda x: x[1]))
print(sorted_by_value)
# OrderedDict([('cherry', 2), ('banana', 3), ('apple', 5)])

# 按值降序排序
sorted_by_value_desc = OrderedDict(sorted(d.items(), key=lambda x: x[1], reverse=True))
print(sorted_by_value_desc)
# OrderedDict([('apple', 5), ('banana', 3), ('cherry', 2)])
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

## 11. 面向对象编程

### 11.1 类的定义与实例化

```python
# 基本类定义
class Person:
    pass

# 创建实例
p = Person()

# 带初始化的类
class Person:
    def __init__(self, name, age):
        self.name = name  # 实例属性
        self.age = age

    def greet(self):  # 实例方法
        print(f"Hello, I'm {self.name}")

p = Person("Alice", 25)
p.greet()  # Hello, I'm Alice
```

### 11.2 类属性与实例属性

```python
class Student:
    # 类属性（所有实例共享）
    school = "Python Academy"
    count = 0

    def __init__(self, name, grade):
        # 实例属性（每个实例独有）
        self.name = name
        self.grade = grade
        Student.count += 1

s1 = Student("Tom", 90)
s2 = Student("Jerry", 85)

print(Student.school)  # Python Academy
print(Student.count)   # 2
print(s1.school)       # Python Academy
print(s1.name)         # Tom

# 修改类属性
Student.school = "New Academy"
print(s1.school)  # New Academy
print(s2.school)  # New Academy

# 实例属性会覆盖类属性
s1.school = "Private School"
print(s1.school)  # Private School
print(s2.school)  # New Academy
```

### 11.3 类方法与静态方法

```python
class Math:
    pi = 3.14159

    def __init__(self, value):
        self.value = value

    # 实例方法（需要self）
    def square(self):
        return self.value ** 2

    # 类方法（需要cls，可以访问类属性）
    @classmethod
    def from_string(cls, s):
        value = int(s)
        return cls(value)

    @classmethod
    def get_pi(cls):
        return cls.pi

    # 静态方法（不需要self或cls）
    @staticmethod
    def add(a, b):
        return a + b

    @staticmethod
    def is_even(n):
        return n % 2 == 0

# 使用实例方法
m = Math(5)
print(m.square())  # 25

# 使用类方法
m2 = Math.from_string("10")
print(m2.value)  # 10
print(Math.get_pi())  # 3.14159

# 使用静态方法
print(Math.add(3, 4))  # 7
print(Math.is_even(6))  # True
```

### 11.4 继承

```python
# 单继承
class Animal:
    def __init__(self, name):
        self.name = name

    def speak(self):
        pass

class Dog(Animal):
    def speak(self):
        return f"{self.name} says Woof!"

class Cat(Animal):
    def speak(self):
        return f"{self.name} says Meow!"

dog = Dog("Buddy")
cat = Cat("Whiskers")
print(dog.speak())  # Buddy says Woof!
print(cat.speak())  # Whiskers says Meow!

# 调用父类方法
class Dog(Animal):
    def __init__(self, name, breed):
        super().__init__(name)  # 调用父类的__init__
        self.breed = breed

    def speak(self):
        return f"{self.name} says Woof!"

# 多继承
class A:
    def method_a(self):
        print("Method A")

class B:
    def method_b(self):
        print("Method B")

class C(A, B):  # 多继承
    def method_c(self):
        print("Method C")

c = C()
c.method_a()  # Method A
c.method_b()  # Method B
c.method_c()  # Method C

# 查看继承顺序（MRO）
print(C.__mro__)
# (<class '__main__.C'>, <class '__main__.A'>, <class '__main__.B'>, <class 'object'>)
```

### 11.5 封装（访问控制）

封装是面向对象的三大特性之一，用于隐藏对象的内部实现细节。Python通过命名约定实现访问控制：

- `name`: 公有属性/方法，可以在任何地方访问
- `_name`: 受保护属性/方法（约定），建议仅在类内部和子类中使用
- `__name`: 私有属性/方法，会被名称改编为 `_ClassName__name`，更难从外部访问

```python
class BankAccount:
    def __init__(self, owner, balance):
        # 公有属性：可以在任何地方直接访问
        self.owner = owner

        # 受保护属性：以单下划线开头，约定俗成仅在类内部和子类使用
        # 技术上仍可从外部访问，但表示"请不要直接访问"
        self._balance = balance

        # 私有属性：以双下划线开头，Python会将其改编为 _BankAccount__password
        # 这使得外部访问变得困难（但不是完全不可能）
        self.__password = "1234"

    # 公有方法：可以被任何代码调用
    def deposit(self, amount):
        """存款方法，对外公开"""
        if amount > 0:
            self._balance += amount  # 内部可以访问受保护属性

    # 受保护方法：以单下划线开头，建议仅内部使用
    def _check_balance(self):
        """内部余额检查方法"""
        return self._balance

    # 私有方法：以双下划线开头，外部无法直接调用
    def __verify_password(self, pwd):
        """私有密码验证方法，仅供内部使用"""
        return pwd == self.__password

    def withdraw(self, amount, password):
        """取款方法，需要密码验证"""
        # 内部可以调用私有方法
        if self.__verify_password(password):
            if amount <= self._balance:
                self._balance -= amount
                return True
        return False

    def get_balance(self):
        """获取余额的公开接口"""
        return self._balance

# 使用示例
account = BankAccount("Alice", 1000)

# 公有属性可以直接访问
print(account.owner)           # Alice

# 受保护属性可以访问，但不推荐（违反约定）
print(account._balance)        # 1000（技术上可以，但不应该这样做）

# 私有属性无法直接访问
# print(account.__password)    # AttributeError: 'BankAccount' object has no attribute '__password'

# 但可以通过名称改编后的名字访问（不推荐，破坏封装）
print(account._BankAccount__password)  # 1234

# 使用公开的接口方法
account.deposit(500)
print(account.get_balance())   # 1500

# 私有方法无法从外部调用
# account.__verify_password("1234")  # AttributeError
```

**访问控制级别对比：**

```python
class Example:
    def __init__(self):
        self.public = "任何人都可以访问"
        self._protected = "约定仅内部使用"
        self.__private = "名称改编，难以访问"

obj = Example()
print(obj.public)       # ✓ 正常访问
print(obj._protected)   # ✓ 可以访问，但不建议
# print(obj.__private)  # ✗ AttributeError
print(obj._Example__private)  # ✓ 通过名称改编访问（不推荐）
```

### 11.6 属性装饰器 (@property)

`@property`装饰器将方法转换为属性，允许我们像访问属性一样调用方法，同时可以添加验证逻辑。
这是实现getter/setter模式的Python风格方法。

**语法说明：**

- `@property`: 定义getter方法，用于读取属性值
- `@属性名.setter`: 定义setter方法，用于设置属性值（可选）
- `@属性名.deleter`: 定义deleter方法，用于删除属性（可选）

```python
class Circle:
    def __init__(self, radius):
        # 实际存储数据的私有属性
        self._radius = radius

    # @property装饰器：将方法转换为"只读"属性
    # 当访问 obj.radius 时，会自动调用这个方法
    @property
    def radius(self):
        """getter方法：读取半径"""
        print("Getting radius")  # 演示：getter被调用
        return self._radius

    # @radius.setter装饰器：定义属性的赋值行为
    # 当执行 obj.radius = value 时，会自动调用这个方法
    @radius.setter
    def radius(self, value):
        """setter方法：设置半径，包含验证逻辑"""
        print(f"Setting radius to {value}")  # 演示：setter被调用
        if value < 0:
            raise ValueError("Radius cannot be negative")
        self._radius = value

    # @radius.deleter装饰器：定义属性的删除行为
    # 当执行 del obj.radius 时，会自动调用这个方法
    @radius.deleter
    def radius(self):
        """deleter方法：删除半径"""
        print("Deleting radius")
        del self._radius

    # 只读属性：只有@property，没有setter
    # 试图给area赋值会引发AttributeError
    @property
    def area(self):
        """计算属性：每次访问时动态计算"""
        return 3.14159 * self._radius ** 2

    # 可读写的计算属性
    @property
    def diameter(self):
        """直径的getter：通过半径计算"""
        return self._radius * 2

    @diameter.setter
    def diameter(self, value):
        """直径的setter：设置直径时自动更新半径"""
        self._radius = value / 2

# 使用示例
c = Circle(5)

# 像访问属性一样调用方法（自动调用getter）
print(c.radius)    # Getting radius -> 5
print(c.area)      # 78.53975（只读，动态计算）
print(c.diameter)  # 10

# 像设置属性一样调用setter方法
c.radius = 10      # Setting radius to 10
print(c.area)      # 314.159（半径变了，面积也变了）

# 通过diameter间接修改radius
c.diameter = 20    # 设置直径为20，半径自动变为10
print(c.radius)    # Getting radius -> 10.0

# 尝试设置只读属性会报错
# c.area = 100     # AttributeError: can't set attribute

# 使用deleter删除属性
# del c.radius     # Deleting radius

# 验证逻辑生效
try:
    c.radius = -5  # ValueError: Radius cannot be negative
except ValueError as e:
    print(e)
```

**@property的优势：**

```python
# 不使用@property（传统方式）
class OldStyle:
    def __init__(self, value):
        self._value = value

    def get_value(self):  # 需要调用方法
        return self._value

    def set_value(self, value):  # 需要调用方法
        self._value = value

old = OldStyle(10)
print(old.get_value())  # 必须用方法调用
old.set_value(20)

# 使用@property（Python风格）
class NewStyle:
    def __init__(self, value):
        self._value = value

    @property
    def value(self):  # 像属性一样访问
        return self._value

    @value.setter
    def value(self, val):  # 像属性一样赋值
        self._value = val

new = NewStyle(10)
print(new.value)  # 更简洁、更直观
new.value = 20
```

### 11.7 魔法方法（特殊方法）

魔法方法（Magic Methods）也叫特殊方法或双下划线方法（dunder methods），
以双下划线开头和结尾，如 `__init__`、`__str__` 等。它们让我们可以自定义对象的行为，
使自定义类能够像内置类型一样使用Python的运算符和内置函数。

```python
class Vector:
    """二维向量类，演示各种魔法方法的使用"""

    def __init__(self, x, y):
        """构造方法：创建对象时自动调用"""
        self.x = x
        self.y = y

    # ============ 字符串表示相关 ============
    def __str__(self):
        """定义 str(obj) 和 print(obj) 的输出
        用于给用户看的友好输出"""
        return f"Vector({self.x}, {self.y})"

    def __repr__(self):
        """定义 repr(obj) 的输出，也是交互式环境中直接输入对象名的显示
        应该返回一个能重新创建对象的表达式字符串"""
        return f"Vector({self.x}, {self.y})"

    # ============ 运算符重载（算术运算） ============
    def __add__(self, other):
        """定义加法运算符 +
        v1 + v2 会调用 v1.__add__(v2)"""
        return Vector(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        """定义减法运算符 -
        v1 - v2 会调用 v1.__sub__(v2)"""
        return Vector(self.x - other.x, self.y - other.y)

    def __mul__(self, scalar):
        """定义乘法运算符 *
        v * 2 会调用 v.__mul__(2)，实现向量的数乘"""
        return Vector(self.x * scalar, self.y * scalar)

    # ============ 比较运算符重载 ============
    def __eq__(self, other):
        """定义相等运算符 ==
        v1 == v2 会调用 v1.__eq__(v2)"""
        return self.x == other.x and self.y == other.y

    def __lt__(self, other):
        """定义小于运算符 <
        v1 < v2 会调用 v1.__lt__(v2)
        这里比较的是向量的模（长度）"""
        return (self.x ** 2 + self.y ** 2) < (other.x ** 2 + other.y ** 2)

    # 注意：定义了 __lt__ 和 __eq__ 后，Python可以自动推导出 >, <=, >=, !=

    # ============ 容器相关 ============
    def __len__(self):
        """定义 len(obj) 的行为
        返回向量的长度（模）"""
        return int((self.x ** 2 + self.y ** 2) ** 0.5)

    def __getitem__(self, index):
        """定义索引访问 obj[index]
        v[0] 获取x坐标，v[1] 获取y坐标"""
        if index == 0:
            return self.x
        elif index == 1:
            return self.y
        raise IndexError("Index out of range")

    def __setitem__(self, index, value):
        """定义索引赋值 obj[index] = value
        v[0] = 10 设置x坐标"""
        if index == 0:
            self.x = value
        elif index == 1:
            self.y = value
        else:
            raise IndexError("Index out of range")

    # ============ 可调用对象 ============
    def __call__(self):
        """定义对象被当作函数调用时的行为
        obj() 会调用 obj.__call__()
        这里返回向量的模"""
        return (self.x ** 2 + self.y ** 2) ** 0.5

# ============ 使用示例 ============
v1 = Vector(3, 4)
v2 = Vector(1, 2)

# 字符串表示
print(v1)           # 调用__str__: Vector(3, 4)
print(repr(v1))     # 调用__repr__: Vector(3, 4)

# 算术运算符（运算符重载）
print(v1 + v2)      # 调用__add__: Vector(4, 6)
print(v1 - v2)      # 调用__sub__: Vector(2, 2)
print(v1 * 2)       # 调用__mul__: Vector(6, 8)

# 比较运算符
print(v1 == v2)     # 调用__eq__: False
print(v1 > v2)      # 调用__lt__（逻辑反转）: True
print(v1 != v2)     # 基于__eq__自动实现: True

# 容器操作
print(len(v1))      # 调用__len__: 5
print(v1[0])        # 调用__getitem__: 3
print(v1[1])        # 调用__getitem__: 4
v1[0] = 10          # 调用__setitem__
print(v1.x)         # 10

# 可调用对象
print(v1())         # 调用__call__: 10.77...（向量的模）

# 支持迭代（因为实现了__getitem__）
for coord in v2:
    print(coord)    # 1, 2
```

**常用魔法方法的触发时机：**

```python
class Demo:
    def __init__(self): pass
    def __str__(self): return "str"
    def __repr__(self): return "repr"
    def __add__(self, other): return "add"
    def __len__(self): return 42
    def __getitem__(self, key): return f"item[{key}]"
    def __call__(self): return "called"

d = Demo()
print(d)         # 触发 __str__
repr(d)          # 触发 __repr__
d + 5            # 触发 __add__
len(d)           # 触发 __len__
d[0]             # 触发 __getitem__
d()              # 触发 __call__
```

### 11.8 常用魔法方法总结

```python
# 初始化和表示
__init__(self, ...)        # 构造函数
__del__(self)              # 析构函数
__str__(self)              # str()和print()使用
__repr__(self)             # repr()使用，交互式环境显示

# 运算符重载
__add__(self, other)       # +
__sub__(self, other)       # -
__mul__(self, other)       # *
__truediv__(self, other)   # /
__floordiv__(self, other)  # //
__mod__(self, other)       # %
__pow__(self, other)       # **

# 比较运算符
__eq__(self, other)        # ==
__ne__(self, other)        # !=
__lt__(self, other)        # <
__le__(self, other)        # <=
__gt__(self, other)        # >
__ge__(self, other)        # >=

# 容器类型
__len__(self)              # len()
__getitem__(self, key)     # obj[key]
__setitem__(self, key, value)  # obj[key] = value
__delitem__(self, key)     # del obj[key]
__contains__(self, item)   # item in obj
__iter__(self)             # 迭代
__next__(self)             # 迭代的下一个元素

# 其他
__call__(self, ...)        # obj()调用对象
__hash__(self)             # hash()
__bool__(self)             # bool()转换
```

### 11.9 抽象基类 (Abstract Base Class)

抽象基类（ABC）是一种特殊的类，不能被实例化，只能被继承。
它定义了子类必须实现的方法（抽象方法），用于制定接口规范。

**关键概念：**

- 继承 `ABC` 类：表明这是一个抽象基类
- `@abstractmethod` 装饰器：标记抽象方法，子类必须实现
- 抽象类不能实例化，只有实现了所有抽象方法的子类才能实例化

```python
from abc import ABC, abstractmethod

# 抽象基类：继承ABC，包含抽象方法
class Shape(ABC):
    """形状抽象基类，定义所有形状必须实现的接口"""

    # @abstractmethod 标记抽象方法：子类必须实现此方法
    @abstractmethod
    def area(self):
        """计算面积（抽象方法，子类必须实现）"""
        pass  # 抽象方法通常只声明，不实现

    @abstractmethod
    def perimeter(self):
        """计算周长（抽象方法，子类必须实现）"""
        pass

    # 普通方法：子类可以直接继承使用，也可以重写
    def description(self):
        """非抽象方法：提供默认实现"""
        return "This is a shape"

# 具体类1：实现所有抽象方法
class Rectangle(Shape):
    """矩形类：实现了Shape的所有抽象方法"""

    def __init__(self, width, height):
        self.width = width
        self.height = height

    # 必须实现area方法，否则Rectangle也会变成抽象类
    def area(self):
        return self.width * self.height

    # 必须实现perimeter方法
    def perimeter(self):
        return 2 * (self.width + self.height)

# 具体类2：实现所有抽象方法
class Circle(Shape):
    """圆形类：实现了Shape的所有抽象方法"""

    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return 3.14159 * self.radius ** 2

    def perimeter(self):  # 也叫circumference（周长）
        return 2 * 3.14159 * self.radius

# ============ 使用示例 ============

# 抽象类不能实例化
try:
    shape = Shape()  # TypeError: Can't instantiate abstract class Shape
except TypeError as e:
    print(f"错误: {e}")

# 具体类可以实例化（因为实现了所有抽象方法）
rect = Rectangle(5, 3)
print(rect.area())         # 15
print(rect.perimeter())    # 16
print(rect.description())  # This is a shape（继承的普通方法）

circle = Circle(5)
print(circle.area())       # 78.53975
print(circle.perimeter())  # 31.4159

# ============ 多态性：统一接口 ============
def print_shape_info(shape: Shape):
    """接收任何Shape类型的对象"""
    print(f"面积: {shape.area()}")
    print(f"周长: {shape.perimeter()}")
    print(f"描述: {shape.description()}")

shapes = [Rectangle(4, 5), Circle(3), Rectangle(2, 8)]
for s in shapes:
    print_shape_info(s)
    print("---")
```

**不完整实现的情况：**

```python
from abc import ABC, abstractmethod

class Animal(ABC):
    @abstractmethod
    def speak(self):
        pass

    @abstractmethod
    def move(self):
        pass

# 错误示例：只实现了部分抽象方法
class Dog(Animal):
    def speak(self):  # 只实现了speak
        return "Woof!"
    # 没有实现move方法

# 尝试实例化会报错
try:
    dog = Dog()  # TypeError: Can't instantiate abstract class Dog
except TypeError as e:
    print(e)  # Dog没有实现抽象方法move

# 正确示例：实现所有抽象方法
class Cat(Animal):
    def speak(self):
        return "Meow!"

    def move(self):
        return "Walking"

cat = Cat()  # ✓ 可以实例化
print(cat.speak())  # Meow!
```

**抽象类的优势：**

1. **接口规范**：强制子类实现特定方法
2. **类型检查**：可以用作类型提示，确保对象有特定方法
3. **代码组织**：将公共接口和部分实现放在基类中

### 11.10 多态 (Polymorphism)

多态是指同一个接口可以有不同的实现方式。在Python中，多态通过方法重写（子类重新定义父类的方法）实现。
**核心思想**：不同的对象调用同名方法时，会执行各自的实现。

```python
# 父类定义接口
class Animal:
    """动物基类"""
    def speak(self):
        """所有动物都能发声（但具体声音不同）"""
        pass  # 这里可以不实现，由子类实现

# 子类1：重写speak方法
class Dog(Animal):
    def speak(self):
        return "Woof!"  # 狗的叫声

# 子类2：重写speak方法
class Cat(Animal):
    def speak(self):
        return "Meow!"  # 猫的叫声

# 子类3：重写speak方法
class Bird(Animal):
    def speak(self):
        return "Chirp!"  # 鸟的叫声

# ============ 多态的体现 ============
# 函数接收Animal类型，但可以处理所有子类
def make_animal_speak(animal):
    """让动物发声
    参数animal可以是任何Animal的子类实例
    调用同一个方法speak()，但行为不同（多态）
    """
    print(animal.speak())  # 根据实际对象类型调用不同的speak()

# 创建不同类型的动物
animals = [Dog(), Cat(), Bird()]

# 同一个函数，处理不同类型的对象
for animal in animals:
    make_animal_speak(animal)  # 同样的调用，不同的结果
# 输出:
# Woof!   <- Dog的speak()
# Meow!   <- Cat的speak()
# Chirp!  <- Bird的speak()
```

**多态的实际应用：**

```python
# 例子：支付系统（不同支付方式）
class Payment:
    def pay(self, amount):
        raise NotImplementedError("子类必须实现pay方法")

class CreditCardPayment(Payment):
    def pay(self, amount):
        return f"使用信用卡支付 ${amount}"

class AlipayPayment(Payment):
    def pay(self, amount):
        return f"使用支付宝支付 ¥{amount}"

class WeChatPayment(Payment):
    def pay(self, amount):
        return f"使用微信支付 ¥{amount}"

# 统一的处理函数
def process_payment(payment: Payment, amount):
    """处理支付 - 不关心具体支付方式"""
    print(payment.pay(amount))

# 使用不同的支付方式
payments = [
    CreditCardPayment(),
    AlipayPayment(),
    WeChatPayment()
]

for p in payments:
    process_payment(p, 100)  # 同一接口，不同实现
```

### 11.11 组合 (Composition)

组合是指一个类包含其他类的实例作为其成员。这是"has-a"（有一个）关系。
**设计原则**：优先使用组合而不是继承（Composition over Inheritance）。

**组合 vs 继承：**

- **继承（is-a）**: Dog **是一个** Animal → `class Dog(Animal)`
- **组合（has-a）**: Car **有一个** Engine → `self.engine = Engine()`

```python
# 组件类1：引擎
class Engine:
    """引擎类 - 独立的组件"""
    def __init__(self, horsepower):
        self.horsepower = horsepower  # 马力

    def start(self):
        return "Engine started"

    def stop(self):
        return "Engine stopped"

# 组件类2：轮子
class Wheel:
    """轮子类 - 独立的组件"""
    def __init__(self, size):
        self.size = size  # 尺寸（英寸）

# 复合类：通过组合使用其他类
class Car:
    """汽车类 - 组合了Engine和Wheel

    Car不是Engine，也不是Wheel（不用继承）
    Car拥有Engine和Wheel（使用组合）
    """
    def __init__(self, model, horsepower, wheel_size):
        self.model = model

        # 组合：创建Engine对象作为Car的一部分
        self.engine = Engine(horsepower)

        # 组合：创建4个Wheel对象
        self.wheels = [Wheel(wheel_size) for _ in range(4)]

    def start(self):
        """启动汽车 - 委托给engine对象"""
        return f"{self.model}: {self.engine.start()}"

    def stop(self):
        return f"{self.model}: {self.engine.stop()}"

    def info(self):
        """显示汽车信息 - 访问组合对象的属性"""
        return f"{self.model} with {self.engine.horsepower}HP and {self.wheels[0].size}\" wheels"

# ============ 使用示例 ============
car = Car("Tesla Model 3", 300, 18)
print(car.start())  # Tesla Model 3: Engine started
print(car.info())   # Tesla Model 3 with 300HP and 18" wheels
print(car.stop())   # Tesla Model 3: Engine stopped

# 可以直接访问组合的对象
print(f"引擎马力: {car.engine.horsepower}HP")  # 300HP
print(f"轮子数量: {len(car.wheels)}")  # 4
```

**组合的优势：**

```python
# 使用继承（紧耦合，不灵活）
class ElectricCar(Car):
    pass  # 继承了gasoline engine，不合适

# 使用组合（灵活，可替换）
class ElectricEngine:
    def __init__(self, battery_capacity):
        self.battery_capacity = battery_capacity

    def start(self):
        return "Electric motor started"

class FlexibleCar:
    def __init__(self, model, engine):
        self.model = model
        self.engine = engine  # 可以是任何类型的引擎

    def start(self):
        return f"{self.model}: {self.engine.start()}"

# 灵活使用不同类型的引擎
gas_car = FlexibleCar("Ford F-150", Engine(400))
electric_car = FlexibleCar("Tesla Model S", ElectricEngine(100))

print(gas_car.start())      # Ford F-150: Engine started
print(electric_car.start()) # Tesla Model S: Electric motor started
```

### 11.12 数据类 (dataclass)

数据类（Python 3.7+）是一个装饰器，用于自动生成常用的特殊方法（如`__init__`、`__repr__`、`__eq__`等），
减少样板代码，特别适合用于存储数据的类。

**@dataclass 自动生成的方法：**

- `__init__()`: 根据字段自动生成构造函数
- `__repr__()`: 生成有用的字符串表示
- `__eq__()`: 实现相等性比较
- 可选：`__lt__`, `__le__`, `__gt__`, `__ge__`（排序相关）

```python
from dataclasses import dataclass, field
from typing import List

# ============ 基本数据类 ============
@dataclass  # 装饰器自动生成__init__, __repr__, __eq__等方法
class Point:
    """二维点 - 最简单的数据类"""
    x: int  # 类型注解（必需），会自动成为__init__的参数
    y: int

    # 不需要手动写__init__了！
    # 等价于：
    # def __init__(self, x: int, y: int):
    #     self.x = x
    #     self.y = y

p = Point(3, 4)
print(p)           # 自动生成的__repr__: Point(x=3, y=4)
print(p.x, p.y)    # 3 4

p2 = Point(3, 4)
print(p == p2)     # 自动生成的__eq__: True

# ============ 带默认值和方法 ============
@dataclass
class Student:
    """学生类 - 演示默认值和自定义方法"""
    name: str          # 必需参数（无默认值）
    age: int           # 必需参数

    # field(default_factory=list) 为可变类型提供默认值
    # 注意：不能直接用 grades: List[int] = []，这会导致所有实例共享同一个列表
    grades: List[int] = field(default_factory=list)

    # 可以添加普通方法
    def average(self):
        """计算平均分"""
        return sum(self.grades) / len(self.grades) if self.grades else 0

# 创建实例
s = Student("Alice", 20)  # grades使用默认值[]
print(s)  # Student(name='Alice', age=20, grades=[])

s.grades = [85, 90, 95]
print(s)  # Student(name='Alice', age=20, grades=[85, 90, 95])
print(s.average())  # 90.0

# ============ 不可变数据类 ============
@dataclass(frozen=True)  # frozen=True 使对象不可变（类似tuple）
class ImmutablePoint:
    """不可变的点 - 创建后不能修改"""
    x: int
    y: int

p = ImmutablePoint(1, 2)
print(p.x)  # 1（可以读取）

# 尝试修改会报错
try:
    p.x = 10  # FrozenInstanceError: cannot assign to field 'x'
except Exception as e:
    print(f"错误: {e}")

# 不可变对象可以作为字典的键或放入set
points_set = {ImmutablePoint(1, 2), ImmutablePoint(3, 4)}

# ============ 支持排序的数据类 ============
@dataclass(order=True)  # order=True 自动生成比较方法 (<, <=, >, >=)
class Person:
    """人员类 - 可排序"""
    name: str
    age: int = field(compare=True)      # 参与比较
    height: float = field(compare=False)  # 不参与比较

    # 默认按字段声明顺序比较：先比name，再比age
    # height不参与比较

people = [
    Person("Alice", 25, 165),
    Person("Bob", 30, 180),
    Person("Charlie", 20, 175),
    Person("Alice", 20, 170)  # 同名但年龄不同
]

# 可以直接排序
people.sort()  # 按 name, age 排序
for p in people:
    print(p.name, p.age, p.height)
# Alice 20 170
# Alice 25 165
# Bob 30 180
# Charlie 20 175
```

**数据类 vs 普通类对比：**

```python
# 普通类：需要手动写很多代码
class PersonOld:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def __repr__(self):
        return f"PersonOld(name={self.name!r}, age={self.age!r})"

    def __eq__(self, other):
        if isinstance(other, PersonOld):
            return (self.name, self.age) == (other.name, other.age)
        return False

# 数据类：自动生成上述所有代码
@dataclass
class PersonNew:
    name: str
    age: int

# 功能完全相同，但代码量大幅减少！
```

**field() 函数的常用参数：**

```python
from dataclasses import dataclass, field

@dataclass
class Config:
    # default: 简单类型的默认值
    host: str = "localhost"
    port: int = 8080

    # default_factory: 可变类型的默认值（函数）
    tags: List[str] = field(default_factory=list)

    # init=False: 不包含在__init__中
    internal_id: int = field(init=False, default=0)

    # repr=False: 不显示在__repr__中（隐藏敏感信息）
    password: str = field(repr=False, default="")

    # compare=False: 不参与比较
    created_at: float = field(compare=False, default=0.0)

c = Config()
print(c)  # Config(host='localhost', port=8080, tags=[], internal_id=0, created_at=0.0)
          # 注意password没有显示（repr=False）
```

### 11.13 单例模式 (Singleton Pattern)

单例模式确保一个类只有一个实例，并提供全局访问点。
常用场景：配置管理器、日志记录器、数据库连接池等。

**核心思想**：无论创建多少次，始终返回同一个对象。

```python
# ============ 方式1: 使用 __new__ 方法 ============
class Singleton:
    """单例类 - 通过__new__控制实例创建"""

    _instance = None  # 类变量：存储唯一实例

    def __new__(cls):
        """__new__在__init__之前调用，负责创建对象

        流程：
        1. 检查_instance是否已存在
        2. 如果不存在，创建新实例并保存
        3. 如果已存在，直接返回已有实例
        """
        if cls._instance is None:
            # 第一次创建：调用父类的__new__创建实例
            cls._instance = super().__new__(cls)
            print("创建新实例")
        else:
            print("返回已有实例")
        return cls._instance

    def __init__(self):
        """注意：每次调用Singleton()时__init__都会执行！"""
        self.value = 0

# 测试
s1 = Singleton()  # 创建新实例
s2 = Singleton()  # 返回已有实例
print(s1 is s2)   # True - 同一个对象
print(id(s1) == id(s2))  # True - 内存地址相同

s1.value = 100
print(s2.value)   # 100 - 因为s1和s2是同一个对象

# ============ 方式2: 使用装饰器 ============
def singleton(cls):
    """单例装饰器

    工作原理：
    1. 用字典instances存储类的实例
    2. 替换原始类为包装函数get_instance
    3. get_instance检查实例是否存在，不存在则创建
    """
    instances = {}  # 闭包变量：存储各个类的实例

    def get_instance(*args, **kwargs):
        """替代原始类的构造函数"""
        if cls not in instances:
            # 第一次调用：创建实例并缓存
            instances[cls] = cls(*args, **kwargs)
            print(f"创建{cls.__name__}实例")
        else:
            print(f"返回已有{cls.__name__}实例")
        return instances[cls]

    return get_instance

@singleton  # 等价于 Database = singleton(Database)
class Database:
    """数据库类 - 使用装饰器实现单例"""
    def __init__(self):
        self.connection = "Connected"
        print("初始化数据库连接")

# 测试
db1 = Database()  # 创建Database实例 -> 初始化数据库连接
db2 = Database()  # 返回已有Database实例
print(db1 is db2) # True

# ============ 方式3: 使用元类 (最强大) ============
class SingletonMeta(type):
    """单例元类

    元类控制类的创建过程，可以精确控制实例化行为。
    元类的__call__方法在调用类()时执行（即创建实例时）。
    """
    _instances = {}  # 存储所有使用此元类的类的实例

    def __call__(cls, *args, **kwargs):
        """当调用类()创建实例时，这个方法会被调用

        参数：
        - cls: 要实例化的类（如Logger）
        - args, kwargs: 传给__init__的参数
        """
        if cls not in cls._instances:
            # 调用type的__call__，即正常创建实例
            cls._instances[cls] = super().__call__(*args, **kwargs)
            print(f"创建{cls.__name__}实例")
        else:
            print(f"返回已有{cls.__name__}实例")
        return cls._instances[cls]

class Logger(metaclass=SingletonMeta):  # 指定元类
    """日志记录器 - 使用元类实现单例"""
    def __init__(self):
        self.logs = []  # 存储日志
        print("初始化Logger")

    def log(self, message):
        """记录日志"""
        self.logs.append(message)

# 测试
logger1 = Logger()  # 创建Logger实例 -> 初始化Logger
logger2 = Logger()  # 返回已有Logger实例
print(logger1 is logger2)  # True

logger1.log("消息1")
logger2.log("消息2")
print(logger1.logs)  # ['消息1', '消息2'] - 共享数据
print(logger2.logs)  # ['消息1', '消息2']
```

**三种方式对比：**

```python
# 方式1: __new__
# 优点: 简单直接
# 缺点: __init__会多次调用，可能需要额外处理

# 方式2: 装饰器
# 优点: 非侵入式，可复用
# 缺点: 改变了类的类型（不再是原始类）

# 方式3: 元类
# 优点: 最灵活，__init__只调用一次，保持类的类型
# 缺点: 较复杂，需要理解元类
```

**线程安全的单例（多线程环境）：**

```python
import threading

class ThreadSafeSingleton:
    """线程安全的单例"""
    _instance = None
    _lock = threading.Lock()  # 线程锁

    def __new__(cls):
        if cls._instance is None:
            with cls._lock:  # 加锁，确保同时只有一个线程创建实例
                # 双重检查：避免多个线程同时通过第一个检查
                if cls._instance is None:
                    cls._instance = super().__new__(cls)
        return cls._instance
```

### 11.14 上下文管理器 (Context Manager)

上下文管理器用于管理资源的获取和释放（如文件、网络连接、锁等）。
通过 `with` 语句使用，确保资源在使用后正确清理，即使发生异常也能执行清理操作。

**核心概念：**

- `__enter__()`: 进入 `with` 块时调用，返回值赋给 `as` 后的变量
- `__exit__()`: 离开 `with` 块时调用（正常结束或异常都会调用）

```python
# ============ 方式1: 使用 __enter__ 和 __exit__ ============
class FileManager:
    """文件管理器 - 自动关闭文件"""

    def __init__(self, filename, mode):
        """初始化：保存文件名和模式"""
        self.filename = filename
        self.mode = mode
        self.file = None

    def __enter__(self):
        """进入with块时调用

        返回值会赋给as后的变量
        with FileManager(...) as f:  <- f就是这里的返回值
        """
        print(f"打开文件: {self.filename}")
        self.file = open(self.filename, self.mode)
        return self.file  # 返回文件对象

    def __exit__(self, exc_type, exc_val, exc_tb):
        """离开with块时调用（无论正常结束还是异常）

        参数说明：
        - exc_type: 异常类型（如果有异常）
        - exc_val: 异常值
        - exc_tb: 异常追踪信息

        返回值：
        - False或None: 异常会向外传播
        - True: 抑制异常（不向外传播）
        """
        if self.file:
            print(f"关闭文件: {self.filename}")
            self.file.close()

        # 处理异常信息
        if exc_type is not None:
            print(f"发生异常: {exc_type.__name__}: {exc_val}")

        return False  # False表示不抑制异常，异常会继续传播

# 使用示例
with FileManager('test.txt', 'w') as f:
    # __enter__被调用，f = 文件对象
    f.write('Hello, World!')
    print("正在写入文件")
# 离开with块，__exit__被调用，文件自动关闭

print("\n--- 异常情况 ---")
try:
    with FileManager('test2.txt', 'w') as f:
        f.write('Some data')
        raise ValueError("测试异常")  # 即使发生异常
        # __exit__仍会被调用，文件仍会关闭
except ValueError:
    print("异常被捕获")

# ============ 方式2: 使用 contextlib 装饰器 ============
from contextlib import contextmanager

@contextmanager
def timer():
    """计时器上下文管理器

    @contextmanager装饰器让我们用生成器实现上下文管理器：
    - yield之前的代码 = __enter__
    - yield的值 = __enter__的返回值
    - yield之后的代码 = __exit__
    """
    import time

    # yield之前 = __enter__部分
    print("开始计时")
    start = time.time()

    yield  # 这里暂停，执行with块中的代码
    # yield的值可以赋给as后的变量
    # 如果不需要返回值，就只写yield

    # yield之后 = __exit__部分
    end = time.time()
    print(f"Time elapsed: {end - start:.4f}s")

# 使用装饰器实现的上下文管理器
with timer():
    # 开始计时
    result = sum([i**2 for i in range(1000000)])
    # 结束计时并打印时间
# Time elapsed: 0.xxxx s

# 带返回值的上下文管理器
@contextmanager
def database_connection():
    """模拟数据库连接"""
    print("连接数据库")
    conn = {"status": "connected"}  # 模拟连接对象

    try:
        yield conn  # 返回连接对象
    finally:
        # finally确保即使发生异常也会执行清理
        print("关闭数据库连接")
        conn["status"] = "closed"

with database_connection() as conn:
    print(f"数据库状态: {conn['status']}")
    # 使用连接...
# 自动关闭连接

# ============ 多个上下文管理器 ============
class ManagedResource:
    """资源管理器 - 演示多个上下文管理器的执行顺序"""

    def __init__(self, name):
        self.name = name

    def __enter__(self):
        print(f"→ 获取资源: {self.name}")
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        print(f"← 释放资源: {self.name}")
        return False  # 不抑制异常

print("\n--- 多个上下文管理器 ---")
# 多个上下文管理器的执行顺序：
# 进入顺序：A -> B -> C (从左到右)
# 退出顺序：C -> B -> A (从右到左，类似栈)
with ManagedResource('A') as a, \
     ManagedResource('B') as b, \
     ManagedResource('C') as c:
    print("  ✓ 使用资源 A, B, C")
# 输出:
# → 获取资源: A
# → 获取资源: B
# → 获取资源: C
#   ✓ 使用资源 A, B, C
# ← 释放资源: C
# ← 释放资源: B
# ← 释放资源: A
```

**上下文管理器的实际应用：**

```python
# 1. 临时修改工作目录
@contextmanager
def change_dir(path):
    import os
    old_dir = os.getcwd()
    os.chdir(path)
    try:
        yield
    finally:
        os.chdir(old_dir)

# 2. 临时设置环境变量
@contextmanager
def set_env(key, value):
    import os
    old_value = os.environ.get(key)
    os.environ[key] = value
    try:
        yield
    finally:
        if old_value is None:
            del os.environ[key]
        else:
            os.environ[key] = old_value

# 3. 线程锁管理
import threading
lock = threading.Lock()

with lock:  # Lock本身就是上下文管理器
    # 临界区代码
    pass
# 自动释放锁
```

**上下文管理器 vs try-finally：**

```python
# 不使用上下文管理器
f = open('file.txt', 'w')
try:
    f.write('data')
finally:
    f.close()  # 确保文件关闭

# 使用上下文管理器（更简洁、更安全）
with open('file.txt', 'w') as f:
    f.write('data')
# 自动关闭，代码更清晰
```

### 11.15 描述符 (Descriptor)

描述符是实现了特定协议的类，可以自定义属性访问、赋值和删除的行为。
它是 `@property`、`classmethod`、`staticmethod` 等特性的底层实现机制。

**描述符协议：**

- `__get__(self, obj, objtype=None)`: 获取属性值时调用
- `__set__(self, obj, value)`: 设置属性值时调用
- `__delete__(self, obj)`: 删除属性时调用
- `__set_name__(self, owner, name)`: Python 3.6+，知道自己的名字

```python
class Validator:
    """数据验证描述符

    描述符类：定义属性的访问行为
    当作为类属性时，可以拦截对该属性的访问
    """

    def __init__(self, min_value=None, max_value=None):
        """初始化验证器"""
        self.min_value = min_value
        self.max_value = max_value
        self.name = None  # 将在__set_name__中设置

    def __set_name__(self, owner, name):
        """Python 3.6+ 新增：自动获取属性名

        参数：
        - owner: 拥有此描述符的类（如Person）
        - name: 此描述符在owner中的属性名（如'age'）

        这个方法在类定义时自动调用
        """
        self.name = f"_{name}"  # 实际存储数据的属性名
        print(f"描述符绑定到 {owner.__name__}.{name}")

    def __get__(self, obj, objtype=None):
        """获取属性值时调用

        obj.age 会调用 Validator.__get__(descriptor, obj, type(obj))

        参数：
        - obj: 实例对象（如person实例），类访问时为None
        - objtype: 类对象（如Person类）
        """
        if obj is None:
            # 通过类访问（Person.age），返回描述符本身
            return self

        # 通过实例访问（person.age），返回实际值
        return getattr(obj, self.name, None)

    def __set__(self, obj, value):
        """设置属性值时调用

        obj.age = value 会调用 Validator.__set__(descriptor, obj, value)

        参数：
        - obj: 实例对象
        - value: 要设置的值
        """
        # 验证范围
        if self.min_value is not None and value < self.min_value:
            raise ValueError(
                f"{self.name[1:]} must be >= {self.min_value}, got {value}"
            )
        if self.max_value is not None and value > self.max_value:
            raise ValueError(
                f"{self.name[1:]} must be <= {self.max_value}, got {value}"
            )

        # 存储到实例的私有属性中（_age, _height等）
        setattr(obj, self.name, value)

class Person:
    """使用描述符的类"""

    # 类属性：描述符实例
    # 这些不是普通属性，而是描述符对象
    age = Validator(min_value=0, max_value=150)
    height = Validator(min_value=0, max_value=300)

    def __init__(self, name, age, height):
        self.name = name    # 普通属性
        self.age = age      # 触发Validator.__set__
        self.height = height  # 触发Validator.__set__

# 创建实例
print("\n--- 创建Person实例 ---")
p = Person("Alice", 25, 165)

# 读取属性（触发__get__）
print(f"\n年龄: {p.age}")  # Validator.__get__ -> 25
print(f"身高: {p.height}")  # Validator.__get__ -> 165

# 设置属性（触发__set__）
print("\n--- 修改属性 ---")
p.age = 30  # Validator.__set__ -> 验证通过
print(f"新年龄: {p.age}")  # 30

# 验证失败的情况
print("\n--- 验证错误 ---")
try:
    p.age = -5  # Validator.__set__ -> 验证失败
except ValueError as e:
    print(f"错误: {e}")

try:
    p.age = 200  # Validator.__set__ -> 验证失败
except ValueError as e:
    print(f"错误: {e}")

# 通过类访问描述符
print("\n--- 类级别访问 ---")
print(Person.age)  # <__main__.Validator object> - 返回描述符本身
print(type(Person.age))  # <class '__main__.Validator'>
```

**描述符的应用场景：**

```python
# 1. 类型检查描述符
class TypedProperty:
    def __init__(self, name, expected_type):
        self.name = name
        self.expected_type = expected_type

    def __get__(self, obj, objtype=None):
        if obj is None:
            return self
        return obj.__dict__.get(self.name)

    def __set__(self, obj, value):
        if not isinstance(value, self.expected_type):
            raise TypeError(
                f"{self.name} must be {self.expected_type.__name__}"
            )
        obj.__dict__[self.name] = value

class Book:
    title = TypedProperty('title', str)
    pages = TypedProperty('pages', int)

    def __init__(self, title, pages):
        self.title = title
        self.pages = pages

book = Book("Python Guide", 300)
# book.pages = "300"  # TypeError: pages must be int
```

### 11.16 元类 (Metaclass)

元类是"创建类的类"，是Python面向对象的高级特性。
类是对象的模板，元类是类的模板。

**关键概念：**

- 普通类创建实例：`obj = MyClass()`
- 元类创建类：`MyClass = MyMetaclass(name, bases, dict)`
- `type` 是Python中所有类的默认元类

```python
# ============ 基本元类 ============
class Meta(type):
    """自定义元类

    元类继承自type，可以控制类的创建过程
    """

    def __new__(mcs, name, bases, dct):
        """创建新类时调用

        参数：
        - mcs (metaclass): 元类自身
        - name: 要创建的类的名字（字符串）
        - bases: 要创建的类的父类（元组）
        - dct: 要创建的类的属性字典（包含方法、类变量等）

        返回值：新创建的类对象
        """
        print(f"\n元类创建类: {name}")
        print(f"  父类: {bases}")
        print(f"  属性: {list(dct.keys())}")

        # 可以在这里修改类的定义
        # 例如：为所有非私有方法添加日志功能
        for key, value in list(dct.items()):
            if callable(value) and not key.startswith('_'):
                print(f"  为方法 {key} 添加日志")
                dct[key] = Meta.log_method(value)

        # 调用type.__new__创建类
        return super().__new__(mcs, name, bases, dct)

    @staticmethod
    def log_method(func):
        """包装方法，添加日志功能"""
        def wrapper(*args, **kwargs):
            print(f"[LOG] 调用方法: {func.__name__}")
            result = func(*args, **kwargs)
            print(f"[LOG] 方法 {func.__name__} 执行完成")
            return result
        wrapper.__name__ = func.__name__
        return wrapper

# 使用元类创建类
print("--- 定义类（元类开始工作）---")
class MyClass(metaclass=Meta):  # 指定元类
    """使用Meta元类的类"""

    def method1(self):
        print("  执行 Method 1")

    def method2(self):
        print("  执行 Method 2")
# 输出: 元类创建类: MyClass...

print("\n--- 使用类 ---")
obj = MyClass()
obj.method1()
# [LOG] 调用方法: method1
#   执行 Method 1
# [LOG] 方法 method1 执行完成

# ============ 实用元类：单例模式 ============
class SingletonMeta(type):
    """单例元类

    使用此元类的类只能有一个实例
    """
    _instances = {}  # 存储各个类的唯一实例

    def __call__(cls, *args, **kwargs):
        """当调用类()创建实例时，这个方法被调用

        cls(): 创建实例 -> SingletonMeta.__call__(cls)
        """
        if cls not in cls._instances:
            # 第一次创建：调用type的__call__（正常创建实例）
            print(f"创建 {cls.__name__} 的唯一实例")
            cls._instances[cls] = super().__call__(*args, **kwargs)
        else:
            print(f"返回 {cls.__name__} 的已有实例")
        return cls._instances[cls]

class Config(metaclass=SingletonMeta):
    """配置类 - 单例"""
    def __init__(self):
        self.settings = {}
        print("初始化Config")

print("\n--- 单例模式测试 ---")
c1 = Config()  # 创建Config的唯一实例
c2 = Config()  # 返回Config的已有实例
print(f"c1 is c2: {c1 is c2}")  # True

c1.settings['key'] = 'value'
print(f"c2.settings: {c2.settings}")  # {'key': 'value'}
```

**元类的工作流程：**

```python
# 当Python看到类定义时：
class MyClass(metaclass=MyMeta):
    x = 1
    def method(self):
        pass

# 实际执行的是：
MyClass = MyMeta(
    'MyClass',           # name
    (),                  # bases
    {'x': 1, 'method': ...}  # dct
)

# 元类、类、实例的关系：
# type (元类) -> MyClass (类) -> obj (实例)
# type 创建 MyClass
# MyClass 创建 obj
```

**元类的实际应用：**

```python
# 1. ORM框架（如Django）
class ModelMeta(type):
    """ORM模型的元类"""
    def __new__(mcs, name, bases, dct):
        # 收集所有字段
        fields = {k: v for k, v in dct.items()
                  if isinstance(v, Field)}
        dct['_fields'] = fields
        return super().__new__(mcs, name, bases, dct)

# 2. 自动注册类
class AutoRegisterMeta(type):
    registry = {}

    def __new__(mcs, name, bases, dct):
        cls = super().__new__(mcs, name, bases, dct)
        mcs.registry[name] = cls  # 自动注册
        return cls
```

---

**最后更新**: 2026年2月17日
