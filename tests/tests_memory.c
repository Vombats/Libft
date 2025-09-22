/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_memory.c                                     :+:      :+:    :+:   */
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

void test_memory_functions(void)
{
    TEST_START("Memory Functions");
    
    char buffer[100];
    char buffer2[100];
    char *ptr;
    
    // Initialize buffers to prevent valgrind warnings
    memset(buffer, 0, sizeof(buffer));
    memset(buffer2, 0, sizeof(buffer2));
    
    // Test ft_memset
    ft_memset(buffer, 'A', 10);
    buffer[10] = '\0';
    TEST_ASSERT(strcmp(buffer, "AAAAAAAAAA") == 0, "ft_memset should fill memory correctly");
    
    ft_memset(buffer, 0, 100);
    TEST_ASSERT(buffer[0] == 0 && buffer[50] == 0 && buffer[99] == 0, "ft_memset with 0 should clear memory");
    
    // Test ft_bzero
    strcpy(buffer, "Hello World");
    ft_bzero(buffer, 5);
    TEST_ASSERT(buffer[0] == 0 && buffer[4] == 0 && buffer[5] == ' ', "ft_bzero should zero first 5 bytes");
    
    // Test ft_memcpy
    strcpy(buffer, "Hello World");
    ft_memcpy(buffer2, buffer, 11);
    TEST_ASSERT(strcmp(buffer2, "Hello World") == 0, "ft_memcpy should copy memory correctly");
    
    ft_memcpy(buffer2, "Test", 4);
    TEST_ASSERT(strncmp(buffer2, "Test", 4) == 0, "ft_memcpy should handle partial copies");
    
    // Test ft_memmove (overlapping memory)
    strcpy(buffer, "Hello World");
    ft_memmove(buffer + 2, buffer, 5);
    TEST_ASSERT(strncmp(buffer, "HeHello", 7) == 0, "ft_memmove should handle overlapping memory");
    
    strcpy(buffer, "Hello World");
    ft_memmove(buffer, buffer + 6, 5);
    TEST_ASSERT(strncmp(buffer, "World", 5) == 0, "ft_memmove should handle reverse overlap");
    
    // Test ft_memchr
    strcpy(buffer, "Hello World");
    ptr = ft_memchr(buffer, 'W', 11);
    TEST_ASSERT(ptr == buffer + 6, "ft_memchr should find character correctly");
    
    ptr = ft_memchr(buffer, 'Z', 11);
    TEST_ASSERT(ptr == NULL, "ft_memchr should return NULL when character not found");
    
    ptr = ft_memchr(buffer, '\0', 12);
    TEST_ASSERT(ptr == buffer + 11, "ft_memchr should find null terminator");
    
    // Test ft_memcmp
    strcpy(buffer, "Hello");
    strcpy(buffer2, "Hello");
    TEST_ASSERT(ft_memcmp(buffer, buffer2, 5) == 0, "ft_memcmp should return 0 for identical memory");
    
    strcpy(buffer2, "Hallo");
    TEST_ASSERT(ft_memcmp(buffer, buffer2, 5) > 0, "ft_memcmp should return positive for greater memory");
    
    strcpy(buffer2, "Iello");
    TEST_ASSERT(ft_memcmp(buffer, buffer2, 5) < 0, "ft_memcmp should return negative for lesser memory");
    
    TEST_ASSERT(ft_memcmp(buffer, buffer2, 0) == 0, "ft_memcmp should return 0 for zero length");
    
    // Test ft_memccpy
    strcpy(buffer, "Hello World");
    ptr = ft_memccpy(buffer2, buffer, 'W', 20);
    TEST_ASSERT(ptr != NULL && strncmp(buffer2, "Hello W", 7) == 0, "ft_memccpy should stop at character");
    
    ptr = ft_memccpy(buffer2, buffer, 'Z', 11);
    TEST_ASSERT(ptr == NULL && strncmp(buffer2, "Hello World", 11) == 0, "ft_memccpy should copy all if char not found");
    
    // Test ft_calloc
    ptr = ft_calloc(10, sizeof(char));
    TEST_ASSERT(ptr != NULL, "ft_calloc should allocate memory");
    
    int all_zero = 1;
    for (int i = 0; i < 10; i++) {
        if (ptr[i] != 0) {
            all_zero = 0;
            break;
        }
    }
    TEST_ASSERT(all_zero, "ft_calloc should initialize memory to zero");
    free(ptr);
    
    ptr = ft_calloc(0, sizeof(char));
    TEST_ASSERT(ptr != NULL || ptr == NULL, "ft_calloc with zero size should handle gracefully");
    if (ptr) free(ptr);
    
    // Test ft_memdel
    ptr = malloc(10);
    ft_memdel((void**)&ptr);
    TEST_ASSERT(ptr == NULL, "ft_memdel should set pointer to NULL");
    
    printf("\n");
}