#include "dirichlet.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

double dirichlet::ddirichlet(const vector<double> & xvals, const vector<double> & alphas){

  int lxval = xvals.size();
  int lalph = alphas.size();
 
  try{
    if(lxval != lalph){
      throw 1;
    }
  }
  catch(int e){
    cerr << "ERROR: xvals and alphas need to be the same length ; error num: " << e << endl;
    exit(1);
  }
  
  try{
    if(lxval < 2){
      throw 1;
    }
  }
  catch(int e){
    cerr << "ERROR: there must be more than two values in alpha and xvals; error num: " << e << endl;
    exit(1);  
  }
  
  for(int i = 0; i < lxval; i++){
    try{
      if(xvals[i] == 0.0 || xvals[i] == 1.0){
	throw 1;
      }
    }
    catch(int e){
      cerr << "ERROR: xvals must be on intervals [0,1] ; error num: " << e << endl;
      exit(1);
    }
    try{
      if(alphas[i] == 0.0){
	throw 1;
      }
    }
      catch(int e){
	cerr << "ERROR: alpha must be greater than 0.0 ; error num: " << e << endl;
	exit(1);
      }
  }


  /// right product of the dirichlete pdf

  double prodr = pow(xvals[0], (alphas[0] - 1.0));

 /// sum of the alphas for the bottom of the B normalization function
  
  double alpha_sum = alphas[0];

  /// product of the top B normalization function

  double gamma_prod = tgamma(alphas[0]); 

 
  for(int j = 1; j < lxval; j++){

    gamma_prod *= tgamma(alphas[j]);

    alpha_sum  += alphas[j];

    prodr      *= pow(xvals[j], (alphas[j] - 1));
  }

  /// Normalization constant

  double B = gamma_prod / tgamma(alpha_sum);

  double pdf = (1.0/B) * prodr;

  return pdf;

}
