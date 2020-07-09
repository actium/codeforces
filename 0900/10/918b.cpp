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

std::string name(const std::vector<std::pair<std::string, std::string>>& a, const std::string& b)
{
    for (const auto& x : a) {
        if (x.second + ';' == b)
            return x.first;
    }
    return "";
}

void solve(const std::vector<std::pair<std::string, std::string>>& a, const std::vector<std::pair<std::string, std::string>>& c)
{
    for (const auto& x : c) {
        std::cout << x.first << ' ' << x.second << " #" << name(a, x.second) << '\n';
    }
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<std::string, std::string>> a(n);
    std::cin >> a;

    std::vector<std::pair<std::string, std::string>> c(m);
    std::cin >> c;

    solve(a, c);

    return 0;
}

