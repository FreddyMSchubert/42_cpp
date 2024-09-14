#!/bin/bash

os=$(uname -s)

if [[ "$os" == "Linux" ]]; then
	/PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
elif [[ "$os" == "Darwin" ]]; then
	./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
fi
