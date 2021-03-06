#ifndef GASMIXING_H
#define GASMIXING_H
#include <vector>
#include <fstream>
#include "randomv.h"
#include "entropy.h"
#include "system.h"

using namespace std;

/**
 * Gas mixing
 * lattice rule is random swap two adjacent particles. At each time step,
 * choose 2 horizontally or vertically adjacent squares uniformly at random
 * and swap them only if they’re colored differentl
 */

class gasMixing : public system{
  public:
    gasMixing(void); //! Default constructor
    gasMixing(int side){}; //! Constructor with side of world
    /**
    * One time step (generation), extends the base class step.
    * @param[in] r   Random number generation class.
    * @return              Nothing
    */
    void step(randomv &r);
    /**
    * Move particle to new location if empty.
    * @param[in] x1   X-axis coordinate of particle
    * @param[in] y1   Y-axis coordinate of particle
    * @param[in] x2   X-axis coordinate of target
    * @param[in] y2   Y-axis coordinate of target
    * @return    int  Movement performed (1) or not (0)
    */
    int  swap(int x1, int y1, int x2, int y2);
};
#endif
