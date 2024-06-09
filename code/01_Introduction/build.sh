#!/bin/bash

gcc -O2 -g hello.c -o hello

if [ $? -eq 0 ]; then
    echo "Build successful. Running the program..."
    ./hello
else
    echo "Build failed."
fi
