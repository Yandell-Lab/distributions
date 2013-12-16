#include "multinomial.hpp"
#include <iostream>
#include <vector>

using namespace std;


int main (void){
 
  double talp[3] = {0.2,0.2,0.6};
  double txvs[3] = {1,2,3};

  vector<double> alphas;
  vector<double> xvals; 

  alphas.assign(talp, talp+3);
  xvals.assign(txvs, txvs+3);
  
  multinomial mult;

  cout << 't' << endl;
  
  double pdf = mult.dmultinomial(xvals, alphas);
  
  cout << pdf << endl;
 
}
