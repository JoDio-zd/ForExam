#include "base/sqList.h"
/**
 * @brief 核心思想与删除某个特定的元素是一样的，都是一个指针前进检测，一个指针用于更新
*/
template<typename T>
bool delSToT(sqList<T>& L, T s, T t) {
    int a = 0, b = 0;
    if (L.length == 0 || s > t) {
        return false;
    }
    for (; a < L.length - 1; a++) {
        if (L.data[a] < s || L.data[a] > t) {
            continue;
        }
        L.data[b] = L.data[a];
        b++;
    }
    L.length = b;
    return true;
}