#!/bin/bash

# This script recursively deletes files generated by CMake.

# Define the directories to search for CMake-generated files.
directories=(
  "AzaleaEngine"
  "AzaleaTest"
  "."
)

# Define the file extensions of CMake-generated files to delete.
file_extensions=(
  ".cmake"
  "CMakeCache.txt"
  "CMakeFiles"
  "Makefile"
  "cmake_install.cmake"
)

# Iterate over the directories and delete CMake-generated files.
for dir in "${directories[@]}"
do
  if [ -d "$dir" ]
  then
    echo "Deleting CMake-generated files in $dir..."
    for ext in "${file_extensions[@]}"
    do
      find "$dir" -name "$ext" -exec rm -rf {} \;
    done
  fi
done

echo "Done."
