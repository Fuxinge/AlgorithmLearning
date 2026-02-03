import sys

n = int(input())

arr = list(map(int,sys.stdin.readline().split()))

def quick_sort(arr,l,r):
    if l>=r:
        return
    i = l - 1
    j = r + 1
    x = arr[(l+r)//2]
    while i<j:
        while 1:
            i+=1
            if arr[i]>= x:
                break
        while 1:
            j-=1
            if arr[j]<=x:
                break
        if i<j:
            arr[i],arr[j] = arr[j],arr[i]
    quick_sort(arr,l,j)
    quick_sort(arr,j+1,r)
    
quick_sort(arr,0,n-1)

for i in arr:
    sys.stdout.write(str(i)+" ")
    