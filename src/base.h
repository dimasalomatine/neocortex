/******************************************************************************

                      ==============
        Network:      Hopfield Model
                      ==============

        Application:  Autoassociative Memory
                      Associative Recall of Images

        Author:       Karsten Kutza
        Date:         30.1.96

        Reference:    J.J. Hopfield
                      Neural Networks and Physical Systems
                      with Emergent Collective Computational Abilities
                      Proceedings of the National Academy of Sciences, 79,
                      pp. 2554-2558, 1982

 ******************************************************************************/




/******************************************************************************
                            D E C L A R A T I O N S
 ******************************************************************************/


#ifndef __BASE_H
#define __BASE_H



#include <stdlib.h>
#include <stdio.h>

#ifdef	__cplusplus
extern "C" {
#endif

typedef int           BOOL;
typedef char          CHAR;
typedef int           INT;

#define FALSE         0
#define TRUE          1
#define NOT           !
#define AND           &&
#define OR            ||

#define LO            -1
#define HI            +1

#define BINARY(x)     ((x)==LO ? FALSE : TRUE)
#define BIPOLAR(x)    ((x)==FALSE ? LO : HI)


typedef struct {                     /* A NET:                                */
        INT           Units;         /* - number of units in this net         */
        INT*          Output;        /* - output of ith unit                  */
        INT*          Threshold;     /* - threshold of ith unit               */
        INT**         Weight;        /* - connection weights to ith unit      */
} NET;

#ifdef	__cplusplus
}
#endif

#endif
