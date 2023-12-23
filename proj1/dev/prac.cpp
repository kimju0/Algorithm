#include <iostream>
#include <vector>
int main(){
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    for (int i = 0; i < v.size(); i++){
        std::cout << v[i] << std::endl;
    }
    return 0;
}