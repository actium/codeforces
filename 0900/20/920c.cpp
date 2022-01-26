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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& a, const std::string& s)
{
    const size_t n = a.size();

    std::vector<unsigned> d(n);
    for (size_t i = n-1; i-- > 0; ) {
        if (s[i] == '1')
            d[i] = d[i+1] + 1;
    }

    for (size_t i = 0; i < n; ++i) {
        if (i + d[i] < a[i] - 1)
            return answer(false);
    }

    answer(true);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::string s;
    std::cin >> s;

    solve(a, s);

    return 0;
}
