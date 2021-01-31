#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

class Set {
public:
    Set(std::initializer_list<unsigned> c) :
        c(c)
    {
        const auto r = std::minmax_element(c.begin(), c.end());
        d = *r.second - *r.first;
    }

    bool operator <(const Set& s) const
    {
        return d < s.d;
    }

private:
    std::vector<unsigned> c;
    unsigned d;

    friend std::ostream& operator <<(std::ostream& output, const Set& s)
    {
        const char* separator = "";
        for (const unsigned x : s.c) {
            output << separator << x;
            separator = " ";
        }
        return output;
    }
};

void answer(const Set& v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& c)
{
    Set b = { c[0].front(), c[1].front(), c[2].front(), c[3].front() };

    size_t d[4] = {};

    const auto done = [&] {
        for (size_t i = 0; i < 4; ++i) {
            if (d[i] + 1 < c[i].size())
                return false;
        }
        return true;
    };

    while (!done()) {
        size_t i = 0;
        for (size_t j = 1; j < 4; ++j) {
            if (c[j][d[j]] < c[i][d[i]])
                i = j;
        }

        ++d[i];

        b = std::min(b, { c[0][d[0]], c[1][d[1]], c[2][d[2]], c[3][d[3]] });
    }

    answer(b);
}

int main()
{
    std::vector<std::vector<unsigned>> c(4);
    for (size_t i = 0; i < 4; ++i) {
        size_t n;
        std::cin >> n;

        c[i].resize(n);
        std::cin >> c[i];

        std::sort(c[i].begin(), c[i].end());
    }

    solve(c);

    return 0;
}

