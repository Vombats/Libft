/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libft-test <test@libft.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 00:00:00 by libft-test       #+#    #+#             */
/*   Updated: 2025/09/22 00:00:00 by libft-test      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

// External test macros
extern int tests_run, tests_passed, tests_failed;
#define COLOR_GREEN "\033[0;32m"
#define COLOR_RED "\033[0;31m"
#define COLOR_BLUE "\033[0;34m"
#define COLOR_RESET "\033[0m"

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

void test_conversion_functions(void)
{
    TEST_START("Conversion Functions");
    
    char *result;
    
    // Test ft_atoi
    TEST_ASSERT(ft_atoi("42") == 42, "ft_atoi should convert positive number");
    TEST_ASSERT(ft_atoi("-42") == -42, "ft_atoi should convert negative number");
    TEST_ASSERT(ft_atoi("0") == 0, "ft_atoi should convert zero");
    TEST_ASSERT(ft_atoi("   42") == 42, "ft_atoi should skip leading whitespace");
    TEST_ASSERT(ft_atoi("42abc") == 42, "ft_atoi should stop at non-digit");
    TEST_ASSERT(ft_atoi("   +42") == 42, "ft_atoi should handle explicit positive sign");
    TEST_ASSERT(ft_atoi("   -42") == -42, "ft_atoi should handle negative sign after spaces");
    TEST_ASSERT(ft_atoi("2147483647") == 2147483647, "ft_atoi should handle INT_MAX");
    TEST_ASSERT(ft_atoi("-2147483648") == -2147483648, "ft_atoi should handle INT_MIN");
    TEST_ASSERT(ft_atoi("") == 0, "ft_atoi should return 0 for empty string");
    TEST_ASSERT(ft_atoi("abc") == 0, "ft_atoi should return 0 for non-numeric string");
    
    // Test ft_atoi_base
    TEST_ASSERT(ft_atoi_base("42", "0123456789") == 42, "ft_atoi_base decimal");
    TEST_ASSERT(ft_atoi_base("101", "01") == 5, "ft_atoi_base binary");
    TEST_ASSERT(ft_atoi_base("ff", "0123456789abcdef") == 255, "ft_atoi_base hexadecimal lowercase");
    TEST_ASSERT(ft_atoi_base("FF", "0123456789ABCDEF") == 255, "ft_atoi_base hexadecimal uppercase");
    TEST_ASSERT(ft_atoi_base("777", "01234567") == 511, "ft_atoi_base octal");
    TEST_ASSERT(ft_atoi_base("zz", "0123456789abcdefghijklmnopqrstuvwxyz") == 1295, "ft_atoi_base base36");
    TEST_ASSERT(ft_atoi_base("", "01") == 0, "ft_atoi_base empty string");
    TEST_ASSERT(ft_atoi_base("123", "") == 0, "ft_atoi_base empty base");
    TEST_ASSERT(ft_atoi_base("123", "01+") == 0, "ft_atoi_base invalid base with +");
    TEST_ASSERT(ft_atoi_base("123", "01-") == 0, "ft_atoi_base invalid base with -");
    TEST_ASSERT(ft_atoi_base("123", "001") == 0, "ft_atoi_base invalid base with duplicates");
    
    // Test ft_itoa
    result = ft_itoa(42);
    TEST_ASSERT(result != NULL && strcmp(result, "42") == 0, "ft_itoa positive number");
    free(result);
    
    result = ft_itoa(-42);
    TEST_ASSERT(result != NULL && strcmp(result, "-42") == 0, "ft_itoa negative number");
    free(result);
    
    result = ft_itoa(0);
    TEST_ASSERT(result != NULL && strcmp(result, "0") == 0, "ft_itoa zero");
    free(result);
    
    result = ft_itoa(2147483647);
    TEST_ASSERT(result != NULL && strcmp(result, "2147483647") == 0, "ft_itoa INT_MAX");
    free(result);
    
    result = ft_itoa(-2147483648);
    TEST_ASSERT(result != NULL && strcmp(result, "-2147483648") == 0, "ft_itoa INT_MIN");
    free(result);
    
    result = ft_itoa(1);
    TEST_ASSERT(result != NULL && strcmp(result, "1") == 0, "ft_itoa single digit");
    free(result);
    
    result = ft_itoa(-1);
    TEST_ASSERT(result != NULL && strcmp(result, "-1") == 0, "ft_itoa negative single digit");
    free(result);
    
    result = ft_itoa(123456789);
    TEST_ASSERT(result != NULL && strcmp(result, "123456789") == 0, "ft_itoa large positive number");
    free(result);
    
    result = ft_itoa(-123456789);
    TEST_ASSERT(result != NULL && strcmp(result, "-123456789") == 0, "ft_itoa large negative number");
    free(result);
    
    printf("\n");
}