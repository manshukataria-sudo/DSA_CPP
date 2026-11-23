#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/product-of-the-last-k-numbers
/* 

TC = O(1) for any operation
SC = O(4 * 1e4) for storing the prefix products of nums

 */
class ProductOfNumbers {
   public:
    vector<int> array;
    vector<int> products;
    int i = 0;
    ProductOfNumbers() { products.resize(4 * 1e4); }

    void add(int num) {
        if (num == 0) {
            i = 0;
        } else {
            if (i == 0) {
                products[i] = num;
            } else {
                products[i] = products[i - 1] * num;
            }
            i++;
        }
        array.push_back(num);
    }

    int getProduct(int k) {
        if (k > i) {
            return 0;
        }
        return products[i - 1] / (products[i - k] / array[array.size() - k]);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */