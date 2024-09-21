import heapq
from collections import deque

# Função auxiliar - registra os caminhos explorados no grafo
def atualizaCaminhos(caminhos, caminho):
    caminhos.append(caminho)

# Assim que o objetivo é encontrado, podemos imprimir o caminho explorado até ele
def imprimeCaminho(caminhos, objetivo):
    for lista in caminhos:
        if lista[-1] == objetivo:
            for i in range(len(lista) - 1):
                print(lista[i], "-->", end="")
            print(objetivo)
            break

# Implementação da Busca em Profundidade (DFS)
def dfs(grafo, inicio, objetivo):
    visitados = set()
    caminhos = []

    def dfs_recursivo(vertice, caminho):
        if vertice in visitados:
            return False
        visitados.add(vertice)
        caminho.append(vertice)
        if vertice == objetivo:
            atualizaCaminhos(caminhos, caminho)
            return True
        for vizinho, peso in grafo.get(vertice, []):
            if dfs_recursivo(vizinho, caminho.copy()):
                return True
        return False

    dfs_recursivo(inicio, [])
    imprimeCaminho(caminhos, objetivo)

# Implementação da Busca em Largura (BFS)
def bfs(grafo, inicio, objetivo):
    visitados = set()
    fila = deque([[inicio]])
    caminhos = []

    while fila:
        caminho = fila.popleft()
        vertice = caminho[-1]
        if vertice in visitados:
            continue
        visitados.add(vertice)
        if vertice == objetivo:
            atualizaCaminhos(caminhos, caminho)
            break
        for vizinho, peso in grafo.get(vertice, []):
            nova_caminho = list(caminho)
            nova_caminho.append(vizinho)
            fila.append(nova_caminho)

    imprimeCaminho(caminhos, objetivo)

# Implementação do Algoritmo de Custo Mínimo
def minimo_custo(grafo, inicio, objetivo):
    visitados = set()
    fila = [(0, inicio, [])]  # (custo, vertice, caminho)
    caminhos = []

    while fila:
        (custo, vertice, caminho) = heapq.heappop(fila)
        if vertice in visitados:
            continue
        visitados.add(vertice)
        caminho = caminho + [vertice]
        if vertice == objetivo:
            atualizaCaminhos(caminhos, caminho)
            break
        for vizinho, peso in grafo.get(vertice, []):
            if vizinho not in visitados:
                heapq.heappush(fila, (custo + peso, vizinho, caminho))

    imprimeCaminho(caminhos, objetivo)

# Implementação do Algoritmo A*
def a_star(grafo, inicio, objetivo, h):
    visitados = set()
    fila = [(0 + h(inicio), 0, inicio, [])]  # (f(n), g(n), vertice, caminho)
    caminhos = []

    while fila:
        (f, g, vertice, caminho) = heapq.heappop(fila)
        if vertice in visitados:
            continue
        visitados.add(vertice)
        caminho = caminho + [vertice]
        if vertice == objetivo:
            atualizaCaminhos(caminhos, caminho)
            break
        for vizinho, peso in grafo.get(vertice, []):
            if vizinho not in visitados:
                g_novo = g + peso
                f_novo = g_novo + h(vizinho)
                heapq.heappush(fila, (f_novo, g_novo, vizinho, caminho))

    imprimeCaminho(caminhos, objetivo)

# Exemplo de uso

# Exemplo de grafo
grafo = {
    'A': [('B', 2), ('C', 5)],
    'B': [('A', 2), ('D', 4), ('E', 1)],
    'C': [('A', 5), ('F', 3)],
    'D': [('B', 4), ('E', 1), ('G', 2)],
    'E': [('B', 1), ('D', 1), ('G', 3), ('H', 2)],
    'F': [('C', 3), ('H', 5)],
    'G': [('D', 2), ('E', 3), ('H', 1)],
    'H': [('E', 2), ('F', 5), ('G', 1)]
}

# Função heurística para A*
def h(n):
    heuristica = {
        'A': 7,
        'B': 6,
        'C': 5,
        'D': 4,
        'E': 3,
        'F': 4,
        'G': 2,
        'H': 0
    }
    return heuristica[n]

# Chamada dos algoritmos
inicio = 'A'
objetivo = 'F'

print("DFS:")
dfs(grafo, inicio, objetivo)
print()

print("BFS:")
bfs(grafo, inicio, objetivo)
print()

print("Custo Mínimo:")
minimo_custo(grafo, inicio, objetivo)
print()

print("A*:")
a_star(grafo, inicio, objetivo, h)
print()
