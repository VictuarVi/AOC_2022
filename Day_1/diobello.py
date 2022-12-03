f=open("input.txt",'r')
r=f.readlines()
h=[[]]
pt1=[]
for n in range(len(r)):

    if r[n]=='\n':
        h.append([])
    else:
        r[n] = int(r[n][:-1])
        h[-1].append(r[n])
for elem in h:
    pt1.append(sum(elem))
print(max(pt1))
print(sum((list(reversed(sorted(pt1))))[:3]))