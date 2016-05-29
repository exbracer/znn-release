#!/bin/bash
g++-4.9 -std=c++11 $1.cpp -I../../.. -I../../../src/include -DNDEBUG -O3 -DZNN_CUBE_POOL_LOCKFREE -DZNN_USE_FLOATS -lpthread -lfftw3f -ljemalloc -o $1 -DZNN_DONT_CACHE_FFTS
