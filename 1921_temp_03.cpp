// ELIMINATE MAXIMUN NUMBER OF MONSTERS
// n == dist.length == speed.length
// 1 <= n <= 10^5
// 1 <= dist[i], speed[i] <= 10^5

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:

    int eliminateMaximum(std::vector<int>& dist, std::vector<int>& speed) 
    {
        int maximun = 0;
        std::vector<float> time(dist.size());

        for (int i = 0; i < dist.size(); i++)
        {
            time[i] = dist[i] / (float)speed[i];
        }

        std::sort(time.begin(), time.end());

        while (!time.empty() && time[0] > 0)
        {
            std::cout << "Time: ";
            for (auto t : time) std::cout << t << ", ";
            std::cout << "\n";

            time.erase(time.begin());

            maximun += 1;

            for (int i = 0; i < time.size(); i++)
            {
                time[i] -= 1;
            }
        }
        return maximun;
    }
};

// time == time.size()

int main()
{
    Solution test1, test2, test3, test4;

    //[23,6,20,44,46,22,19,34,36,40,45,22,8,11,47,42,27,49,5,45,34]
    //[2,20,5,1,2,2,2,8,1,7,2,1,2,2,2,7,2,1,1,1,1]

    std::vector<int> dist4  = {23,6,20,44,46,22,19,34,36,40,45,22,8,11,47,42,27,49,5,45,34};
    std::vector<int> speed4 = {2,20,5,1,2,2,2,8,1,7,2,1,2,2,2,7,2,1,1,1,1};

    std::vector<int> dist1  = {4, 3, 3, 3, 4};
    std::vector<int> speed1 = {1, 1, 1, 1, 4};
    std::vector<int> dist2  = {1, 1, 2, 3};
    std::vector<int> speed2 = {1, 1, 1, 1};
    std::vector<int> dist3  = {1, 3, 4};
    std::vector<int> speed3 = {1, 1, 1};

    //std::cout << "Maximun deads: \n" << test1.eliminateMaximum(dist1, speed1) << std::endl;
    //std::cout << "Maximun deads: \n" << test2.eliminateMaximum(dist2, speed2) << std::endl;
    //std::cout << "Maximun deads: \n" << test3.eliminateMaximum(dist3, speed3) << std::endl;
    std::cout << "Maximun deads: \n" << test4.eliminateMaximum(dist4, speed4) << std::endl;

    return 0;
}