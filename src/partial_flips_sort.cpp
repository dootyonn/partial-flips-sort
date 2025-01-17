#include <partial_flips_sort.hpp>

#include <partial_flip.hpp>

#include <algorithm>
#include <vector>
#include <iostream>

namespace SWQuiz {

    size_t find_k_index(std::vector<unsigned int>::const_iterator start, unsigned int k) {
        auto it = find(start, start + k, k);
        return (it - start) + 1;
    }

    void partial_flips_sort(
        std::vector<unsigned int>& input,
        std::vector<size_t>& k_values
    ) {
        for (unsigned int k = input.size(); k > 0; --k) {
            size_t index = find_k_index(begin(input), k);

            if (index == k) {
                continue;
            }

            if (index > 1) {
                partial_flip(input, index);
                k_values.push_back(index);
            }

            partial_flip(input, k);
            k_values.push_back(k);
        }
    }

}
