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

    std::pair<unsigned, unsigned> max = { 0, 0 };

    std::map<unsigned, unsigned> f;
    for (const unsigned x : a) {
        auto it = f.find(x);
        if (it == f.end())
            it = f.emplace(x, 0).first;

        if (++it->second > max.second)
            max = *it;
    }

    unsigned k = 0;
    for (const auto& p : f) {
        if (p.second == max.second)
            ++k;
    }

    const unsigned z = k * max.second;
    const unsigned r = n - z;

    answer(k - 1 + r / (max.second - 1));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

