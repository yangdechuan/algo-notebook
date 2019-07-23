#include<algorithm>
#include<vector>
#include<iostream>


using namespace std;

int main(){
    // 1. binary_search返回bool
    vector<int> a = {2, 2, 4, 4, 6, 6, 8, 9, 10, 10};
    // 是否含有5
    if(binary_search(a.begin(), a.end(), 6)){
        cout << "Found!" << endl;
    }

    // 2. equal_range()返回pair<>
    pair<vector<int>::iterator,vector<int>::iterator> bounds = equal_range(a.begin(), a.end(), 4);
    cout << "bounds at positions " << (bounds.first - a.begin());
    cout << " and " << (bounds.second - a.begin()) << '\n';

    // 3. lower_bound()和upper_bound()返回iterator
    int myints[] = {10,20,30,30,20,10,10,20};
    vector<int> vec(myints, myints + 8);
    sort(vec.begin(), vec.end());   
    vector<int>::iterator low,up;
    // 返回第一个大于等于20的位置
    low = lower_bound (vec.begin(), vec.end(), 20);
    // 返回第一个大于20的位置
    up = upper_bound (vec.begin(), vec.end(), 20);

    cout << "lower_bound at position " << (low- vec.begin()) << '\n';
    cout << "upper_bound at position " << (up - vec.begin()) << '\n';
    // lower_bound at position 3
    // upper_bound at position 6
}