#include <algorithm>
#include <iostream>
#include <string>
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

void solve(const std::vector<std::string>& s, const std::vector<unsigned>& a)
{
    const size_t n = s.size();
    const size_t m = a.size();

    std::vector<size_t> v(m);
    for (size_t j = 0; j < m; ++j) {
        std::vector<size_t> k(5);
        for (size_t i = 0; i < n; ++i) {
            const char c = s[i][j];
            ++k[c - 'A'];
        }
        v[j] = *std::max_element(k.cbegin(), k.cend());
    }

    unsigned t = 0;
    for (size_t j = 0; j < m; ++j)
        t += v[j] * a[j];

    answer(t);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    std::cin >> s;

    std::vector<unsigned> a(m);
    std::cin >> a;

    solve(s, a);

    return 0;
}

