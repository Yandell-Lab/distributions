/// The Gaussian distribution 

#ifndef __dist__norm__hpp
#define __dist__norm__hpp 

#include <math.h>


using namespace std;

class normal {
  private:
      double mean, sd, x;
  public:
      void   setAttributes(double , double , double);
      double dnorm ();
};

#endif

