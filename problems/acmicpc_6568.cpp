#include <array>
#include <iostream>
#include <memory>
#include <optional>

struct state {
    std::array<uint8_t, 32> memory;
    uint8_t adder;
    uint8_t pc;
};

static state &get_global_state() {
    static state global_state{};
    return global_state;
}

static void init_global_state(std::array<std::string, 32> const &input) {
    auto &global_state = get_global_state();
    global_state.adder = 0;
    global_state.pc = 0;
    for(int i = 0; i < 32; i++) {
        for(char c : input[i]) {
            global_state.memory[i] = ((global_state.memory[i] << 1) | (c - '0'));
        }
    }
}

static inline uint8_t pp(uint8_t &v, uint8_t p) {
    uint8_t const val = v;
    v = ((v + 1) & p);
    return val;
}

static inline uint8_t mm(uint8_t &v, uint8_t p) {
    uint8_t const val = v;
    v = ((v - 1) & p);
    return val;
}

inline bool work() {
    auto &global_state = get_global_state();
    auto current_memory = global_state.memory[global_state.pc];
    pp(global_state.pc, 31);
    switch(current_memory >> 5) {
        case 0:
            global_state.memory[current_memory & 31] = global_state.adder;
            break;
        case 1:
            global_state.adder = global_state.memory[current_memory & 31];
            break;
        case 2:
            if(!global_state.adder) {
                global_state.pc = (current_memory & 31);
            }
            break;
        case 3:
            break;
        case 4:
            mm(global_state.adder, 255);
            break;
        case 5:
            pp(global_state.adder, 255);
            break;
        case 6:
            global_state.pc = (current_memory & 31);
            break;
        case 7:
            return false;
        default: __builtin_unreachable();
    }
    return true;
}

std::string output(uint8_t v) {
    std::string res;
    for(int x = 7; x >= 0; x--) {
        res += static_cast<char>(((v >> x) & 1) + '0');
    }
    return res;
}

void print_state(state const &st) {
    std::cout << "memory:\n";
    for(int i = 0; i < 32; i++) {
        std::string ln(std::to_string(i));
        while(ln.size() < 2) {
            ln = "0" + ln;
        }
        std::cout << ln << ": " << output(st.memory[i]) << '\n';
    }
    std::cout << "adder: " << output(st.adder) << '\n';
    std::cout << "pc: " << output(st.pc) << "\n\n";
}

bool get_input(std::array<std::string, 32> &input) {
    for(auto &str : input) {
        if(!(std::cin >> str)) return false;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    std::array<std::string, 32> input;
    while(get_input(input)) {
        init_global_state(input);
        while(work());
        std::cout << output(get_global_state().adder) << '\n';
    }
}