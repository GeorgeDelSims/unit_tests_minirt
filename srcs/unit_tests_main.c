#include "../includes/tests.h"

// Function to print a green PASSED or red FAILED
void print_test_result(const char* test_name, bool passed) 
{
    if (passed) 
        printf(TERM_GREEN "PASSED: %s\n" TERM_RESET, test_name);
    else 
        printf(TERM_RED "FAILED: %s\n" TERM_RESET, test_name);
}


int main() 
{
    // tuple_arithmetic
    printf("\ntuple_arithmetic.c\n");
    test_add_tuple();
    test_subtr_tuple();
    test_negate_tuple();
    test_scale_tuple();
    test_div_tuple();
    test_magnitude();
    test_normalise();
    test_dot_prod();
    test_cross_prod();

    // matrix_ops.c:
    printf("\nmatrix_ops.c\n");
    test_matrix_equal();
    test_matrix_mul();
    test_matrix_transpose();
    test_scalar_div();
    test_scalar_mul();
    
    // ray_transformations.c
    printf("\nray_transformations.c\n");
    test_matrix_point_mul();
    test_matrix_vect_mul();

    // invert.c
    printf("\ninvert_matrix\n");
    test_determinant4x4();
    test_cofactor_matrix();
    test_inverse_matrix();
    
    return (0);
}
