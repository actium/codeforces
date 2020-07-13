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

void answer(size_t v)
{
    constexpr const char* s[2] = { "contest", "home" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& /*s*/, const std::vector<std::string>& f)
{
    answer(f.size() % 2 == 0);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<std::string> f(n);
    std::cin >> f;

    solve(s, f);

    return 0;
}

