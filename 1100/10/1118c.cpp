#include <iostream>
#include <map>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& v)
{
    const char* separator = "";
    for (const T x : v) {
        output << separator << x;
        separator = " ";
    }
    return output;
}

void answer(const std::vector<std::vector<unsigned>>& x)
{
    std::cout << "YES" << '\n';

    for (const std::vector<unsigned>& v : x)
        std::cout << v << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(size_t n, const std::vector<unsigned>& a)
{
    std::map<unsigned, unsigned> f;
    for (const unsigned x : a)
        ++f[x];

    const auto next = [&](std::map<unsigned, unsigned>::iterator it, unsigned k) {
        while (it != f.end() && it->second < k) {
            if (it->second == 0)
                it = f.erase(it);
            else
                ++it;
        }
        return it;
    };

    std::vector<std::vector<unsigned>> b(n, std::vector<unsigned>(n));
    {
        size_t r = 0, c = 0;
        for (auto it = next(f.begin(), 4); r < n / 2 && it != f.end(); it = next(it, 4)) {
            b[r][c] = it->first;
            b[r][n-1-c] = it->first;
            b[n-1-r][c] = it->first;
            b[n-1-r][n-1-c] = it->first;

            if (++c == n / 2) {
                ++r;
                c = 0;
            }

            it->second -= 4;
        }

        if (n % 2 == 0)
            return f.empty() ? answer(b) : no_answer();

        for (auto it = next(f.begin(), 2); c < n / 2 && it != f.end(); it = next(it, 2)) {
            b[n/2][c++] = it->first;
            b[n/2][n-c] = it->first;
            it->second -= 2;
        }
        for (auto it = next(f.begin(), 2); r > 0 && it != f.end(); it = next(it, 2)) {
            b[--r][n/2] = it->first;
            b[n-1-r][n/2] = it->first;
            it->second -= 2;
        }

        if (f.size() != 1 || f.begin()->second != 1)
            return no_answer();

        b[n/2][n/2] = f.begin()->first;
    }

    answer(b);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n * n);
    std::cin >> a;

    solve(n, a);

    return 0;
}
