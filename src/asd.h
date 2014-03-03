/* 
 * File:   asd.h
 * Author: dima
 *
 * Created on March 3, 2014, 7:08 PM
 */

#ifndef ASD_H
#define	ASD_H

#include "base.h"

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct {                     /* A SAMLE inputs:                                */

        INT**          Input;     /*               */
        INT**         Input_;        /*      */
        FILE* f;
} SAMPLE;

SAMPLE* InitializeApplication_d(SAMPLE*s,int nd,int x,int y,CHAR*** Pattern,CHAR*** Pattern_,FILE*f);


#ifdef	__cplusplus
}
#endif

#endif	/* ASD_H */

