# 二分查找

> 尽管二分查找的基本思想相对简单，但细节可以令人难以招架 ... — 高德纳

在写二分查找类型的问题时，思路很清晰，但很难一次性写出正确的代码，总是在各种边界条件的处理上出现问题。常常陷入面向测试用例编程的困境，代码中充斥着各种 `if` 的补丁。为了加深理解，本文将细致分析实现的细节。

本文采用 C++ 风格的左闭右开区间表示数组，下标从 `0` 开始，数组升序排列。

## 上界

```c++
template<class ForwardIt, class T>
ForwardIt upper_bound(ForwardIt first, ForwardIt last, const T& value) {
    ForwardIt it;
    typename std::iterator_traits<ForwardIt>::difference_type count, step;
    count = std::distance(first, last);
 
    while (count > 0) {
        it = first; 
        step = count / 2; 
        std::advance(it, step);
 
        if (!(value < *it)) {
            first = ++it;
            count -= step + 1;
        } else {
            count = step;
        }
    }
 
    return first;
}
```

### 算法

1. 数组长度 `last - first > 0`
2. 令数组长度 `count = last - first`，将数组划分为 3 部分：
   1. `[first, count / 2)`，左区间
   2. `[count / 2]`，中间值
   3. `[count / 2 + 1, last)`，右区间
3. 如果中间值 `it <= value`，数组更新为右区间，否则更新为左区间。

### 分析

1. 数组划分为三个部分必需覆盖整个数组；
2. 取中间值的前提是数组非空，因此循环条件要求 `count > 0`；
3. `count == 1` 时，左区间为空，`first` 为中间值；
4. `count == 2` 时，右区间为空，`first` 不存在。
