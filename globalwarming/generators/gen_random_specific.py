import sys
import random
random.seed(int(sys.argv[1]))

mn = 0
mx = 10**6
if 'binary' in sys.argv:
    mx = 1
if 'small' in sys.argv:
    mx = 40
if 'close' in sys.argv:
    mn = max(0, mx-10)

cnts = map(int,sys.stdin.read().strip().split())
es = []
n = 0
for c in cnts:
    here = []
    for i in range(c):
        for j in range(i+1,c):
            here.append((n+i+1, n+j+1, random.randint(mn,mx)))
    if 'unique' in sys.argv:
        found = set()
        for i in range(len(here)):
            a,b,_ = here[i]
            if a not in found and b not in found:
                found.add(a)
                found.add(b)
                here[i] = (a,b,mx-1)
            else:
                here[i] = (a,b,mx)

    random.shuffle(here)
    es += here
    n += c

for i in range(len(es)):
    if random.randint(0,1) == 1:
        es[i] = (es[i][1], es[i][0], es[i][2])

if 'ordered' not in sys.argv:
    random.shuffle(es)

sys.stdout.write('%d %d\n' % (n, len(es)))
for (a,b,c) in es:
    sys.stdout.write('%d %d %d\n' % (a,b,c))

