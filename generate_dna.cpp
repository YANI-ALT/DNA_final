#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc,char * argv[])
{
  ofstream outputdna;
  outputdna.open("text/dna.txt");
  int length_dna=atoi(argv[1]);
  int r;
  for(int i=0;i<length_dna;i++)
  {
    r=rand()%5;
    if(r==1)
    {
      outputdna<<'A';

    }
    else if(r==2)
    {
      outputdna<<'G';
    }
    else if(r==3)
    {
      outputdna<<'T';
    }
    else if(r==4)
    {
      outputdna<<'C';
    }

  }


}
