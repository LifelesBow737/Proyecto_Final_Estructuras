''' 
    Autor: Gustavo Richarte Pérez.
    Programa que BFS para grafos ponderados dirigidos (Recorrido en ANCHURA)
'''
from collections import deque
import os
graph = {
    'A': ['B','C'],
    'B': ['D','E','F'],
    'C':['G'],
    'D':[],
    'E':[],
    'F':['H'],
    'G':['I'],
    'H':[],
    'I':[],
}

def bfs(graph,node):
    visited = []
    queue = []

    visited.append(node)
    queue.append(node)

    while queue:
        s = queue.pop(0)
        print(s,end=" ")

        for n in graph[s]:
            if n not in visited:
                visited.append(n)
                queue.append(n)

if __name__=='__main__':
    print("\nUnidad 4, Programa de Recorrido en Anchura")
    bfs(graph, 'A')
    print("\n")
    os.system("pause")