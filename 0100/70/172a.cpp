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

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& s)
{
    const size_t n = s.size();

    std::string p = s[0];
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 0; j < p.length(); ++j) {
            if (s[i][j] != p[j]) {
                p.resize(j);
                break;
            }
        }
    }

    answer(p.length());
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}

