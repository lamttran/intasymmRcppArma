#include <Rcpp.h>

using namespace Rcpp;

//[[Rcpp::export]]

NumericMatrix cumsum_col(NumericMatrix m) {
  NumericMatrix q = clone(m);
  for (int j = 0; j < m.ncol(); ++j) {
    for (int i = 1; i < m.nrow(); ++i) {
      q(i, j) += q(i - 1, j);
    }
  }
  return q;
}
