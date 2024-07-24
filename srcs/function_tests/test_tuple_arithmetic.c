#include "../../includes/tests.h"

// Helper function to compare tuples
bool compare_tuples(t_tuple a, t_tuple b) 
{
    double epsilon = 1e-6;
    return fabs(a.x - b.x) < epsilon && fabs(a.y - b.y) < epsilon &&
           fabs(a.z - b.z) < epsilon && fabs(a.type - b.type) < epsilon;
}


void test_add_tuple() 
{
    bool passed;
    t_tuple expected;
    t_tuple result;
    
    passed = true;
    
    expected = (t_tuple){5.0, -3.0, 9.0, 1.0};
    result = add_tuple(create_tuple(1.0, 2.0, 3.0, 1.0), create_tuple(4.0, -5.0, 6.0, 0.0));
    if (!compare_tuples(expected, result)) 
        passed = false;

    expected = (t_tuple){0.0, -1.0, -2.0, 0.0};
    result = add_tuple(create_tuple(-1.0, -2.0, -3.0, 0.0), create_tuple(1.0, 1.0, 1.0, 0.0));
    if (!compare_tuples(expected, result)) 
        passed = false;

    expected = (t_tuple){0.0, 0.0, 0.0, 1.0};
    result = add_tuple(create_tuple(2.0, 3.0, 4.0, 1.0), create_tuple(-2.0, -3.0, -4.0, 0.0));
    if (!compare_tuples(expected, result)) 
        passed = false;

    print_test_result("test_add_tuple", passed);
}

void test_subtr_tuple() 
{
    bool passed;
    t_tuple expected;
    t_tuple result;

    passed = true;

    expected = (t_tuple){-3.0, 7.0, -3.0, 1.0};
    result = subtr_tuple(create_tuple(1.0, 2.0, 3.0, 1.0), create_tuple(4.0, -5.0, 6.0, 0.0));
    if (!compare_tuples(expected, result)) 
        passed = false;

    expected = (t_tuple){-2.0, -3.0, -4.0, 0.0};
    result = subtr_tuple(create_tuple(-1.0, -2.0, -3.0, 0.0), create_tuple(1.0, 1.0, 1.0, 0.0));
    if (!compare_tuples(expected, result)) 
        passed = false;

    expected = (t_tuple){0.0, 0.0, 0.0, 0.0};
    result = subtr_tuple(create_tuple(2.0, 3.0, 4.0, 1.0), create_tuple(2.0, 3.0, 4.0, 1.0));
    if (!compare_tuples(expected, result)) 
        passed = false;

    print_test_result("test_subtr_tuple", passed);
}

void test_negate_tuple() 
{
    bool passed;
    t_tuple expected;
    t_tuple result;

    passed = true;

    expected = (t_tuple){-1.0, 2.0, -3.0, 0.0};
    result = negate_tuple(create_tuple(1.0, -2.0, 3.0, 0.0));
    if (!compare_tuples(expected, result)) 
        passed = false;

    expected = (t_tuple){4.0, -5.0, 6.0, 1.0};
    result = negate_tuple(create_tuple(-4.0, 5.0, -6.0, 1.0));
    if (!compare_tuples(expected, result)) 
        passed = false;

    expected = (t_tuple){-7.0, 8.0, -9.0, 0.0};
    result = negate_tuple(create_tuple(7.0, -8.0, 9.0, 0.0));
    if (!compare_tuples(expected, result)) 
        passed = false;

    print_test_result("test_negate_tuple", passed);
}

void test_scale_tuple() 
{
    bool passed;
    t_tuple expected;
    t_tuple result;

    passed = true;

    expected = (t_tuple){2.0, -4.0, 6.0, 0.0};
    result = scale_tuple(create_tuple(1.0, -2.0, 3.0, 0.0), 2.0);
    if (!compare_tuples(expected, result)) 
        passed = false;

    expected = (t_tuple){2.0, -2.5, 3.0, 1.0};
    result = scale_tuple(create_tuple(-4.0, 5.0, -6.0, 1.0), -0.5);
    if (!compare_tuples(expected, result)) 
        passed = false;

    expected = (t_tuple){0.7, -0.8, 0.9, 0.0};
    result = scale_tuple(create_tuple(7.0, -8.0, 9.0, 0.0), 0.1);
    if (!compare_tuples(expected, result)) 
        passed = false;

    print_test_result("test_scale_tuple", passed);
}

void test_div_tuple() 
{
    bool passed;
    t_tuple vector;
    double scalar;
    t_tuple expected;
    t_tuple result;

    passed = true;

    // Test Case 1
    vector = create_tuple(10.0, 20.0, 30.0, VECT);
    scalar = 2.0;
    expected = create_tuple(5.0, 10.0, 15.0, VECT);
    result = div_tuple(vector, scalar);
    if (!compare_tuples(expected, result)) 
        passed = false;

    // Test Case 2
    vector = create_tuple(-6.0, 8.0, -10.0, POINT);
    scalar = 2.0;
    expected = create_tuple(-3.0, 4.0, -5.0, POINT);
    result = div_tuple(vector, scalar);
    if (!compare_tuples(expected, result)) 
        passed = false;

    // Test Case 3
    vector = create_tuple(3.0, 6.0, 9.0, VECT);
    scalar = 3.0;
    expected = create_tuple(1.0, 2.0, 3.0, VECT);
    result = div_tuple(vector, scalar);
    if (!compare_tuples(expected, result)) 
        passed = false;

    print_test_result("test_div_tuple", passed);
}


