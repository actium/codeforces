#include <iostream>
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

void solve(const std::vector<int>& t)
{
    const size_t n = t.size();

    std::vector<unsigned> p(1+n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = p[i] + (t[i] >= 0);

    std::vector<unsigned> s(1+n);
    for (size_t i = n; i > 0; --i)
        s[i-1] = s[i] + (t[i-1] <= 0);

    unsigned k = n;
    for (size_t i = 1; i < n; ++i)
        k = std::min(k, p[i] + s[i]);

    answer(k);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    size_t n;
    std::cin >> n;

    std::vector<int> t(n);
    std::cin >> t;

    solve(t);

    return 0;
}

