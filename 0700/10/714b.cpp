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
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const std::set<unsigned> r(a.cbegin(), a.cend());

    if (r.size() > 3)
        return answer(false);

    if (r.size() < 3)
        return answer(true);

    const unsigned x = *std::next(r.cbegin());
    answer(x - *r.cbegin() == *r.crbegin() - x);
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

