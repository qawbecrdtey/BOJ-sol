#include <cassert>
#include <iostream>
#include <optional>
#include <utility>
using namespace std;
struct shark {
    int velocity;
    int size;
    pair<int, int> direction;
    shark(int velocity, int size, pair<int, int> direction)
     :  velocity(velocity), size(size), direction(std::move(direction)) {}
    bool operator<(shark &s) const { return size < s.size; }
};
inline optional<shark> **make_plate(int r, int c) {
    auto plate = new optional<shark>*[r + 1];
    for(int i = 1; i <= r; i++) {
        plate[i] = new optional<shark>[c + 1];
    }
    return plate;
}
inline void delete_plate(int r, optional<shark> **plate) {
    for(int i = 1; i <= r; i++) {
        delete[] plate[i];
    }
    delete[] plate;
}
inline void catch_shark(int &size_sum, int r, int cur, optional<shark> **plate) {
    for(int i = 1; i <= r; i++) {
        if(plate[i][cur] != nullopt) {
            size_sum += plate[i][cur]->size;
            plate[i][cur] = nullopt;
            break;
        }
    }
}
inline void move_shark(int r, int c, optional<shark> **old_plate, optional<shark> **new_plate, int shark_r, int shark_c) {
    if(old_plate[shark_r][shark_c]->direction.first) { // r
        int next_r = ((shark_r - 1 + old_plate[shark_r][shark_c]->direction.first * old_plate[shark_r][shark_c]->velocity) % (2 * (r - 1)) + 2 * (r - 1)) % (2 * (r - 1)) + 1;
        if(next_r > r - 1) {
            next_r = 2 * r - next_r;
            old_plate[shark_r][shark_c]->direction.first = -old_plate[shark_r][shark_c]->direction.first;
        }
        if(new_plate[next_r][shark_c] != nullopt && *old_plate[shark_r][shark_c] < *new_plate[next_r][shark_c]) return;
        new_plate[next_r][shark_c] = std::move(old_plate[shark_r][shark_c]);
    }
    else { // c
        int next_c = ((shark_c - 1 + old_plate[shark_r][shark_c]->direction.second * old_plate[shark_r][shark_c]->velocity) % (2 * (c - 1)) + 2 * (c - 1)) % (2 * (c - 1)) + 1;
        if(next_c > c - 1) {
            next_c = 2 * c - next_c;
            old_plate[shark_r][shark_c]->direction.second = -old_plate[shark_r][shark_c]->direction.second;
        }
        if(new_plate[shark_r][next_c] != nullopt && *old_plate[shark_r][shark_c] < *new_plate[shark_r][next_c]) return;
        new_plate[shark_r][next_c] = std::move(old_plate[shark_r][shark_c]);
    }
}
inline void move_sharks(int r, int c, optional<shark> **plate) {
    auto new_plate = make_plate(r, c);
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            if(plate[i][j] == nullopt) continue;
            move_shark(r, c, plate, new_plate, i, j);
        }
    }
    for(int i = 1; i <= r; i++) {
        swap(plate[i], new_plate[i]);
    }
    delete_plate(r, new_plate);
}
inline pair<int, int> convert_dir(int dir) {
    switch(dir) {
        case 1: return { -1, 0 };
        case 2: return { 1, 0 };
        case 3: return { 0, 1 };
        case 4: return { 0, -1 };
        default: __builtin_unreachable();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int r, c, m; cin >> r >> c >> m;
    auto plate = make_plate(r, c);
    for(int i = 0; i < m; i++) {
        int shark_r, shark_c, speed, dir, size;
        cin >> shark_r >> shark_c >> speed >> dir >> size;
        plate[shark_r][shark_c] = make_optional<shark>(speed, size, convert_dir(dir));
    }
    int size_sum = 0;
    for(int i = 1; i <= c; i++) {
        catch_shark(size_sum, r, i, plate);
        move_sharks(r, c, plate);
    }
    cout << size_sum;
}