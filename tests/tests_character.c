/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libft-test <test@libft.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 00:00:00 by libft-test       #+#    #+#             */
/*   Updated: 2025/09/22 00:00:00 by libft-test      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <ctype.h>

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

void test_character_functions(void)
{
    TEST_START("Character Classification Functions");
    
    // Test ft_isalpha
    TEST_ASSERT(ft_isalpha('a') != 0, "ft_isalpha('a') should return non-zero");
    TEST_ASSERT(ft_isalpha('Z') != 0, "ft_isalpha('Z') should return non-zero");
    TEST_ASSERT(ft_isalpha('5') == 0, "ft_isalpha('5') should return 0");
    TEST_ASSERT(ft_isalpha(' ') == 0, "ft_isalpha(' ') should return 0");
    TEST_ASSERT(ft_isalpha(128) == 0, "ft_isalpha(128) should return 0");
    
    // Test ft_isdigit
    TEST_ASSERT(ft_isdigit('0') != 0, "ft_isdigit('0') should return non-zero");
    TEST_ASSERT(ft_isdigit('9') != 0, "ft_isdigit('9') should return non-zero");
    TEST_ASSERT(ft_isdigit('a') == 0, "ft_isdigit('a') should return 0");
    TEST_ASSERT(ft_isdigit(' ') == 0, "ft_isdigit(' ') should return 0");
    TEST_ASSERT(ft_isdigit(-1) == 0, "ft_isdigit(-1) should return 0");
    
    // Test ft_isalnum
    TEST_ASSERT(ft_isalnum('a') != 0, "ft_isalnum('a') should return non-zero");
    TEST_ASSERT(ft_isalnum('5') != 0, "ft_isalnum('5') should return non-zero");
    TEST_ASSERT(ft_isalnum(' ') == 0, "ft_isalnum(' ') should return 0");
    TEST_ASSERT(ft_isalnum('!') == 0, "ft_isalnum('!') should return 0");
    
    // Test ft_isascii
    TEST_ASSERT(ft_isascii(0) != 0, "ft_isascii(0) should return non-zero");
    TEST_ASSERT(ft_isascii(127) != 0, "ft_isascii(127) should return non-zero");
    TEST_ASSERT(ft_isascii(128) == 0, "ft_isascii(128) should return 0");
    TEST_ASSERT(ft_isascii(-1) == 0, "ft_isascii(-1) should return 0");
    TEST_ASSERT(ft_isascii('A') != 0, "ft_isascii('A') should return non-zero");
    
    // Test ft_isprint
    TEST_ASSERT(ft_isprint(' ') != 0, "ft_isprint(' ') should return non-zero");
    TEST_ASSERT(ft_isprint('~') != 0, "ft_isprint('~') should return non-zero");
    TEST_ASSERT(ft_isprint(31) == 0, "ft_isprint(31) should return 0");
    TEST_ASSERT(ft_isprint(127) == 0, "ft_isprint(127) should return 0");
    TEST_ASSERT(ft_isprint('A') != 0, "ft_isprint('A') should return non-zero");
    
    // Test ft_tolower
    TEST_ASSERT(ft_tolower('A') == 'a', "ft_tolower('A') should return 'a'");
    TEST_ASSERT(ft_tolower('Z') == 'z', "ft_tolower('Z') should return 'z'");
    TEST_ASSERT(ft_tolower('a') == 'a', "ft_tolower('a') should return 'a'");
    TEST_ASSERT(ft_tolower('5') == '5', "ft_tolower('5') should return '5'");
    TEST_ASSERT(ft_tolower(' ') == ' ', "ft_tolower(' ') should return ' '");
    
    // Test ft_toupper
    TEST_ASSERT(ft_toupper('a') == 'A', "ft_toupper('a') should return 'A'");
    TEST_ASSERT(ft_toupper('z') == 'Z', "ft_toupper('z') should return 'Z'");
    TEST_ASSERT(ft_toupper('A') == 'A', "ft_toupper('A') should return 'A'");
    TEST_ASSERT(ft_toupper('5') == '5', "ft_toupper('5') should return '5'");
    TEST_ASSERT(ft_toupper(' ') == ' ', "ft_toupper(' ') should return ' '");
    
    printf("\n");
}