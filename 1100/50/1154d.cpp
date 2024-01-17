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

void solve(const std::vector<unsigned>& s, unsigned b, unsigned a)
{
    const size_t n = s.size();

    size_t x = 0;
    for (unsigned c = a; x < n && b + c != 0; ++x) {
        if (b != 0 && (c == 0 || s[x] == 1 && c != a)) {
            --b;
            c += s[x];
        } else {
            --c;
        }
    }

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned b, a;
    std::cin >> b >> a;

    std::vector<unsigned> s(n);
    std::cin >> s;

    solve(s, b, a);

    return 0;
}
