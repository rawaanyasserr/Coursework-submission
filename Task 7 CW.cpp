// Task 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<tuple>
#include <vector>
#include<stack>
using namespace std;

bool isin(vector<tuple<int, int>> vis, tuple<int, int> n2) {
    for (tuple<int, int> a : vis) {
        if (a == n2)
            return true;
    }
    return false;
}
vector<vector<int>> grid = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{0,0,0,0,0,1,0,1,0,1,0,0,0,0,0},{0,1,1,1,0,1,0,1,0,1,0,1,1,1,0},
    {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},{0,1,0,1,1,1,0,1,0,1,1,1,0,1,0},{0,1,0,1,0,0,0,1,0,0,0,1,0,1,0},{0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,},
    {0,1,0,1,0,0,0,0,0,0,0,1,0,1,0},{0,1,0,1,1,1,1,0,1,1,1,1,0,1,0},{0,1,0,1,0,0,0,0,0,0,0,1,0,1,0},{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
vector < tuple<int, int>> onesquare = { make_tuple(0,1),make_tuple(1,0),make_tuple(-1,0),make_tuple(0,-1) };
vector<tuple<int, int>> depth_first(tuple<int, int> s, tuple<int, int> e) {
    stack<tuple<int, int>> stck;
    stck.push(s);
    vector<tuple<int, int>> vis;
    tuple<int, int> n;
    tuple<int, int> n2;
    vis.push_back(s);
    while (!stck.empty()) {
        n = stck.top();
        stck.pop();
        if (n == e)
            return vis;
        for (tuple<int, int> onesq : onesquare) {
            n2 = make_tuple(get<0>(n) + get<0>(onesq), get<1>(n) + get<1>(onesq));
            if (!isin(vis, n2) && get<0>(n2) >= 0 && get<1>(n2) >= 0 && get<0>(n2) < 15 && get<1>(n2) < 15 && grid[get<0>(n2)][get<1>(n2)]) {
                stck.push(n2);
                vis.push_back(n2);
            }
        }
    }
    return vis;
}

int main()
{
    tuple<int, int> s, e;
    s = make_tuple(13, 0);
    e = make_tuple(1, 14);
    for (tuple<int, int> a : depth_first(s, e)) {
        cout << "[" << get<0>(a) << ", " << get<1>(a) << "]  ";
    }

}


