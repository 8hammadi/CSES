c=0
n=int(input())
while n>0:
    n-=max([int(i) for i in str(n)])
    c+=1
print(c)
