#!/bin/bash

# Test summary script for libft

echo "=== LIBFT TEST SUMMARY ==="
echo ""

# Clean start
make clean > /dev/null 2>&1

echo "Testing individual modules:"
echo ""

test_categories=("char" "memory" "string" "manipulation" "conversion" "output" "list" "utility")

for category in "${test_categories[@]}"; do
    echo -n "  $category: "
    if make test-$category > /tmp/test_output_$category 2>&1; then
        # Extract test results
        passed=$(grep "Passed:" /tmp/test_output_$category | cut -d: -f2 | tr -d ' ')
        failed=$(grep "Failed:" /tmp/test_output_$category | cut -d: -f2 | tr -d ' ')
        echo "✓ ($passed passed, $failed failed)"
    else
        echo "✗ (compilation or runtime error)"
    fi
    rm -f /tmp/test_output_$category
done

echo ""
echo "Workspace status:"
echo "  Object files: $(ls *.o 2>/dev/null | wc -l) (automatically cleaned)"
echo "  Library files: $(ls *.a 2>/dev/null | wc -l)"
echo ""
echo "Available commands:"
echo "  make test-<category> - Run specific tests"
echo "  make test-clean      - Clean test files and objects"
echo "  make test-fclean     - Clean everything including library"
echo ""