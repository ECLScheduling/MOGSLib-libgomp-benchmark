#include <iostream>
#include <cstdlib>
#include <random>

using norm_t = std::normal_distribution<>;
using exp_t = std::exponential_distribution<>;

template<typename distribution_t>
void generate(int n, bool round, distribution_t dist) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::cout << n << std::endl;
    if (round)
        for (auto i = 0; i < n; ++i)
            std::cout << std::round(dist(gen)) << std::endl;
    else
        for (auto i = 0; i < n; ++i)
            std::cout << dist(gen) << std::endl;
}

int main(int argc, const char *argv[]) {
    int n, dist, round;

    if (argc < 4) {
        std::cout << "Usage: " << argv[0] << " N DIST ROUND" << std::endl;
        std::cout << "  N\t(int)\tAmount of numbers to generate" << std::endl;
        std::cout << "  ROUND\t(bool)\tRound to closest integer" << std::endl;
        std::cout << "  DIST\t(int)\tThe random distribution type" << std::endl;
        std::cout << "  \t\t\t0 - Exponential" << std::endl;
        std::cout << "  \t\t\t1 - Normal" << std::endl;
        std::cout << "  ARGS\t(int)\tThe distribution arguments" << std::endl;
        std::cout << "  \t\t\tExponential: (double) alpha" << std::endl;
        std::cout << "  \t\t\tNormal: (double) mean, (double) stddev"
            << std::endl << std::endl;
        std::cout << "Output: The workload file contents for the benchmark"
            << std::endl;
        return 1;
    }

    n = std::atoi(argv[1]);
    round = std::atoi(argv[2]);
    dist = std::atoi(argv[3]);
    if (dist == 0)
        generate(n, round, exp_t(std::atof(argv[4])));
    else
        generate(n, round, norm_t(std::atof(argv[4]), std::atof(argv[5])));
}
