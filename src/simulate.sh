# make
#./run side model replicates Tmax, by wfileS vfileS

#first step:
#-----------

# Gas free expansion
./run 64 1 1 1000000 10000 10000 1000 ../data/gfe.statistics.dat ../data/gfe.window.dat ../data/gfe.vector.dat
# Game of Life
./run 64 2 1 500 1 1 10 ../data/gol.statistics.dat ../data/gol.window.dat ../data/gol.vector.dat


#1000 replicates:
#---------------
# Gas free expansion
./run 64 1 1000 1000000 10000 10000 1000000 ../data/gfe100.statistics.dat ../data/gfe100.window.dat ../data/gfe100.vector.dat &
# Game of Life
./run 64 2 1000 500 1 1 1000 ../data/gol100.statistics.dat ../data/gol100.window.dat ../data/gol100.vector.dat

# Static:
#-----------
# Gradient
./run 64 3 1 1 1 1 1 ../data/gradient.statistics.dat ../data/gradient.window.dat ../data/gradient.vector.dat
# Uniform
./run 64 4 1 1 1 1 1 ../data/uniform.statistics.dat ../data/uniform.window.dat ../data/uniform.vector.dat
