
''' 
    Programa que DFS para grafos ponderados dirigidos (Recorrido en profundidad)
'''
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
    dfs(grafo, 'A')

main()