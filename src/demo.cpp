#include <stdio.h>

#include "../src/plainopts.h"

using namespace plainopts;

int main(int argc, char const *argv[]) {
  
  printf("#parameters passed: %d\n", argc);

  Plainopts popts;

  /* declare some flags */
  popts.add_flag('v', "verbose");
  popts.set_help("verbose", "some help");
  popts.set_help('v', "more help");
  
  /* declare some options */
  


  /* declare some arguments */
  

  /* parse */


  /* react */

  return 0;
}