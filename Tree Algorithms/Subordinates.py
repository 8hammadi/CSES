n=int(input())
l=list(map(int,input().split()))
c=list(n*[0])
for i in range(n-2,-1,-1):
    c[l[i]-1]+=c[i+1]+1
for i in c:
    print(i,end=" ")
