#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& t, unsigned a, unsigned b)
{
    unsigned c = 0, k = 0;
    for (const unsigned x : t) {
        if (x == 1) {
            if (a > 0) {
                --a;
                continue;
            }
            if (b > 0) {
                --b, ++c;
                continue;
            }
            if (c > 0) {
                --c;
                continue;
            }
            ++k;
        } else {
            if (b > 0) {
                --b;
                continue;
            }
            k += 2;
        }
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned a, b;
    std::cin >> a >> b;

    std::vector<unsigned> t(n);
    std::cin >> t;

    solve(t, a, b);

    return 0;
}

