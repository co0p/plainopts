#include <stdio.h>
#include <iostream>

#include "../src/plainopts.h"

using namespace plainopts;

int main(int argc, char *argv[]) {
  
  Plainopts popts;

  /* declare some flags */
  popts.add_flag('v', "verbose");
  popts.set_help("verbose", "some help");
  popts.set_help('v', "more help");
  
  /* declare some options */
  

  /* declare some arguments */
  

  /* parse */
  switch (popts.parse(argc, argv)) {
    case plainopts::ERROR:
      cout << "error: " << popts.last_error() << endl;
      return 0;
    case plainopts::MISSING:
      cout << "missing: " << popts.missing_entry() << endl;
      return 0;
    case plainopts::HELP:
      cout << popts.help() << endl;
      return 0;
    default: 
      cout << "all good." << endl;
  }


  /* react */

  return 0;
}