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

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::string>& s)
{
    const auto check = [&](const std::string& x) {
        for (const std::string& q : s) {
            if (q.find(x) != std::string::npos)
                return false;
        }
        return true;
    };

    std::vector<std::string> c;
    for (char i = 'a'; i <= 'z'; ++i)
        c.emplace_back(1, i);

    size_t x = 0;
    while (!check(c[x])) {
        for (char i = 'a'; i <= 'z'; ++i)
            c.push_back(c[x] + i);

        ++x;
    }

    answer(c[x]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
