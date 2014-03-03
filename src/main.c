

#include "balg.h"
#include "asd.h"

/******************************************************************************
               A P P L I C A T I O N - S P E C I F I C   C O D E
 ******************************************************************************/

CHAR                  Pattern[NUM_DATA][Y][X]  = { { "O O O O O ",
                                                     " O O O O O",
                                                     "O O O O O ",
                                                     " O O O O O",
                                                     "O O O O O ",
                                                     " O O O O O",
                                                     "O O O O O ",
                                                     " O O O O O",
                                                     "O O O O O ",
                                                     " O O O O O"  },

                                                   { "OO  OO  OO",
                                                     "OO  OO  OO",
                                                     "  OO  OO  ",
                                                     "  OO  OO  ",
                                                     "OO  OO  OO",
                                                     "OO  OO  OO",
                                                     "  OO  OO  ",
                                                     "  OO  OO  ",
                                                     "OO  OO  OO",
                                                     "OO  OO  OO"  },

                                                   { "OOOOO     ",
                                                     "OOOOO     ",
                                                     "OOOOO     ",
                                                     "OOOOO     ",
                                                     "OOOOO     ",
                                                     "     OOOOO",
                                                     "     OOOOO",
                                                     "     OOOOO",
                                                     "     OOOOO",
                                                     "     OOOOO"  },

                                                   { "O  O  O  O",
                                                     " O  O  O  ",
                                                     "  O  O  O ",
                                                     "O  O  O  O",
                                                     " O  O  O  ",
                                                     "  O  O  O ",
                                                     "O  O  O  O",
                                                     " O  O  O  ",
                                                     "  O  O  O ",
                                                     "O  O  O  O"  },

                                                   { "OOOOOOOOOO",
                                                     "O        O",
                                                     "O OOOOOO O",
                                                     "O O    O O",
                                                     "O O OO O O",
                                                     "O O OO O O",
                                                     "O O    O O",
                                                     "O OOOOOO O",
                                                     "O        O",
                                                     "OOOOOOOOOO"  } };

CHAR                  Pattern_[NUM_DATA][Y][X] = { { "          ",
                                                     "          ",
                                                     "          ",
                                                     "          ",
                                                     "          ",
                                                     " O O O O O",
                                                     "O O O O O ",
                                                     " O O O O O",
                                                     "O O O O O ",
                                                     " O O O O O"  },

                                                   { "OOO O    O",
                                                     " O  OOO OO",
                                                     "  O O OO O",
                                                     " OOO   O  ",
                                                     "OO  O  OOO",
                                                     " O OOO   O",
                                                     "O OO  O  O",
                                                     "   O OOO  ",
                                                     "OO OOO  O ",
                                                     " O  O  OOO"  },

                                                   { "OOOOO     ",
                                                     "O   O OOO ",
                                                     "O   O OOO ",
                                                     "O   O OOO ",
                                                     "OOOOO     ",
                                                     "     OOOOO",
                                                     " OOO O   O",
                                                     " OOO O   O",
                                                     " OOO O   O",
                                                     "     OOOOO"  },

                                                   { "O  OOOO  O",
                                                     "OO  OOOO  ",
                                                     "OOO  OOOO ",
                                                     "OOOO  OOOO",
                                                     " OOOO  OOO",
                                                     "  OOOO  OO",
                                                     "O  OOOO  O",
                                                     "OO  OOOO  ",
                                                     "OOO  OOOO ",
                                                     "OOOO  OOOO"  },

                                                   { "OOOOOOOOOO",
                                                     "O        O",
                                                     "O        O",
                                                     "O        O",
                                                     "O   OO   O",
                                                     "O   OO   O",
                                                     "O        O",
                                                     "O        O",
                                                     "O        O",
                                                     "OOOOOOOOOO"  } };

INT                   Input [NUM_DATA][N];
INT                   Input_[NUM_DATA][N];

FILE*                 f;


/******************************************************************************
                                    M A I N
 ******************************************************************************/


void main()
{
  NET Net;
  INT n;

  SAMPLE s;
  f=NULL;
  InitializeApplication_d(&s,NUM_DATA,X,Y,(CHAR***)Pattern,(CHAR***)Pattern_,f);
  f=s.f;

  InitializeRandoms();
  InitalizeApplication(&Net);
  GenerateNetwork(&Net,N);
  f=InitializeApplication(&Net, NUM_DATA, X, Y,Input,Input_,Pattern,Pattern_,NULL);
  CalculateWeights(&Net,Input,NUM_DATA);
   
  for (n=0; n<NUM_DATA; n++) {
    SimulateNet(&Net, Input[n],N,X,Y,f);
  }
 // for (n=0; n<NUM_DATA; n++) {
  //  SimulateNet(&Net, Input_[n],N,X,Y,f);
 // }
   
  f=FinalizeApplication(&Net,f);
}
