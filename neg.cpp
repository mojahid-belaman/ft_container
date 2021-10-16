#include <iomanip>
#include <iostream>
#include <vector>
#include <iomanip>

void plusMinus(std::vector<int> arr) {
    double pos_count = 0;
    double neg_count = 0;
    double zero_count = 0;
    int nb = 0;

    for (size_t i = 0; i < arr.size(); i++) {
        nb++;
        if (arr[i] < 0)
            neg_count++;
        if (arr[i] == 0)
            zero_count++;
        if (arr[i] > 0)
            pos_count++;
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(6) << pos_count / nb << std::endl;
    std::cout << std::setprecision(6) << neg_count / nb << std::endl;
    std::cout << std::setprecision(6) << zero_count / nb << std::endl;
    
}

int main()
{
    //1 2 3 -1 -2 -3 0 0
    std::vector<int> arr;
    // // arr.push_back(-4);
    // // arr.push_back(3);
    // // arr.push_back(-9);
    // // arr.push_back(0);
    // // arr.push_back(4);
    // // arr.push_back(1);
    // arr.push_back(1);
    // // arr.push_back(2);
    // // arr.push_back(3);
    // // arr.push_back(-1);
    // // arr.push_back(-2);
    // // arr.push_back(-3);
    // // arr.push_back(0);
    // //arr.push_back(0);
    
    plusMinus(arr);
}