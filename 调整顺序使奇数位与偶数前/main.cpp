#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int head = 0;
        int tail = nums.size() - 1;

        while(head < tail)
        {
            while(head < tail && (nums[head] & 0x1) != 0)
            {
                head++;
                std::cout << "head: " << head << std::endl;
            }
            while(head < tail && (nums[tail] & 0x1) == 0 )
            {
                tail--;
                std::cout << "tail: " << tail << std::endl;
            }

            if (head < tail)
            {
                int tmp = nums[head];
                nums[head] = nums[tail];
                nums[tail] = tmp;
            }
        }
        return nums;

    }
};
int main()
{
    vector<int> vec = {1 , 2 , 3 , 4};
    for(auto v : vec)
    {
        std::cout << v << std::endl;
    }

    Solution s;
    std::vector<int> res = s.exchange(vec);
    for (auto v : res) {
        std::cout << v << std::endl;

    }
    return 0;
}
