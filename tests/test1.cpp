#include "gtest/gtest.h"
#include <cmath>

namespace {
    // The test case name and the test name.
    // You should not use underscore (_) in the names.

    TEST(ExampleTestCase, ExampleTest) {
        EXPECT_EQ(1, 1);
    }

    TEST(ExampleTestCase, SinusTest) {
        EXPECT_FLOAT_EQ(1.0, sin(M_PI_2));
    }

    TEST(ExampleTestCase, BoolTest) {
        EXPECT_TRUE(true);
        EXPECT_FALSE(false);
    }
}
