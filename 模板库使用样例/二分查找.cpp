#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void test_bound() {
    // lower_bound(first, last, value) 返回第一个大于等于val的位置
    // upper_bound(first, last, value) 返回第一个大于val的位置
    // 如果value在范围内，那么 [lower_bound, upper_bound) 区间等于value
    // 如果value不在范围内，那么 lower_bound=upper_bound
    vector<int> vec = {1, 1, 2, 2, 4, 4};

    int val = 2;
    auto it1 = lower_bound(vec.begin(), vec.end(), val);
    auto it2 = upper_bound(vec.begin(), vec.end(), val);
    assert(it1 - vec.begin() == 2);
    assert(it2 - vec.begin() == 4);
    
    val = 0;
    it1 = lower_bound(vec.begin(), vec.end(), val);
    it2 = upper_bound(vec.begin(), vec.end(), val);
    assert(it1 - vec.begin() == 0);
    assert(it2 - vec.begin() == 0);

    val = 5;
    it1 = lower_bound(vec.begin(), vec.end(), val);
    it2 = upper_bound(vec.begin(), vec.end(), val);
    assert(it1 == vec.end());
    assert(it2 == vec.end());
}


void test_range() {
    // equal_range(first, last, value) 返回一个 pair，分别对应lower_bound和upper_bound的返回结果
    vector<int> vec = {1, 1, 2, 2, 4, 4};

    int val = 2;
    pair<vector<int>::iterator, vector<int>::iterator> bounds = equal_range(vec.begin(), vec.end(), val);
    assert(bounds.first - vec.begin() == 2);
    assert(bounds.second - vec.begin() == 4);

    val = 0;
    bounds = equal_range(vec.begin(), vec.end(), val);
    assert(bounds.first - vec.begin() == 0);
    assert(bounds.second - vec.begin() == 0);

    val = 5;
    bounds = equal_range(vec.begin(), vec.end(), val);
    assert(bounds.first == vec.end());
    assert(bounds.second == vec.end());
}


void test_binary() {
    // binary_search(first, last, value) 判断value是否在范围内
    vector<int> vec = {1, 1, 2, 2, 4, 4};

    bool flag = binary_search(vec.begin(), vec.end(), 1);
    assert(flag == true);

    flag = binary_search(vec.begin(), vec.end(), 3);
    assert(flag == false);
}


int main() {
    test_bound();
    test_range();
    test_binary();
}
