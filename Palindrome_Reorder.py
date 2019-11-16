s=input()
D={i:0 for i in s}
for c in s:
	D[c]+=1
p=[i for i in D if D[i]%2==1]
if(len(p)>1):
	print("NO SOLUTION")
elif p==[]:
	s=''.join(sorted(s))
	s=s[::2]
	v=s[::-1]
	print(s+v)
else:
	po=s.find(p[0])
	s=s[:po]+s[po+1:]
	s=''.join(sorted(s))
	s=s[::2]
	v=s[::-1]
	print(s+p[0]+v)
