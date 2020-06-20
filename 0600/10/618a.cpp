#include <iostream>
#include <vector>

void solve(size_t n)
{
    std::vector<size_t> v;
    for (size_t i = 0; i < n; ++i) {
        v.push_back(1);

        while (v.size() > 1 && v[v.size() - 1] == v[v.size() - 2]) {
            v.pop_back();
            ++v.back();
        }
    }

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << x;
        separator = " ";
    }
}

int main()
{
    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}

