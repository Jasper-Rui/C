cmake_minimum_required(VERSION 3.11)
project(miner C)

set(CMAKE_C_STANDARD 99)

add_executable(miner main.c transactions.c transactions.h siggen.c siggen.h mempool.c mempool.h)