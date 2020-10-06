#include <algorithm>
#include <iostream>
#include <vector>

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

void solve(size_t n, std::vector<size_t>& d)
{
    const size_t m = d.size();

    std::sort(d.begin(), d.end());

    for (size_t i = 2; i < m; ++i) {
        if (d[i] == d[i-2] + 2)
            return answer(false);
    }

    answer(m == 0 || (d.front() != 1 && d.back() != n));
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<size_t> d(m);
    std::cin >> d;

    solve(n, d);

    return 0;
}

