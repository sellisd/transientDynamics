#!/usr/bin/env bash

# make
#./run side model replicates Tmax, by wfileS vfileS

#first step:
#-----------

# Gas mixing
./run 64 1 1 1000000 10000 10000 1000 ../data/gm.statistics.dat ../data/gm.window.dat ../data/gm.vector.dat
# Game of Life
./run 64 2 1 500 1 1 10 ../data/gol.statistics.dat ../data/gol.window.dat ../data/gol.vector.dat
# Game of Life for animation
./run 64 2 1 500 1 1 1 ../data/gol.anim.statistics.dat ../data/gol.anim.window.dat ../data/gol.anim.vector.dat



#1000 replicates:
#---------------
# Gas mixing
./run 64 1 1000 1000000 10000 10000 1000000 ../data/gm100.statistics.dat ../data/gm100.window.dat ../data/gm100.vector.dat &
# Game of Life
./run 64 2 1000 500 1 1 1000 ../data/gol100.statistics.dat ../data/gol100.window.dat ../data/gol100.vector.dat

# Static:
#-----------
# Gradient
./run 64 3 1 1 1 1 1 ../data/gradient.statistics.dat ../data/gradient.window.dat ../data/gradient.vector.dat
# Uniform
./run 64 4 1 1 1 1 1 ../data/uniform.statistics.dat ../data/uniform.window.dat ../data/uniform.vector.dat
