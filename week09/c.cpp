// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// using namespace std;

// int main() {  
//   // Generate a random number between 0 and 100
//   srand(time(0));
//   int randomNum =  70 + rand() % 31;
  
//   cout << randomNum;
//   return 0;
// }
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> arr = {5, 2, 9, 1, 5, 6};

    std::sort(arr.begin(), arr.end(), std::greater<int>());

    std::cout << "Sorted array in descending order: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

