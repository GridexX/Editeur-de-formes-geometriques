#include <experimental/filesystem>
//g++ -c main.cpp -std=c++17
//g++ -o main main.o -lstdc++fs
namespace fs = std::experimental::filesystem;


int main() {

    fs::create_directories("./save/");

    return 0;
}