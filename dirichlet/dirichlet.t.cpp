#include "dirichlet.hpp"
#include <iostream>
#include <vector>

using namespace std;


int main (void){

 
  double txvs[3] = {0.127728904,0.22795519,0.6443159};
  double talp[3] = {1,2,3};


  vector<double> alphas;
  vector<double> xvals; 

  alphas.assign(talp, talp+3);
  xvals.assign(txvs, txvs+3);
  
  dirichlet dirichlet;

  cout << 't' << endl;
  
  double pdf = dirichlet.ddirichlet(xvals, alphas);
  
  cout << pdf << endl;
 
}
