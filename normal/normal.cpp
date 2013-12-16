/// methods for the Gaussian distribution 

#include "normal.hpp"
#include <iostream>
#include <cstdlib>

#define PI 3.14159265359
#define EU 2.71828182846

void normal::setAttributes(double umean, double usd, double ux){
  try{
    x    = ux;
    mean = umean;
    sd   = usd;
  }
  catch(int e){
    std::cerr << "ERROR: failed to set the mean or sd; error num: " << e << std::endl; 
  }
  try{
    if(sd == 0.0){
      throw 1;
    }
  }
  catch(int e){
    std::cerr << "ERROR: the standard deviation cannot be equal to 0.0; error num: " << e << std::endl;
    exit(1);
  }
}

double normal::dnorm(void){

  try{
    /// double first term
        double fet    = 1.0 / (sd * sqrt(2.0*PI));
    
	// std::cerr << "fet " << fet << endl;

    /// double e power top
        double tet    = pow((x - mean), 2);

	//    std::cerr << "tet " << tet << endl;

    /// double e power bottom
        double bet    = 2.0 * pow(sd, 2);
	
	//    std::cerr << "bet " << bet << endl;

    /// double second term
    double sec    = 1.0 / pow(EU, (tet/bet));

    //    std::cerr << "sec " << sec << endl;

    /// double pdf
    double pdf    = fet * sec;
  }
  catch(int e){
    std::cerr << "ERROR: failed to calculate pdf; error num: " << e << std::endl; 
  }
}
