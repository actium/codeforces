#include <iostream>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

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

void solve(std::vector<std::pair<unsigned, unsigned>>& c, unsigned a, unsigned b)
{
    const size_t n = c.size();

    const auto check = [=](std::pair<unsigned, unsigned>& x, std::pair<unsigned, unsigned>& y) {
        for (unsigned i = 0; i < 2; ++i) {
            for (unsigned j = 0; j < 2; ++j) {
                if (x.first + y.first <= a && x.second <= b && y.second <= b)
                    return true;

                if (x.first <= a && y.first <= a && x.second + y.second <= b)
                    return true;

                if (x.first + y.first <= b && x.second <= a && y.second <= a)
                    return true;

                if (x.first <= b && y.first <= b && x.second + y.second <= a)
                    return true;

                std::swap(y.first, y.second);
            }

            std::swap(x.first, x.second);
        }
        return false;
    };

    unsigned s = 0;
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (check(c[i], c[j]))
                s = std::max(s, c[i].first * c[i].second + c[j].first * c[j].second);
        }
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned a, b;
    std::cin >> a >> b;

    std::vector<std::pair<unsigned, unsigned>> c(n);
    std::cin >> c;

    solve(c, a, b);

    return 0;
}
