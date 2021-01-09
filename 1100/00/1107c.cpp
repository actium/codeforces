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

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a, const std::string& s, size_t k)
{
    const size_t n = a.size();

    integer t = 0;
    for (size_t i = 0; i < n; ) {
        std::vector<unsigned> b;
        for (size_t j = i; i < n && s[i] == s[j]; ++i)
            b.push_back(a[i]);

        if (b.size() > k) {
            std::sort(b.begin(), b.end(), std::greater<unsigned>());
            b.resize(k);
        }

        for (const unsigned x : b)
            t += x;
    }

    answer(t);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::string s;
    std::cin >> s;

    solve(a, s, k);

    return 0;
}

