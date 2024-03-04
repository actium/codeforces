#include <algorithm>
#include <iostream>
#include <string>
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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::pair<std::string, unsigned>>& s)
{
    std::vector<unsigned> a[4];
    for (const std::pair<std::string, unsigned>& x : s) {
        const size_t i = (x.first[0] - '0') * 2 + (x.first[1] - '0');
        a[i].push_back(x.second);
    }

    const size_t m = std::min(a[1].size(), a[2].size());

    for (size_t i = 1; i < 3; ++i) {
        std::sort(a[i].begin(), a[i].end());

        const size_t x = a[i].size() - m;
        a[0].insert(a[0].end(), a[i].begin(), a[i].begin() + x);
        a[3].insert(a[3].end(), a[i].begin() + x, a[i].end());
    }

    std::sort(a[0].begin(), a[0].end());

    const size_t k = std::min(a[0].size(), (a[3].size() - 2 * m));
    a[3].insert(a[3].end(), a[0].end() - k, a[0].end());

    unsigned v = 0;
    for (const unsigned x : a[3])
        v += x;

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<std::string, unsigned>> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
