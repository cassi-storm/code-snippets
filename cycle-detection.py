def dfs(graph, cr, vi, st):
    vi[cr] = st[cr] = True
    for i in graph.get(cr, []):
        if st[i]: return True
        if vi[i]: continue
        if dfs(graph, i, vi, st): return True 
    st[cr] = False
    return False

def hascycle(graph, n):
    vi = [False] * n
    st = [False] * n
    for i in range(n):
        if vi[i]: continue
        if dfs(graph, i, vi, st): return True
    return False

# graph is dictionary, may be disconnected
