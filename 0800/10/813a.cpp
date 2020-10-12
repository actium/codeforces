#include <algorithm>
#include <iostream>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<std::pair<unsigned, unsigned>>& t)
{
    unsigned s = 0;
    for (const unsigned x : a)
        s += x;

    const auto compare = [](const std::pair<unsigned, unsigned>& t, unsigned x) {
        return t.second < x;
    };

    const auto it = std::lower_bound(t.cbegin(), t.cend(), s, compare);
    if (it == t.cend())
        return no_answer();

    answer(std::max(s, it->first));
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    size_t m;
    std::cin >> m;

    std::vector<std::pair<unsigned, unsigned>> t(m);
    std::cin >> t;

    solve(a, t);

    return 0;
}

