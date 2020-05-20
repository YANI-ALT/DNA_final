#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <fstream>
#include"graph.h"
using namespace std;


void exhaust(graph *G,int p,stack<int>*S)
{
  //cout<<"____exhaust_____"<<endl;
  int u;
  //cout<<"G->in_deg["<<p<<"]: "<<G->in_deg[p]<<endl;
  //cout<<"G->out_deg["<<p<<"]: "<<G->out_deg[p]<<endl;
  u=p;
  while(G->in_deg[u]!=0&&G->out_deg[u])
  {
    cout<<u<<" ";
    for(int w:G->Adj[u])
    {
      if(G->A[u][w]!=0)
      {
        G->out_deg[u]--;
        G->A[u][w]--;
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
  ofstream out_deb;
  out_deb.open("../text/OUT_DEB2.txt",ios::app);
  out_deb<<s<<endl;
  out_deb.close();
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
  {
    cout<<" NOT POSSIBLE"<<endl;
    return;
  }
  //S=explore(G)

  stack<int>*S1=new stack<int>;


  cout<<" calling explore on start_v"<<start_v<<" and end_v "<<end_v<<endl;
  S=*explore(G,start_v,end_v,S1);
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
        exhaust(G,p,&S);
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
cout<<" ALL OK .. returning from euler"<<endl;
return;


}
map<string,int> vertices;
 map<int,string> rev_vert;

void create_debruijn(graph *G,long int n)
{
  cout<<"create_debruijn.cpp :: _____FUNCTION: create_debruijn_____"<<endl;
   //vector<string> vertex[100];
   //map<string,int> rev_vertex;

   string str;
   fstream infile("../text/Output_dna_segments2.txt");
   long int count=0;
   long int prev=0;
   string str1,str2;
   infile>>str;
   str1=str.substr(0,9);
   str2=str.substr(1,10);
   vertices[str1]=count;
   rev_vert[count]=str1;
   count++;
   if(vertices.find(str2)==vertices.end())//this string has not been previously seen so make a new vertex for it
   {
     vertices[str2]=count;//maps the string to the number of the vertex since graph is built on numbers
     rev_vert[count]=str2;
     count++;
   }
   G->addEdge(vertices[str1],vertices[str2]);


   //   //G->addEdge(prev,count);
   //   //prev=count;
   // }
   // else
   // {
   //   G->addEdge(prev,vertices[str]);
   //   //prev=vertices[str2];
   // }

   while(infile)
   {
     if(count==n-1)
     {
       cout<<"DONE WITH "<<n<<" elements  "<<endl;
       break;
     }
     infile>>str;
     if(str=="!")
     break;
     // if(str.size()!=10)
     // break;
     cout<<str<<endl;
     str1=str.substr(0,9);
     str2=str.substr(1,10);
     cout<<"str1:"<<str1<<endl;
     cout<<"str2:"<<str2<<endl;


     if(vertices.find(str1)==vertices.end())//this string has not been previously seen so make a new vertex for it
     {
       vertices[str1]=count;//maps the string to the number of the vertex since graph is built on numbers
       rev_vert[count]=str1;
       count++;
     }
     if(vertices.find(str2)==vertices.end())//this string has not been previously seen so make a new vertex for it
     {
       vertices[str2]=count;//maps the string to the number of the vertex since graph is built on numbers
       rev_vert[count]=str2;
       count++;
     }
     G->addEdge(vertices[str1],vertices[str2]);


  }
  cout<<"PRinting vertex array";
  for(int k=0;k<=count;k++)
    {

      cout<<rev_vert[k]<<" : "<<vertices[rev_vert[k]]<<endl;
    }
}

void call_euler(graph*G)
{
  cout<<"create_debruijn :: _____FUNCITON: call_euler___"<<endl;
  euler(G);
  return;
}

void convert_dna()
{
  fstream inp("../text/OUT_DEB2.txt");
  ofstream output_seq("../text/SEQU2.txt",ios::app);
  string str;
  long int count;
  long int t=0;
  while(inp>>str&&!(t>=80))
  {
    //inp>>str;
    //cout<<str;
    count=stoi(str);

    if(count==0)
    {
      output_seq<<rev_vert[count];
      cout<<rev_vert[count];

    }
    else
    {
      output_seq<<rev_vert[count].substr(8);
      cout<<rev_vert[count].substr(8);
    }
    t++;
  }
  output_seq.close();

}

int main()
{
  cout<<"create_debruijn.cpp:____________int main()_____________________"<<endl;
  cout<<"creating the debruijn......"<<endl;
  graph *G=new graph(90);
  create_debruijn(G,80);
  call_euler(G);
  convert_dna();



}
