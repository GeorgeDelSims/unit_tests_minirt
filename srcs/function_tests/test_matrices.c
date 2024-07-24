#include "../../includes/tests.h"

// Compare two matrices for equality
bool test_matrix_equal() 
{
    double **m1;
    double **m2;
    bool result;

    m1 = matrix_alloc(4);
    m2 = matrix_alloc(4);

    // Initialize matrices to be equal
    for (size_t i = 0; i < 4; i++) 
    {
        for (size_t j = 0; j < 4; j++) 
        {
            m1[i][j] = i + j;
            m2[i][j] = i + j;
        }
    }

    result = matrix_equal(m1, m2, 4);
    matrix_free(m1, 4);
    matrix_free(m2, 4);
    print_test_result("matrix_equal", result);
    return result;
}

// Test matrix multiplication with predefined test cases
bool test_matrix_mul() 
{
    double **m1;
    double **m2;
    double **result;
    double **expected;
    bool equal;

    // Test Case 1
    m1 = matrix_alloc(4);
    m2 = matrix_alloc(4);
    expected = matrix_alloc(4);
    
    // Initialize matrices for Test Case 1
    m1[0][0] = 1; m1[0][1] = 2; m1[0][2] = 3; m1[0][3] = 4;
    m1[1][0] = 5; m1[1][1] = 6; m1[1][2] = 7; m1[1][3] = 8;
    m1[2][0] = 9; m1[2][1] = 10; m1[2][2] = 11; m1[2][3] = 12;
    m1[3][0] = 13; m1[3][1] = 14; m1[3][2] = 15; m1[3][3] = 16;

    m2[0][0] = 1; m2[0][1] = 0; m2[0][2] = 0; m2[0][3] = 0;
    m2[1][0] = 0; m2[1][1] = 1; m2[1][2] = 0; m2[1][3] = 0;
    m2[2][0] = 0; m2[2][1] = 0; m2[2][2] = 1; m2[2][3] = 0;
    m2[3][0] = 0; m2[3][1] = 0; m2[3][2] = 0; m2[3][3] = 1;

    // Expected result for Test Case 1
    expected[0][0] = 1; expected[0][1] = 2; expected[0][2] = 3; expected[0][3] = 4;
    expected[1][0] = 5; expected[1][1] = 6; expected[1][2] = 7; expected[1][3] = 8;
    expected[2][0] = 9; expected[2][1] = 10; expected[2][2] = 11; expected[2][3] = 12;
    expected[3][0] = 13; expected[3][1] = 14; expected[3][2] = 15; expected[3][3] = 16;

    result = matrix_mul(m1, m2);
    equal = matrix_equal(result, expected, 4);
    print_test_result("matrix_mul", equal);
    matrix_free(m1, 4);
    matrix_free(m2, 4);
    matrix_free(result, 4);
    matrix_free(expected, 4);

    return (equal);
}

// Test matrix transpose
bool test_matrix_transpose() 
{
    double **matrix;
    double **transposed;
    double **expected;
    bool equal;

    matrix = matrix_alloc(4);
    expected = matrix_alloc(4);

    // Initialize matrix and expected transposed matrix
    for (size_t i = 0; i < 4; i++) 
    {
        for (size_t j = 0; j < 4; j++) 
        {
            matrix[i][j] = i + j;
            expected[j][i] = i + j;
        }
    }

    transposed = matrix_transpose(matrix);
    equal = matrix_equal(transposed, expected, 4);
    matrix_free(matrix, 4);
    matrix_free(transposed, 4);
    matrix_free(expected, 4);
    print_test_result("matrix_transpose", equal);
    return equal;
}


// Test scalar division
bool test_scalar_div() 
{
    double **matrix;
    double **divided;
    double **expected;
    double scalar;
    bool equal;

    matrix = matrix_alloc(4);
    expected = matrix_alloc(4);
    scalar = 2.0;

    // Initialize matrix and expected result
    for (size_t i = 0; i < 4; i++) 
    {
        for (size_t j = 0; j < 4; j++) 
        {
            matrix[i][j] = (i + j) * scalar;
            expected[i][j] = i + j;
        }
    }

    divided = scalar_div(matrix, scalar, 4);
    equal = matrix_equal(divided, expected, 4);
    matrix_free(matrix, 4);
    matrix_free(divided, 4);
    matrix_free(expected, 4);
    print_test_result("scalar_div", equal);
    return equal;
}

// Test scalar multiplication
bool test_scalar_mul() 
{
    double **matrix;
    double **multiplied;
    double **expected;
    double scalar;
    bool equal;

    matrix = matrix_alloc(4);
    expected = matrix_alloc(4);
    scalar = 2.0;

    // Initialize matrix and expected result
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            matrix[i][j] = i + j;
            expected[i][j] = (i + j) * scalar;
        }
    }

    multiplied = scalar_mul(matrix, scalar, 4);
    equal = matrix_equal(multiplied, expected, 4);
    matrix_free(matrix, 4);
    matrix_free(multiplied, 4);
    matrix_free(expected, 4);
    print_test_result("scalar_mul", equal);
    return equal;
}


