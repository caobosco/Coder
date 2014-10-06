#include <vector>
#include <cstdio>
#include <set>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

typedef pair<int, int> Point;

int main(){
    int T, len;
    Point input_point;
    long dist;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        set<Point> points;
        set<long> distance;
        for (int j = 0; j < 8; j++) {
            scanf("%d %d", &input_point.first, &input_point.second);
            points.insert(input_point);
        }
        
        if (points.size() != 4) {
            printf("NO\n");
            continue;
        }
            
        vector<Point> cal(points.begin(), points.end());
        for (int j = 0; j < 4; j++) {
            for (int k = j+1; k < 4; k++) {
                dist = pow(cal[j].first - cal[k].first, 2) + pow(cal[j].second- cal[k].second, 2);
                distance.insert(dist);
            }
        }
        len = distance.size();
        if (len > 3) { 
            printf("NO\n");
            continue;
        }
        vector<long> distances(distance.begin(), distance.end());
        sort(distances.begin(), distances.end());
        if(len == 2) {
            if (distances[0]*2 == distances[1])
                printf("YES\n");
            else printf("NO\n");
            continue;
        } else {
            if (distances[0]+ distances[1] == distances[2])
                printf("YES\n");
            else printf("NO\n");
            continue;
        }
        printf("NO\n");
    }
}
