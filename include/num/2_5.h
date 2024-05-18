#include "base/seqList.h"
template<typename T>
bool delRedunInOrder(seqList<T>& L) {
    if (L.length <= 1) {
        return false;
    }
    int a = 1, b = 0;
    for (; a < L.length; a++) {
        if (L.data[a] == L.data[b]) {
            continue;
        }
        b++;
        L.data[b] = L.data[a];
    }
    L.length = b + 1;
    return true;
}