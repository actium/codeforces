#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size() + 1;

    std::vector<std::vector<unsigned>> c(n);
    c[0] = { 0, 1, 2, 3 };
    for (size_t i = 1; i < n; ++i) {
        for (const unsigned u : c[i-1]) {
            for (const unsigned v : { 0, 1, 2, 3 }) {
                if ((u | v) == a[i-1] && (u & v) == b[i-1])
                    c[i].push_back(v);
            }
        }
    }

    if (c[n-1].empty())
        return no_answer();

    std::vector<unsigned> t(n);
    t[n-1] = c[n-1][0];
    for (size_t i = n-2; ~i != 0; --i) {
        for (const unsigned u : c[i]) {
            if ((u | t[i+1]) == a[i] && (u & t[i+1]) == b[i])
                t[i] = u;
        }
    }

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n-1), b(n-1);
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
