# CSP-CCF

## 3 简单模拟

3.4 日期处理
    
    A 日期差值：给出两个日期之间相差的天数
        idea：日期y1-m1-d1 < y2-m2-d2，不断增加date1直到达到date2，可以快速变化（直接加一个月或一年），参考《算法笔记》。       
    B Day-of-Week：给出年月日判断星期几
        A的变体，通过相差的天数mod 7可以判断出是星期几
    C 打印日期：给出年份和天数打印出对应的年月日
        A的变体，简单。
    D 日期类：计算下一天的日期
        不考虑闰年，及其简单。

3.5 进制转换
    
    A 又一版A+B：求A+B结果的x进制数
        用x一次次去除，每次得到的余数就是各位。
    B 数制转换：将a进制数n转换为b进制数
        ！！！注意conner case，当n=0，需要打印的不是空string，而是“0”，需要额外判断。
    C 进制转换：将30位十进制数字转化为二进制数
        ！！！注意用long long也不够，因为30*4=120位仍然不够
        ！需要训练大整数加减乘除
    D 八进制：将数字转化为8进制
        较简单

3.6 字符串处理

    A 字符串连接：不用标准库拼接两个字符串，过于沙雕。
    B 首字母大写：将一句string中的单词改为首字母大写。
        ！！！getline不会读入换行符'\n'，输出时还是需要"%s\n"
    C 字符串的查找删除：将一句string中的一个小子串（不分大小写）都删掉。
        ！erase时index就会即时变化
        ！！！`erase(s.begin() + i)` 参数是迭代器，不是index
    D 单词替换：
        使用replace方法即可。
    E 字符串去特定字符：简单。
    F 数组逆置：简单。
    G 比较字符串：简单。
    H 编排字符串：限制长度为4的队列
        一点点取模%的技巧。
    *I 【字符串】回文串：简单。

## 4 算法初步

4.1 排序

    B 特殊排序：挑出最大值后再排序，其实就是先排序再挑出最大值，简单。
    C EXCEL排序：struct排序，准备三个cmp
        ！struct初始化函数中似乎需要使用 `this->name = _name` 的格式
        ！！！sort含多个指标的时候一定要规定第一指标相等时何为第二指标。
    D 字符串内排序：过于简单
    E Problem B：计算方阵的行，列，对角线和并排序，非常简单，题目描述出错，多组数据说成只有1组
    F 小白鼠排队：按小白鼠重量排序输出颜色。
        典型struct排序，简单。
    G 中位数：找中文数，简单
    H 整数奇偶排序：
    I 排名：

4.2 散列

    A 谁是你的潜在朋友：
    B 分组统计：输入“数字-组号”，需要统计每个组中出现的数字的数目（0个也需要统计）。
        idea：题目没有给出“数字”和“组号”的范围，所以需要使用map来将其映射为index，较为复杂容易出错。
    C Be Unique (20)：连续出现数字，第一个全程没有被重复的数字是unique的。
        idea：使用queue和hash数据结构，需要伪代码思维缜密。
    D String Subtraction (20)：两个字符串s1,s2，将s1中所有在s2中出现的字符都去除。
        idea：hash[128]并扫描一遍s2就可以了。

4.3 递归

    A 吃糖果：超简单的斐波那契数列递归N<20。
        自己写了个打表的程序。
    B 数列：打印斐波那契数列，字符画，无聊。
    C 神奇的口袋：N比较小没有必要动态规划，但是纯写递归没有意思
    D 八皇后：经典问题

4.4 贪心

    A 看电视：区间问题，贪心策略是end最早，编写程序简单
        ！使用 `pair<int,int>` 来记录区间
    B 出租车费：
        ！！！float的精度是有限的，别忘了可以使用double类型
    C To Fill or Not to Fill：
    D Repair the Wall：用不同大小的砖块填补一个缝隙，用的越少越好
        ！使用 `fill(A, A+N, 0)` 来清空数组，常用的方法。
        贪心策略很简单，只要使用尽可能大的砖块。
    E FatMouse's Trade：
        ！！！浮点数处理一定要小心
        ！！！涉及到除法一定要记得，整数除法得到的商仍然是整数，需要小数的时候记得用double
    F 迷瘴：
        重点在于浮点数除法以及比较的处理
        ！！！注意`<`和`<=`的区别
    G 找零钱：非常简单的问题，用尽可能少的钞票买东西

