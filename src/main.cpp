#include <partial_flips_sort.hpp>

#include <iostream>
#include <vector>

using namespace SWQuiz;

template<typename T>
void print(std::string_view name, const std::vector<T>& input) {
    std::cout << name << ": [ ";
    for (int i = 0; i < input.size(); i++) {
        std::cout << input[i] << ' ';
    }
    std::cout << "]" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "Start..." << std::endl;

    std::vector<unsigned int> input = {};
    std::vector<size_t> k;
    partial_flips_sort(input, k);
}