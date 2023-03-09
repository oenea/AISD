#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct pt{
    int x, y;
};

struct pt center;

int cmp(const void* a, const void* b){
    struct pt apt = *(struct pt*)a;
    struct pt bpt = *(struct pt*)b;

    apt.x -= center.x;
    apt.y -= center.y;

    bpt.x -= center.x;
    bpt.y -= center.y;

    int r = apt.x * bpt.y - apt.y * bpt.x;

    return (r > 0) - (r < 0);

}
struct pt find_center(struct pt* pts, int n){
    struct pt center;
    int x = 0, y = 0;
    for(int i = 0; i < n; i++){
        x += pts[i].x;
        y += pts[i].y;
    }
    center.x = x / n;
    center.y = y / n;
    return center;
}

int main(){
    int n, amount;
    cin >> amount;
    for(int k = 0; k < amount; k++){
        cin >> n;
        n /= 2;
        struct pt* pts = new struct pt[n];
        for(int i = 0; i < n; i++){
            cin >> pts[i].x >> pts[i].y;
        }

        center = find_center(pts, n);

        qsort(pts, n, sizeof(struct pt), cmp);
        /*
        for(int i = 0; i < n; i++){
            cout << pts[i].x << ' '<< pts[i].y << '\n';
        }*/

        int determinant = 0;
        for(int i = 0; i < (n-1); i++){
            determinant += pts[i].x * pts[i+1].y;
            determinant -= pts[i].y * pts[i+1].x;  
        }
        determinant += pts[n-1].x * pts[0].y;
        determinant -= pts[n-1].y * pts[0].x;
        determinant /= 2;
        if(determinant < 0){
            determinant *= -1;
        }
        cout << determinant << '\n';
    }
}
//tests sorted
//8 0 0 0 2 2 2 2 0
//10 92 61 62 69 -94 61 -92 -80 78 -9
//6 2 5 -4 3 5 1

// test to_sort
//8 2 2 0 0 0 2 2 0
//10 78 -9 62 69 92 61 -92 -80 -94 61 
//6 -4 3 5 1 2 5

//3 8 0 0 0 2 2 2 2 0 10 92 61 62 69 -94 61 -92 -80 78 -9 6 2 5 -4 3 5 1
//1 8 0 0 0 2 2 2 2 0