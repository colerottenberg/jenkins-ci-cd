#include "unity_internals.h"
#include <stdbool.h>
#include <stdlib.h>
#include <unity.h>

void setUp(void) {}
void tearDown(void) {}

void test_always_pass(void) { TEST_ASSERT_TRUE(1); }
void test_always_fail(void) { TEST_ASSERT_TRUE(0); }

int main() {
  UNITY_BEGIN();
  RUN_TEST(test_always_pass);
  RUN_TEST(test_always_fail);
  return UNITY_END();
}
