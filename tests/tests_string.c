/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_string.c                                     :+:      :+:    :+:   */
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

void test_string_functions(void)
{
    TEST_START("String Functions");
    
    char buffer[100];
    char *ptr;
    
    // Test ft_strlen
    TEST_ASSERT(ft_strlen("") == 0, "ft_strlen(\"\") should return 0");
    TEST_ASSERT(ft_strlen("Hello") == 5, "ft_strlen(\"Hello\") should return 5");
    TEST_ASSERT(ft_strlen("Hello World") == 11, "ft_strlen(\"Hello World\") should return 11");
    
    // Test ft_strchr
    ptr = ft_strchr("Hello World", 'W');
    TEST_ASSERT(ptr != NULL && *ptr == 'W', "ft_strchr should find character");
    
    ptr = ft_strchr("Hello World", 'Z');
    TEST_ASSERT(ptr == NULL, "ft_strchr should return NULL when character not found");
    
    ptr = ft_strchr("Hello World", '\0');
    TEST_ASSERT(ptr != NULL && *ptr == '\0', "ft_strchr should find null terminator");
    
    // Test ft_strrchr
    ptr = ft_strrchr("Hello World", 'l');
    TEST_ASSERT(ptr != NULL && ptr == strrchr("Hello World", 'l'), "ft_strrchr should find last occurrence");
    
    ptr = ft_strrchr("Hello World", 'Z');
    TEST_ASSERT(ptr == NULL, "ft_strrchr should return NULL when character not found");
    
    // Test ft_strncmp
    TEST_ASSERT(ft_strncmp("Hello", "Hello", 5) == 0, "ft_strncmp should return 0 for identical strings");
    TEST_ASSERT(ft_strncmp("Hello", "Hallo", 5) > 0, "ft_strncmp should return positive for greater string");
    TEST_ASSERT(ft_strncmp("Hallo", "Hello", 5) < 0, "ft_strncmp should return negative for lesser string");
    TEST_ASSERT(ft_strncmp("Hello", "HelloWorld", 5) == 0, "ft_strncmp should compare only n characters");
    TEST_ASSERT(ft_strncmp("", "", 5) == 0, "ft_strncmp should handle empty strings");
    
    // Test ft_strcmp
    TEST_ASSERT(ft_strcmp("Hello", "Hello") == 0, "ft_strcmp should return 0 for identical strings");
    TEST_ASSERT(ft_strcmp("Hello", "Hallo") > 0, "ft_strcmp should return positive for greater string");
    TEST_ASSERT(ft_strcmp("Hallo", "Hello") < 0, "ft_strcmp should return negative for lesser string");
    
    // Test ft_strnstr
    ptr = ft_strnstr("Hello World", "World", 11);
    TEST_ASSERT(ptr != NULL && strncmp(ptr, "World", 5) == 0, "ft_strnstr should find substring");
    
    ptr = ft_strnstr("Hello World", "World", 8);
    TEST_ASSERT(ptr == NULL, "ft_strnstr should return NULL when substring not in range");
    
    ptr = ft_strnstr("Hello World", "xyz", 11);
    TEST_ASSERT(ptr == NULL, "ft_strnstr should return NULL when substring not found");
    
    ptr = ft_strnstr("Hello", "", 5);
    TEST_ASSERT(ptr != NULL, "ft_strnstr should find empty string");
    
    // Test ft_strdup
    ptr = ft_strdup("Hello World");
    TEST_ASSERT(ptr != NULL && strcmp(ptr, "Hello World") == 0, "ft_strdup should duplicate string correctly");
    free(ptr);
    
    ptr = ft_strdup("");
    TEST_ASSERT(ptr != NULL && strcmp(ptr, "") == 0, "ft_strdup should handle empty string");
    free(ptr);
    
    // Test ft_strlcpy
    size_t result = ft_strlcpy(buffer, "Hello World", sizeof(buffer));
    TEST_ASSERT(result == 11 && strcmp(buffer, "Hello World") == 0, "ft_strlcpy should copy string correctly");
    
    result = ft_strlcpy(buffer, "Hello World", 6);
    TEST_ASSERT(result == 11 && strcmp(buffer, "Hello") == 0, "ft_strlcpy should truncate when buffer too small");
    
    result = ft_strlcpy(buffer, "Hi", sizeof(buffer));
    TEST_ASSERT(result == 2 && strcmp(buffer, "Hi") == 0, "ft_strlcpy should handle short strings");
    
    // Test ft_strlcat
    strcpy(buffer, "Hello");
    result = ft_strlcat(buffer, " World", sizeof(buffer));
    TEST_ASSERT(result == 11 && strcmp(buffer, "Hello World") == 0, "ft_strlcat should concatenate correctly");
    
    strcpy(buffer, "Hello");
    result = ft_strlcat(buffer, " World", 8);
    TEST_ASSERT(result == 11 && strcmp(buffer, "Hello W") == 0, "ft_strlcat should truncate when buffer too small");
    
    // Test ft_strnew
    ptr = ft_strnew(10);
    TEST_ASSERT(ptr != NULL, "ft_strnew should allocate memory");
    
    int all_zero = 1;
    for (int i = 0; i < 10; i++) {
        if (ptr[i] != '\0') {
            all_zero = 0;
            break;
        }
    }
    TEST_ASSERT(all_zero, "ft_strnew should initialize to zeros");
    free(ptr);
    
    printf("\n");
}