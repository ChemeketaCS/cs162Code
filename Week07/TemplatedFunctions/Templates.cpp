#include "Templates.h"

//Regular function implemented in .cpp
int simpleSmaller(int x, int y) {
    if (x < y)
        return x;
    else
        return y;
}


//////Templated function should NOT be here, does no good...
//template <typename T>
//T smaller(T x, T y)
//{
//    if (x < y)
//        return x;
//    else
//        return y;
//}
