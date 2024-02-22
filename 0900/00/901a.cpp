#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

std::ostream& operator <<(std::ostream& output, const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        output << separator << x;
        separator = " ";
    }

    return output;
}

void answer(const std::vector<unsigned>& x, const std::vector<unsigned>& y)
{
    std::cout << "ambiguous" << '\n';
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void no_answer()
{
    std::cout << "perfect" << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    size_t x = 2;
    while (x < n && (a[x-1] < 2 || a[x] < 2))
        ++x;

    if (x == n)
        return no_answer();

    std::vector<unsigned> p[2];
    for (size_t i = 0; i < n; ++i) {
        const size_t v = p[0].size();

        for (size_t j = 0; j < a[i]; ++j) {
            if (i != x) {
                p[0].push_back(v);
                p[1].push_back(v);
            } else {
                p[0].push_back(v - (j == 0));
                p[1].push_back(v);
            }
        }
    }

    answer(p[0], p[1]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t h;
    std::cin >> h;

    std::vector<unsigned> a(1 + h);
    std::cin >> a;

    solve(a);

    return 0;
}
