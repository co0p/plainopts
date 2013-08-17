
#include <stdio.h>
#include <iostream>

#include "minunit.h"
#include "../src/plainopts.h"

using namespace plainopts;
int tests_run = 0;
 

/*******************************************************************************
* testcases for flag class
*/
static const char *test_flag_constructor() {
  Flag flag('v');
  mu_assert("help should be empty", flag.get_help() == "");

  Flag flag2('v', "verbose");
  mu_assert("help should be empty", flag2.get_help() == "");

  Flag flag3("verbose");
  mu_assert("help should be empty", flag3.get_help() == "");  
  return 0;
}

static const char *test_flag_help() {
  Flag flag('v');
  flag.set_help("string text");
  mu_assert("help text should not be empty", flag.get_help() == "string text");

  flag.set_help("string text2");
  mu_assert("help text should have changed", flag.get_help() == "string text2");
  return 0;
}


/*******************************************************************************
* testcases for option class
*/
static const char *test_option_getvalue() {
  Option option('o');
  option.set_parameter("abc");
  mu_assert("parameter should be abc", option.get_value<string>() == "abc");
  
  option.set_parameter("123");
  mu_assert("parameter should be int 123", option.get_value<int>() == 123);
  
  option.set_parameter("123.5");
  mu_assert("parameter should be float 123.5", option.get_value<float>() == 123.5);
  
  return 0;
}




/*******************************************************************************
* testrunner
*/
static char * all_tests() {
  mu_run_test(test_flag_constructor);
  mu_run_test(test_flag_help);
  mu_run_test(test_option_getvalue);
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