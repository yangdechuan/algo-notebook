#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
using namespace std;

bool comp (int i,int j) {
    return i > j;
}

int main () {
    int a[8] = {32, 71, 12, 45, 26, 80, 53, 33};
    sort(a, a + 8);  // 默认升序
    for(int i : a){
      cout << i << " ";
    }
    cout << endl;

    vector<int> vec = {2, 4, 9, 6, 5};
    sort(vec.begin(), vec.end(), comp);  // 降序
    for(int i: vec){
      cout << i << " ";
    }
    cout << endl;
    return 0;
    /*
    输出结果：
    12 26 32 33 45 53 71 80 
    9 6 5 4 2 
     */
}