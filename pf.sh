#!/usr/bin/env bash

clear
make re
gcc main.c -I ./includes/ -L . -lftprintf
./a.out