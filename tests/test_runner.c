/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_runner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libft-test <test@libft.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 00:00:00 by libft-test       #+#    #+#             */
/*   Updated: 2025/09/22 00:00:00 by libft-test      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>
#include <unistd.h>

// Test result tracking (declared in test_main.c)
extern int tests_run;
extern int tests_passed;
extern int tests_failed;

// Color codes for output
#define COLOR_GREEN "\033[0;32m"
#define COLOR_RED "\033[0;31m"
#define COLOR_YELLOW "\033[0;33m"
#define COLOR_BLUE "\033[0;34m"
#define COLOR_RESET "\033[0m"

// Test macros
#define TEST_START(name) do { \
    printf(COLOR_BLUE "Testing %s..." COLOR_RESET "\n", name); \
} while (0)

#define TEST_ASSERT(condition, message) do { \
    tests_run++; \
    if (condition) { \
        tests_passed++; \
        printf(COLOR_GREEN "  ✓ %s" COLOR_RESET "\n", message); \
    } else { \
        tests_failed++; \
        printf(COLOR_RED "  ✗ %s" COLOR_RESET "\n", message); \
    } \
} while (0)

#define TEST_SUMMARY() do { \
    printf("\n" COLOR_YELLOW "=== TEST SUMMARY ===" COLOR_RESET "\n"); \
    printf("Total tests: %d\n", tests_run); \
    printf(COLOR_GREEN "Passed: %d" COLOR_RESET "\n", tests_passed); \
    if (tests_failed > 0) { \
        printf(COLOR_RED "Failed: %d" COLOR_RESET "\n", tests_failed); \
    } else { \
        printf("Failed: 0\n"); \
    } \
    printf("Success rate: %.1f%%\n", tests_run > 0 ? (float)tests_passed / tests_run * 100 : 0); \
} while (0)

// Function prototypes for test modules
void test_character_functions(void);
void test_memory_functions(void);
void test_string_functions(void);
void test_string_manipulation(void);
void test_conversion_functions(void);
void test_output_functions(void);
void test_list_functions(void);
void test_utility_functions(void);

int main(int argc, char **argv)
{
    printf(COLOR_YELLOW "=== LIBFT COMPREHENSIVE TEST SUITE ===" COLOR_RESET "\n\n");
    
    if (argc > 1) {
        // Run specific test categories
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "char") == 0) {
                test_character_functions();
            } else if (strcmp(argv[i], "memory") == 0) {
                test_memory_functions();
            } else if (strcmp(argv[i], "string") == 0) {
                test_string_functions();
            } else if (strcmp(argv[i], "manipulation") == 0) {
                test_string_manipulation();
            } else if (strcmp(argv[i], "conversion") == 0) {
                test_conversion_functions();
            } else if (strcmp(argv[i], "output") == 0) {
                test_output_functions();
            } else if (strcmp(argv[i], "list") == 0) {
                test_list_functions();
            } else if (strcmp(argv[i], "utility") == 0) {
                test_utility_functions();
            } else {
                printf("Unknown test category: %s\n", argv[i]);
                printf("Available categories: char, memory, string, manipulation, conversion, output, list, utility\n");
                return 1;
            }
        }
    } else {
        // Run all tests
        test_character_functions();
        test_memory_functions();
        test_string_functions();
        test_string_manipulation();
        test_conversion_functions();
        test_output_functions();
        test_list_functions();
        test_utility_functions();
    }
    
    TEST_SUMMARY();
    
    return (tests_failed == 0) ? 0 : 1;
}