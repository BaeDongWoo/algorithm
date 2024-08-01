#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int maxW = 0;
    int maxH = 0; 
    for(int i=0;i<sizes.size();i++){
        int w = sizes[i][0];
        int h = sizes[i][1];
        if(w < h ){
            sizes[i][0]=h;
            sizes[i][1]=w;
        }
        
        if(maxW < sizes[i][0]) maxW = sizes[i][0];
        if(maxH < sizes[i][1]) maxH = sizes[i][1];
    }
    return maxW * maxH;
}