/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_list.c                                       :+:      :+:    :+:   */
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

// Helper functions for list testing
void del_content(void *content)
{
    free(content);
}

void print_content(void *content)
{
    // This function is used in ft_lstiter tests
    // We don't actually print to avoid cluttering test output
    (void)content;
}

void *duplicate_content(void *content)
{
    char *str = (char *)content;
    char *dup = malloc(strlen(str) + 1);
    if (dup)
        strcpy(dup, str);
    return dup;
}

void test_list_functions(void)
{
    TEST_START("Linked List Functions");
    
    t_list *list = NULL;
    t_list *node;
    t_list *new_list;
    char *str1, *str2, *str3;
    
    // Allocate test strings
    str1 = malloc(10);
    str2 = malloc(10);
    str3 = malloc(10);
    strcpy(str1, "first");
    strcpy(str2, "second");
    strcpy(str3, "third");
    
    // Test ft_lstnew
    node = ft_lstnew(str1);
    TEST_ASSERT(node != NULL, "ft_lstnew should create a new node");
    TEST_ASSERT(node->content == str1, "ft_lstnew should set content correctly");
    TEST_ASSERT(node->next == NULL, "ft_lstnew should set next to NULL");
    
    // Test ft_lstadd_front
    list = node;
    node = ft_lstnew(str2);
    ft_lstadd_front(&list, node);
    TEST_ASSERT(list == node, "ft_lstadd_front should update list head");
    TEST_ASSERT(list->content == str2, "ft_lstadd_front should set content correctly");
    TEST_ASSERT(list->next != NULL, "ft_lstadd_front should link to previous head");
    TEST_ASSERT(list->next->content == str1, "ft_lstadd_front should preserve old head");
    
    // Test ft_lstsize
    TEST_ASSERT(ft_lstsize(list) == 2, "ft_lstsize should return correct size");
    TEST_ASSERT(ft_lstsize(NULL) == 0, "ft_lstsize should return 0 for NULL list");
    
    // Test ft_lstlast
    t_list *last = ft_lstlast(list);
    TEST_ASSERT(last != NULL && last->content == str1, "ft_lstlast should return last node");
    TEST_ASSERT(ft_lstlast(NULL) == NULL, "ft_lstlast should return NULL for empty list");
    
    // Test ft_lstadd_back
    node = ft_lstnew(str3);
    ft_lstadd_back(&list, node);
    TEST_ASSERT(ft_lstsize(list) == 3, "ft_lstadd_back should increase size");
    last = ft_lstlast(list);
    TEST_ASSERT(last->content == str3, "ft_lstadd_back should add to end");
    
    // Test adding to empty list with ft_lstadd_back
    t_list *empty_list = NULL;
    node = ft_lstnew(strdup("alone"));
    ft_lstadd_back(&empty_list, node);
    TEST_ASSERT(empty_list == node, "ft_lstadd_back should work on empty list");
    TEST_ASSERT(ft_lstsize(empty_list) == 1, "ft_lstadd_back should create single-element list");
    
    // Test ft_lstiter
    ft_lstiter(list, print_content);
    TEST_ASSERT(1, "ft_lstiter should iterate without crashing"); // Just test it doesn't crash
    
    ft_lstiter(NULL, print_content);
    TEST_ASSERT(1, "ft_lstiter should handle NULL list");
    
    // Test ft_lstmap
    new_list = ft_lstmap(list, duplicate_content, del_content);
    TEST_ASSERT(new_list != NULL, "ft_lstmap should create new list");
    TEST_ASSERT(ft_lstsize(new_list) == ft_lstsize(list), "ft_lstmap should preserve size");
    TEST_ASSERT(new_list != list, "ft_lstmap should create different list");
    TEST_ASSERT(new_list->content != list->content, "ft_lstmap should create different content");
    TEST_ASSERT(strcmp((char*)new_list->content, (char*)list->content) == 0, "ft_lstmap should duplicate content correctly");
    
    // Clean up new_list
    ft_lstclear(&new_list, del_content);
    TEST_ASSERT(new_list == NULL, "ft_lstclear should set list pointer to NULL");
    
    // Test ft_lstmap with NULL list
    new_list = ft_lstmap(NULL, duplicate_content, del_content);
    TEST_ASSERT(new_list == NULL, "ft_lstmap should return NULL for NULL input");
    
    // Test ft_lstdelone (create a separate node for this test)
    node = ft_lstnew(strdup("to_delete"));
    ft_lstdelone(node, del_content);
    TEST_ASSERT(1, "ft_lstdelone should delete node without crashing");
    
    // Test ft_lstdelone with NULL
    ft_lstdelone(NULL, del_content);
    TEST_ASSERT(1, "ft_lstdelone should handle NULL node");
    
    // Test ft_lstclear
    TEST_ASSERT(list != NULL && ft_lstsize(list) == 3, "List should have 3 elements before clear");
    ft_lstclear(&list, del_content);
    TEST_ASSERT(list == NULL, "ft_lstclear should set list to NULL");
    
    // Test ft_lstclear with NULL
    ft_lstclear(&list, del_content);
    TEST_ASSERT(list == NULL, "ft_lstclear should handle already NULL list");
    
    // Clean up empty_list
    ft_lstclear(&empty_list, del_content);
    
    printf("\n");
}