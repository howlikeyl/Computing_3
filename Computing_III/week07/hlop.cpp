// #include <iostream>
// #include <vector>
// using namespace std;
// int main(){
//     vector<int> num = {1, 2, 3, 4, 5, 6, 7};
//     for(auto i: num){
//         cout << i << " ";
//     }
//     cout << endl;
//     // iterator
//     vector<int>:: iterator it;
//     for(it = num.begin(); it != num.end(); it++){
//         cout << *it << " ";
//     }
//     cout << endl;
//     it = num.begin();
//     it++;
//     cout << *it << endl;
//     cout << it[4] << endl;
//     cout << *(it + 1) << endl;
//     // reverse iterator
//     vector<int>:: reverse_iterator its;
//     for(its = num.rbegin(); its != num.rend(); its++){
//         cout << *its << " ";
//     }
//     return 0;
// }
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string word;
    cout << "Enter a word: ";
    getline(cin, word);
    cout << "Original word: " << word << endl;
    reverse(word.begin(), word.end());
    cout << "Reversed word: " << word << endl;
    sort(word.begin(), word.end());
    cout << "Sorted word: " << word << endl;
    return 0;
}
