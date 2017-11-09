class NumArray {
public:
    NumArray(vector<int> nums): N(nums.size() - 1), tree(4 * nums.size(), 0) {
        buildSegTree(nums, 0, N, 0);
    }
    
    void update(int i, int val) {
        update(0, 0, N, i, val);
    }
    
    int sumRange(int i, int j) {
        return query(0, 0, N, i, j);
    }
private:
    int N;
    vector<int> tree;
    
    void buildSegTree(const vector<int>& nums, int lo, int hi, int idx) {
        if (lo > hi) {
            return;
        }
        if (lo == hi) {
            tree[idx] = nums[lo];
            return;
        }
        int mid = lo + (hi - lo) / 2;
        buildSegTree(nums, lo, mid, left(idx));
        buildSegTree(nums, mid+1, hi, right(idx));
        tree[idx] = tree[left(idx)] + tree[right(idx)];
    }
    
    int query(int idx, int lo, int hi, int i, int j) {
        if (j < lo || i > hi) {
            return 0;
        }
        if (j >= hi && i <= lo) {
            return tree[idx];
        }
        int mid = lo + (hi - lo) / 2;
        int res = 0;
        if (i <= mid)
            res += query(left(idx), lo, mid, i, j);
        if (j > mid)
            res += query(right(idx), mid+1, hi, i, j);
        return res;
    }
    
    void update(int idx, int lo, int hi, int i, int val) {
        if (i < lo || i > hi) {
            return;
        }
        if (hi == lo) {
            tree[idx] = val;
            return;
        }
        int mid = lo + (hi - lo) / 2;
        if (i <= mid) {
            update(left(idx), lo, mid, i, val);
        }
        else {
            update(right(idx), mid + 1, hi, i, val);
        }
        tree[idx] = tree[left(idx)] + tree[right(idx)];
    }
    
    int left(int idx) { return 2 * idx + 1; }
    int right(int idx) { return 2 * idx + 2; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
