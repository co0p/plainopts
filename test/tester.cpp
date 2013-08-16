
#include <stdio.h>


#include "minunit.h"
#include "../src/plainopts.h"

using namespace plainopts;
int tests_run = 0;


/**
* testcases for flag class
*/
static char *test_flag_constructor() {
  Flag flag("v");
  mu_assert("should not be mandatory", flag.is_mandatory() == false);
  mu_assert("should be empty", flag.get_help() == "");
  return 0;
}

static char *test_flag_mandatory() {
  Flag flag("v");
  flag.set_mandatory(true);
  mu_assert("should mandatory", flag.is_mandatory() == true);

  flag.set_mandatory(false);
  mu_assert("should not mandatory", flag.is_mandatory() == false);

  return 0;
}


static char * all_tests() {
  mu_run_test(test_flag_constructor);
  mu_run_test(test_flag_mandatory);
  return 0;
}

int main(int argc, char **argv) {
  char *result = all_tests();
  if (result != 0) {
    printf("%s\n", result);
  } else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);
  return result != 0;
}