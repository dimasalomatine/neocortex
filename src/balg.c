
#include "balg.h"

/******************************************************************************
        R A N D O M S   D R A W N   F R O M   D I S T R I B U T I O N S
 ******************************************************************************/


void InitializeRandoms()
{
  srand(4711);
}


INT RandomEqualINT(INT Low, INT High)
{
  return rand() % (High-Low+1) + Low;
}      



FILE* InitializeApplication(NET* Net,int nd,int x,int y,INT Input[][N],INT Input_[][N],CHAR Pattern[][X][Y],CHAR Pattern_[][X][Y],FILE*f)
{
  INT n,i,j;

  for (n=0; n<nd; n++) {
    for (i=0; i<y; i++) {
      for (j=0; j<x; j++) {
        Input [n][i*x+j] = BIPOLAR(Pattern [n][i][j] == 'O');
        Input_[n][i*x+j] = BIPOLAR(Pattern_[n][i][j] == 'O');
      }
    }
  }
  
  f = fopen("HOPFIELD.txt", "w");
  return f;
}


void WriteNet(NET* Net,int x,int y,FILE*f)
{
  INT i,j;
   
  for (i=0; i<y; i++) {
    for (j=0; j<x; j++) {
      fprintf(f, "%c", BINARY(Net->Output[i*x+j]) ? 'O' : ' ');
    }
    fprintf(f, "\n");
  }
  fprintf(f, "\n");
}


void FinalizeApplication(NET* Net,FILE*f)
{
  fclose(f);
}


/******************************************************************************
                          I N I T I A L I Z A T I O N
 ******************************************************************************/


void GenerateNetwork(NET* Net,int n)
{
  INT i;

  Net->Units     = n;
  Net->Output    = (INT*)  calloc(n, sizeof(INT));
  Net->Threshold = (INT*)  calloc(n, sizeof(INT));
  Net->Weight    = (INT**) calloc(n, sizeof(INT*));

  for (i=0; i<n; i++) {
    Net->Threshold[i] = 0;
    Net->Weight[i]    = (INT*) calloc(n, sizeof(INT));
  }
}


void CalculateWeights(NET* Net,INT Input[][N],int nd)
{
  INT i,j,n;
  INT Weight;

  for (i=0; i<Net->Units; i++) {
    for (j=0; j<Net->Units; j++) {
      Weight = 0;
      if (i!=j) {
        for (n=0; n<nd; n++) {
          Weight += Input[n][i] * Input[n][j];
        }
      }
      Net->Weight[i][j] = Weight;
    }
  }
}


void SetInput(NET* Net, INT* Input,int x,int y,FILE*f)
{
  INT i;
   
  for (i=0; i<Net->Units; i++) {
    Net->Output[i] = Input[i];
  }
  WriteNet(Net, x, y,f);
}


void GetOutput(NET* Net, INT* Output,int x,int y,FILE*f)
{
  INT i;
   
  for (i=0; i<Net->Units; i++) {
    Output[i] = Net->Output[i];
  }
  WriteNet(Net,x,y,f);
}


/******************************************************************************
                     P R O P A G A T I N G   S I G N A L S
 ******************************************************************************/


BOOL PropagateUnit(NET* Net, INT i)
{
  INT  j;
  INT  Sum, Out;
  BOOL Changed;

  Changed = FALSE;
  Sum = 0;
  for (j=0; j<Net->Units; j++) {
    Sum += Net->Weight[i][j] * Net->Output[j];
  }
  if (Sum != Net->Threshold[i]) {
    if (Sum < Net->Threshold[i]) Out = LO;
    if (Sum > Net->Threshold[i]) Out = HI;
    if (Out != Net->Output[i]) {
      Changed = TRUE;
      Net->Output[i] = Out;
    }
  }
  return Changed;
}


void PropagateNet(NET* Net)
{
  INT Iteration, IterationOfLastChange;

  Iteration = 0;
  IterationOfLastChange = 0;
  do {
    Iteration++;
    if (PropagateUnit(Net, RandomEqualINT(0, Net->Units-1)))
      IterationOfLastChange = Iteration;
  } while (Iteration-IterationOfLastChange < 10*Net->Units);
}


/******************************************************************************
                      S I M U L A T I N G   T H E   N E T
 ******************************************************************************/


void SimulateNet(NET* Net, INT* Input,int n,int x,int y,FILE*f)
{
  INT Output[n];
   
  SetInput(Net, Input,x,y,f);
  PropagateNet(Net);
  GetOutput(Net, Output,x,y,f);
}



