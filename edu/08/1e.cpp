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

void solve(const std::vector<unsigned>& d)
{
    const size_t n = d.size();

    unsigned k = 0, q = 0, s = 0, z = 0;
    for (const unsigned x : d) {
        k += x % 2;
        q += (x == 1);
        s += x;
        z += (x == 0);
    }

    if (n > 1 && (q < 2 || z > 0))
        return answer(false);

    answer(k % 2 == 0 && s + 2 == n * 2);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> d(n);
    std::cin >> d;

    solve(d);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
