#include <array>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void answer(const std::vector<std::array<unsigned, 3>>& v)
{
    std::cout << "YES" << '\n';

    std::cout << v.size() << '\n';
    for (const auto& x : v)
        std::cout << 1+x[0] << ' ' << 1+x[1] << ' ' << 1+x[2] << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned x = 0;
    for (size_t i = 0; i < n; ++i)
        x ^= a[i];

    if (n % 2 == 0 && x != 0)
        return no_answer();

    std::vector<std::array<unsigned, 3>> q;
    for (size_t i = 0; i < n-2; i += 2) {
        const std::array<unsigned, 3> o = { i, i+1, n-1 };
        q.push_back(o);
    }
    for (size_t i = 0; i < n-2; i += 2) {
        const std::array<unsigned, 3> o = { i, i+1, n-1 };
        q.push_back(o);
    }

    answer(q);
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

