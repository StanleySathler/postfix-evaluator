#include <stdio.h>
#include "../lib/assert.h"
#include "../src/evaluator.h"

void
test_evaluate()
{
  int actual;

  actual = postfix_evaluate("26+9-");
  assert_int(-1, actual, "Expression without spaces and same priorities");

  actual = postfix_evaluate("264*+8-");
  assert_int(18, actual, "Expression without spaces and different priorities");

  actual = postfix_evaluate("284/+");
  assert_int(4, actual, "Expression without spaces and division");
}

int
main()
{
  test_evaluate();
}
