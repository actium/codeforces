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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::pair<char, unsigned>>& e)
{
    bool v[1000000] = {};

    unsigned c = 0, k = 0;
    for (const auto [t, i] : e) {
        if (t == '+') {
            ++c;
            v[i-1] = true;
            k = std::max(k, c);
        } else if (v[i-1]) {
            --c;
            v[i-1] = false;
        } else {
            ++k;
        }
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<char, unsigned>> e(n);
    std::cin >> e;

    solve(e);

    return 0;
}

