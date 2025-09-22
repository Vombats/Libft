/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_manipulation.c                               :+:      :+:    :+:   */
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

char test_toupper_func(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

void test_striteri_func(unsigned int i, char *c)
{
    if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

void test_string_manipulation(void)
{
    TEST_START("String Manipulation Functions");
    
    char *str, *result;
    char **split_result;
    char buffer[100];
    
    // Test ft_substr
    str = "Hello World";
    result = ft_substr(str, 6, 5);
    TEST_ASSERT(result != NULL && strcmp(result, "World") == 0, "ft_substr should extract substring correctly");
    free(result);
    
    result = ft_substr(str, 0, 5);
    TEST_ASSERT(result != NULL && strcmp(result, "Hello") == 0, "ft_substr should extract from beginning");
    free(result);
    
    result = ft_substr(str, 6, 20);
    TEST_ASSERT(result != NULL && strcmp(result, "World") == 0, "ft_substr should handle length beyond string");
    free(result);
    
    result = ft_substr(str, 20, 5);
    TEST_ASSERT(result != NULL && strcmp(result, "") == 0, "ft_substr should return empty string for out-of-bounds start");
    free(result);
    
    result = ft_substr("", 0, 5);
    TEST_ASSERT(result != NULL && strcmp(result, "") == 0, "ft_substr should handle empty string");
    free(result);
    
    // Test ft_strjoin
    result = ft_strjoin("Hello", " World");
    TEST_ASSERT(result != NULL && strcmp(result, "Hello World") == 0, "ft_strjoin should concatenate strings");
    free(result);
    
    result = ft_strjoin("", "World");
    TEST_ASSERT(result != NULL && strcmp(result, "World") == 0, "ft_strjoin should handle empty first string");
    free(result);
    
    result = ft_strjoin("Hello", "");
    TEST_ASSERT(result != NULL && strcmp(result, "Hello") == 0, "ft_strjoin should handle empty second string");
    free(result);
    
    result = ft_strjoin("", "");
    TEST_ASSERT(result != NULL && strcmp(result, "") == 0, "ft_strjoin should handle both empty strings");
    free(result);
    
    // Test ft_strtrim
    result = ft_strtrim("   Hello World   ", " ");
    TEST_ASSERT(result != NULL && strcmp(result, "Hello World") == 0, "ft_strtrim should trim spaces");
    free(result);
    
    result = ft_strtrim("abcHello Worldcba", "abc");
    TEST_ASSERT(result != NULL && strcmp(result, "Hello World") == 0, "ft_strtrim should trim multiple characters");
    free(result);
    
    result = ft_strtrim("Hello World", "xyz");
    TEST_ASSERT(result != NULL && strcmp(result, "Hello World") == 0, "ft_strtrim should return original if no trim chars");
    free(result);
    
    result = ft_strtrim("   ", " ");
    TEST_ASSERT(result != NULL && strcmp(result, "") == 0, "ft_strtrim should return empty for all-trim string");
    free(result);
    
    result = ft_strtrim("", " ");
    TEST_ASSERT(result != NULL && strcmp(result, "") == 0, "ft_strtrim should handle empty string");
    free(result);
    
    // Test ft_split
    split_result = ft_split("hello,world,42,school", ',');
    TEST_ASSERT(split_result != NULL, "ft_split should return valid array");
    TEST_ASSERT(split_result[0] != NULL && strcmp(split_result[0], "hello") == 0, "ft_split first element");
    TEST_ASSERT(split_result[1] != NULL && strcmp(split_result[1], "world") == 0, "ft_split second element");
    TEST_ASSERT(split_result[2] != NULL && strcmp(split_result[2], "42") == 0, "ft_split third element");
    TEST_ASSERT(split_result[3] != NULL && strcmp(split_result[3], "school") == 0, "ft_split fourth element");
    TEST_ASSERT(split_result[4] == NULL, "ft_split should be NULL-terminated");
    ft_split_free(split_result);
    
    split_result = ft_split("hello", ',');
    TEST_ASSERT(split_result != NULL && split_result[0] != NULL && strcmp(split_result[0], "hello") == 0, "ft_split single word");
    TEST_ASSERT(split_result[1] == NULL, "ft_split single word should be NULL-terminated");
    ft_split_free(split_result);
    
    split_result = ft_split("", ',');
    TEST_ASSERT(split_result != NULL && split_result[0] == NULL, "ft_split empty string should return empty array");
    ft_split_free(split_result);
    
    split_result = ft_split(",,,", ',');
    TEST_ASSERT(split_result != NULL && split_result[0] == NULL, "ft_split only delimiters should return empty array");
    ft_split_free(split_result);
    
    split_result = ft_split("  hello  world  ", ' ');
    TEST_ASSERT(split_result != NULL && split_result[0] != NULL && strcmp(split_result[0], "hello") == 0, "ft_split with spaces");
    TEST_ASSERT(split_result[1] != NULL && strcmp(split_result[1], "world") == 0, "ft_split with spaces second element");
    TEST_ASSERT(split_result[2] == NULL, "ft_split with spaces should be NULL-terminated");
    ft_split_free(split_result);
    
    // Test ft_strmapi
    result = ft_strmapi("hello", test_toupper_func);
    TEST_ASSERT(result != NULL && strcmp(result, "HELLO") == 0, "ft_strmapi should apply function to each character");
    free(result);
    
    result = ft_strmapi("", test_toupper_func);
    TEST_ASSERT(result != NULL && strcmp(result, "") == 0, "ft_strmapi should handle empty string");
    free(result);
    
    // Test ft_striteri
    strcpy(buffer, "hello");
    ft_striteri(buffer, test_striteri_func);
    TEST_ASSERT(strcmp(buffer, "HeLlO") == 0, "ft_striteri should apply function to characters at even indices");
    
    // Test ft_straddchar
    char *test_str = ft_strdup("hello");
    result = ft_straddchar(test_str, '!');
    TEST_ASSERT(result != NULL && strcmp(result, "hello!") == 0, "ft_straddchar should add character to end");
    free(result);
    
    test_str = ft_strdup("");
    result = ft_straddchar(test_str, 'a');
    TEST_ASSERT(result != NULL && strcmp(result, "a") == 0, "ft_straddchar should handle empty string");
    free(result);
    
    // Test ft_wordcount
    TEST_ASSERT(ft_wordcount("hello world 42", ' ') == 3, "ft_wordcount should count words correctly");
    TEST_ASSERT(ft_wordcount("hello", ' ') == 1, "ft_wordcount single word");
    TEST_ASSERT(ft_wordcount("", ' ') == 0, "ft_wordcount empty string");
    TEST_ASSERT(ft_wordcount("   hello   world   ", ' ') == 2, "ft_wordcount with extra spaces");
    TEST_ASSERT(ft_wordcount("   ", ' ') == 0, "ft_wordcount only spaces");
    
    printf("\n");
}