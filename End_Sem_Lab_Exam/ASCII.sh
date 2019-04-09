#!/usr/bin/env bash

# Write a shell program which takes input as a character and prints output as its ASCII value.

echo "The ASCII Value of " $1 " is"
# LC_CTYPE=C
printf '%d\n' "'$1"