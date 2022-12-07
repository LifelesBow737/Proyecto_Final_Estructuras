
''' 
    Autor: Gustavo Richarte Pérez.
    Programa que DFS para grafos ponderados dirigidos (Recorrido en profundidad)
'''
import os
grafo = {
    'A': ['B','G'],
    'B': ['C','D','E'],
    'C':[],
    'D':[],
    'E':['F'],
    'F':[],
    'G':['H'],
    'H':['I'],
    'I':[],
}

def dfs(grafo,nodo):
    visitado = []
    stack = []

    visitado.append(nodo)
    stack.append(nodo)

    while stack:
        s = stack.pop(0)
        print(s, end=" ")

        for n in reversed(grafo[s]):
            if n not in visitado:
                visitado.append(n)
                stack.append(n)

def main():
    
    print("\nUnidad 4, Programa de Recorrido en Profundidad")
    dfs(grafo, 'A')
    print("\n")
    os.system("pause")
    

main()