import sys

# 从标准输入中读取一行字符串
sentence = sys.stdin.read().strip()

# 分割字符串为单词列表
words = sentence.split()


# 将每个单词的首字母大写并输出
for word in words:
    print(word.title())