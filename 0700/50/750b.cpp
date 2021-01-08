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

void solve(const std::vector<std::pair<unsigned, std::string>>& r)
{
    int d = 0;
    for (const auto& i : r) {
        if (d == 0 && i.second != "South")
            return answer(false);

        if (d == 20000 && i.second != "North")
            return answer(false);

        if (i.second == "South")
            d += i.first;

        if (i.second == "North")
            d -= i.first;

        if (d < 0 || d > 20000)
            return answer(false);
    }

    answer(d == 0);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, std::string>> r(n);
    std::cin >> r;

    solve(r);

    return 0;
}

