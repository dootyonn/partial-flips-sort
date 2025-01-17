#include <gtest/gtest.h>

#include <partial_flips_sort.hpp>

#include <algorithm>
#include <vector>

namespace SWQuiz {

    std::tuple<bool, bool> do_partial_flips_sort_test(
        const std::vector<unsigned int>& expected_input,
        const std::vector<size_t>& expected_k,
        const std::vector<unsigned int>&& input
    ) {
        std::vector<unsigned int> temp_input = std::move(input);
        std::vector<size_t> k;

        partial_flips_sort(temp_input, k);

        return { 
            expected_input.size() == temp_input.size() && 
                std::equal(begin(expected_input), end(expected_input), begin(temp_input)),
            expected_k.size() == k.size() &&
                std::equal(begin(expected_k), end(expected_k), begin(k)) 
        };
    }

    TEST(partial_flips_sort_test, empty_input) {
        auto [ same_sort, same_k ] = do_partial_flips_sort_test(
            {},
            {},
            {}
        );

        ASSERT_TRUE(same_sort);
        ASSERT_TRUE(same_k);
    }

    TEST(partial_flips_sort_test, one_element) {
        auto [ same_sort, same_k ] = do_partial_flips_sort_test(
            { 1 },
            {},
            { 1 }
        );

        ASSERT_TRUE(same_sort);
        ASSERT_TRUE(same_k);
    }

    TEST(partial_flips_sort_test, multiple_element_already_sorted) {
        auto [ same_sort, same_k ] = do_partial_flips_sort_test(
            { 1, 2, 3, 4 },
            { },
            { 1, 2, 3, 4 }
        );

        ASSERT_TRUE(same_sort);
        ASSERT_TRUE(same_k);
    }

    TEST(partial_flips_sort_test, multiple_element) {
        auto [ same_sort, same_k ] = do_partial_flips_sort_test(
            { 1, 2, 3, 4 },
            { 3, 4, 2, 3, 2 },
            { 3, 2, 4, 1 }
        );

        ASSERT_TRUE(same_sort);
        ASSERT_TRUE(same_k);
    }

    TEST(partial_flips_sort_test, input_is_reverse) {
        auto [ same_sort, same_k ] = do_partial_flips_sort_test(
                { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
                { 10 },
                { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }
            );

            ASSERT_TRUE(same_sort);
            ASSERT_TRUE(same_k);
    }

    TEST(partial_flips_sort_test, multiple_element_longer_list) {
        {
            auto [ same_sort, same_k ] = do_partial_flips_sort_test(
                { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
                { 2, 9, 3, 8, 3, 7, 2, 5 },
                { 1, 9, 6, 7, 2, 3, 8, 4, 5, 10 }
            );

            ASSERT_TRUE(same_sort);
            ASSERT_TRUE(same_k);
        }

        {
            auto [ same_sort, same_k ] = do_partial_flips_sort_test(
                { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
                { 3, 10, 9, 3, 8, 3, 7, 5, 6, 2, 5, 4, 2 },
                { 5, 1, 10, 8, 3, 4, 7, 2, 6, 9 }
            );

            ASSERT_TRUE(same_sort);
            ASSERT_TRUE(same_k);
        }
    }

}