#include <iostream>
#include <vector>

class Solution {
    public:
        std::vector<int> minOperations(std::string boxes) {
            std::vector<int> minOp;
            int steps = 0;

            for (int i = 0; i < boxes.length(); i++){
                for (int j = 0; j < boxes.length(); j++){
                    if (boxes[j] == '1'){
                         steps += abs(i - j);
                    } 
                }
                minOp.push_back(steps);
                steps = 0;
            }
            return minOp; 
        }

        std::vector<int> minFast(std::string boxes){
            std::vector<int> minOp;
            int ballCount = 0;
            int stepCount = 0;
            int ballAfter = 0;

            for (int i = 0; i < boxes.length(); i++){
                if (boxes[i] == '1'){
                    ballCount++;
                    stepCount += i;
                }
            }

            std::cout << "BALL COUNT: " << ballCount << std::endl;
            std::cout << "STEP COUNT: " << stepCount << std::endl;

            for (int i = 0; i < boxes.length(); i++){
                minOp.push_back(stepCount);
                if (boxes[i] == '1'){
                    ballCount--;
                    ballAfter++;
                    stepCount -= (ballCount - ballAfter);
                } else {
                    stepCount -= (ballCount - ballAfter);
                }
            }
            return minOp;
        }

        std::vector<int> ultra(std::string boxes) {
            std::vector<int> res(boxes.length()); 
            for (int i = 0, ops = 0, cnt = 0; i < boxes.length(); ++i) {
                res[i] += ops;
                cnt += boxes[i] == '1' ? 1 : 0;
                ops += cnt;
            }
            for (int i = boxes.length() - 1, ops = 0, cnt = 0; i >= 0; --i) {
                res[i] += ops;
                cnt += boxes[i] == '1' ? 1 : 0;
                ops += cnt;
            }
            return res;
        }
        
};

int main(){
    Solution test;

    //std::string boxes = "001011";
    std::string boxes = "110";
    std::vector<int> ans;
    
    //ans = test.minOperations(boxes);
    ans = test.minFast(boxes); 

    for(int it : ans) std::cout << it << ", ";
    std::cout << "\n";
    //[11,8,5,4,3,4]

    return 0;
}
