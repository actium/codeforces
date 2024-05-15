#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<unsigned>& d)
{
    const size_t n = d.size();

    unsigned f[10] = {};
    for (const unsigned x : d)
        ++f[x];

    if (f[0] == 0)
        return no_answer();

    unsigned s = 0;
    for (unsigned i = 1; i < 10; ++i)
        s += i * f[i];

    s %= 3;

    for (unsigned i = s; i < 10 && s != 0; i += 3) {
        if (f[i] != 0) {
            --f[i];
            s = 0;
        }
    }
    for (unsigned i = 3 - s; i < 10 && s != 0; i += 3) {
        if (f[i] == 0)
            continue;

        for (unsigned j = 3 - s; j < 10 && s != 0; j += 3) {
            if (f[j] > (j == i)) {
                --f[i];
                --f[j];
                s = 0;
            }
        }
    }

    std::string t;
    for (unsigned i = 9; i > 0; --i)
        t.append(f[i], '0' + i);

    t.append(t.empty() ? 1 : f[0], '0');

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> d(n);
    std::cin >> d;

    solve(d);

    return 0;
}
