#include "asd.h"

SAMPLE* InitializeApplication_d(SAMPLE*s,int nd,int x,int y,CHAR*** Pattern,CHAR*** Pattern_,FILE*f)
{
     INT n, i, j;

    s->Input=  (INT**) calloc(nd, sizeof (INT*));
    s->Input_=  (INT**) calloc(nd, sizeof (INT*));

    for (n = 0; n < nd; n++) {
        s->Input[n]=  (INT*) calloc(x*y, sizeof (INT));
        s->Input_[n]=  (INT*) calloc(x*y, sizeof (INT));

        for (i = 0; i < y; i++) {
            for (j = 0; j < x; j++) {
                s->Input [n][i * x + j] = BIPOLAR(Pattern [n][i][j] == 'O');
                s->Input_[n][i * x + j] = BIPOLAR(Pattern_[n][i][j] == 'O');
            }
        }
    }

    if(f==NULL){
    s->f = fopen("HOPFIELD_s.txt", "w");
    }else{
     s->f=f;
    }
    return s;
}
