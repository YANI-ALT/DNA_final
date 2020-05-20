#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <string>
using namespace std;

class graph// its for a directed graph
{
public:
  int in_deg[100];
  int out_deg[100];
  int A[100][100];
  int count;
  vector<string> vertices[100];
  vector<int> Adj[100];
  int N;

  graph(int n);


  void addEdge(int v,int u);


  void print_in_out_deg();

  bool s_e_vertexEuler(int* s,int* e);



};

#endif
