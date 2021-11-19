#include "bem3_aw_qd1.h"

int main(int argc,char **argv)
{
  AQD1 aq;
  
  read_aqd1(argc,argv,&aq); // read datafile
  print_aqd1(&aq);          // print data
  initialize_aqd1(&aq);     // memory allocation and initialize coefficients
  
  solve_bieq_aqd1(&aq);     // solve boundary integral equations
  
  dat_write_aqd1(argv[5],&aq);      // write datafile 
  finalize_aqd1(&aq);       //  memory free
  
  return 0;
}
