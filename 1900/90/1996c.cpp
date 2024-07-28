#include <iostream>
#include <string>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

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

void solve(const std::string& a, const std::string& b, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = a.length();

    std::vector<int> pf[26];
    for (size_t i = 0; i < 26; ++i)
        pf[i].resize(1+n);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < 26; ++j)
            pf[j][i+1] = pf[j][i];

        ++pf[b[i]-'a'][i+1];
        --pf[a[i]-'a'][i+1];
    }

    for (const std::pair<unsigned, unsigned>& q : r) {
        unsigned k = 0;
        for (size_t i = 0; i < 26; ++i)
            k += std::abs(pf[i][q.second] - pf[i][q.first-1]);

        answer(k / 2);
    }
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::string a, b;
    std::cin >> a >> b;

    std::vector<std::pair<unsigned, unsigned>> r(q);
    std::cin >> r;

    solve(a, b, r);
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
