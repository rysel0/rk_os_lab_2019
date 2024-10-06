#!/bin/bash
count=$#
sum=0

for arg in "$@"; do
    sum=$((sum + arg))
done

avg=$(echo "$sum / $count" | bc -l)

echo $count
echo $avg