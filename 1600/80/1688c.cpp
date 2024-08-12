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

void answer(char x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, const std::vector<std::string>& t)
{
    char x = 0;

    const auto handle = [&](const std::string& q) {
        for (const char c : q)
            x ^= c;
    };

    handle(s);
    for (const std::string& q : t)
        handle(q);

    answer(x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> t(2 * n);
    std::cin >> t;

    std::string s;
    std::cin >> s;

    solve(s, t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
