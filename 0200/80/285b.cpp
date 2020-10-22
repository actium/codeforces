#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& p, unsigned s, unsigned t)
{
    unsigned k = 0;
    for (std::vector<bool> v(p.size()); s != t; s = p[s-1], ++k) {
        if (v[s-1])
            return no_answer();

        v[s-1] = true;
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned s, t;
    std::cin >> s >> t;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p, s, t);

    return 0;
}

