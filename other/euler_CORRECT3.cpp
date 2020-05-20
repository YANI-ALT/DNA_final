#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class graph// its for a directed graph
{
public:
  int in_deg[100];
  int out_deg[100];
  int A[100][100];
  int count=0;
  vector<string> vertices[100];
  vector<int> Adj[100];
  int N;

  graph(int n)
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

  void addEdge(int v,int u)
  {
    //if(out_deg[count]==in_deg)
    Adj[v].push_back(u);
    A[v][u]++;
    out_deg[v]++;
    in_deg[u]++;
  }

  void print_in_out_deg()
  {
    for(int i=0;i<N;i++)
    {
      cout<<"in_deg["<<i<<"] :"<<in_deg[i]<<endl;
      cout<<"out_deg["<<i<<"] :"<<out_deg[i]<<endl;
    }
  }

  bool s_e_vertexEuler(int* s,int* e)
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
      //cout<<"in_deg["<<i<<"] :"<<in_deg[i]<<endl;
      //cout<<"out_deg["<<i<<"] :"<<out_deg[i]<<endl;
      if(in_deg[i]!=out_deg[i])
      {
        if(in_deg[i]+1==out_deg[i])
        {
          if(found_end==true)
          return false;
          v2=i;
          *s=i;
          found_end=true;
        }
        else if(in_deg[i]==out_deg[i]+1)
        {
          if(found_start==true)
            return false;
          v1=i;
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


};
//void read_file_edges()
//{
  //make the srtings into vertices of the debruijn graph.
  //map the strings->int->strings
  //use the int for creating the graph and
  //then use the int to string mapping to process the output tour.


//}
/*void explore(graph *G,int s,int e)
{
  G->in_deg[s]--;
  if(s==e)
  {
    return path;

  }
  for(int w:G->Adj[s])
  {
    if(G->A[s][w]!=0)
    {
      G->out_deg[s]--;
      G->A[s][w]--;
      explore(G,w,e);
    }
  }

}*/
void exhaust(graph *G,int p,stack<int>*S)
{
  //cout<<"____exhaust_____"<<endl;
  int u;
  //cout<<"G->in_deg["<<p<<"]: "<<G->in_deg[p]<<endl;
  //cout<<"G->out_deg["<<p<<"]: "<<G->out_deg[p]<<endl;
  u=p;
  while(G->in_deg[u]!=0&&G->out_deg[u]!=0)
  {
    cout<<u<<" ";
    for(int w:G->Adj[u])
    {
      if(G->A[u][w]!=0)
      {
        G->out_deg[u]--;
        G->A[u][w]--;//multiple edges can exist between the same two vertices
        //if(e==s)
        //return S;
      }
      if(G->out_deg[w]!=0)
      {
        u=w;
        S->push(w);
      }
    }
  }
  cout<<p<<endl;

  return;
}


stack<int>* explore(graph *G,int s,int e,stack<int>*S)
{
 cout<<s<<" ";
 S->push(s);
 G->in_deg[s]--;
 if(s==e)
 {
   cout<<endl;
   cout<<" DONE ...returning from explore "<<endl;
   return S;

 }
 for(int w:G->Adj[s])
 {
   if(G->A[s][w]!=0)
   {
     G->out_deg[s]--;
     G->A[s][w]--;
     return explore(G,w,e,S);
     //if(e==s)
      //return S;
   }
 }
}
void euler(graph *G)
{
  cout<<"euler_CORRECT3.cpp :: _____FUNCTION: euler()______"<<endl;

  int start_v=0;
  int end_v=0;
  int*sv=&start_v;
  int*ev=&end_v;

  stack<int> S;

  if(!(G->s_e_vertexEuler(sv,ev)))
  /*checks if in the given graph it is possible fors  e
  uler path to exits return true or false and if true stores
  the begin and end vertex of the euler path in the variables*/
  {
    cout<<" NOT POSSIBLE"<<endl;
    return;
  }
  //S=explore(G)

  stack<int>*S1=new stack<int>;


  cout<<" calling explore on start_v"<<start_v<<" and end_v "<<end_v<<endl;
  S=*explore(G,start_v,end_v,S1);
  //this gives the path in the
  //form of a stack from the start vertex to the end vertex
  cout<<" Returned from explore ..."<<endl;
  //G->print_in_out_deg();
  int p;
  int p1;

  while(!S.empty())
  {
    p=S.top();
    S.pop();
    p1=p;
    if(G->in_deg[p]!=0&&G->out_deg[p]!=0)
      {
        exhaust(G,p,&S);//"exhaust" this function takes a point and then
        //recursively exhausts...actually it puts it on a stack ...and then
        //exhausts all the paths from this point back to itslef
      }

  }
  /*while(!S.empty())
  {
    p=S.top();
    S.pop();
    p1=p;
    cout<<" Exhausting vertex now :"<<p<<endl;
    while(G->in_deg[p1]!=0&&G->out_deg[p1]!=0)
    {
      cout<<p1<<"-> "<<endl;
      //cout<<"printing Adj["<<p1<<"]"<<endl;
      for(int w:G->Adj[p1])
      {
        //cout<<w<<" ";
      }
      G->print_in_out_deg();
      cout<<endl;
      for(int w:G->Adj[p1])
      {
        if(G->A[p1][w]!=0)
        {
          G->out_deg[p1]--;
          G->A[p1][w]--;
          p1=w;
          //S=*explore(G,p1,w,&S);
          //p1=w;
          //euler(G);
        }
      }

    }

  }*/
//G->print_in_out_deg();
for(int i=0;i<G->N;i++)
{

  if(i==start_v||i==end_v)
  continue;

  if(G->in_deg[i]!=0&& G->out_deg[i]!=0)
  {
    cout<<" FAILED....check"<<i<<endl;
    return;
  }
}
cout<<" ALL OK .. returning"<<endl;
return;


}

//int main()
//{
  /*cout<<"_____main______"<<endl;
  int n=12;
  graph *G=new graph(n);*/

  //adding edges HERE
  /*CASE 1
  G->addEdge(0,1);
  G->addEdge(1,2);
  G->addEdge(2,3);
  G->addEdge(3,4);
  G->addEdge(4,5);
  G->addEdge(5,6);
  G->addEdge(6,7);
  G->addEdge(7,8);
  G->addEdge(8,9);
  */

  //CASE 2
/*
  G->addEdge(0,1);
  G->addEdge(1,2);
  G->addEdge(2,3);
  G->addEdge(3,1);
  G->addEdge(1,4);
  G->addEdge(4,5);
  G->addEdge(5,6);
  G->addEdge(6,7);
  G->addEdge(7,8);
  G->addEdge(8,9);
*/

//CASE 3
  /*G->addEdge(0,1);
  G->addEdge(1,2);
  G->addEdge(2,3);
  G->addEdge(3,1);
  G->addEdge(1,4);
  G->addEdge(4,5);
  G->addEdge(5,6);
  G->addEdge(6,7);
  G->addEdge(7,5);
  G->addEdge(5,8);
  G->addEdge(8,9);
*/

//CASE 4
/*G->addEdge(0,1);
G->addEdge(1,2);
G->addEdge(2,3);
G->addEdge(2,3);
G->addEdge(2,3);
G->addEdge(3,4);
G->addEdge(3,4);
G->addEdge(3,4);
G->addEdge(4,10);
G->addEdge(4,10);
G->addEdge(10,11);
G->addEdge(10,11);
G->addEdge(11,2);
G->addEdge(11,2);
G->addEdge(4,5);
G->addEdge(5,6);
G->addEdge(6,7);

G->addEdge(7,8);
G->addEdge(8,9);
//G->addEdge(1,7);



  //calling euler;

  euler(G);
  cout<<" DONE EXECUTING CALL TO EULER"<<endl;


}*/
