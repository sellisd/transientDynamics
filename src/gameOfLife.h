#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include <vector>
#include <fstream>
#include <map>
#include "randomv.h"
#include "entropy.h"
#include "system.h"

using namespace std;
/**
 * Game of Life on flat 2D torus grid
 */
class gameOfLife : public system{
 public:
  gameOfLife(void);   //! Default constructor
  gameOfLife(int side){};   //! Constructor with system side
  /**
  * Calculate sum of values around cell i,j
  * @param[in] i      x-axis coordinate.
  * @param[in] j      y-axis coordinate.
  * @return   sum
  */
  int sumN(int i, int j);
  //! Evolve the system by a single step.
  void step(randomv &r);
};
#endif
