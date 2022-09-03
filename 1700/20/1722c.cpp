#include <iostream>
#include <map>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void solve(const std::vector<std::vector<std::string>>& w)
{
    std::map<std::string, unsigned> f;
    for (size_t i = 0; i < 3; ++i) {
        for (const std::string& s : w[i])
            ++f[s];
    }

    std::vector<unsigned> v(3);
    for (size_t i = 0; i < 3; ++i) {
        for (const std::string& s : w[i]) {
            switch (f[s]) {
                case 1: v[i] += 3; break;
                case 2: v[i] += 1; break;
            }
        }
    }

    answer(v[0], v[1], v[2]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<std::string>> w(3, std::vector<std::string>(n));
    std::cin >> w;

    solve(w);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
