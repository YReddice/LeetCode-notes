## 目录
- [目录](#目录)
  - [1.array](#1array)
  - [2.vector](#2vector)
      - [vector用法](#vector用法)
      - [vector访问元素方式](#vector访问元素方式)
      - [vector操作元素](#vector操作元素)
  - [3.string](#3string)
  - [stack](#stack)

<a id="array"></a>
<br/>

### 1.array

* #include \<array>
* 创建具有 10 个 double 类型元素的 array 容器，也可以像创建常规数组那样对元素进行初始化：`std::array<double, 10> values {0.5,1.0,1.5,,2.0};`
* []的方式直接访问（不会检查索引是否越界）
* at(i)函数访问（会检查索引，越界时会抛出std::out_of_range异常）

<br/>

**支持的成员函数**
1. begin()	返回指向容器中第一个元素的随机访问迭代器。
2. end()	返回指向容器最后一个元素之后一个位置的随机访问迭代器，通常和 begin() 结合使用。
3. rbegin()	返回指向最后一个元素的随机访问迭代器。
4. rend()	返回指向第一个元素之前一个位置的随机访问迭代器。
5. cbegin()	和 begin() 功能相同，只不过在其基础上增加了 const 属性，不能用于修改元素。
6. cend()	和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
7. crbegin()	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
8. crend()	和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
9. size()	返回容器中当前元素的数量，其值始终等于初始化 array 类的第二个模板参数 N。
10. max_size()	返回容器可容纳元素的最大数量，其值始终等于初始化 array 类的第二个模板参数 N。
11. empty()	判断容器是否为空，和通过 size()==0 的判断条件功能相同，但其效率可能更快。
12. at(n)	返回容器中 n 位置处元素的引用，该函数自动检查 n 是否在有效的范围内，如果不是则抛出 out_of_range 异常。
13. front()	返回容器中第一个元素的直接引用，该函数不适用于空的 array 容器。
14. back()	返回容器中最后一个元素的直接应用，该函数同样不适用于空的 array 容器。
15. data()	返回一个指向容器首个元素的指针。利用该指针，可实现复制容器中所有元素等类似功能。
16. fill(val)	将 val 这个值赋值给容器中的每个元素。
17. array1.swap(array2)	交换 array1 和 array2 容器中的所有元素，但前提是它们具有相同的长度和类型。




<br/><br/><br/><br/><br/>
<a id="vector"></a>

### 2.vector
##### vector用法
* #include \<vector>
* 可以在创建的同时指定初始值以及元素个数: `std::vector<int> primes {2, 3, 5, 7, 11, 13, 17, 19};`
* 在创建 vector 容器时，也可以指定元素个数（默认初始值为0）：`std::vector<double> values(20);`
* 如果不想用 0 作为默认值，也可以指定一个其它值（变量也可以），例如：`std::vector<double> values(20, 1.0);` 或
```
int num=20;
double value =1.0;
std::vector<double> values(num, value);
```
* 通过存储元素类型相同的其它 vector 容器，也可以创建新的 vector 容器，例如：
```
std::vector<char>value1(5, 'c');
std::vector<char>value2(value1);
``` 
如果不想复制其它容器中所有的元素，可以用一对指针或者迭代器来指定初始值的范围，例如：
```
int array[]={1,2,3};
std::vector<int>values(array, array+2);//values 将保存{1,2}
std::vector<int>value1{1,2,3,4,5};
std::vector<int>value2(std::begin(value1),std::begin(value1)+3);//value2保存{1,2,3}
```

##### vector访问元素方式
* []的方式直接访问（不会检查索引是否越界）
* at(i)函数访问（会检查索引，越界时会抛出std::out_of_range异常）
* vector 容器还提供了 2 个成员函数，即 front() 和 back()，它们分别返回 vector 容器中第一个和最后一个元素的引用，通过利用这 2 个函数返回的引用
* vector 容器还提供了 data() 成员函数，该函数的功能是返回指向容器中首个元素的指针
  
##### vector操作元素
* push_back()成员函数在 vector 容器尾部添加一个元素
* insert()成员函数在 vector 容器的指定位置插入一个或多个元素：
  * iterator insert(pos,elem)	在迭代器 pos 指定的位置之前插入一个新元素elem，并返回表示新插入元素位置的迭代器。
  * iterator insert(pos,n,elem)	在迭代器 pos 指定的位置之前插入 n 个元素 elem，并返回表示第一个新插入元素位置的迭代器。
  * iterator insert(pos,first,last) 	在迭代器 pos 指定的位置之前，插入其他容器（不仅限于vector）中位于 [first,last) 区域的所有元素，并返回表示第一个新插入元素位置的迭代器。
  * iterator insert(pos,initlist)	在迭代器 pos 指定的位置之前，插入初始化列表（用大括号{}括起来的多个元素，中间有逗号隔开）中所有的元素，并返回表示第一个新插入元素位置的迭代器。
* 删除元素：
  * pop_back()	删除 vector 容器中最后一个元素，该容器的大小（size）会减 1，但容量（capacity）不会发生改变。
  * erase(pos)	删除 vector 容器中 pos 迭代器指定位置处的元素，并返回指向被删除元素下一个位置元素的迭代器。该容器的大小（size）会减 1，但容量（capacity）不会发生改变。
  * swap(beg)、pop_back()	先调用 swap() 函数交换要删除的目标元素和容器最后一个元素的位置，然后使用 pop_back() 删除该目标元素。
  * erase(beg,end)	删除 vector 容器中位于迭代器 [beg,end)指定区域内的所有元素，并返回指向被删除区域下一个位置元素的迭代器。该容器的大小（size）会减小，但容量（capacity）不会发生改变。
  * remove()	删除容器中所有和指定元素值相等的元素，并返回指向最后一个元素下一个位置的迭代器。值得一提的是，调用该函数不会改变容器的大小和容量。
  * clear()	删除 vector 容器中所有的元素，使其变成空的 vector 容器。该函数会改变 vector 的大小（变为 0），但不是改变其容量。

<br/>

**支持的成员函数**
1. begin()	返回指向容器中第一个元素的迭代器。
2. end()	返回指向容器最后一个元素所在位置后一个位置的迭代器，通常和 begin() 结合使用。
3. rbegin()	返回指向最后一个元素的迭代器。
4. rend()	返回指向第一个元素所在位置前一个位置的迭代器。
5. cbegin()	和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
6. cend()	和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
7. crbegin()	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
8. crend()	和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
9. size()	返回实际元素个数。
10. max_size()	返回元素个数的最大值。这通常是一个很大的值，一般是 232-1，所以我们很少会用到这个函数。
11. resize()	改变实际元素的个数。
12. capacity()	返回当前容量。
13. empty()	判断容器中是否有元素，若无元素，则返回 true；反之，返回 false。
14. reserve()	增加容器的容量。
15. shrink _to_fit()	将内存减少到等于当前元素实际所使用的大小。
16. operator[ ]	重载了 [ ] 运算符，可以向访问数组中元素那样，通过下标即可访问甚至修改 vector 容器中的元素。
17. at()	使用经过边界检查的索引访问元素。
18. front()	返回第一个元素的引用。
19. back()	返回最后一个元素的引用。
20. data()	返回指向容器中第一个元素的指针。
21. assign()	用新元素替换原有内容。
22. push_back()	在序列的尾部添加一个元素。
23. pop_back()	移出序列尾部的元素。
24. insert()	在指定的位置插入一个或多个元素。
25. erase()	移出一个元素或一段元素。
26. clear()	移出所有的元素，容器大小变为 0。
27. swap()	交换两个容器的所有元素。
28. emplace()	在指定的位置直接生成一个元素。
29. emplace_back()	在序列尾部生成一个元素。




<br/><br/><br/><br/><br/>
<a id="string"></a>

### 3.string

* #include \<string>
* string2char*:string 类为我们提供了一个转换函数 c_str()，该函数能够将 string 字符串转换为C风格的字符串，并返回该字符串的 const 指针（const char*）
* []直接访问字符串中字符
* 字符串可通过'+'拼接

**操作字符**
* 插入：insert() 函数可以在 string 字符串中指定的位置插入另一个字符串，原型为：`string& insert (size_t pos, const string& str);`
* 删除：erase() 函数可以删除 string 中的一个子字符串。原型为：`string& erase (size_t pos = 0, size_t len = npos);`
* 提取子字符串：substr() 函数用于从 string 字符串中提取子字符串，它的原型为：`string substr (size_t pos = 0, size_t len = npos) const;`

**字符串查找**
1. find():find() 函数用于在 string 字符串中查找子字符串出现的位置，它其中的两种原型为：第一个参数为待查找的子字符串，它可以是 string 字符串，也可以是C风格的字符串。第二个参数为开始查找的位置（下标）；如果不指明，则从第0个字符开始查找。
```
size_t find (const string& str, size_t pos = 0) const;
size_t find (const char* s, size_t pos = 0) const;
```

2. rfind():rfind() 和 find() 很类似，同样是在字符串中查找子字符串，不同的是 find() 函数从第二个参数开始往后查找，而 rfind() 函数则最多查找到第二个参数处，如果到了第二个参数所指定的下标还没有找到子字符串，则返回一个无穷大值4294967295。
3. find_first_of():find_first_of() 函数用于查找子字符串和字符串共同具有的字符在字符串中首次出现的位置。




<br/><br/><br/><br/><br/>
<a id="stack"></a>

### stack
* #include \<stack>
* 创建一个不包含任何元素的 stack 适配器，并采用默认的 deque 基础容器：`std::stack<int> values;`(底层采用 deque 基础容器的 stack 适配器。)

**支持的成员函数**
1. empty()	当 stack 栈中没有元素时，该成员函数返回 true；反之，返回 false。
2. size()	返回 stack 栈中存储元素的个数。
3. top()	返回一个栈顶元素的引用，类型为 T&。如果栈为空，程序会报错。
4. push(const T& val)	先复制 val，再将 val 副本压入栈顶。这是通过调用底层容器的 push_back() 函数完成的。
5. push(T&& obj)	以移动元素的方式将其压入栈顶。这是通过调用底层容器的有右值引用参数的 push_back() 函数完成的。
6. pop()	弹出栈顶元素。
7. emplace(arg...)	arg... 可以是一个参数，也可以是多个参数，但它们都只用于构造一个对象，并在栈顶直接生成该对象，作为新的栈顶元素。
8. swap(stack<T> & other_stack)	将两个 stack 适配器中的元素进行互换，需要注意的是，进行互换的 2 个 stack 适配器中存储的元素类型以及底层采用的基础容器类型，都必须相同。
