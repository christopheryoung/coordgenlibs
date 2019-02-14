/*
 *  sketcherMinimizerConstraintInteraction.h
 *
 *  Created by Nicola Zonta on 7/02/2019.
 *   Copyright Schrodinger, LLC. All rights reserved.
 *
 */

#ifndef sketcherMINIMIZERCONSTRAINTINTERACTION
#define sketcherMINIMIZERCONSTRAINTINTERACTION

#include "sketcherMinimizerInteraction.h"

static const float CONSTRAINT_SCALE = .5f;
/*force field bond stretches*/
class sketcherMinimizerConstraintInteraction : public sketcherMinimizerInteraction
{
  public:
    sketcherMinimizerConstraintInteraction(sketcherMinimizerAtom* at1,
                                        sketcherMinimizerPointF
                                           position)
    : sketcherMinimizerInteraction(at1, at1), origin(position) {k = CONSTRAINT_SCALE;};
    virtual ~sketcherMinimizerConstraintInteraction(){};

    /*calculate the energy of the interaction*/
    virtual void energy(float& e)
    {
        e += k * sketcherMinimizerMaths::squaredDistance(atom1->coordinates, origin);
    };

    /*calculate the forces and apply them*/
    void score(float& totalE, bool = false)
    {
        energy(totalE);
        return;
    };
private:
    sketcherMinimizerPointF origin;
};

#endif // sketcherMINIMIZERCONSTRAINTINTERACTION

