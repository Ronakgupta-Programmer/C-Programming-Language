#include <stdio.h>
#include <math.h>
#include <string.h>
#define M_PI 3.14159265358979323846

// Function to calculate Fibonacci sequence
void fibonacci(int n, int* fib_sequence) {
    fib_sequence[0] = 0;
    fib_sequence[1] = 1;
    for (int i = 2; i < n; i++) {
        fib_sequence[i] = fib_sequence[i-1] + fib_sequence[i-2];
    }
}
// Function to calculate factorial
int factorial(int n) {
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return -1;
    }
    if (n== 0 || n== 1) {
        return 1;
    }
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Basic arithmetic operations
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    if (b == 0) {
        printf("Cannot divide by zero.\n");
        return -1.0;
    }
    return (float)a / b;
}

int modulus(int a, int b) {
    return a % b;
}

float exponentiate(int base, int exp) {
    return pow(base, exp);
}

float square_root(int n) {
    if (n < 0) {
        printf("Square root is not defined for negative numbers.\n");
        return -1.0;
    }
    return sqrt(n);
}

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return abs(a * b) / gcd(a, b);
}

float logarithm(int base, int value) {
    if (base <= 0 || base == 1 || value <= 0) {
        printf("Logarithm is undefined for this input.\n");
        return -1.0;
    }
    return log(value) / log(base);
}

int is_power_of_two(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

float mean(float* numbers, int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return sum / size;
}

float geometric_mean(float* numbers, int size) {
    float product = 1.0;
    for (int i = 0; i < size; i++) {
        product *= numbers[i];
    }
    return pow(product, 1.0 / size);
}

float median(float* numbers, int size) {
    float sorted_numbers[size];
    memcpy(sorted_numbers, numbers, size * sizeof(float));
    qsort(sorted_numbers, size, sizeof(float), compare_floats);
    int mid = size / 2;
    if (size % 2 == 0) {
        return (sorted_numbers[mid - 1] + sorted_numbers[mid]) / 2.0;
    }
    return sorted_numbers[mid];
}

int compare_floats(const void* a, const void* b) {
    float fa = *(float*)a;
    float fb = *(float*)b;
    if (fa < fb) return -1;
    if (fa > fb) return 1;
    return 0;
}

float mode(float* numbers, int size) {
    int counts[size];
    memset(counts, 0, size * sizeof(int));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (numbers[i] == numbers[j]) {
                counts[i]++;
            }
        }
    }
    int max_count = 0;
    int max_index = 0;
    for (int i = 0; i < size; i++) {
        if (counts[i] > max_count) {
            max_count = counts[i];
            max_index = i;
        }
    }
    return numbers[max_index];
}

float variance(float* numbers, int size) {
    float avg = mean(numbers, size);
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += pow(numbers[i] - avg, 2);
    }
    return sum / size;
}

float standard_deviation(float* numbers, int size) {
    return sqrt(variance(numbers, size));
}

float compound_interest(float principal, float rate, float time, int frequency) {
    return principal * pow(1 + rate / frequency, frequency * time);
}

float area_rectangle(float length, float width) {
    return length * width;
}

float perimeter_rectangle(float length, float width) {
    return 2 * (length + width);
}

float area_circle(float radius) {
    return M_PI * radius * radius;
}

float perimeter_circle(float radius) {
    return 2 * M_PI * radius;
}

float area_triangle(float base, float height) {
    return 0.5 * base * height;
}

float area_trapezoid(float base1, float base2, float height) {
    return 0.5 * (base1 + base2) * height;
}

void matrix_addition(float* matrix_a, float* matrix_b, float* result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i * cols + j] = matrix_a[i * cols + j] + matrix_b[i * cols + j];
        }
    }
}

void matrix_multiplication(float* matrix_a, float* matrix_b, float* result, int rows_a, int cols_a, int cols_b) {
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            for (int k = 0; k < cols_a; k++) {
                result[i * cols_b + j] += matrix_a[i * cols_a + k] * matrix_b[k * cols_b + j];
            }
        }
    }
}

void quadratic_solver(float a, float b, float c, float* roots) {
    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        printf("No real roots.\n");
    } else if (discriminant == 0) {
        roots[0] = -b / (2 * a);
    } else {
        roots[0] = (-b + sqrt(discriminant)) / (2 * a);
        roots[1] = (-b - sqrt(discriminant)) / (2 * a);
    }
}

float pendulum_period(float length) {
    return 2 * M_PI * sqrt(length / 9.81);
}

