#ifndef PARTIAL_FLIPS_SORT
#define PARTIAL_FLIPS_SORT

#include <vector>

namespace SWQuiz {

    // k must be bounded between 1 and the size of input, if not k will be bounded to the closest lower or upper bound.
    void partial_flips_sort(
        std::vector<unsigned int>& input,
        std::vector<size_t>& k
    );
}

#endif