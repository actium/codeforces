#include <iostream>
#include <vector>

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

void solve(char c, const std::vector<char>& s)
{
    const size_t n = s.size();

    size_t d = 0;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] != c)
            continue;

        size_t j = i;
        while (s[j % n] != 'g')
            ++j;

        d = std::max(d, j - i);
        i = j;
    }

    answer(d);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    char c;
    std::cin >> c;

    std::vector<char> s(n);
    std::cin >> s;

    solve(c, s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
