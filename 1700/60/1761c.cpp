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

void answer(const std::vector<std::vector<unsigned>>& v)
{
    for (const std::vector<unsigned>& a : v) {
        std::cout << a.size();
        for (const unsigned x : a)
            std::cout << ' ' << x;

        std::cout << '\n';
    }
}

void solve(const std::vector<std::string>& b)
{
    const size_t n = b.size();

    std::vector<std::vector<unsigned>> v(n);
    for (size_t i = 0; i < n; ++i) {
        v[i].push_back(i + 1);
        for (size_t j = 0; j < n; ++j) {
            if (j != i && b[i][j] == '1')
                v[j].push_back(i + 1);
        }
    }

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> b(n);
    std::cin >> b;

    solve(b);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
