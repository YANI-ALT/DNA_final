#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{

  ifstream inp1("text/dna.txt");
  ifstream inp2("text/SEQU2.txt");
  bool flag=true;
  char c1,c2;
  while(true)
  {
    inp1>>c1;
    //cout<<c1<<endl;
    inp2>>c2;
    //cout<<c2<<endl;
    if(inp1.eof() && inp2.eof())
    {
      // cout<<"(!inp1.eof() and !inp2.eof()) :"<<(!inp1.eof() and !inp2.eof())<<endl;
      flag=true;
      break;
    }
    else if( inp1.eof())
    {
        // cout<<"!inp1.eof() :"<<!inp1.eof()<<endl;
        flag=false;
        break;
    }
    else if(inp2.eof())
    {
      // cout<<"!inp2.eof() :"<<!inp1.eof()<<endl;
      flag=false;
      break;
    }
    if(c1!=c2)
    {
      flag=false;
      break;
    }

  }
  if(flag)
  {
    cout<<"\nTRUE"<<endl;
  }
  else
  {
    cout<<"\nFALSE"<<endl;
  }


}
