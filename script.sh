#! /usr/bin/env bash

make re && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=readline.supp --trace-children=yes --log-file=valgrind-out.txt ./minishell