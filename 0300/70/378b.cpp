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

void answer(const std::string& x, const std::string& y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& s)
{
    const size_t n = s.size();

    std::string a(n, '0'), b(n, '0');
    for (size_t i = 0; i < n / 2; ++i) {
        a[i] = '1';
        b[i] = '1';
    }

    for (size_t i = 0, j = 0, k = 0; k < n; ++k) {
        if (s[i].first < s[j].second)
            a[i++] = '1';
        else
            b[j++] = '1';
    }

    answer(a, b);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}

