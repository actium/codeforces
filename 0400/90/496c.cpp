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

void solve(const std::vector<std::string>& s)
{
    const size_t n = s.size(), m = s[0].length();

    std::vector<std::string> t(n);

    const auto check = [&] {
        for (size_t i = 1; i < n; ++i) {
            if (t[i-1] <= t[i])
                continue;

            for (std::string& s : t)
                s.pop_back();

            return 1;
        }
        return 0;
    };

    unsigned k = 0;
    for (size_t j = 0; j < m; ++j) {
        for (size_t i = 0; i < n; ++i)
            t[i].push_back(s[i][j]);

        k += check();
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
