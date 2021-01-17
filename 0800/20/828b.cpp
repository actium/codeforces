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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<std::string>& s)
{
    const size_t n = s.size(), m = s[0].length();

    std::pair<size_t, size_t> lb = { n, m }, ub = { 0, 0 };
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (s[i][j] == 'B') {
                lb.first = std::min(lb.first, i);
                lb.second = std::min(lb.second, j);
                ub.first = std::max(ub.first, i);
                ub.second = std::max(ub.second, j);
            }
        }
    }

    if (lb.first == n && lb.second == m && ub.first == 0 && ub.second == 0)
        return answer(1);

    const size_t r = ub.first - lb.first + 1, c = ub.second - lb.second + 1, d = std::max(r, c);
    if (d > std::min(n, m))
        return no_answer();

    unsigned k = 0;
    for (size_t i = lb.first; i <= ub.first; ++i) {
        for (size_t j = lb.second; j <= ub.second; ++j)
            k += (s[i][j] == 'W');
    }

    answer(k + d * d - r * c);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}

