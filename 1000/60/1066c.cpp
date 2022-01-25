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

void solve(const std::vector<std::pair<char, unsigned>>& r)
{
    int k1 = 0, k2 = 0;

    std::vector<int> x(1 + 200000);
    for (const auto& q : r) {
        if (q.first == 'L') {
            x[q.second] = --k1;
        }
        if (q.first == 'R') {
            x[q.second] = ++k2;
        }
        if (q.first == '?') {
            const int c1 = -k1 + x[q.second], c2 = k2 - x[q.second];
            x[q.second] < 0 ? answer(std::min(c1, c2 - 1)) : answer(std::min(c1 - 1, c2));
        }
    }
}

int main()
{
    size_t q;
    std::cin >> q;

    std::vector<std::pair<char, unsigned>> r(q);
    std::cin >> r;

    solve(r);

    return 0;
}

