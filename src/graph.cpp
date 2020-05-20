#include "graph.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

  graph:: graph(int n)
  {
    N=n;
    for(int i=0;i<N;i++)
    {
      in_deg[i]=0;
      out_deg[i]=0;
      for(int j=0;j<n;j++)
      {
        A[i][j]=0;
      }
    }

  }

  void graph:: addEdge(int v,int u)
  {
    //if(out_deg[count]==in_deg)
    Adj[v].push_back(u);
    A[v][u]++;
    out_deg[v]++;
    in_deg[u]++;
  }

  void graph:: print_in_out_deg()
  {
    for(int i=0;i<N;i++)
    {
      cout<<"in_deg["<<i<<"] :"<<in_deg[i]<<endl;
      cout<<"out_deg["<<i<<"] :"<<out_deg[i]<<endl;
    }
  }

  bool graph:: s_e_vertexEuler(int* s,int* e)
  {
    cout<<"_____s_e_vertexEuler()______"<<endl;
    int v1=-1;
    bool found_start=false;
    bool found_end=false;
    int v2=-1;
    /*for(int i=0;i<N;i++)
    {
      cout<<"in_deg["<<i<<"] :"<<in_deg[i]<<endl;
      cout<<"out_deg["<<i<<"] :"<<out_deg[i]<<endl;
    }*/
    for(int i=0;i<N;i++)
    {
      cout<<"in_deg["<<i<<"] :"<<in_deg[i]<<endl;
      cout<<"out_deg["<<i<<"] :"<<out_deg[i]<<endl;
      if(in_deg[i]!=out_deg[i])
      {
        if(in_deg[i]+1==out_deg[i])
        {
          if(found_end==true)
            return false;
          v2=i;
          cout<<v2<<endl;
          *s=i;
          found_end=true;
        }
        else if(in_deg[i]==out_deg[i]+1)
        {
          if(found_start==true)
            return false;
          v1=i;
          cout<<v1<<endl;
          *e=i;
          found_start=true;

        }
        else
        {
          return false;
        }
        //return false;

      }
      else
      {
        continue;
      }
    }

      if(v2==-1 && v1==-1)
      {
        v2=0;
        v1=1;
        return true;
      }

    return true;

  }
