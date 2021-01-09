#ifndef PGM_RANDOM_H
#define PGM_RANDOM_H

#include <numpy/random/bitgen.h>


typedef enum {GAMMA, DEVROYE, ALTERNATE, SADDLE, HYBRID} sampler_t;

/*
 * generate a sample from a Polya-Gamma distribution PG(h, zh
 *
 * Samples are draw from a Polya-Gamma distribution with specified para-
 *  meters `h` and `z`.

 *  Parameters
 *  ----------
 *  h : double 
 *      The `h` parameter as described in [1]. The value(s) must be
 *      positive.
 *  z : double
 *      The exponential tilting parameter as described in [1].
 *  method : sampler_t
 *      The type of method to use when sampling. Must be one of {GAMMA,
 *      DEVROYE, ALTERNATE, HYBRID}. The HYBRID sampler automatically chooses
 *      the appropriate method using the parameter values.
 *
 *  References
 *  ----------
 * [1] Polson, Nicholas G., James G. Scott, and Jesse Windle.
 *     "Bayesian inference for logistic models using Pólya–Gamma latent
 *     variables." Journal of the American statistical Association
 *     108.504 (2013): 1339-1349.
 * [2] Windle, Jesse, Nicholas G. Polson, and James G. Scott.
 *     "Sampling Polya-Gamma random variates: alternate and approximate
 *     techniques." arXiv preprint arXiv:1405.0506 (2014)
 *
 */
double pgm_random_polyagamma(bitgen_t* bitgen_state, double h, double z,
                             sampler_t method);
/*
 * Generate n samples from a PG(h, z) distribution.
 *
 * Parameters
 * ----------
 *  n : size_t
 *      The number of samples to generate.
 *  out: array of type double
 *      The array to place the generated samples. Only the first n elements
 *      will be populated.
 */
void pgm_random_polyagamma_fill(bitgen_t* bitgen_state, double h, double z,
                                sampler_t method, size_t n, double* out);
#endif
