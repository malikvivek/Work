//============================================================================
// Name        : Exception_example_compiler.cpp
// Author      : Vivek
// Version     :
// Copyright   : Copyright Vivek Malik, 2011
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main () {
  try
  {
    throw 20;
  }
  catch (int e)
  {
    cout << "An exception occurred. Exception Nr. " << e << '\n';
  }
  return 0;
}
