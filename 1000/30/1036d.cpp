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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b)
{
    unsigned k = 0;
    {
        unsigned long long s[2] = {};
        while (!a.empty() && !b.empty()) {
            if (s[0] < s[1]) {
                s[0] += a.back();
                a.pop_back();
            } else {
                s[1] += b.back();
                b.pop_back();
            }
            k += (s[0] == s[1]);
        }
        while (!a.empty()) {
            s[0] += a.back();
            a.pop_back();
            k += (s[0] == s[1]);
        }
        while (!b.empty()) {
            s[1] += b.back();
            b.pop_back();
            k += (s[0] == s[1]);
        }

        if (s[0] != s[1])
            return no_answer();
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    size_t m;
    std::cin >> m;

    std::vector<unsigned> b(m);
    std::cin >> b;

    solve(a, b);

    return 0;
}
