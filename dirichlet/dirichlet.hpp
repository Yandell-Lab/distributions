/// The Dirichlete distribution

#ifndef __dist__dirichlet__hpp
#define __dist__dirichlet__hpp 

#include <math.h>
#include <vector>

using namespace std;

class dirichlet{
private:
  vector<double> xs;
  vector<double> alphas;
public:
  double ddirichlet(const vector<double> &, const vector<double> &);
};

#endif
