#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
#include <string>

using namespace std;

void compareElements(const std::vector<std::string>& vec1, const std::vector<std::string>& vec2) {
    // If sizes are not the same, they can't have the same elements
    vector<string> ans = {};
    if (vec1.size() != vec2.size()) {
        std::cout << "The vectors have different sizes." << std::endl;
        return;
    }

    for(auto& a:vec1){
        for(auto& b: vec2){
            if(a==b){
                ans.push_back(a);
            }
        }
    }
    cout << ans.size() << " " << vec1.size() << endl;
}

int main() {
    std::vector<std::string> vector1 = {"()()()()","(()()())","(()())()","((()()))","()(()())","(())()()","((())())","()(())()","((()))()","(((())))","()((()))","()(())()","(()(()))","()()(())"};
    std::vector<std::string> vector2 = {"(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"};

    compareElements(vector1, vector2);

    return 0;
}
