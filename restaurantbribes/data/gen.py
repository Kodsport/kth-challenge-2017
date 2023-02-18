#!/usr/bin/env python3

import math
import random
import itertools
import networkx as nx

def empty():
    return []

def clique(n):
    return nx.clique(n)

def randomG(n):
    return nx.gnm_random_graph(n,math.ceil(1*n*math.log(n)))

def randomT(n):
    G = nx.Graph()
    G.add_nodes_from(range(n))
    for i in range(1,n):
        j = random.randint(0,i-1)
        G.add_edge(i,j)
    return G

def star(n):
    return nx.star_graph(n-1)

def small_world(n):
    return nx.watts_strogatz_graph(n,10,.3)

def randomB(n,k):
    return list(zip(random.sample(range(n),k),[math.ceil(1000*random.random()**2) for _ in range(k)]))

N=20000
G = small_world(N)
B = []
B = [(0,50)]
B = [(0,50),(1,40)]
#B = [(i,1) for i in range(1,N)]
B = randomB(N,1000)
#B = [(0,1)]

print(N,G.size(),len(B))
for (a,b) in G.edges_iter():
    print(a+1,b+1)
for (a,b) in B:
    print(a+1,b)
