#include <partial_flips_sort.hpp>

#include <optional>
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace SWQuiz;

enum return_code {
    SUCCESS = 0,
    ERROR = 1,
};

template<typename T>
void print_array(std::string_view name, const std::vector<T>& input) {
    std::cout << name << ": [ ";
    for (int i = 0; i < input.size(); i++) {
        std::cout << input[i] << ' ';
    }
    std::cout << "]" << std::endl;
}

void print_help(std::optional<std::string> error) {
    std::cout << "Usage: quizsort [INTEGER]...\n"
              << "Sort an array using partial flips." << std::endl;

    if (error.has_value()) {
        std::cerr << "\nerror: " << error.value() << std::endl;
    }
}

void print_result(
    const std::vector<unsigned int>& values,
    const std::vector<size_t>& k
) {
    print_array("sorted array", values);
    print_array("k values", k);
}

bool is_valid_random_sequence(const std::vector<unsigned int> values) {
    for (unsigned int i = 1; i <= values.size(); ++i) {
        auto it = find(begin(values), end(values), i);
        if (it == end(values)) {
            return false;
        }
    }

    return true;
}

int main(int argc, char** argv) {
    
    if (argc < 2) {
        print_help("No arguments specified.");
        return ERROR;
    }

    std::vector<unsigned int> inputs;
    inputs.reserve(argc - 1);

    for (size_t i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (value <= 0) {
            std::stringstream ss;
            ss << "'" << argv[i] << "' must be a non-null positive integer." << std::endl;
            print_help(ss.str());
            return ERROR;
        }

        inputs.push_back(value);
    }

    if (!is_valid_random_sequence(inputs)) {
        print_help("Input array must have all integer values between 1 and length of the array only once");
        return ERROR;
    }

    std::vector<size_t> k;
    partial_flips_sort(inputs, k);

    print_result(inputs, k);

    return SUCCESS;
}