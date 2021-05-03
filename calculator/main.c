#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Stack.h"

void convert_infix_to_postfix(char *infix_exp, char *out);
void calculate(char *postfix, char *output);

int is_equal(char *s1, char *s2);
int is_operator(char *tok);
int is_operand(char *tok);

void eval(char *n1, char *n2, char *op, char *out);
int get_precedence(char *operator);

int main()
{
  char postfix[100];
  char res[100];
  // tokens must have space in between
  char exp[] = "2 * 3 / 1 + 10 - 22";

  printf("\nexpression: %s", exp);
  convert_infix_to_postfix(exp, postfix);

  printf("\npostfix: %s", postfix);

  calculate(postfix, res);
  printf("\nresult: %s\n", res);

  return 0;
}

void convert_infix_to_postfix(char *infix_exp, char *out)
{
  Stack stack = newStack();
  char *tok = strtok(infix_exp, " ");

  while (tok != NULL)
  {
    if (is_operand(tok))
    {
      strcat(out, tok);
      strcat(out, " ");
    }
    else if (is_operator(tok))
    {
      if (!(isEmpty(stack) || is_equal(peek(stack), "(") || get_precedence(tok) > get_precedence(peek(stack))))
      {
        while (!(isEmpty(stack) || is_equal(peek(stack), "(")))
        {
          strcat(out, pop(stack));
          strcat(out, " ");
        }
      }
      push(stack, tok);
    }
    else if (is_equal(tok, "("))
      push(stack, tok);
    else if (is_equal(tok, ")"))
    {
      while (!is_equal(peek(stack), "("))
      {
        strcat(out, pop(stack));
        strcat(out, " ");
      }

      pop(stack);
    }

    tok = strtok(NULL, " ");
  }

  while (!isEmpty(stack))
  {
    strcat(out, pop(stack));
    strcat(out, " ");
  }

  destroyStack(&stack);
}

void calculate(char *postfix, char *output)
{
  Stack stack = newStack();

  char *tok = strtok(postfix, " ");
  char *right_op, *left_op;

  while (tok != NULL)
  {
    if (is_operand(tok))
      push(stack, tok);
    else
    {
      char out[20];

      right_op = pop(stack);
      left_op = pop(stack);

      eval(left_op, right_op, tok, out);
      push(stack, out);
    }
    tok = strtok(NULL, " ");
  }

  strcpy(output, pop(stack));
  destroyStack(&stack);
}

int is_equal(char *s1, char *s2) { return !strcmp(s1, s2); }
int is_operator(char *tok) { return is_equal(tok, "+") || is_equal(tok, "-") || is_equal(tok, "*") || is_equal(tok, "/"); }
int is_operand(char *tok)
{
  for (int i = 0; tok[i] != '\0'; i++)
  {
    if (tok[i] < '0' || tok[i] > '9')
      return 0;
  }
  return 1;
}
void eval(char *n1, char *n2, char *op, char *out)
{
  int left_op = atoi(n1);
  int right_op = atoi(n2);
  int res;

  if (is_equal(op, "-"))
    res = left_op - right_op;
  else if (is_equal(op, "+"))
    res = left_op + right_op;
  else if (is_equal(op, "/"))
    res = left_op / right_op;
  else if (is_equal(op, "*"))
    res = left_op * right_op;

  sprintf(out, "%d", res);
}
int get_precedence(char *operator) { return is_equal(operator, "*") || is_equal(operator, "/"); }
