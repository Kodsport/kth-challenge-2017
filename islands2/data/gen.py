#!/usr/bin/env python3

from random import randint
import math

def one_and_cluster(N):
    print(N,N-1,1000)
    print(0,1000000,100)
    for i in range(1,N):
        print(i*1000,0,300)
    for i in range(1,N):
        print(i*1000,0,100)

def two_clusters(N,M):
    print(N+M,N+M,1000)
    for i in range(N):
        print(i*1000,0,300)
    for i in range(M):
        print(i*1000,1000000,300)
    for i in range(N):
        print(i*1000,0,100)
    for i in range(M):
        print(i*1000,1000000,100)

def random_grid(N,M):
    print(N*M,N*M,10)
    for i in range(N):
        for j in range(M):
            print(i*1000,j*1000,300)
    for i in range(N):
        for j in range(M):
            print(i*1000,j*1000,19+50*randint(1,199))

def directed_path(N):
    print(N,N,1)
    for i in range(N):
        print(i*250-1000000,0,100)
    for i in range(N):
        print(i*250+99-1000000,0,52)

def undirected_path(N):
    print(N,2*N,1)
    for i in range(N):
        print(i*250-900000,0,100)
    for i in range(N):
        print(i*250+99-900000,0,52)
        print(i*250-99-900000,0,52)

def mixed_path(N):
    print(N,N+N//2,1)
    for i in range(N):
        print(i*250-900000,0,100)
    for i in range(N):
        print(i*250+99-900000,0,52)
    for i in range(N//2):
        print(i*250-99-900000,0,52)
        
def clique(N,M,possible):
    print(N*M+(1 if possible else 2),N*M,1000)
    print(-1000000,-1000000,200)
    if (not possible):
        print(-999700,-999700,200)        
    for i in range(N):
        for j in range(M):
            print(i*1000,j*1000,300)
    for i in range(N):
        for j in range(M):
            print(i*1000,j*1000,1000)

def cycle(N):
    R = 1000*N/(2*math.pi)
    print(N,N,1)
    for i in range(N):
        print(int(R*math.cos(i*2*math.pi/N)),
              int(R*math.sin(i*2*math.pi/N)),
              400)
    for i in range(N):
        print(int(R*math.cos((i+.3)*2*math.pi/N)),
              int(R*math.sin((i+.3)*2*math.pi/N)),
              400)

#one_and_cluster(1000)
#two_clusters(500,500)
#two_clusters(50,950)
#two_clusters(950,50)
#random_grid(32,31)
#directed_path(5000)
#undirected_path(5000)
#mixed_path(5000)
#clique(71,70,True)
#clique(71,70,False)
#cycle(5000)
