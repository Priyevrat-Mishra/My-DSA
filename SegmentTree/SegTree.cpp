#include <iostream>
#include <vector>
using namespace std;

class SegTree{
    vector<int> tree, arr; // Segment Tree, Array
    int n;                 // Array Size

    int range(int node, int start, int end, int left, int right){
        // Fully out -----------------
        // right side  ||  left side
        if (start > right || end < left)
            return 0;
        // Fully in Range ----------------
        if (start >= left && end <= right)
            return tree[node];
        // Overlap Range -------------------
        int mid = start + (end - start) / 2;
        return range(2 * node + 1, start, mid, left, right) + range(2 * node + 2, mid + 1, end, left, right);
    }

    void updating(int node, int start, int end, int idx, int val){
        if (idx < start || idx > end)
            return;

        if (start == end){
            tree[node] = val;
            return;
        }

        tree[node] += val - arr[idx];
        int mid = start + (end - start) / 2;
        updating(2 * node + 1, start, mid, idx, val);
        updating(2 * node + 2, mid, end, idx, val);
    }

public:
    SegTree(vector<int> input){
        arr = input;
        n = input.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    void build(int node, int start, int end){
        if (start == end){
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node + 1, start, mid);   // Left Child
        build(2 * node + 2, mid + 1, end); // Right Child
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int query(int left, int right){
        return range(0, 0, n - 1, left, right);
    }

    void update(int idx, int val){
        updating(0, 0, n - 1, idx, val);
    }

    void show(){
        for (int i=0; i<n; i++)
            cout << arr[i] << " ";
    }
};

int main(){
    vector<int> a;
    a.push_back(3);
    a.push_back(6);
    a.push_back(4);
    a.push_back(25);
    a.push_back(5);
    a.push_back(13);
    a.push_back(18);
    SegTree *tree = new SegTree(a);
    cout << tree->query(0, 8) << endl;
    tree->show();
    tree->update(1, 1000);
    tree->show();

    return 0;
}