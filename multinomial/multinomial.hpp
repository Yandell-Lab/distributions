/// The Dirichlete distribution

#ifndef __dist__multinomial__hpp
#define __dist__multinomial__hpp 

#include <math.h>
#include <vector>

using namespace std;

class multinomial{
private:
  vector<double> xs;
  vector<double> ps;
public:
  double dmultinomial(const vector<double> &, const vector<double> &);
};

#endif
