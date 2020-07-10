#include <algorithm>
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

void answer(const std::pair<std::string, std::string>& v)
{
    std::cout << v.first << ' ' << v.second << '\n';
}

void solve(std::pair<std::string, std::string>& a, const std::vector<std::pair<std::string, std::string>>& b)
{
    std::for_each(std::begin(b), std::end(b), [&](const std::pair<std::string, std::string>& x) {
        answer(a);

        if (x.first == a.first)
            a.first = x.second;
        else
            a.second = x.second;
    });

    answer(a);
}

int main()
{
    std::pair<std::string, std::string> a;
    std::cin >> a;

    unsigned n;
    std::cin >> n;

    std::vector<std::pair<std::string, std::string>> b(n);
    std::cin >> b;

    solve(a, b);

    return 0;
}

