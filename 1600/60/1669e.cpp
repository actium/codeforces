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
    unsigned q = 0;
    for (char c = 'a'; c <= 'k'; ++c) {
        for (size_t i = 0; i < 2; ++i) {
            unsigned f[11] = {}, k = 0;
            for (const std::string& w : s) {
                if (w[i] != c)
                    continue;

                q += k++ - f[w[i^1] - 'a']++;
            }
        }
    }

    answer(q);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
