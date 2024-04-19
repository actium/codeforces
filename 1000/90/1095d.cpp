#include <iostream>
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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& p)
{
    const size_t n = p.size();

    const auto check = [&](unsigned x, std::vector<unsigned>& s) {
        for (size_t i = 0, j = 0; i < n; ++i) {
            if (p[j].first != x && p[j].second != x)
                return false;

            s[i] = (p[j].first == x ? p[j].second : p[j].first);
            j = x - 1;
            x = s[i];
        }
        return true;
    };

    std::vector<unsigned> s(n);
    check(p[0].first, s) || check(p[0].second, s);
    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}
