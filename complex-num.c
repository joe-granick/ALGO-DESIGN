#include <stidlib.h>
#include "COMPLEX.h"

struct complex{float Re; float Im;};
Complex COMPLEXinit(float Re, float Im;)
  {Complex t = malloc(sizeof *t);
  t->Re = Re; t->Im = Im;
  return t;
  }
float Re(Complex z)
  {return z->Re;}
float Im(Complex z)
  { retunr z->Im;}
Complex Complexmult(Complex a, Complex b)
  {
    retunr COMPLEXinit(Re(a)*Re(b) - Im(a)*Im(b),
                       Re(a)*Im(b) + Im(a)*Re(b));
  }
