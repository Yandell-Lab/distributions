#include "multinomial.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

double multinomial::dmultinomial(const vector<double> & xvals, const vector<double> & ps){

  int lxval = xvals.size();
  int lalph = ps.size();
 
  try{
    if(lxval != lalph){
      throw 1;
    }
  }
  catch(int e){
    cerr << "ERROR: xvals and prob need to be the same length ; error num: " << e << endl;
    exit(1);
  }  
  try{
    if(lxval ==1){
      throw 1;
    }
  }
  catch(int e){
    cerr << "ERROR: there must be more than one value in probability and xvals; error num: " << e << endl;
    exit(1);  
  }
  
  double psum = 0;
  
 for(int i = 0; i < lxval; i++){
   psum += ps[i];
    try{
      if(xvals[i] == 0.0){
	throw 1;
      }
    }
    catch(int e){
      cerr << "ERROR: xvals must be greater than zero ; error num: " << e << endl;
      exit(1);
    }
    try{
      if(ps[i] == 0.0){
	throw 1;
      }
    }
    catch(int e){
      cerr << "ERROR: probability must be greater than 0.0 ; error num: " << e << endl;
      exit(1);
    }
 }

 try{
   if((1.0 - psum) > 0.000000000001){
     throw 1;
   }
 }
 catch(int e){
   cerr << "ERROR: probabilities must sum to one; error num: " << e << endl;
   cerr << "ERROR: probabilities sum to: " << psum << endl;
   exit(1);
 }
 

  /// sum of the total X

  double nsum = xvals[0];

  /// bottom of the normalization terms

  double bnt = tgamma(xvals[0] + 1);

 /// sum of the second term

  double sec  = pow(ps[0], xvals[0]);
  
  for(int j = 1; j < lxval; j++){

    nsum += xvals[j];

    sec  *= pow(ps[j], xvals[j]);

    bnt  *= tgamma(xvals[j] +1);

  }

  /// Normalization constant

  double B = tgamma(nsum + 1) / bnt;

  double pdf = B * sec;

  return pdf;

}
