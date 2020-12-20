#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

using integer = unsigned long long;

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& v, integer s)
{
    const size_t n = v.size();

    integer q = v[0], t = 0;
    for (const unsigned x : v) {
        q = std::min<unsigned>(q, x);
        t += x;
    }

    if (s <= t)
        return answer(std::min((t - s) / n, q));

    no_answer();
}

int main()
{
    size_t n;
    std::cin >> n;

    integer s;
    std::cin >> s;

    std::vector<unsigned> v(n);
    std::cin >> v;

    solve(v, s);

    return 0;
}

