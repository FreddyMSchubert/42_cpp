#!/bin/bash

echo "Expected result: 42"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

echo "Expected result: 42"
./RPN "7 7 * 7 -"

echo "Expected result: 42"
./RPN "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -"

echo "Expected result: 0"
./RPN "1 2 * 2 / 2 * 2 4 - +"

echo "Expected result: 15"
./RPN "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /"

echo "Expected result: Error"
./RPN "(1 + 1)"