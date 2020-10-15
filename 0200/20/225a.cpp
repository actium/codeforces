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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned x, const std::vector<std::pair<unsigned, unsigned>>& t)
{
    for (const std::pair<unsigned, unsigned>& e : t) {
        if (x == e.first || x == 7 - e.first || x == e.second || x == 7 - e.second)
            return answer(false);
    }

    answer(true);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<std::pair<unsigned, unsigned>> t(n);
    std::cin >> t;

    solve(x, t);

    return 0;
}

