#!/usr/bin/env python3

from random import randint

def mkcase(k,bounds):
    with open("secret/{}-random.in".format(k),"w") as f:
        i,j=(1,1)
        while(i*j%2==1):
            i,j=randint(*bounds),randint(*bounds)
        print(i,j,file=f)
    

for k in range(10,25):
    mkcase(k,(2,10))

#for k in range(25,40):
#    mkcase(k,(9950,10000))