int permutations(int n, int r) {
    return factorial(n) / factorial(n - r);
}

int combinations(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

float pythagorean_theorem(float a, float b) {
    return sqrt(a * a + b * b);
}

float surface_area_cylinder(float radius, float height) {
    return 2 * M_PI * radius * (radius + height);
}

float volume_cylinder(float radius, float height) {
    return M_PI * radius * radius * height;
}

int main() {
    int choice;
    printf("Choose an operation:\n");
    printf("1. Fibonacci\n");
    printf("2. Factorial\n");
    printf("3. Addition\n");
    printf("4. Subtraction\n");
    printf("5. Multiplication\n");
    printf("6. Division\n");
    printf("7. Modulus\n");
    printf("8. Exponentiation\n");
    printf("9. Square Root\n");
    printf("10. Check Prime\n");
    printf("11. GCD\n");
    printf("12. LCM\n");
    printf("13. Logarithm\n");
    printf("14. Check Power of Two\n");
    printf("15. Mean\n");
    printf("16. Geometric Mean\n");
    printf("17. Median\n");
    printf("18. Mode\n");
    printf("19. Variance\n");
    printf("20. Standard Deviation\n");
    printf("21. Compound Interest\n");
    printf("22. Area and Perimeter of Rectangle\n");
    printf("23. Area and Circumference of Circle\n");
    printf("24. Area of Triangle\n");
    printf("25. Area of Trapezoid\n");
    printf("26. Matrix Addition\n");
    printf("27. Matrix Multiplication\n");
    printf("28. Quadratic Equation Solver\n");
    printf("29. Pendulum Period\n");
    printf("30. Per mutations\n");
    printf("31. Combinations\n");
    printf("32. Pythagorean Theorem\n");
    printf("33. Surface Area and Volume of Cylinder\n");
    
    scanf("%d", &choice);
    
    if (choice == 1) {
        int n;
        printf("Enter the number of Fibonacci terms: ");
        scanf("%d", &n);
        int fib_sequence[n];
        fibonacci(n, fib_sequence);
        printf("Fibonacci sequence: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", fib_sequence[i]);
        }
        printf("\n");
    } else if (choice == 2) {
        int n;
        printf("Enter a number to compute factorial: ");
        scanf("%d", &n);
        int result = factorial(n);
        if (result != -1) {
            printf("Factorial of %d: %d\n", n, result);
        }
    } else if (choice == 3) {
        float a, b;
        printf("Enter first number: ");
        scanf("%f", &a);
        printf("Enter second number: ");
        scanf("%f", &b);
        printf("Sum: %f\n", add(a, b));
    } else if (choice == 4) {
        float a, b;
        printf("Enter first number: ");
        scanf("%f", &a);
        printf("Enter second number: ");
        scanf("%f", &b);
        printf("Difference: %f\n", subtract(a, b));
    } else if (choice == 5) {
        float a, b;
        printf("Enter first number: ");
        scanf("%f", &a);
        printf("Enter second number: ");
        scanf("%f", &b);
        printf("Product: %f\n", multiply(a, b));
    } else if (choice == 6) {
        float a, b;
        printf("Enter numerator: ");
        scanf("%f", &a);
        printf("Enter denominator: ");
        scanf("%f", &b);
        float result = divide(a, b);
        if (result != -1.0) {
            printf("Quotient: %f\n", result);
        }
    } else if (choice == 7) {
        float a, b;
        printf("Enter first number: ");
        scanf("%f", &a);
        printf("Enter second number: ");
        scanf("%f", &b);
        printf("%f %% %f = %d\n", a, b, modulus(a, b));
    } else if (choice == 8) {
        float base, exp;
        printf("Enter base: ");
        scanf("%f", &base);
        printf("Enter exponent: ");
        scanf("%f", &exp);
        printf("%f raised to the power of %f is: %f\n", base, exp, exponentiate(base, exp));
    } else if (choice == 9) {
        float n;
        printf("Enter a number to compute square root: ");
        scanf("%f", &n);
        float result = square_root(n);
        if (result != -1.0) {
            printf("Square root of %f is: %f\n", n, result);
        }
    } else if (choice == 10) {
        int n;
        printf("Enter a number to check if it is prime: ");
        scanf("%d", &n);
        if (is_prime(n)) {
            printf("%d is a prime number.\n", n);
        } else {
            printf("%d is not a prime number.\n", n);
        }
    } else if (choice == 11) {
        int a, b;
        printf("Enter first number: ");
        scanf("%d", &a);
        printf("Enter second number: ");
        scanf("%d", &b);
        printf("GCD of %d and %d is: %d\n", a, b, gcd(a, b));
    } else if (choice == 12) {
        int a, b;
        printf("Enter first number: ");
        scanf("%d", &a);
        printf("Enter second number: ");
        scanf("%d", &b);
        printf("LCM of %d and %d is: %d\n", a, b, lcm(a, b));
    } else if (choice == 13) {
        float base, value;
        printf("Enter base: ");
        scanf("%f", &base);
        printf("Enter value: ");
        scanf("%f", &value);
        float result = logarithm(base, value);
        if (result != -1.0) {
            printf("Logarithm of %f with base %f is: %f\n", value, base, result);
        }
    } else if (choice == 14) {
        int n;
        printf("Enter a number to check if it is a power of two: ");
        scanf("%d", &n);
        if (is_power_of_two(n)) {
            printf("%d is a power of two.\n", n);
        } else {
            printf("%d is not a power of two.\n", n);
        }
    } else if (choice == 15) {
        int size;
        printf("Enter the number of numbers: ");
        scanf("%d", &size);
        float numbers[size];
        printf("Enter numbers separated by spaces: ");
        for (int i = 0; i < size; i++) {
            scanf("%f", &numbers[i]);
        }
        printf("Mean: %f\n", mean(numbers, size));
    } else if (choice == 16) {
        int size;
        printf("Enter the number of numbers: ");
        scanf("%d", &size);
        float numbers[size];
        printf("Enter numbers separated by spaces: ");
        for (int i = 0; i < size; i++) {
            scanf("%f", &numbers[i]);
        }
        printf("Geometric Mean: %f\n", geometric_mean(numbers, size));
    } else if (choice == 17) {
        int size;
        printf("Enter the number of numbers: ");
        scanf("%d", &size);
        float numbers[size];
        printf("Enter numbers separated by spaces: ");
        for (int i = 0; i < size; i++) {
            scanf("%f", &numbers[i]);
        }
        printf("Median: %f\n", median(numbers, size));
    } else if (choice == 18) {
        int size;
        printf("Enter the number of numbers: ");
        scanf("%d", &size);
        float numbers[size];
        printf("Enter numbers separated by spaces: ");
        for (int i = 0; i < size; i++) {
            scanf("%f", &numbers[i]);
        }
        printf("Mode: %f\n", mode(numbers, size));
    } else if (choice == 19) {
        int size;
        printf("Enter the number of numbers: ");
        scanf("%d", &size);
        float numbers[size];
        printf("Enter numbers separated by spaces: ");
        for (int i = 0; i < size; i++) {
            scanf("%f", &numbers[i]);
        }
        printf("Variance: %f\n", variance(numbers, size));
    } else if (choice == 20) {
        int size;
        printf("Enter the number of numbers: ");
        scanf("%d", &size);
        float numbers[size];
        printf("Enter numbers separated by spaces: ");
        for (int i = 0; i < size; i++) {
            scanf("%f", &numbers[i]);
        }
        printf("Standard Deviation: %f\n", standard_deviation(numbers, size));
    } else if (choice == 21) {
        float principal, rate, time;
        int frequency;
        printf("Enter principal amount: ");
        scanf("%f", &principal);
        printf("Enter interest rate (in decimal): ");
        scanf("%f", &rate);
        printf("Enter time (in years): ");
        scanf("%f", &time);
        printf("Enter the number of times interest is compounded per year: ");
        scanf("%d", &frequency);
        printf("Compound interest is: %f\n", compound_interest(principal, rate, time, frequency));
    } else if (choice == 22) {
        float length, width;
        printf("Enter length of the rectangle: ");
        scanf("%f", &length);
        printf("Enter width of the rectangle: ");
        scanf("%f", &width);
        printf("Area: %f\n", area_rectangle(length, width));
        printf("Perimeter: %f\n", perimeter_rectangle(length, width));
    } else if (choice == 23) {
        float radius;
        printf("Enter radius of the circle: ");
        scanf("%f", &radius);
        printf("Area: %f\n", area_circle(radius));
        printf("Circumference: %f\n", perimeter_circle(radius));
    } else if (choice == 24) {
        float base, height;
        printf("Enter base of the triangle: ");
        scanf("%f", &base);
        printf("Enter height of the triangle: ");
        scanf("%f", &height);
        printf("Area: %f\n", area_triangle(base, height));
    } else if (choice == 25) {
        float base1, base2, height;
        printf("Enter base1 of the trapezoid: ");
        scanf("%f", &base1);
        printf("Enter base2 of the trapezoid: ");
        scanf("%f", &base2);
        printf("Enter height of the trapezoid: ");
        scanf("%f", &height);
        printf("Area: %f\n", area_trapezoid(base1, base2, height));
    } else if (choice == 26) {
        int rows;
        printf("Enter number of rows for the matrices: ");
        scanf("%d", &rows);
        float matrix_a[rows * rows];
        float matrix_b[rows * rows];
        float result[rows * rows];
        printf("Enter the first matrix:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < rows; j++) {
                scanf("%f", &matrix_a[i * rows + j]);
            }
        }
        printf("Enter the second matrix:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < rows; j++) {
                scanf("%f", &matrix_b[i * rows + j]);
            }
        }
        matrix_addition(matrix_a, matrix_b, result, rows, rows);
        printf("Result of addition:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < rows; j++) {
                printf("%f ", result[i * rows + j]);
            }
            printf("\n");
        }
    } else if (choice == 27) {
        int rows_a, cols_a, rows_b, cols_b;
        printf("Enter number of rows for first matrix: ");
        scanf("%d", &rows_a);
        printf("Enter number of columns for first matrix: ");
        scanf("%d", &cols_a);
        printf("Enter number of rows for second matrix: ");
        scanf("%d", &rows_b);
        printf("Enter number of columns for second matrix: ");
        scanf("%d", &cols_b);
        if (cols_a != rows_b) {
            printf("Matrix multiplication is not possible.\n");
        } else {
            float matrix_a[rows_a * cols_a];
            float matrix_b[rows_b * cols_b];
            float result[rows_a * cols_b];
            printf("Enter the first matrix:\n");
            for (int i = 0; i < rows_a; i++) {
                for (int j = 0; j < cols_a; j++) {
                    scanf("%f", &matrix_a[i * cols_a + j]);
                }
            }
            printf("Enter the second matrix:\n");
            for (int i = 0; i < rows_b; i++) {
                for (int j = 0; j < cols_b; j++) {
                    scanf("%f", &matrix_b[i * cols_b + j]);
                }
            }
            matrix_multiplication(matrix_a, matrix_b, result, rows_a, cols_a, cols_b);
            printf("Result of multiplication:\n");
            for (int i = 0; i < rows_a; i++) {
                for (int j = 0; j < cols_b; j++) {
                    printf("%f ", result[i * cols_b + j]);
                }
                printf("\n");
            }
        }
    } else if (choice == 28) {
        float a, b, c ;
        printf("Enter coefficient a: ");
        scanf("%f", &a);
        printf("Enter coefficient b: ");
        scanf("%f", &b);
        printf("Enter coefficient c: ");
        scanf("%f", &c);
        float roots[2];
        quadratic_solver(a, b, c, roots);
        printf("Roots: %f %f\n", roots[0], roots[1]);
    } else if (choice == 29) {
        float length;
        printf("Enter length of the pendulum (in meters): ");
        scanf("%f", &length);
        printf("Period of the pendulum: %f seconds\n", pendulum_period(length));
    } else if (choice == 30) {
        int n, r;
        printf("Enter total items (n): ");
        scanf("%d", &n);
        printf("Enter selected items (r): ");
        scanf("%d", &r);
        printf("Permutations: %d\n", permutations(n, r));
    } else if (choice == 31) {
        int n, r;
        printf("Enter total items (n): ");
        scanf("%d", &n);
        printf("Enter selected items (r): ");
        scanf("%d", &r);
        printf("Combinations: %d\n", combinations(n, r));
    } else if (choice == 32) {
        float a, b;
        printf("Enter length of side a: ");
        scanf("%f", &a);
        printf("Enter length of side b: ");
        scanf("%f", &b);
        printf("Hypotenuse: %f\n", pythagorean_theorem(a, b));
    } else if (choice == 33) {
        float radius, height;
        printf("Enter radius of the cylinder: ");
        scanf("%f", &radius);
        printf("Enter height of the cylinder: ");
        scanf("%f", &height);
        printf("Surface Area: %f\n", surface_area_cylinder(radius, height));
        printf("Volume: %f\n", volume_cylinder(radius, height));
    } else {
        printf("Invalid choice. Please select a number between 1 and 33.\n");
    }
    
    return 0;
}