4.5 二分

    A ：
    B ：
    C ：
    D ：

4.6 two pointers

    A ：
    B ：
    C ：
    D ：

4.7 其他高校技巧及算法

    A：

## 5 数学问题

## 6 C++标准库

6.1 vector的常见用法详解

    A Course List for Student (25)：输入每门课程的学生名单，得到每名学生的课程名单
        ！关键在于设计数据结构，学生为string，课程名单用vector<int>表示，就可以用一个map来保存这种关系
        ！！！使用getline涉及%*c容易出错，对于短小的数据还不如使用cin >> name。
    B Student List for Course (25)：

6.2 set的常见用法详解

    A Set Similarity (25)：计算两个集合的相似度（交集/并集）
        ！使用STL自带的交集并集函数，非常方便，将集合sa和sb运算的结果保存在sc中。
            set_intersection(sa.begin(), sa.end(), sb.begin(), sb.end(), inserter(sc, sc.begin()));
            set_union       (sa.begin(), sa.end(), sb.begin(), sb.end(), inserter(sc, sc.begin()));

6.3 string的常见用法详解

    A 字符串处理： 

6.4 map的常见用法详解

    A Speech Patterns (25)：计算一句话中最频繁的词的出现次数
        ！！！需要考虑输入为空串的corner case
        ！多组输入一定要记得//initial清空容器的操作再开始输入
        ！使用map[]记得先find确定是否存在

6.5 queue的常见用法详解

    A C语言-数字交换：本题过于简单，不需要使用queue，直接找到最大最小值swap即可。

6.6 priority_queue的常见用法详解

    A 任务调度：
        ！使用friend bool <() {}设计struct的大小关系，用于优先队列。
        ！！！设计比较函数需要考虑尽可能多的情况，尤其是对于相等的情况题目可能对顺序有所规定（使得正确答案唯一）。

6.7 stack的常见用法详解

    A 简单计算器：四则运算计算器，精确到小数点后两位。
        自己设置的计算器不需要将中缀表达式转化为后缀表达式，最终运算结果oprt栈为空，oprd仅剩1个元素（最终结果）。
    B Problem E：判断三种括号匹配是否正确。
        ！！！需要注意清空的位置（可以通过使用多个测试样例来判断）。
    
6.8 pair的常见用法详解

6.9 algorithm头文件下常用的函数

## 7 数据结构专题1：栈，队列，链表

7.1 栈的应用（同6.7）

7.2 队列的应用（同6.8）

7.3 链表处理

    A 算法2-8~2-11：链表的基本操作：繁琐恶心恶心恶心TMD不想写。
        ！！！
    B C语言-链表排序：输入两个链表，结点有一定顺序，合并链表。
        利用集合内部自动排序没有超时，如果时间卡得紧应该使用类似归并排序的双指针策略。
    C 最快合并链表(线性表)：把两个链表按照“最快”速度拼起来。
        毫无意义，让我拼我就拼啊，直接分别保存按顺序输出就是了。
    D 算法2-24 单链表反转：把链表正序反序输出。
        只反序可以用stack，但是要正序的话就只能用vector了，记得清空vector。
    E 算法2-25 有序单链表删除重复元素：根据一个递增的整数序列构造有序单链表，删除其中的重复元素（逼我用set？）
        更简单的思路，一个vector，一个set，一个之后sort，一个自动排序去重，简单粗暴。

## 8 搜索

8.1 深度优先搜索（DFS）

8.2 广度优先搜索（BFS）

## 9 数据结构专题2：树，并查集，堆

9.1 树与二叉树

9.2 二叉树的遍历

9.3 

## 10 图算法专题

## 11 动态规划专题

## 12 字符串专题

```
6-1-A：答案错误81
```