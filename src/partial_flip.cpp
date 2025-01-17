#include <partial_flip.hpp>
#include <math.h>

namespace SWQuiz {

    void partial_flip(std::vector<unsigned int>& values, size_t k) {
        k = std::max(1ul, std::min(k, values.size()));
        --k;

        for (size_t i = 0; k > i; ++i, --k) {
            int temp = values[i];
            values[i] = values[k];
            values[k] = temp;
        }
    }

}