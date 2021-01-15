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

struct Foul {
    unsigned t;
    char l;
    unsigned m;
    char c;
};

std::istream& operator >>(std::istream& input, Foul& v)
{
    input >> v.t >> v.l >> v.m >> v.c;
    v.l = (v.l == 'a');
    return input;
}

void solve(const std::string& s, const std::string& t, const std::vector<Foul>& f)
{
    const auto team = [&](size_t i) {
        return i == 0 ? s : t;
    };

    unsigned v[100][2] = {};
    for (const auto& q : f) {
        unsigned& t = v[q.m][q.l];
        if ((q.c == 'y' && t >= 1 && t <= 90) || (q.c == 'r' && t <= 90)) {
            std::cout << team(q.l) << ' ' << q.m << ' ' << q.t << '\n';
            t = 90;
        }
        t += q.t;
    }
}

int main()
{
    std::string s, t;
    std::cin >> s >> t;

    size_t n;
    std::cin >> n;

    std::vector<Foul> f(n);
    std::cin >> f;

    solve(s, t, f);

    return 0;
}

