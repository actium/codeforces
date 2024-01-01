#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

constexpr unsigned oo = ~0u;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    std::map<unsigned, std::vector<unsigned>> c;
    for (size_t i = 0; i < n; ++i) {
        unsigned q = 0;
        for (unsigned x = a[i]; x != 0; x /= 2)
            c[x].push_back(q++);

        c[0].push_back(q);
    }

    unsigned q = oo;
    for (auto& e : c) {
        if (e.second.size() < k)
            continue;

        std::partial_sort(e.second.begin(), e.second.begin() + k, e.second.end());

        unsigned s = 0;
        for (size_t i = 0; i < k; ++i)
            s += e.second[i];

        q = std::min(q, s);
    }

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}