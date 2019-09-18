#include <stdio.h>
#include <unordered_map>

using namespace std;

unordered_map<char, int> values;

struct player {
    unordered_map<char, int> card_counts;
    int min_count;
    char min_char;
    int max_count;
    char max_char;
    bool has_wildcard;
    bool just_got_wildcad;

    bool add_card(char card) {
        int count = ++card_counts[card];
        if (count > max_count) {
            max_count = count;
            max_char = card;
            if (max_count == 4) {
                return true;
            }
        }
        if (count < min_count ||
            (count == min_count && values[card] < values[min_char])) {
            min_count = count;
            min_char = card;
        }
        return false;
    }

    void remove_card(char card) {
        int count = --card_counts[card];
        if (count > max_count) {
            max_count = count;
            max_char = card;
        }
        if (count < min_count) {
            min_count = count;
            min_char = card;
        }
    }
};

const int N = 13;
player players[N + 2] = {};
int n, k;

int next_turn(int now) {
    return (now + 1) % n;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        char a, b, c, d;
        scanf(" %c%c%c%c", &a, &b, &c, &d);
        players[i].add_card(a);
        players[i].add_card(b);
        players[i].add_card(c);
        players[i].add_card(d);
    }

    int turn = k - 1;
    players[turn].has_wildcard = 1;
    players[turn].just_got_wildcad = 1;

    while (true) {
        auto current = players[turn];
        int next = next_turn(turn);
        if (current.has_wildcard && !current.just_got_wildcad) {
            current.has_wildcard = 0;
            players[next].has_wildcard = 1;
            players[next].just_got_wildcad = 1;
        }
    }
}
