#include <iostream>
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

void solve(const std::vector<unsigned>& s)
{
    const size_t n = s.size();

    std::vector<unsigned> q(1 + n);
    for (size_t i = n; i > 0; --i)
        q[i-1] = q[i] + (s[i-1] == 1);

    unsigned k = 0;
    for (size_t i = 0, z = 0; i < n; ++i) {
        z += (s[i] == 0);
        k = std::max<unsigned>(k, z + q[i]);
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
