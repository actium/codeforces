#include <iostream>
#include <map>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::map<unsigned, unsigned> f;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < i; ++j)
            ++f[a[i] + a[j]];
    }

    unsigned k = 0;
    for (const auto& x : f)
        k = std::max(k, x.second);

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

