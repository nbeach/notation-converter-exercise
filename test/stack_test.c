#include <stdlib.h>
#include <stdbool.h>
#include <check.h>

#include "../src/stack.h"

START_TEST (char_stack_push_adds_characters_to_top_of_stack)
{
  char stack[5] = "ab";
  char_stack_push(stack, 'c');
  ck_assert_str_eq("abc", stack);
}
END_TEST

START_TEST (char_stack_push_adds_terminator_past_end_of_stack)
{
  char stack[5] = "ab";
  char_stack_push(stack, 'c');
  ck_assert_int_eq('\0', stack[3]);
}
END_TEST

START_TEST (char_stack_peek_returns_the_value_on_top_of_the_stack)
{
  char stack[5] = "ab";
  ck_assert_int_eq('b', char_stack_peek(stack));
}
END_TEST

START_TEST (char_stack_peek_does_not_modify_the_stack)
{
  char stack[5] = "ab";
  char_stack_peek(stack);
  ck_assert_str_eq("ab", stack);
}
END_TEST

START_TEST (char_stack_pop_returns_the_value_on_top_of_the_stack)
{
  char stack[5] = "ab";
  ck_assert_int_eq('b', char_stack_pop(stack));
}
END_TEST

START_TEST (char_stack_pop_removes_the_value_on_top_of_the_stack)
{
  char stack[5] = "ab";
  char_stack_pop(stack);
  ck_assert_int_eq('\0', stack[1]);
}
END_TEST

START_TEST (char_stack_pop_returns_null_when_nothing_on_the_stack)
{
  char stack[5] = "a";
  char_stack_pop(stack);
  char item = char_stack_pop(stack);
  ck_assert_int_eq('\0', item);
}
END_TEST

Suite * stack_suite() {
  Suite *s = suite_create("stack_test");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, char_stack_push_adds_characters_to_top_of_stack);
  tcase_add_test(tc_core, char_stack_push_adds_terminator_past_end_of_stack);

  tcase_add_test(tc_core, char_stack_peek_returns_the_value_on_top_of_the_stack);
  tcase_add_test(tc_core, char_stack_peek_does_not_modify_the_stack);

  tcase_add_test(tc_core, char_stack_pop_returns_the_value_on_top_of_the_stack);
  tcase_add_test(tc_core, char_stack_pop_removes_the_value_on_top_of_the_stack);
  tcase_add_test(tc_core, char_stack_pop_returns_null_when_nothing_on_the_stack);

  suite_add_tcase(s, tc_core);
  return s;
}
