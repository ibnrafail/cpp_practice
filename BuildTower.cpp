
#include <iostream>
#include <string>
#include <vector>

class Kata
{
public:
    std::vector<std::string> towerBuilder(int nFloors) {
		std::vector<std::string> res;
        auto maxNumOfStars = nFloors * 2 - 1;
        auto mid = maxNumOfStars / 2;
        for (auto stars = 1; stars <= maxNumOfStars; stars += 2, mid--) {
            std::string str = "";
            for (auto i = 0, sTemp = stars; i < maxNumOfStars; i++) {
                if (i >= mid && sTemp != 0) {
                    str += "*";
                    sTemp--;
                }
                else str += " ";
            }
            res.push_back(str);
        }
        return res;
    }
};

int main()
{
   towerBuilder(4);
   return 0;
}
