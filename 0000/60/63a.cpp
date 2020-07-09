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

unsigned priority(const std::string& status)
{
    if (status == "captain")
        return 0;

    if (status == "man")
        return 1;

    if (status == "rat")
        return 3;

    return 2;
}

void solve(std::vector<std::pair<std::string, std::string>>& p)
{
    const auto c = [](const std::pair<std::string, std::string>& a, const std::pair<std::string, std::string>& b) {
        return priority(a.second) > priority(b.second);
    };
    std::stable_sort(p.begin(), p.end(), c);

    for (const auto& x : p)
        std::cout << x.first << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<std::string, std::string>> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}

