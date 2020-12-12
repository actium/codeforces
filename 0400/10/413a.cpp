#include <iostream>
#include <set>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "Incorrect", "Correct" };
    std::cout << s[v] << '\n';
}


void solve(size_t n, const std::vector<unsigned>& t, unsigned min, unsigned max)
{
    std::multiset<unsigned> s(t.cbegin(), t.cend());
    if (*s.begin() != min)
        s.insert(min);

    if (*s.rbegin() != max)
        s.insert(max);

    answer(s.size() <= n && *s.begin() == min && *s.rbegin() == max);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    unsigned min, max;
    std::cin >> min >> max;

    std::vector<unsigned> t(m);
    std::cin >> t;

    solve(n, t, min, max);

    return 0;
}

