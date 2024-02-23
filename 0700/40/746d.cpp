#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(unsigned n, unsigned k, unsigned a, unsigned b)
{
    constexpr char t[2] = { 'G', 'B' };

    std::string s;
    {
        unsigned r[2] = { a, b };
        for (size_t x = (b > a); n != 0; x ^= 1) {
            if (r[x] == 0)
                return no_answer();

            const unsigned q = r[x] > r[x^1] ? std::min(r[x] - r[x^1], k) : 1;
            s.append(q, t[x]);
            r[x] -= q;
            n -= q;
        }
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, k, a, b;
    std::cin >> n >> k >> a >> b;

    solve(n, k, a, b);

    return 0;
}
