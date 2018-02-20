#include <random>
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {

  if(argc < 5) {
    std::cout << "Usage: [min] [max] [amount] [filename]" << std::endl;
    return 1;
  }

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(atoi(argv[1]), atoi(argv[2]));

  std::ofstream outfile (argv[4], std::ofstream::binary);

  outfile << atoi(argv[3]) << std::endl;
  for (int n=0; n<atoi(argv[3]); ++n) {
    outfile << dis(gen) << std::endl;
  }

  outfile.close();

  return 0;
}