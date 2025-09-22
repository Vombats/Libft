/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libft-test <test@libft.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 00:00:00 by libft-test       #+#    #+#             */
/*   Updated: 2025/09/22 00:00:00 by libft-test      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Global variables for test tracking
int tests_run = 0;
int tests_passed = 0;
int tests_failed = 0;

// Include all test implementations
#include "test_runner.c"
#include "tests_character.c"
#include "tests_memory.c"
#include "tests_string.c"
#include "tests_manipulation.c"
#include "tests_conversion.c"
#include "tests_output.c"
#include "tests_list.c"
#include "tests_utility.c"