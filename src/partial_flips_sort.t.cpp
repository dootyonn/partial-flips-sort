#include <gtest/gtest.h>

#include <partial_flips_sort.hpp>
#include <partial_flip.hpp>

#include <ranges>
#include <algorithm>
#include <vector>

namespace SWQuiz {

    template <typename T>
    bool is_same_array(
        const std::vector<T>& l,
        const std::vector<T>& r
    ) {
        return l.size() == r.size() && std::equal(begin(l), end(l), begin(r));
    }

    std::tuple<bool, bool, bool> do_partial_flips_sort_test(
        const std::vector<unsigned int>& expected_input,
        const std::vector<size_t>& expected_k,
        const std::vector<unsigned int>& input
    ) {
        std::vector<unsigned int> temp_input = input;
        std::vector<size_t> k;

        partial_flips_sort(temp_input, k);

        bool is_same_sort = is_same_array(expected_input, temp_input);
        bool is_same_k = is_same_array(expected_k, k);

        for(size_t k : std::ranges::views::reverse(k)) {
            partial_flip(temp_input, k);
        }

        bool can_be_reconstructed = is_same_array(temp_input, input);

        return { is_same_sort, is_same_k, can_be_reconstructed };
    }

    TEST(partial_flips_sort_test, empty_input) {
        auto [ is_same_sort, is_same_k, can_be_reconstructed ] = do_partial_flips_sort_test(
            {},
            {},
            {}
        );

        ASSERT_TRUE(is_same_sort);
        ASSERT_TRUE(is_same_k);
        ASSERT_TRUE(can_be_reconstructed);
    }

    TEST(partial_flips_sort_test, one_element) {
        auto [ is_same_sort, is_same_k, can_be_reconstructed ] = do_partial_flips_sort_test(
            { 1 },
            {},
            { 1 }
        );

        ASSERT_TRUE(is_same_sort);
        ASSERT_TRUE(is_same_k);
        ASSERT_TRUE(can_be_reconstructed);
    }

    TEST(partial_flips_sort_test, multiple_element_already_sorted) {
        auto [ is_same_sort, is_same_k, can_be_reconstructed ] = do_partial_flips_sort_test(
            { 1, 2, 3, 4 },
            { },
            { 1, 2, 3, 4 }
        );

        ASSERT_TRUE(is_same_sort);
        ASSERT_TRUE(is_same_k);
        ASSERT_TRUE(can_be_reconstructed);
    }

    TEST(partial_flips_sort_test, multiple_element) {
        auto [ is_same_sort, is_same_k, can_be_reconstructed ] = do_partial_flips_sort_test(
            { 1, 2, 3, 4 },
            { 3, 4, 2, 3, 2 },
            { 3, 2, 4, 1 }
        );

        ASSERT_TRUE(is_same_sort);
        ASSERT_TRUE(is_same_k);
        ASSERT_TRUE(can_be_reconstructed);
    }

    TEST(partial_flips_sort_test, input_is_reverse) {
        auto [ is_same_sort, is_same_k, can_be_reconstructed ] = do_partial_flips_sort_test(
            { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
            { 10 },
            { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }
        );

        ASSERT_TRUE(is_same_sort);
        ASSERT_TRUE(is_same_k);
        ASSERT_TRUE(can_be_reconstructed);
    }

    TEST(partial_flips_sort_test, multiple_element_longer_list) {
        {
            auto [ is_same_sort, is_same_k, can_be_reconstructed ] = do_partial_flips_sort_test(
                { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
                { 2, 9, 3, 8, 3, 7, 2, 5 },
                { 1, 9, 6, 7, 2, 3, 8, 4, 5, 10 }
            );

            ASSERT_TRUE(is_same_sort);
            ASSERT_TRUE(is_same_k);
            ASSERT_TRUE(can_be_reconstructed);
        }

        {
            auto [ is_same_sort, is_same_k, can_be_reconstructed ] = do_partial_flips_sort_test(
                { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
                { 3, 10, 9, 3, 8, 3, 7, 5, 6, 2, 5, 4, 2 },
                { 5, 1, 10, 8, 3, 4, 7, 2, 6, 9 }
            );

            ASSERT_TRUE(is_same_sort);
            ASSERT_TRUE(is_same_k);
            ASSERT_TRUE(can_be_reconstructed);
        }
    }

}