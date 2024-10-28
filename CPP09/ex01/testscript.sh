#!/bin/bash

test_case() {
    input="$1"
    expected="$2"
    output=$(./RPN "$input")

    if [ "$output" == "$expected" ]; then
        echo "Test passed: $input"
    else
        echo "Test failed: $input"
        echo "Expected: $expected"
        echo "Got: $output"
    fi
}

test_case "3 4 +" "Result: 7"
test_case "" "Error: Invalid RPN expression."
test_case "5 1 2 + 4 * + 3 -" "Result: 14"
test_case "8 2 /" "Result: 4"
test_case "5 0 /" "Error: Division by zero."
test_case "3 a +" "Error: Invalid token."
test_case "+" "Error: Not enough operands for the operation."
test_case "10" "Single numbers are accepted. 0 - 9 !"
test_case "2 3 + -" "Error: Not enough operands for the operation."
