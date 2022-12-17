#!/bin/bash
clang++ -o $1 -std=c++20 -O3 -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio "./$1.cpp"