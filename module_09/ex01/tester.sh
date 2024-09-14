#!/bin/bash

echo "Expected result: 42"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

echo "Expected result: 42"
./RPN "7 7 * 7 -"

echo "Expected result: 0"
./RPN "1 2 * 2 / 2 * 2 4 - +"

echo "Expected result: Error"
./RPN "(1 + 1)"