#!/bin/bash
cd src/

# compile
make

# link dynamic library
export LD_LIBRARY_PATH=lib/

# run
./servidor &
env IP_TUPLAS=localhost ./cliente