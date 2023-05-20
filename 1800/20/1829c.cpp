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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<std::pair<unsigned, std::string>>& b)
{
    constexpr unsigned oo = ~0u;

    unsigned d[3] = { oo, oo, oo };
    for (const std::pair<unsigned, std::string>& e : b) {
        if (e.second[0] == '1')
            d[0] = std::min(d[0], e.first);
        if (e.second[1] == '1')
            d[1] = std::min(d[1], e.first);
        if (e.second == "11")
            d[2] = std::min(d[2], e.first);
    }

    if (d[0] != oo && d[1] != oo)
        return answer(std::min(d[0] + d[1], d[2]));

    no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, std::string>> b(n);
    std::cin >> b;

    solve(b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
