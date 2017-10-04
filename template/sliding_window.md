```C++
bool slidingWindow(string s1, string s2) {
    vector<int> dict(26, 0);
    int count = 0;
    for (char c : s1) {
        if (dict[c - 'a'] == 0) {
            ++count;
        }
        ++dict[c - 'a'];
    }
    int left = 0;
    for (int right = 0; right < s2.size(); ++right) {
        char c = s2[right];
        --dict[c - 'a'];
        if (dict[c - 'a'] == 0) {
            --count;
            if (0 == count) {
                return true;
            }
        }
        if (right - left + 1 == s1.size()) {
            char cc = s2[left++];
            if (dict[cc - 'a'] == 0) {
                ++count;
            }
            ++dict[cc - 'a'];
        }
    }
    return false;
}
```
