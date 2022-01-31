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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::pair<std::string, std::string>>& h, const std::vector<unsigned>& p)
{
    const size_t n = h.size();

    std::string x;

    const auto update = [&x](const std::string& c) {
        if (c > x) {
            x = c;
            return true;
        }
        return false;
    };

    for (const unsigned i : p) {
        const auto c = std::minmax(h[i-1].first, h[i-1].second);
        if (!update(c.first) && !update(c.second))
            return answer(false);
    }

    answer(true);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<std::string, std::string>> h(n);
    std::cin >> h;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(h, p);

    return 0;
}
