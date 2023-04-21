#!/bin/bash

# ---
# Runs the tests
# ---

cd src/

make
make test


# run tests
export IP_TUPLAS=localhost

# link dynamic library
export LD_LIBRARY_PATH=lib/

# run server
./servidor &
pid_servidor=$!

sleep 1

./testing

echo "Killing server at $pid_servidor"
kill $pid_servidor