#!/bin/python3
array = [1, 2, 3, 4, 5, 60, 7, 8, 9, 10]
max = array[0]
for item in array:
  if item > max:
    max = item
print("max:", max)
