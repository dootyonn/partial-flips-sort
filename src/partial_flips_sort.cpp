#include <partial_flips_sort.hpp>

#include <partial_flip.hpp>

#include <algorithm>
#include <vector>
#include <iostream>

namespace SWQuiz {

    size_t find_max_index(std::vector<unsigned int>::const_iterator start, size_t k) {
        auto it = std::max_element(start, start + k);
        return (it - start) + 1;
    }

    void partial_flips_sort(
        std::vector<unsigned int>& input,
        std::vector<size_t>& k_values
    ) {

        for (int k = input.size(); k > 0; --k) {
            size_t max_index = find_max_index(begin(input), k);

            if (max_index != k) {
                if (max_index > 1) {
                    partial_flip(input, max_index);
                    k_values.push_back(max_index);
                }

                partial_flip(input, k);
                k_values.push_back(k);
            }
        }
    }

    // size_t find_max_index(std::vector<unsigned int>::const_iterator start, size_t min_k, size_t max_k) {
    //     auto it = std::max_element(start + min_k, start + max_k);
    //     return (it - start) + 1;
    // }

    // size_t find_min_index(std::vector<unsigned int>::const_iterator start, size_t min_k, size_t max_k) {
    //     auto it = std::min_element(start + min_k, start + max_k);
    //     return (it - start);
    // }

    // void partial_flips_sort_max(
    //     std::vector<unsigned int>& input,
    //     std::vector<size_t>& k_values
    // ) {
    //     size_t k = input.size();

    //     while (k > 1) {
    //         size_t max_index = find_max_index(begin(input), 0, k);

    //         if (max_index != k) {
    //             if (max_index > 1) {
    //                 partial_flip(input, max_index);
    //                 k_values.push_back(max_index);
    //             }

    //             partial_flip(input, k);
    //             k_values.push_back(k);
    //         }

    //         --k;
    //     }
    // }

    // void partial_flips_sort_minmax(
    //     std::vector<unsigned int>& input,
    //     std::vector<size_t>& k_values
    // ) {
    //     size_t k_min = 0; // 0 based
    //     size_t k_max = input.size(); // 1 based

    //     while (k_max > k_min) {
    //         size_t min_index = find_min_index(begin(input), k_min, k_max);

    //         if (min_index != k_min) {
    //             partial_flip(input, min_index + 1);
    //             k_values.push_back(min_index + 1);
    //         }

    //         ++k_min;

    //         if (k_min < k_max) {
    //             size_t max_index = find_max_index(begin(input), k_min, k_max);

    //             if (max_index != k_max) {
    //                 if (max_index > k_min) {
    //                     partial_flip(input, max_index);
    //                     k_values.push_back(max_index);
    //                 }

    //                 partial_flip(input, k_max);
    //                 k_values.push_back(k_max);

    //                 if (k_max > k_min) {
    //                     partial_flip(input, k_max - 1);
    //                     k_values.push_back(k_max - 1);
    //                 }
    //             }
    //         }

    //         --k_max;
    //     }
    // }

}
