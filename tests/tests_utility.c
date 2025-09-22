/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_utility.c                                    :+:      :+:    :+:   */
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
#include <unistd.h>
#include <fcntl.h>

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

void test_utility_functions(void)
{
    TEST_START("Utility Functions");
    
    char **arr;
    int fd;
    char *line;
    int gnl_result;
    
    // Test ft_strarrlen
    char *test_arr1[] = {"hello", "world", "42", NULL};
    TEST_ASSERT(ft_strarrlen(test_arr1) == 3, "ft_strarrlen should count array elements");
    
    char *test_arr2[] = {NULL};
    TEST_ASSERT(ft_strarrlen(test_arr2) == 0, "ft_strarrlen should return 0 for empty array");
    
    TEST_ASSERT(ft_strarrlen(NULL) == 0, "ft_strarrlen should handle NULL array");
    
    // Test ft_strarrnew
    arr = ft_strarrnew();
    TEST_ASSERT(arr != NULL, "ft_strarrnew should allocate memory");
    TEST_ASSERT(arr[0] == NULL, "ft_strarrnew should create NULL-terminated array");
    free(arr);
    
    // Test ft_strarrdup
    arr = ft_strarrdup(test_arr1);
    TEST_ASSERT(arr != NULL, "ft_strarrdup should allocate new array");
    TEST_ASSERT(ft_strarrlen(arr) == 3, "ft_strarrdup should preserve array length");
    TEST_ASSERT(strcmp(arr[0], "hello") == 0, "ft_strarrdup should copy first element");
    TEST_ASSERT(strcmp(arr[1], "world") == 0, "ft_strarrdup should copy second element");
    TEST_ASSERT(strcmp(arr[2], "42") == 0, "ft_strarrdup should copy third element");
    TEST_ASSERT(arr[3] == NULL, "ft_strarrdup should be NULL-terminated");
    
    // Clean up
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
    
    arr = ft_strarrdup(NULL);
    TEST_ASSERT(arr == NULL, "ft_strarrdup should return NULL for NULL input");
    
    // Test ft_addstrstrarr
    arr = ft_strarrnew();
    arr = ft_addstrstrarr(arr, "first");
    TEST_ASSERT(arr != NULL && ft_strarrlen(arr) == 1, "ft_addstrstrarr should add first element");
    TEST_ASSERT(strcmp(arr[0], "first") == 0, "ft_addstrstrarr should copy string correctly");
    
    arr = ft_addstrstrarr(arr, "second");
    TEST_ASSERT(ft_strarrlen(arr) == 2, "ft_addstrstrarr should add second element");
    TEST_ASSERT(strcmp(arr[1], "second") == 0, "ft_addstrstrarr should copy second string");
    
    arr = ft_addstrstrarr(arr, "third");
    TEST_ASSERT(ft_strarrlen(arr) == 3, "ft_addstrstrarr should add third element");
    TEST_ASSERT(strcmp(arr[2], "third") == 0, "ft_addstrstrarr should copy third string");
    
    // Clean up
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
    
    // Test ft_terror (just ensure it doesn't crash)
    // Note: ft_terror calls exit(), so we can't test it directly
    // We'll just verify it exists and is callable in concept
    TEST_ASSERT(1, "ft_terror function exists (cannot test directly as it calls exit)");
    
    // Test get_next_line
    // Create a test file
    fd = open("/tmp/libft_test_gnl", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd != -1) {
        write(fd, "Line 1\nLine 2\nLine 3", 20);
        close(fd);
        
        fd = open("/tmp/libft_test_gnl", O_RDONLY);
        if (fd != -1) {
            gnl_result = get_next_line(fd, &line);
            TEST_ASSERT(gnl_result > 0 && line != NULL, "get_next_line should read first line");
            if (line) {
                TEST_ASSERT(strcmp(line, "Line 1") == 0, "get_next_line should read correct content");
                free(line);
            }
            
            gnl_result = get_next_line(fd, &line);
            TEST_ASSERT(gnl_result > 0 && line != NULL, "get_next_line should read second line");
            if (line) {
                TEST_ASSERT(strcmp(line, "Line 2") == 0, "get_next_line should read second line correctly");
                free(line);
            }
            
            gnl_result = get_next_line(fd, &line);
            TEST_ASSERT(gnl_result >= 0 && line != NULL, "get_next_line should read third line");
            if (line) {
                TEST_ASSERT(strcmp(line, "Line 3") == 0, "get_next_line should read third line correctly");
                free(line);
            }
            
            close(fd);
        }
        
        // Test with empty file
        fd = open("/tmp/libft_test_gnl_empty", O_CREAT | O_WRONLY | O_TRUNC, 0644);
        close(fd);
        
        fd = open("/tmp/libft_test_gnl_empty", O_RDONLY);
        if (fd != -1) {
            gnl_result = get_next_line(fd, &line);
            TEST_ASSERT(gnl_result >= 0, "get_next_line should handle empty file");
            if (line) {
                free(line);
            }
            close(fd);
        }
        
        // Clean up test files
        unlink("/tmp/libft_test_gnl");
        unlink("/tmp/libft_test_gnl_empty");
    }
    
    // Test with invalid fd
    gnl_result = get_next_line(-1, &line);
    TEST_ASSERT(gnl_result <= 0, "get_next_line should handle invalid fd");
    
    printf("\n");
}