void test_magnitude() 
{
    bool passed;
    t_tuple vector;
    double expected;
    double result;

    passed = true;

    // Test Case 1
    vector = create_tuple(3.0, 4.0, 0.0, VECT);
    expected = 5.0;
    result = magnitude(vector);
    if (fabs(expected - result) > 1e-6) 
        passed = false;

    // Test Case 2
    vector = create_tuple(1.0, 2.0, 2.0, VECT);
    expected = 3.0;
    result = magnitude(vector);
    if (fabs(expected - result) > 1e-6) 
        passed = false;

    // Test Case 3
    vector = create_tuple(0.0, 0.0, 0.0, VECT);
    expected = 0.0;
    result = magnitude(vector);
    if (fabs(expected - result) > 1e-6) 
        passed = false;

    print_test_result("test_magnitude", passed);
}

void test_normalise() 
{
    bool passed;
    t_tuple vector;
    t_tuple expected;
    t_tuple result;

    passed = true;

    // Test Case 1
    vector = create_tuple(4.0, 0.0, 0.0, VECT);
    expected = create_tuple(1.0, 0.0, 0.0, VECT);
    result = normalise(vector);
    if (!compare_tuples(expected, result)) 
        passed = false;

    // Test Case 2
    vector = create_tuple(1.0, 2.0, 3.0, VECT);
    expected = create_tuple(0.267261, 0.534522, 0.801784, VECT);
    result = normalise(vector);
    if (!compare_tuples(expected, result)) 
        passed = false;

    // Test Case 3
    vector = create_tuple(0.0, 0.0, 0.0, VECT);
    expected = create_tuple(0.0, 0.0, 0.0, VECT); // Normalizing a zero vector might be undefined behavior, this is a placeholder
    result = normalise(vector);
    if (!compare_tuples(expected, result)) 
        passed = false;

    print_test_result("test_normalise", passed);
}

void test_dot_prod() 
{
    bool passed;
    t_tuple v1, v2;
    double expected;
    double result;

    passed = true;

    // Test Case 1
    v1 = create_tuple(1.0, 2.0, 3.0, VECT);
    v2 = create_tuple(4.0, -5.0, 6.0, VECT);
    expected = 12.0; // (1*4 + 2*(-5) + 3*6)
    result = dot_prod(v1, v2);
    if (fabs(expected - result) > 1e-6) 
    {
        printf("case 1\n");    
        passed = false;
    }
    // Test Case 2
    v1 = create_tuple(1.0, 0.0, 0.0, VECT);
    v2 = create_tuple(0.0, 1.0, 0.0, VECT);
    expected = 0.0; // (1*0 + 0*1 + 0*0)
    result = dot_prod(v1, v2);
    if (fabs(expected - result) > 1e-6)
    {
        printf("case 2\n");    
        passed = false;
    }
    // Test Case 3
    v1 = create_tuple(2.0, 3.0, 4.0, VECT);
    v2 = create_tuple(2.0, 3.0, 4.0, VECT);
    expected = 29.0; // (2*2 + 3*3 + 4*4)
    result = dot_prod(v1, v2);
    if (fabs(expected - result) > 1e-6) 
    {
        printf("case 3\n");    
        passed = false;
    }
    // Test Case 4: Fractional values
    v1 = create_tuple(1.5, 2.5, -3.5, VECT);
    v2 = create_tuple(-2.0, 3.0, 0.5, VECT);
    expected = (1.5*(-2) + 2.5*3 + (-3.5)*0.5);
    result = dot_prod(v1, v2);
    if (fabs(expected - result) > 1e-6) 
    {
        printf("result : %f\n", result);
        printf("expected : %f\n", expected);
        printf("case 4\n");    
        passed = false;
    }
    // Test Case 5: Negative values
    v1 = create_tuple(-1.0, -2.0, -3.0, VECT);
    v2 = create_tuple(4.0, 5.0, 6.0, VECT);
    expected = -32.0; // (-1*4 + -2*5 + -3*6)
    result = dot_prod(v1, v2);
    if (fabs(expected - result) > 1e-6) 
    {
        printf("case 5\n");    
        passed = false;
    }
    // Test Case 6: Mixed values
    v1 = create_tuple(0.5, -1.5, 2.0, VECT);
    v2 = create_tuple(-1.0, 2.0, -2.5, VECT);
    expected = (0.5*(-1) + -1.5*2 + 2.0*(-2.5));
    result = dot_prod(v1, v2);
    if (fabs(expected - result) > 1e-6) 
    {
        printf("result : %f\n", result);
        printf("expected : %f\n", expected);
        printf("case 6\n");    
        passed = false;
    }
    print_test_result("test_dot_prod", passed);
}

void test_cross_prod()
{
    bool passed;
    t_tuple expected;
    t_tuple result;

    passed = true;

    // Test 1
    expected = create_tuple(-3.0, 6.0, -3.0, VECT);
    result = cross_prod(create_tuple(1.0, 2.0, 3.0, VECT), create_tuple(4.0, 5.0, 6.0, VECT));
    if (!compare_tuples(expected, result))
        passed = false;

    // Test 2
    expected = create_tuple(3.0, -6.0, 3.0, VECT);
    result = cross_prod(create_tuple(4.0, 5.0, 6.0, VECT), create_tuple(1.0, 2.0, 3.0, VECT));
    if (!compare_tuples(expected, result))
        passed = false;

    // Test 3
    expected = create_tuple(0.0, 0.0, 1.0, VECT);
    result = cross_prod(create_tuple(1.0, 0.0, 0.0, VECT), create_tuple(0.0, 1.0, 0.0, VECT));
    if (!compare_tuples(expected, result))
    {
        passed = false;
        printf("case 3\n");
    }

    print_test_result("test_cross_prod", passed);
}
