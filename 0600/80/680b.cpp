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

void solve(const std::vector<unsigned>& t, size_t a)
{
    const size_t n = t.size();

    unsigned k = t[--a];
    for (size_t d = 1; d < std::max(a+1, n-a); ++d) {
        if (d <= a && a+d < n) {
            if (t[a-d] == 1 && t[a+d] == 1)
                k += 2;
        } else if (d <= a) {
            k += t[a-d];
        } else {
            k += t[a+d];
        }
    }

    answer(k);
}

int main()
{
    size_t n, a;
    std::cin >> n >> a;

    std::vector<unsigned> t(n);
    std::cin >> t;

    solve(t, a);

    return 0;
}

