#include <iostream>
#include <vector>

struct Road {
    size_t x;
    size_t y;
    unsigned w;
};

std::istream& operator >>(std::istream& input, Road& v)
{
    return input >> v.x >> v.y >> v.w;
}

struct Route {
    size_t a;
    size_t b;
};

std::istream& operator >>(std::istream& input, Route& v)
{
    return input >> v.a >> v.b;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(size_t n, const std::vector<Road>& roads, const std::vector<Route>& routes)
{
    constexpr unsigned oo = ~0u >> 1;

    std::vector<std::vector<unsigned>> distance_map(1+n, std::vector<unsigned>(1+n, oo));
    for (size_t i = 1; i <= n; ++i) {
        distance_map[i][i] = 0;
    }
    for (const Road& road : roads) {
        distance_map[road.x][road.y] = road.w;
        distance_map[road.y][road.x] = road.w;
    }
    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= n; ++j) {
            for (size_t k = j+1; k <= n; ++k) {
                if (distance_map[j][k] > distance_map[j][i] + distance_map[i][k]) {
                    distance_map[j][k] = distance_map[j][i] + distance_map[i][k];
                    distance_map[k][j] = distance_map[j][i] + distance_map[i][k];
                }
            }
        }
    }

    integer total_cost = 0;
    for (const Route& route : routes)
        total_cost += distance_map[route.a][route.b];

    integer max_delta = 0;
    for (const Road& road : roads) {
        integer delta = 0;
        for (const Route& route : routes) {
            const unsigned initial_cost = distance_map[route.a][route.b];

            const unsigned c1 = distance_map[route.a][road.x] + distance_map[road.y][route.b];
            const unsigned c2 = distance_map[route.a][road.y] + distance_map[road.x][route.b];

            const unsigned updated_cost = std::min(c1, c2);
            if (updated_cost < initial_cost)
                delta += initial_cost - updated_cost;
        }
        max_delta = std::max(max_delta, delta);
    }

    answer(total_cost - max_delta);
}

int main()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<Road> roads(m);
    std::cin >> roads;

    std::vector<Route> routes(k);
    std::cin >> routes;

    solve(n, roads, routes);

    return 0;
}

