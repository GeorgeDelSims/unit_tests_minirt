#include "../../includes/tests.h"

void test_matrix_point_mul() 
{
    bool passed;
    double **m;
    t_tuple p;
    t_tuple expected;
    t_tuple result;

    passed = true;

    // Test Case 1
    m = create_matrix(1, 2, 3, 4,
                      5, 6, 7, 8,
                      9, 10, 11, 12,
                      13, 14, 15, 16);
    p = create_tuple(1.0, 2.0, 3.0, POINT);
    expected = create_tuple(18.0, 46.0, 74.0, POINT);
    result = matrix_point_mul(m, p);
    if (!compare_tuples(expected, result)) 
        passed = false;
    matrix_free(m, 4);

    // Test Case 2
    m = create_matrix(2, 3, 4, 1,
                      0, 1, 2, 3,
                      1, 0, 1, 2,
                      4, 5, 6, 7);
    p = create_tuple(-1.0, 2.0, 0.0, POINT);
    expected = create_tuple(5, 5, 1, POINT);
    result = matrix_point_mul(m, p);
    if (!compare_tuples(expected, result)) 
        passed = false;
    matrix_free(m, 4);

    // Test Case 3
    m = create_matrix(0.5, 1.5, 2.5, 3.5,
                      -1.5, -2.5, -3.5, -4.5,
                      4.5, 5.5, 6.5, 7.5,
                      -5.5, -6.5, -7.5, -8.5);
    p = create_tuple(1.0, -1.0, 1.0, POINT);
    expected = create_tuple(5, -7, 13, POINT);
    result = matrix_point_mul(m, p);
    if (!compare_tuples(expected, result)) 
        passed = false;
    matrix_free(m, 4);

    print_test_result("test_matrix_point_mul", passed);
}

void test_matrix_vect_mul() 
{
    bool passed;
    double **m;
    t_tuple v;
    t_tuple expected;
    t_tuple result;

    passed = true;

    // Test Case 1
    m = create_matrix(1, 2, 3, 4,
                      5, 6, 7, 8,
                      9, 10, 11, 12,
                      13, 14, 15, 16);
    v = create_tuple(1.0, 2.0, 3.0, VECT);
    expected = create_tuple(14.0, 38.0, 62.0, VECT);
    result = matrix_vect_mul(m, v);
    if (!compare_tuples(expected, result)) 
        passed = false;
    matrix_free(m, 4);

    // Test Case 2
    m = create_matrix(2, 3, 4, 1,
                      0, 1, 2, 3,
                      1, 0, 1, 2,
                      4, 5, 6, 7);
    v = create_tuple(-1.0, 2.0, 0.0, VECT);
    expected = create_tuple(4.0, 2.0, -1.0, VECT);
    result = matrix_vect_mul(m, v);
    if (!compare_tuples(expected, result)) 
        passed = false;
    matrix_free(m, 4);

    // Test Case 3
    m = create_matrix(0.5, 1.5, 2.5, 3.5,
                      -1.5, -2.5, -3.5, -4.5,
                      4.5, 5.5, 6.5, 7.5,
                      -5.5, -6.5, -7.5, -8.5);
    v = create_tuple(1.0, -1.0, 1.0, VECT);
    expected = create_tuple(1.5, -2.5, 5.5, VECT);
    result = matrix_vect_mul(m, v);
    if (!compare_tuples(expected, result)) 
        passed = false;
    matrix_free(m, 4);

    print_test_result("test_matrix_vect_mul", passed);
}
