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


#ifndef __BALG_H
#define __BALG_H

#include "base.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define NUM_DATA      5
#define X             10
#define Y             10

#define N             (X * Y)

/******************************************************************************
        R A N D O M S   D R A W N   F R O M   D I S T R I B U T I O N S
 ******************************************************************************/


void InitializeRandoms();


INT RandomEqualINT(INT Low, INT High);



FILE* InitializeApplication(NET* Net,int nd,int x,int y,INT Input[][N],INT Input_[][N],CHAR Pattern[][X][Y],CHAR Pattern_[][X][Y],FILE*f);


void WriteNet(NET* Net,int x,int y,FILE*f);

void InitalizeApplication(NET* Net);
FILE* FinalizeApplication(NET* Net,FILE*f);


/******************************************************************************
                          I N I T I A L I Z A T I O N
 ******************************************************************************/


void GenerateNetwork(NET* Net,int n);

void CalculateWeights(NET* Net,INT Input[][N],int nd);

void SetInput(NET* Net, INT* Input,int x,int y,FILE*f);

void GetOutput(NET* Net, INT* Output,int x,int y,FILE*f);

/******************************************************************************
                     P R O P A G A T I N G   S I G N A L S
 ******************************************************************************/


BOOL PropagateUnit(NET* Net, INT i);
void PropagateNet(NET* Net);

/******************************************************************************
                      S I M U L A T I N G   T H E   N E T
 ******************************************************************************/


void SimulateNet(NET* Net, INT* Input,int n,int x,int y,FILE*f);

#ifdef	__cplusplus
}
#endif

#endif