#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void read_dna()
{
  cout<<"read_dna.cpp ::______FUNCTION: read_dna_____"<<endl;
  fstream inputdna("text/dna.txt");
  ofstream outputdna;
  outputdna.open("text/Output_dna_segments2.txt");
  string str,remaining="";
  long int n;
  bool flag=true;

  while(inputdna>>str)
  {
    //inputdna>>(str);
    //cout<<str<<endl;
    str=remaining+str;
    n=str.size();
    //flag=true;
    while(n>=10)
    {

      outputdna<<str.substr(0,10)<<endl;
      //outputdna<<str.substr(1,9)<<endl;

      //outputdna<<str.substr(1,9)<<endl;
      str=str.substr(1,9+n-10);
      //cout<<str<<" "<<endl;
      n=str.size();
      if(n<10)
      {
        remaining=str;
        break;
      }

    }


  }
  outputdna<<remaining<<endl;
  outputdna<<"!"<<endl;

//cout<<" CHECK FILES "<<endl;
inputdna.close();
outputdna.close();
}


int main()
{
  read_dna();
}
