#ifndef __POSTFIX_EVALUATOR_H__
#define __POSTFIX_EVALUATOR_H__

  /**
   * @brief: Check if symbol is an operand.
   */
  static int
  is_operand(int operand);

  /**
   * @brief: Check if symbol is an operator.
   */
  static int
  is_operator(int operator);

  /**
   * @brief: Calculate two numbers based on the operator.
   */
  static int
  calculate(int a, int b, int operator);

  /**
   * @brief Evaluate a postfix expression.
   */
  int
  postfix_evaluate(const char* expression);

#endif /* __POSTFIX_EVALUATOR_H__ */
