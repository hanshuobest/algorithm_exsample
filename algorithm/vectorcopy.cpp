/************************************************************************************************
@filename    :vectorcopy.cpp
@brief       :vector复制
@time        :2021/01/19 23:05:09
@author      :hscoder
@versions    :1.0
@email       :hscoder@163.com
@usage       :经过测试方法1速度更快
***********************************************************************************************/

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <chrono>
#include <memory>

class Timer
{
    using Clock = std::chrono::high_resolution_clock;

public:
    void start()
    {
        start_ = Clock::now();
    }

    void end()
    {
        end_ = Clock::now();
    }

    double cost_time()
    {
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_ - start_);
        return duration.count();
    }

private:
    Clock::time_point start_, end_;
};

void method_1(const std::vector<int> &vec1)
{
    std::vector<int> vec(vec1);
    // for (auto v : vec)
    // {
    //     std::cout << v << std::endl;
    // }
}

void method_2(const std::vector<int> &vec2)
{
    std::vector<int> vec;
    std::copy(vec2.begin(), vec2.end(), std::back_inserter(vec));
    // for (auto v : vec)
    // {
    //     std::cout << v << std::endl;
    // }
}

int main(int argc, char **argv)
{
    std::vector<int> vec1 = {1, 2, 3};

    std::shared_ptr<Timer> timer_obj = std::make_shared<Timer>();
    timer_obj->start();
    for (int i = 0; i < 1000000; ++i)
    {
        method_1(vec1);
    }
    timer_obj->end();
    std::cout << "method 1 cost time: " << timer_obj->cost_time() << std::endl;

    std::cout << "--------------------------------------\n";
    timer_obj->start();
    for (int i = 0; i < 1000000; ++i)
    {
        method_2(vec1);
    }
    timer_obj->end();
    std::cout << "method 2 cost time: " << timer_obj->cost_time() << std::endl;

    return 1;
}