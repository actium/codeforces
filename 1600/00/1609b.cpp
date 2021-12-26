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

void solve(std::string& s, const std::vector<std::pair<unsigned, char>>& r)
{
    const size_t n = s.length();

    const auto count = [&](size_t x) {
        unsigned c = 0;
        for (int d = 0; d < 5; ++d) {
            if (x + d < 2 || x + d >= n)
                continue;

            const size_t i = x + d - 2;
            c += (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c');
        }
        return c;
    };

    unsigned k = 0;
    for (size_t i = 0; i = s.find("abc", i), i != std::string::npos; ++i)
        ++k;

    for (const auto& q : r) {
        k -= count(q.first - 1);
        s[q.first - 1] = q.second;
        k += count(q.first - 1);

        answer(k);
    }
}

int main()
{
    size_t n, q;
    std::cin >> n >> q;

    std::string s;
    std::cin >> s;

    std::vector<std::pair<unsigned, char>> r(q);
    std::cin >> r;

    solve(s, r);

    return 0;
}
