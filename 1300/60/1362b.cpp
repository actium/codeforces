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

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(std::vector<size_t>& s)
{
    const size_t n = s.size();

    std::sort(s.begin(), s.end());

    std::vector<size_t> z;
    for (size_t i = 1; i < n; ++i) {
        const size_t k = s[i] ^ s[0];

        z = s;
        std::for_each(z.begin(), z.end(), [k](size_t& x) { x ^= k; });
        std::sort(z.begin(), z.end());
        if (z == s)
            return answer(k);
    }

    answer(-1);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<size_t> s(n);
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

