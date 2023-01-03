#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct Column;
struct Cell { Column *pre, *nex; };


struct Column { int value; vector<Cell> cells; };

struct skiplist {
    static const int MAX_LEVEL = 20;
    Column *head, *tail;

    void init() {
        head = new Column;
        tail = new Column;
        head->value = 0; tail->value = 0;
        for (int i = 0; i < MAX_LEVEL; i++) {
            head->cells.push_back({NULL, tail});
            tail->cells.push_back({head, NULL});
        }
    };
    bool isempty() {
        return head->cells[0].nex == tail;
    }
    Column *lower_bound(int value) {
        Column *cur = head;
        for (int level = MAX_LEVEL-1; level >= 0; level--) 
            while (cur->cells[level].nex != tail && cur->cells[level].nex->value < value)
                cur = cur->cells[level].nex;
        return cur->cells[0].nex;
    }
    void insert(int value) {
        Column *tem = lower_bound(value);
        if (tem != tail && tem->value == value) 
            return;
        delete tem;

        Column *insert_col = new Column;
        insert_col->value = value;
        do
            insert_col->cells.push_back({NULL, NULL});
        while (insert_col->cells.size() < MAX_LEVEL && rand() % 2);

        Column *cur = head;
        for (int level = MAX_LEVEL-1; level >= 0; level--) {
            while (cur->cells[level].nex != tail && cur->cells[level].nex->value < value)
                cur = cur->cells[level].nex;
            if (level < insert_col->cells.size()) {
                Column *next_cur = cur->cells[level].nex;
                cur->cells[level].nex = insert_col;
                next_cur->cells[level].pre = insert_col;
                insert_col->cells[level].pre = cur;
                insert_col->cells[level].nex = next_cur;
            }
        }
    }
    void erase(int value) {
        Column *target = lower_bound(value);
        if (target == tail || target->value != value)
            return;
        
        Column *cur = head;
        for (int level = MAX_LEVEL-1; level >= 0; level--) {
            while (cur->cells[level].nex != tail && cur->cells[level].nex->value <= value)
                cur = cur->cells[level].nex;
            if (cur == target) {
                Column *pre = cur->cells[level].pre, *nex = cur->cells[level].nex;
                pre->cells[level].nex = nex;
                nex->cells[level].pre = pre;
            }
        }
        delete target;
    }
};
