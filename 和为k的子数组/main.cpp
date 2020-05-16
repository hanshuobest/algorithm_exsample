#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int subarraySum(vector<int> &nums, int k)
{

    int size = nums.size();
    int sum = 0, res = 0;
    unordered_map<int, int> map;
    map[0] = 1;
    for (int i = 0; i < size; i++)
    {
        sum += nums[i];
        res += map[sum - k];
        map[sum]++;
    }

    return res;
}

int main()
{
    std::vector<int> a = {1 , 1 , 1};
    int num = subarraySum(a , 2);
    std::cout << num << std::endl;

    return 0;
}