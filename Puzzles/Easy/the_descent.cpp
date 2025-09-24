#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Mountain
{
    int ind;
    int height;
};

int main()
{
    while (1) {
        Mountain maxMountain{0, 0}; 
      
        for (int i = 0; i < 8; i++) {
            int mountainH;
            
            cin >> mountainH; cin.ignore(); 
            
            if (maxMountain.height < mountainH) {
                maxMountain.height = mountainH; 
                maxMountain.ind = i; 
            }
        }
        cout << maxMountain.ind << endl; 
    }
}
