#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/stack.h"
#include "evaluator.h"

/**
 * @brief: Check if symbol is an operand.
 */
static int
is_operand(int operand)
{
  return (
    operand > 47 &&
    operand < 58
  );
}

/**
 * @brief: Check if symbol is an operator.
 */
static int
is_operator(int operator)
{
  return (
    operator == 42 || /* multiplication */
    operator == 43 || /* sum */
    operator == 45 || /* subtraction */
    operator == 47    /* division */
  );
}

/**
 * @brief: Calculate two numbers based on the operator.
 */
static int
calculate(int a, int b, int operator)
{
  char c_operator = (char) operator;

  if (c_operator == '+')
    return (a + b);

  if (c_operator == '-')
    return (a - b);

  if (c_operator == '*')
    return (a * b);

  if (c_operator == '/')
    return (a / b);
}

/**
 * @brief Evaluate a postfix expression.
 */
int
postfix_evaluate(const char* expression)
{
  stack_t operands = stack_create(strlen(expression));

  /* For each item in the expression, from left to right */
  for (int i = 0; expression[i]; i++) {

    /* If an operand, push it into the operands stack. */
    if (is_operand(expression[i]))
      stack_push(&operands, expression[i] - '0');

    /* If an operator, pop two operands from stack,
     * calculate the operation and then push the result
     * into the operands stack again.
     */
    else if (is_operator(expression[i])) {
      int b = stack_pop(&operands);
      int a = stack_pop(&operands);
      stack_push(&operands, calculate(a, b, expression[i]));
    }
  }

  /* The final expression result is in the stack yet. */
  int final_result = stack_pop(&operands);

  stack_destroy(&operands);
  return final_result;
}
