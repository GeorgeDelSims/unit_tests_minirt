#ifndef TESTS_H
#define TESTS_H

#include "../../minirt/includes/minirt.h"

// ANSI escape codes for colored output
#define TERM_RED "\x1B[31m"
#define TERM_GREEN "\x1B[32m"
#define TERM_RESET "\x1B[0m"

// general testing functions 
void print_test_result(const char* test_name, bool passed);

// Tuple_arithmetic testing
bool    compare_tuples(t_tuple a, t_tuple b);
void    test_add_tuple();
void    test_subtr_tuple(); 
void    test_negate_tuple();
void    test_scale_tuple();
void    test_div_tuple();
void    test_magnitude();
void    test_normalise();
void    test_dot_prod();
void    test_cross_prod();

// matrix_ops testing
bool    test_matrix_equal();
bool    test_matrix_mul();
bool    test_matrix_transpose();
bool    test_scalar_div();
bool    test_scalar_mul();

// ray_transformation testing
void    test_matrix_point_mul(); 
void    test_matrix_vect_mul();

// inverse
void    test_inverse_matrix();
void 	test_determinant4x4();
void 	test_cofactor_matrix();

#endif
