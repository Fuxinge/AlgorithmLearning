# C++ STL 速查笔记

> 默认使用 `using namespace std;`

## 目录

- [1. 通用方法](#1-通用方法)
- [2. vector](#2-vector)
- [3. deque](#3-deque)
- [4. stack](#4-stack)
- [5. queue](#5-queue)
- [6. priority_queue (堆)](#6-priority_queue-堆)
- [7. set / multiset](#7-set--multiset)
- [8. map / multimap](#8-map--multimap)
- [9. unordered_set / unordered_map](#9-unordered_set--unordered_map)
- [10. pair](#10-pair)
- [11. string](#11-string)
- [12. algorithm 常用算法](#12-algorithm-常用算法)
- [13. 常见使用技巧](#13-常见使用技巧)

---

## 1. 通用方法

大多数 STL 容器都支持以下通用方法：

### 1.1 size() - 获取容器大小

```cpp
vector<int> v = {1, 2, 3};
cout << v.size() << endl;  // 输出: 3
```

### 1.2 empty() - 判断容器是否为空

```cpp
vector<int> v;
if (v.empty()) {
    cout << "容器为空" << endl;
}
```

### 1.3 clear() - 清空容器

```cpp
vector<int> v = {1, 2, 3};
v.clear();
cout << v.size() << endl;  // 输出: 0
```

### 1.4 begin() / end() - 迭代器

```cpp
vector<int> v = {1, 2, 3, 4, 5};
for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
}
// 输出: 1 2 3 4 5
```

### 1.5 front() / back() - 访问首尾元素

```cpp
vector<int> v = {1, 2, 3, 4, 5};
cout << v.front() << endl;  // 输出: 1
cout << v.back() << endl;   // 输出: 5
```

---

## 2. vector

**头文件**: `#include <vector>`

**定义**: 动态数组，支持随机访问

### 2.1 初始化

```cpp
vector<int> v1;                    // 空vector
vector<int> v2(10);                // 10个元素，初值为0
vector<int> v3(10, 5);             // 10个元素，初值为5
vector<int> v4 = {1, 2, 3, 4, 5};  // 列表初始化
vector<int> v5(v4);                // 拷贝构造
```

### 2.2 push_back() - 尾部插入元素

```cpp
vector<int> v;
v.push_back(1);
v.push_back(2);
v.push_back(3);
// v = {1, 2, 3}
```

### 2.3 pop_back() - 删除尾部元素

```cpp
vector<int> v = {1, 2, 3};
v.pop_back();
// v = {1, 2}
```

### 2.4 insert() - 在指定位置插入元素

```cpp
vector<int> v = {1, 2, 4, 5};
v.insert(v.begin() + 2, 3);  // 在索引2处插入3
// v = {1, 2, 3, 4, 5}

v.insert(v.begin(), 0);  // 在开头插入0
// v = {0, 1, 2, 3, 4, 5}
```

### 2.5 erase() - 删除指定位置的元素

```cpp
vector<int> v = {1, 2, 3, 4, 5};
v.erase(v.begin() + 2);  // 删除索引2的元素
// v = {1, 2, 4, 5}

v.erase(v.begin() + 1, v.begin() + 3);  // 删除区间[1, 3)
// v = {1, 5}
```

### 2.6 operator[] - 通过索引访问元素

```cpp
vector<int> v = {10, 20, 30};
cout << v[0] << endl;  // 输出: 10
v[1] = 25;
cout << v[1] << endl;  // 输出: 25
```

### 2.7 at() - 通过索引访问元素（带边界检查）

```cpp
vector<int> v = {10, 20, 30};
cout << v.at(1) << endl;  // 输出: 20
// v.at(10);  // 会抛出异常
```

### 2.8 resize() - 改变容器大小

```cpp
vector<int> v = {1, 2, 3};
v.resize(5);      // v = {1, 2, 3, 0, 0}
v.resize(2);      // v = {1, 2}
v.resize(4, 10);  // v = {1, 2, 10, 10}
```

### 2.9 reserve() - 预分配空间

```cpp
vector<int> v;
v.reserve(1000);  // 预分配1000个元素的空间，避免频繁扩容
```

### 2.10 二维 vector

```cpp
// 定义一个 n*m 的二维数组，初值为0
int n = 3, m = 4;
vector<vector<int>> v(n, vector<int>(m, 0));

// 访问元素
v[1][2] = 5;
cout << v[1][2] << endl;  // 输出: 5
```

---

## 3. deque

**头文件**: `#include <deque>`

**定义**: 双端队列，支持在头尾两端高效插入和删除

### 3.1 初始化

```cpp
deque<int> dq1;                    // 空deque
deque<int> dq2 = {1, 2, 3, 4, 5};  // 列表初始化
```

### 3.2 push_back() / push_front() - 尾部/头部插入

```cpp
deque<int> dq;
dq.push_back(1);   // 尾部插入: {1}
dq.push_back(2);   // 尾部插入: {1, 2}
dq.push_front(0);  // 头部插入: {0, 1, 2}
```

### 3.3 pop_back() / pop_front() - 删除尾部/头部元素

```cpp
deque<int> dq = {1, 2, 3, 4};
dq.pop_back();   // {1, 2, 3}
dq.pop_front();  // {2, 3}
```

### 3.4 operator[] - 通过索引访问

```cpp
deque<int> dq = {10, 20, 30};
cout << dq[1] << endl;  // 输出: 20
```

### 3.5 使用场景示例 - 滑动窗口

```cpp
deque<int> dq;
vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
int k = 3;

for (int i = 0; i < nums.size(); i++) {
    // 维护单调队列
    while (!dq.empty() && nums[dq.back()] <= nums[i]) {
        dq.pop_back();
    }
    dq.push_back(i);

    // 移除超出窗口的元素
    if (dq.front() <= i - k) {
        dq.pop_front();
    }

    if (i >= k - 1) {
        cout << nums[dq.front()] << " ";
    }
}
```

---

## 4. stack

**头文件**: `#include <stack>`

**定义**: 栈，后进先出 (LIFO)

### 4.1 初始化

```cpp
stack<int> stk;
```

### 4.2 push() - 入栈

```cpp
stack<int> stk;
stk.push(1);
stk.push(2);
stk.push(3);
// 栈顶到栈底: 3, 2, 1
```

### 4.3 pop() - 出栈

```cpp
stack<int> stk;
stk.push(1);
stk.push(2);
stk.pop();  // 移除栈顶元素2
```

### 4.4 top() - 访问栈顶元素

```cpp
stack<int> stk;
stk.push(1);
stk.push(2);
cout << stk.top() << endl;  // 输出: 2
```

### 4.5 size() / empty() - 栈大小和判空

```cpp
stack<int> stk;
cout << stk.empty() << endl;  // 输出: 1 (true)
stk.push(1);
cout << stk.size() << endl;   // 输出: 1
```

### 4.6 使用场景示例 - 括号匹配

```cpp
bool isValid(string s) {
    stack<char> stk;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else {
            if (stk.empty()) return false;
            char top = stk.top();
            if ((c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{')) {
                stk.pop();
            } else {
                return false;
            }
        }
    }
    return stk.empty();
}
```

---

## 5. queue

**头文件**: `#include <queue>`

**定义**: 队列，先进先出 (FIFO)

### 5.1 初始化

```cpp
queue<int> q;
```

### 5.2 push() - 入队

```cpp
queue<int> q;
q.push(1);
q.push(2);
q.push(3);
// 队首到队尾: 1, 2, 3
```

### 5.3 pop() - 出队

```cpp
queue<int> q;
q.push(1);
q.push(2);
q.pop();  // 移除队首元素1
```

### 5.4 front() - 访问队首元素

```cpp
queue<int> q;
q.push(1);
q.push(2);
cout << q.front() << endl;  // 输出: 1
```

### 5.5 back() - 访问队尾元素

```cpp
queue<int> q;
q.push(1);
q.push(2);
cout << q.back() << endl;  // 输出: 2
```

### 5.6 使用场景示例 - BFS

```cpp
vector<int> g[100];  // 邻接表
bool vis[100];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}
```

---

## 6. priority_queue (堆)

**头文件**: `#include <queue>`

**定义**: 优先队列，默认大根堆

### 6.1 初始化

```cpp
priority_queue<int> pq;                               // 大根堆
priority_queue<int, vector<int>, greater<int>> pq2;   // 小根堆
```

### 6.2 push() - 插入元素

```cpp
priority_queue<int> pq;
pq.push(3);
pq.push(1);
pq.push(4);
pq.push(2);
// 堆顶元素为4（最大值）
```

### 6.3 pop() - 删除堆顶元素

```cpp
priority_queue<int> pq;
pq.push(3);
pq.push(1);
pq.push(4);
pq.pop();  // 删除堆顶元素4
```

### 6.4 top() - 访问堆顶元素

```cpp
priority_queue<int> pq;
pq.push(3);
pq.push(1);
pq.push(4);
cout << pq.top() << endl;  // 输出: 4
```

### 6.5 小根堆示例

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
pq.push(3);
pq.push(1);
pq.push(4);
cout << pq.top() << endl;  // 输出: 1（最小值）
```

### 6.6 自定义比较函数 - 结构体

```cpp
struct Node {
    int val, idx;
    bool operator < (const Node& other) const {
        return val > other.val;  // 小根堆：val小的优先级高
    }
};

priority_queue<Node> pq;
pq.push({3, 0});
pq.push({1, 1});
pq.push({4, 2});
cout << pq.top().val << endl;  // 输出: 1
```

### 6.7 使用场景示例 - Dijkstra 最短路

```cpp
typedef pair<int, int> PII;  // (距离, 节点)
vector<PII> g[100];
int dist[100];
bool vis[100];

void dijkstra(int start) {
    memset(dist, 0x3f, sizeof dist);
    dist[start] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto [v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
```

---

## set / multiset

**头文件**: `#include <set>`

**定义**:

- `set`: 有序集合，元素唯一
- `multiset`: 有序集合，元素可重复

### 初始化

```cpp
set<int> s;
multiset<int> ms;
set<int> s2 = {1, 2, 3, 4, 5};
```

### 7.2 insert() - 插入元素

```cpp
set<int> s;
s.insert(1);
s.insert(2);
s.insert(1);  // 不会重复插入
// s = {1, 2}

multiset<int> ms;
ms.insert(1);
ms.insert(2);
ms.insert(1);  // 允许重复
// ms = {1, 1, 2}
```

### 7.3 erase() - 删除元素

```cpp
set<int> s = {1, 2, 3, 4, 5};
s.erase(3);  // 删除值为3的元素
// s = {1, 2, 4, 5}

s.erase(s.begin());  // 删除第一个元素
// s = {2, 4, 5}
```

### 7.4 find() - 查找元素

```cpp
set<int> s = {1, 2, 3, 4, 5};
auto it = s.find(3);
if (it != s.end()) {
    cout << "找到元素: " << *it << endl;  // 输出: 找到元素: 3
}

if (s.find(10) == s.end()) {
    cout << "元素10不存在" << endl;
}
```

### 7.5 count() - 统计元素个数

```cpp
set<int> s = {1, 2, 3};
cout << s.count(2) << endl;  // 输出: 1
cout << s.count(5) << endl;  // 输出: 0

multiset<int> ms = {1, 1, 2, 2, 2, 3};
cout << ms.count(2) << endl;  // 输出: 3
```

### 7.6 lower_bound() / upper_bound() - 二分查找

```cpp
set<int> s = {1, 3, 5, 7, 9};

// lower_bound: 返回第一个 >= x 的元素的迭代器
auto it1 = s.lower_bound(5);
cout << *it1 << endl;  // 输出: 5

auto it2 = s.lower_bound(4);
cout << *it2 << endl;  // 输出: 5

// upper_bound: 返回第一个 > x 的元素的迭代器
auto it3 = s.upper_bound(5);
cout << *it3 << endl;  // 输出: 7
```

### 7.7 遍历 set

```cpp
set<int> s = {5, 2, 8, 1, 9};
for (int x : s) {
    cout << x << " ";  // 输出: 1 2 5 8 9 (自动排序)
}
```

### 7.8 使用场景示例 - 去重并排序

```cpp
vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5};
set<int> s(nums.begin(), nums.end());
// s = {1, 2, 3, 4, 5, 6, 9}
```

---

## map / multimap

**头文件**: `#include <map>`

**定义**:

- `map`: 有序映射，键唯一
- `multimap`: 有序映射，键可重复

### 初始化

```cpp
map<string, int> mp;
map<int, string> mp2 = {{1, "one"}, {2, "two"}};
```

### 8.2 插入元素

```cpp
map<string, int> mp;
mp["apple"] = 5;       // 方式1: 下标访问
mp["banana"] = 3;
mp.insert({"orange", 7});  // 方式2: insert
mp.insert(make_pair("grape", 4));  // 方式3: make_pair
// mp = {{"apple", 5}, {"banana", 3}, {"grape", 4}, {"orange", 7}}
```

### 8.3 operator[] - 访问/修改元素

```cpp
map<string, int> mp;
mp["apple"] = 5;
cout << mp["apple"] << endl;  // 输出: 5

mp["apple"] = 10;  // 修改
cout << mp["apple"] << endl;  // 输出: 10

// 注意: 如果键不存在，会自动创建并赋默认值
cout << mp["banana"] << endl;  // 输出: 0
```

### 8.4 at() - 访问元素（带边界检查）

```cpp
map<string, int> mp = {{"apple", 5}, {"banana", 3}};
cout << mp.at("apple") << endl;  // 输出: 5
// cout << mp.at("orange") << endl;  // 会抛出异常
```

### 8.5 find() - 查找键

```cpp
map<string, int> mp = {{"apple", 5}, {"banana", 3}};
auto it = mp.find("apple");
if (it != mp.end()) {
    cout << it->first << ": " << it->second << endl;  // 输出: apple: 5
}
```

### 8.6 count() - 判断键是否存在

```cpp
map<string, int> mp = {{"apple", 5}, {"banana", 3}};
if (mp.count("apple")) {
    cout << "apple存在" << endl;
}
```

### 8.7 erase() - 删除元素

```cpp
map<string, int> mp = {{"apple", 5}, {"banana", 3}, {"orange", 7}};
mp.erase("banana");  // 删除键为"banana"的元素
// mp = {{"apple", 5}, {"orange", 7}}
```

### 8.8 遍历 map

```cpp
map<string, int> mp = {{"apple", 5}, {"banana", 3}, {"orange", 7}};

// 方式1: 使用迭代器
for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << it->first << ": " << it->second << endl;
}

// 方式2: 使用 range-based for
for (auto& [key, value] : mp) {
    cout << key << ": " << value << endl;
}

// 方式3: 使用 pair
for (auto& p : mp) {
    cout << p.first << ": " << p.second << endl;
}
```

### 8.9 使用场景示例 - 统计词频

```cpp
string text = "apple banana apple orange banana apple";
map<string, int> freq;
stringstream ss(text);
string word;

while (ss >> word) {
    freq[word]++;
}

for (auto& [word, count] : freq) {
    cout << word << ": " << count << endl;
}
// 输出:
// apple: 3
// banana: 2
// orange: 1
```

---

## 9. unordered_set / unordered_map

**头文件**: `#include <unordered_set>` / `#include <unordered_map>`

**定义**: 基于哈希表的无序集合/映射，查找时间复杂度 O(1)

### 9.1 unordered_set 基本用法

```cpp
#include <unordered_set>

unordered_set<int> us;
us.insert(1);
us.insert(2);
us.insert(3);

// 查找
if (us.count(2)) {
    cout << "2存在" << endl;
}

// 删除
us.erase(2);
```

### 9.2 unordered_map 基本用法

```cpp
#include <unordered_map>

unordered_map<string, int> um;
um["apple"] = 5;
um["banana"] = 3;

// 查找
if (um.count("apple")) {
    cout << um["apple"] << endl;  // 输出: 5
}

// 遍历（无序）
for (auto& [key, value] : um) {
    cout << key << ": " << value << endl;
}
```

### 9.3 set vs unordered_set

```cpp
// set: 有序，红黑树实现，O(log n)
set<int> s = {5, 2, 8, 1};
for (int x : s) {
    cout << x << " ";  // 输出: 1 2 5 8
}

// unordered_set: 无序，哈希表实现，O(1)
unordered_set<int> us = {5, 2, 8, 1};
for (int x : us) {
    cout << x << " ";  // 输出顺序不确定
}
```

### 9.4 使用场景示例 - 两数之和

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (mp.count(complement)) {
            return {mp[complement], i};
        }
        mp[nums[i]] = i;
    }
    return {};
}
```

---

## 10. pair

**头文件**: `#include <utility>`

**定义**: 存储两个值的结构

### 10.1 初始化

```cpp
pair<int, int> p1;
pair<int, string> p2 = {1, "one"};
pair<int, int> p3 = make_pair(1, 2);
pair<int, int> p4(1, 2);
```

### 10.2 first / second - 访问元素

```cpp
pair<int, string> p = {1, "one"};
cout << p.first << endl;   // 输出: 1
cout << p.second << endl;  // 输出: one
```

### 10.3 比较操作

```cpp
pair<int, int> p1 = {1, 2};
pair<int, int> p2 = {1, 3};
pair<int, int> p3 = {2, 1};

cout << (p1 < p2) << endl;  // 输出: 1 (先比较first，再比较second)
cout << (p1 < p3) << endl;  // 输出: 1
```

### 10.4 使用场景示例 - 坐标点

```cpp
vector<pair<int, int>> points = {{1, 2}, {3, 4}, {5, 6}};

for (auto& [x, y] : points) {
    cout << "(" << x << ", " << y << ")" << endl;
}
```

### 10.5 使用场景示例 - 排序

```cpp
vector<pair<int, string>> students = {
    {85, "Alice"},
    {92, "Bob"},
    {78, "Charlie"}
};

// 按分数从高到低排序
sort(students.begin(), students.end(), [](auto& a, auto& b) {
    return a.first > b.first;
});

for (auto& [score, name] : students) {
    cout << name << ": " << score << endl;
}
// 输出:
// Bob: 92
// Alice: 85
// Charlie: 78
```

---

## 11. string

**头文件**: `#include <string>`

**定义**: C++ 字符串类

### 11.1 初始化

```cpp
string s1;              // 空字符串
string s2 = "hello";    // 字面量初始化
string s3(5, 'a');      // 5个'a': "aaaaa"
string s4(s2);          // 拷贝构造
```

### 11.2 基本操作

```cpp
string s = "hello";

// 长度
cout << s.size() << endl;     // 输出: 5
cout << s.length() << endl;   // 输出: 5

// 访问字符
cout << s[0] << endl;         // 输出: h
cout << s.at(1) << endl;      // 输出: e

// 修改
s[0] = 'H';                   // s = "Hello"
```

### 11.3 拼接

```cpp
string s1 = "hello";
string s2 = "world";

// 使用 +
string s3 = s1 + " " + s2;    // "hello world"

// 使用 +=
s1 += " ";
s1 += s2;                     // s1 = "hello world"

// 使用 append
string s4 = "hello";
s4.append(" world");          // "hello world"
```

### 11.4 substr() - 子串

```cpp
string s = "hello world";
cout << s.substr(0, 5) << endl;   // 输出: hello
cout << s.substr(6) << endl;      // 输出: world
cout << s.substr(6, 3) << endl;   // 输出: wor
```

### 11.5 find() - 查找子串

```cpp
string s = "hello world";
int pos = s.find("world");
if (pos != string::npos) {
    cout << "找到位置: " << pos << endl;  // 输出: 找到位置: 6
}

// 查找字符
pos = s.find('o');
cout << pos << endl;  // 输出: 4 (第一个'o'的位置)

// rfind: 从后往前查找
pos = s.rfind('o');
cout << pos << endl;  // 输出: 7 (最后一个'o'的位置)
```

### 11.6 replace() - 替换

```cpp
string s = "hello world";
s.replace(6, 5, "C++");  // 从位置6开始，替换5个字符
cout << s << endl;  // 输出: hello C++
```

### 11.7 insert() - 插入

```cpp
string s = "hello world";
s.insert(5, " beautiful");
cout << s << endl;  // 输出: hello beautiful world
```

### 11.8 erase() - 删除

```cpp
string s = "hello world";
s.erase(5, 6);  // 从位置5开始删除6个字符
cout << s << endl;  // 输出: hello
```

### 11.9 compare() - 比较

```cpp
string s1 = "apple";
string s2 = "banana";
string s3 = "apple";

cout << s1.compare(s2) << endl;  // 输出: 负数 (s1 < s2)
cout << s1.compare(s3) << endl;  // 输出: 0 (相等)
```

### 11.10 大小写转换

```cpp
#include <algorithm>
#include <cctype>

string s = "Hello World";

// 转小写
transform(s.begin(), s.end(), s.begin(), ::tolower);
cout << s << endl;  // 输出: hello world

// 转大写
transform(s.begin(), s.end(), s.begin(), ::toupper);
cout << s << endl;  // 输出: HELLO WORLD
```

### 11.11 字符串与数字转换

```cpp
// 字符串转数字
string s1 = "123";
int num1 = stoi(s1);           // 123
long long num2 = stoll(s1);    // 123
double num3 = stod("3.14");    // 3.14

// 数字转字符串
int num = 123;
string s2 = to_string(num);    // "123"
```

### 11.12 使用场景示例 - 分割字符串

```cpp
string s = "apple,banana,orange";
vector<string> result;
int start = 0;
int pos = s.find(',');

while (pos != string::npos) {
    result.push_back(s.substr(start, pos - start));
    start = pos + 1;
    pos = s.find(',', start);
}
result.push_back(s.substr(start));

for (string& word : result) {
    cout << word << endl;
}
// 输出:
// apple
// banana
// orange
```

---

## 12. algorithm 常用算法

**头文件**: `#include <algorithm>`

### 12.1 sort() - 排序

```cpp
vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};

// 升序排序
sort(v.begin(), v.end());
// v = {1, 1, 2, 3, 4, 5, 6, 9}

// 降序排序
sort(v.begin(), v.end(), greater<int>());
// v = {9, 6, 5, 4, 3, 2, 1, 1}

// 自定义比较函数
sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;  // 降序
});
```

### 12.2 reverse() - 反转

```cpp
vector<int> v = {1, 2, 3, 4, 5};
reverse(v.begin(), v.end());
// v = {5, 4, 3, 2, 1}
```

### 12.3 unique() - 去重（需要先排序）

```cpp
vector<int> v = {1, 1, 2, 2, 3, 3, 3, 4};
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
// v = {1, 2, 3, 4}
```

### 12.4 lower_bound() / upper_bound() - 二分查找

```cpp
vector<int> v = {1, 2, 2, 2, 3, 4, 5};

// lower_bound: 第一个 >= x 的位置
auto it1 = lower_bound(v.begin(), v.end(), 2);
cout << it1 - v.begin() << endl;  // 输出: 1

// upper_bound: 第一个 > x 的位置
auto it2 = upper_bound(v.begin(), v.end(), 2);
cout << it2 - v.begin() << endl;  // 输出: 4
```

### 12.5 binary_search() - 判断元素是否存在

```cpp
vector<int> v = {1, 2, 3, 4, 5};
cout << binary_search(v.begin(), v.end(), 3) << endl;  // 输出: 1
cout << binary_search(v.begin(), v.end(), 6) << endl;  // 输出: 0
```

### 12.6 max() / min() - 最大/最小值

```cpp
int a = 5, b = 10;
cout << max(a, b) << endl;  // 输出: 10
cout << min(a, b) << endl;  // 输出: 5

// 多个值
cout << max({1, 5, 3, 9, 2}) << endl;  // 输出: 9
```

### 12.7 max_element() / min_element() - 最大/最小元素

```cpp
vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};
auto it_max = max_element(v.begin(), v.end());
auto it_min = min_element(v.begin(), v.end());

cout << *it_max << endl;          // 输出: 9
cout << *it_min << endl;          // 输出: 1
cout << it_max - v.begin() << endl;  // 输出: 5 (最大值的索引)
```

### 12.8 accumulate() - 求和

```cpp
#include <numeric>

vector<int> v = {1, 2, 3, 4, 5};
int sum = accumulate(v.begin(), v.end(), 0);
cout << sum << endl;  // 输出: 15
```

### 12.9 count() / count_if() - 统计元素个数

```cpp
vector<int> v = {1, 2, 3, 2, 4, 2, 5};

// count: 统计值为x的元素个数
cout << count(v.begin(), v.end(), 2) << endl;  // 输出: 3

// count_if: 统计满足条件的元素个数
cout << count_if(v.begin(), v.end(), [](int x) {
    return x > 2;
}) << endl;  // 输出: 3
```

### 12.10 fill() - 填充

```cpp
vector<int> v(5);
fill(v.begin(), v.end(), 10);
// v = {10, 10, 10, 10, 10}
```

### 12.11 next_permutation() - 下一个排列

```cpp
vector<int> v = {1, 2, 3};
do {
    for (int x : v) cout << x << " ";
    cout << endl;
} while (next_permutation(v.begin(), v.end()));

// 输出所有排列:
// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 1 2
// 3 2 1
```

### 12.12 swap() - 交换

```cpp
int a = 5, b = 10;
swap(a, b);
cout << a << " " << b << endl;  // 输出: 10 5

vector<int> v1 = {1, 2, 3};
vector<int> v2 = {4, 5, 6};
swap(v1, v2);
// v1 = {4, 5, 6}, v2 = {1, 2, 3}
```

---

## 13. 常见使用技巧

### 13.1 快速输入输出优化

```cpp
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
```

### 13.2 数组初始化

```cpp
int a[100];
memset(a, 0, sizeof a);     // 全部初始化为0
memset(a, 0x3f, sizeof a);  // 初始化为无穷大
fill(a, a + 100, -1);       // 全部初始化为-1
```

### 13.3 常用宏定义

```cpp
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> PII;
```

### 13.4 结构体排序

```cpp
struct Student {
    string name;
    int score;

    bool operator < (const Student& other) const {
        return score > other.score;  // 按分数降序
    }
};

vector<Student> students = {
    {"Alice", 85},
    {"Bob", 92},
    {"Charlie", 78}
};
sort(students.begin(), students.end());
```

---

**最后更新**: 2026年2月7日
