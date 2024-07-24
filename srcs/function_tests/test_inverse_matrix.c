#include "../../includes/tests.h"


bool compare_matrices(double **m1, double **m2, size_t size) 
{
    double epsilon;
    
    epsilon = 1e-6;
    for (size_t i = 0; i < size; ++i) 
    {
        for (size_t j = 0; j < size; ++j) 
        {
            if (fabs(m1[i][j] - m2[i][j]) >= epsilon) 
                return false;
        }
    }
    return (true);
}

void test_inverse_matrix() 
{
    bool        passed;
    double      **matrix;
    double      **inverse;
    double      **expected;

    passed = true;

    // Test Case 1
    matrix = create_matrix(1, 2, 3, 4,
                            5, 1, 3, 46,
                            4,  6, 8, 1,
                            4, 52, 3, 4);
    expected = create_matrix(-1.2964018, 0.1033131, 0.4488778, -0.00391877,
                            0.0577841111, -0.00619878, -0.02693266, 0.02023512,
                            0.592233701, -0.04873530, -0.07381546, -0.01332383,
                            0.10103313, 0.013822586, -0.043391521, 	0.0008550);
    inverse = invert_matrix(matrix);
    if (!compare_matrices(expected, inverse, 4)) 
        passed = false;
    matrix_free(matrix, 4);
    matrix_free(expected, 4);
    matrix_free(inverse, 4);

    // Test Case 2
    matrix = create_matrix(5, 6, 6, 8,
                        2, 2, 2, 8,
                        6, 6, 2, 8,
                        2, 3, 6, 7);
    expected = create_matrix(17, -9,	12,	16,
	                        17, 8.75, -11.75, -16,
                            -4,	-2.25, 2.75, 4,
                            1, 0.75, -0.75, -1);
    inverse = invert_matrix(matrix);
    if (!compare_matrices(expected, inverse, 4)) 
        passed = false;
    matrix_free(matrix, 4);
    matrix_free(expected, 4);
    matrix_free(inverse, 4);
    // Test Case 3
    
    matrix = create_matrix(5, 4, 1, 9,
                            7, 6, 1, 6,
                            4, 5, 7, 6,
                            6, 4, 6, 4);
    expected = create_matrix(0.058394160583941606, -0.018248175182481752, -0.29197080291970802918, 0.33394160583941605838,
                            -0.2627737226277372264, 0.3321167883211678834, 0.31386861313868613137, -0.37773722627737226276,
                            -0.01459854014598540143, -0.12043795620437956208, 0.072992700729927007303, 0.10401459854014598539,
                            0.1970802919708029197, -0.1240875912408759124, 0.014598540145985401459, -0.029197080291970802919);
    inverse = invert_matrix(matrix);
    if (!compare_matrices(expected, inverse, 4)) 
        passed = false;
    matrix_free(matrix, 4);
    matrix_free(expected, 4);
    matrix_free(inverse, 4);
    print_test_result("test_inverse_matrix", passed);
}
