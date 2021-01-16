#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const size_t n = v.size();

    std::cout << n;

    const char* separator = "\n";
    for (size_t i = 0; i < n; i += 2) {
        std::cout << separator << v[i];
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned x)
{
    std::vector<unsigned> q;
    while (__builtin_popcount(x + 1) != 1) {
        if (!q.empty()) {
            q.push_back(0);
            ++x;
        }
        q.push_back(__builtin_ctz(x));
        x |= x - 1;
    }

    answer(q);
}

int main()
{
    unsigned x;
    std::cin >> x;

    solve(x);

    return 0;
}

