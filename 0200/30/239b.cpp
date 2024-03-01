#include <iostream>
#include <string>
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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

std::vector<unsigned> interpret(std::string& p)
{
    std::vector<unsigned> f(10);
    {
        int x = 0, d = 1;
        while (x >= 0 && x < p.length()) {
            switch (p[x]) {
                case '<':
                    --x;
                    if (x >= 0 && (p[x] == '<' || p[x] == '>'))
                        p.erase(p.begin() + x + 1);
                    d = -1;
                    break;

                case '>':
                    ++x;
                    if (x < p.length() && (p[x] == '<' || p[x] == '>'))
                        p.erase(--x + p.begin());
                    d = 1;
                    break;

                default:
                    ++f[p[x]-'0'];
                    if (p[x]-- == '0') {
                        p.erase(p.begin() + x);
                        x -= (d == -1);
                    } else {
                        x += d;
                    }
            }
        }
    }
    return f;
}

void solve(const std::string& p, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    for (const std::pair<unsigned, unsigned>& q : r) {
        std::string s = p.substr(q.first - 1, q.second - q.first + 1);
        answer(interpret(s));
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, q;
    std::cin >> n >> q;

    std::string p;
    std::cin >> p;

    std::vector<std::pair<unsigned, unsigned>> r(q);
    std::cin >> r;

    solve(p, r);

    return 0;
}
