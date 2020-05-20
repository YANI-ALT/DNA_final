#BFS
N=10000000000
V=[s,a,b,c,d,f]
count=dict();
dist=dict();
adj=dict();

adj[s]=[a,b]
adj[a]=[c]
adj[b]=[c,d]
adj[d]=[f]
adj[c]=[]
adj[f]=[]


for v in V:
    dist[v]=N;
    count[v]=0;

Q=[s];

while len(Q) not =0:
    u=Q.pop[0]
    for v in adj(u):
        if(dist[v]==N):
            Q.append(v)
            dist[v]=dist[u]+1
            count[v]=count[u]
        elif(dist[v]==dist[u]+1):
            count[v]++
