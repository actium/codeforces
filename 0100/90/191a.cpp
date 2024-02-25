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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::string>& a)
{
    unsigned d[26][26] = {};
    for (const std::string& s : a) {
        const size_t u = s.front() - 'a', v = s.back() - 'a';

        for (size_t i = 0; i < 26; ++i) {
            if (d[i][u] != 0)
                d[i][v] = std::max<unsigned>(d[i][v], d[i][u] + s.length());
        }

        d[u][v] = std::max<unsigned>(d[u][v], s.length());
    }

    unsigned x = 0;
    for (size_t i = 0; i < 26; ++i)
        x = std::max(x, d[i][i]);

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::string> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
