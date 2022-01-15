#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(unsigned n, unsigned k)
{
    if (__builtin_popcount(n) > k || k > n)
        return no_answer();

    std::vector<unsigned> q;
    for (size_t i = 0; i < 32; ++i) {
        if (n & 1 << i)
            q.push_back(1 << i);
    }

    std::vector<unsigned> v;
    while (v.size() + q.size() < k) {
        if (q.back() == 1) {
            v.push_back(1);
            q.pop_back();
        } else {
            q.push_back(q.back() /= 2);
        }
    }

    v.insert(v.end(), q.cbegin(), q.cend());

    answer(v);
}

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}
