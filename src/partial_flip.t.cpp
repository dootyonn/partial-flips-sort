#include <gtest/gtest.h>
#include <partial_flip.hpp>

#include <vector>
#include <algorithm>

namespace SWQuiz {

    bool do_test_partial_flip(
        const std::vector<unsigned int>& expected,
        const std::vector<unsigned int>& input,
        int k
    ) {
        std::vector<unsigned int> temp = input;
        partial_flip(temp, k);

        return std::equal(begin(temp), end(temp), begin(expected));
    }

    TEST(partial_flip_test, empty_input) {
        ASSERT_TRUE(do_test_partial_flip({}, {}, 0));
        ASSERT_TRUE(do_test_partial_flip({}, {}, 1));
    }

    TEST(partial_flip_test, one_element_input) {
        ASSERT_TRUE(do_test_partial_flip({ 2 }, { 2 }, 0)); // out of lower bound
        ASSERT_TRUE(do_test_partial_flip({ 2 }, { 2 }, 1));
        ASSERT_TRUE(do_test_partial_flip({ 2 }, { 2 }, 2)); // out of upper bound
        ASSERT_TRUE(do_test_partial_flip({ 2 }, { 2 }, 3)); // out of upper bound
    }

    TEST(partial_flip_test, non_empty_input) {
        std::vector<unsigned int> values = { 3, 2, 4, 1 };

        ASSERT_TRUE(do_test_partial_flip({ 3, 2, 4, 1 }, values, 0)); // out of lower bound
        ASSERT_TRUE(do_test_partial_flip({ 3, 2, 4, 1 }, values, 1));
        ASSERT_TRUE(do_test_partial_flip({ 2, 3, 4, 1 }, values, 2));
        ASSERT_TRUE(do_test_partial_flip({ 4, 2, 3, 1 }, values, 3));
        ASSERT_TRUE(do_test_partial_flip({ 1, 4, 2, 3 }, values, 4));
        ASSERT_TRUE(do_test_partial_flip({ 1, 4, 2, 3 }, values, 5)); // out of upper bound
        ASSERT_TRUE(do_test_partial_flip({ 1, 4, 2, 3 }, values, 6)); // out of upper bound
    }

}