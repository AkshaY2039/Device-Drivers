#!/usr/bin/env bash

echo "The ASCII Value of " $1 " is"
LC_CTYPE=C printf '%d\n' "'$1"