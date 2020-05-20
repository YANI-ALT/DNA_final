#!/bin/bash
file1=SEQU2.txt
file2=Output_dna_segments2.txt
file3=OUT_DEB2.txt
make clean
cd text
if [[ -f $file1 ]]; then
  rm SEQU2.txt
fi

if [[ -f $file2 ]]; then
  rm Output_dna_segments2.txt
fi
if [[ -f $file3 ]]; then
  rm OUT_DEB2.txt
fi
echo \n
echo `ls`
cd ..
g++ read_dna2.cpp
./a.out
make
cd bin
./exec
cd ..
g++ check_strand.cpp
./a.out

echo "Done"
