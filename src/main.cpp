#include <cassert>
#include "medianOfTwoSortedArrays.hpp"

using namespace std;
int main(int argc, char *argv[]) {
    vector<int> v1{1, 3};
    vector<int> v2{2};
    assert(findMedianSortedArrays(v1, v2) == 2); 
    return 0;
}