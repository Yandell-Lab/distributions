#include "lib/normal.hpp"
#include <iostream>

using namespace std;

int main (void){

  normal norm;
  
  double mean = 10.0;
  double sd   = 2.0;
  double x    = 3.1;

  norm.setAttributes(mean, sd, x);
  
  cout << "INFO: mean: " << mean << endl;
  cout << "INFO: sd: " << sd << endl;
  cout << "INFO: x: " << x << endl;

  
  double d =  norm.dnorm();

  cout << "INFO: pdf: " << d << endl;

  if((0.000519141 - d) < 1e-6){
    cout << "INFO: pdf == testcase, pass! " << d << " == " << 0.0997441 << endl;
    return 0;
  }
  else{
    cout << "ERROR: pdf != testcase, fail! " << d << " != " << 0.0997441 << endl;
    return 1;
  }


}
  
