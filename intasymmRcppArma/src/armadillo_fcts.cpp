// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>

using namespace Rcpp;

// [[Rcpp::export]]

arma::mat cumsum_colrev(NumericMatrix m) {
  arma::mat q = as<arma::mat>(m);
  for (int j = 0; j < m.ncol(); ++j) {
    for (int i = m.nrow() - 1; i > 0; --i) {
      q(i - 1, j) += q(i, j);
    }
  }
  return q;
}

// [[Rcpp::export]]

arma::mat cvpl(NumericMatrix theta, NumericMatrix censor) {
  arma::mat thetaf = as<arma::mat>(theta);
  arma::mat censorf = as<arma::mat>(censor);
  arma::mat revsumsf = cumsum_colrev(theta);
  arma::mat resultmat = censorf % log(thetaf/revsumsf);
  arma::rowvec cvplvec = sum(resultmat,0);
  return cvplvec;
}