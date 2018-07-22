#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <map>
#include <math.h>
#include "randomv.h"
#include "system.h"
#include "gameOfLife.h"
#include "gasMixing.h"
#include "entropy.h"


using namespace std;

int main(int argc, char* argv[]){

/*
command line parameters:
side model replicates Tmax by

Options
1:     Gas mixing
2:     Game of Life
3:     Gradient
4:     Uniform
*/
int x;
int model;
int replicates;
int Tmax;
int byS;
int byW;
int byV;
const char* sfileS = "../data/statistics.dat";
const char* wfileS = "../data/window.dat";
const char* vfileS = "../data/vector.dat";
if(argc == 11){
  x           = atoi(argv[1]); // side
  model       = atoi(argv[2]);
  replicates  = atoi(argv[3]);
  Tmax        = atoi(argv[4]);
  byS         = atoi(argv[5]);
  byW         = atoi(argv[6]);
  byV         = atoi(argv[7]);
  sfileS      = argv[8];
  wfileS      = argv[9];
  vfileS      = argv[10];
}else{
  cerr<<"command line parameters:"<<endl;
  cerr<<"side model replicates Tmax byS byW byV soutFileName woutFileName voutFileName"<<endl;
  exit(1);
}
// Initial state variables
double  squareFillingProb = 0.9;
int     squareSide        = x/2;
entropy entropyFunctions(x, x);
ofstream sout;
ofstream wout;
ofstream vout;
sout.open (sfileS, std::ofstream::out);
wout.open (wfileS, std::ofstream::out);
vout.open (vfileS, std::ofstream::out);
randomv r;
for (int replicate = 0; replicate < replicates; replicate++){
  switch(model){
    case 1:{        // Gas mixing
      gasMixing gasMixing(x);
      gasMixing.fillSquare(r, squareSide, squareFillingProb);
      gasMixing.run(replicate, Tmax, r, sout, wout, vout, entropyFunctions, byS, byW, byV);
      break;
    }
    case 2:{         // Game of Life
      gameOfLife g(x);
      g.fillSquare(r, squareSide, squareFillingProb);
      g.run(replicate, Tmax, r, sout, wout, vout, entropyFunctions, byS, byW, byV);
      break;
    }case 3:{
      class system gradient(x);
      gradient.gradientLinear(r);
      gradient.run(0, 0, r, sout, wout, vout, entropyFunctions, 1, 1, 1);
      break;
     }case 4:{
	double densities[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
	for( int counter = 0; counter < 9; counter++){
	  class system uniform(x);
	  uniform.fillRandom(r, densities[counter]);
	  uniform.run(counter, 0, r, sout, wout, vout, entropyFunctions, 1, 1, 1);
	}
     }default:
      exit(1);
  }
 }
 return EXIT_SUCCESS;
}
