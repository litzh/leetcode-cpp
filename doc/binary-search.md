# 二分查找

> 尽管二分查找的基本思想相对简单，但细节可以令人难以招架 ... — 高德纳

在写二分查找类型的问题时，思路很清晰，但很难一次性写出正确的代码，总是在各种边界条件的处理上出现问题。常常陷入面向测试用例编程的困境，代码中充斥着各种 `if` 的补丁。为了加深理解，本文将细致分析实现的细节。

## 上下界

```c++
template<class ForwardIt, class T>
ForwardIt upper_bound(ForwardIt first, ForwardIt last, const T& value)
{
    ForwardIt it;
    typename std::iterator_traits<ForwardIt>::difference_type count, step;
    count = std::distance(first, last);
 
    while (count > 0)
    {
        it = first; 
        step = count / 2; 
        std::advance(it, step);
 
        if (!(value < *it))
        {
            first = ++it;
            count -= step + 1;
        } 
        else
            count = step;
    }
 
    return first;
}
```
