# 数学题选做以及数学知识学习笔记（持续更新ing）

由于只是杂碎的学一学，就按照题目来进行整理了

[TOC]

## 把学过的公式统计一下：

$$
\binom{n}{k}\times k^{\underline{m}}=\frac{n!}{k!(n-k)!}\times \frac{k!}{(k-m)!}=\frac{n!}{(n-k)!(k-m)!}=\frac{n!}{(n-m)!}\times\frac{(n-m)!}{(n-k)!(k-m)}=\binom{n-m}{k-m}\times n^{\underline{m}}
$$

$$
\sum_{i=0}^k\binom{n}{i}\binom{m}{k-i}=\binom{n+m}{k}
$$

$$
\binom{n}{i}\binom{i}{j}=\frac{n!}{i!(n-i)!}\times\frac{i!}{j!(i-j)!}=\frac{n!}{(n-i)!j!(i-j)!}=\frac{n!(n-j)!}{(n-i)!(i-j)!(n-j)!j!}=\frac{n!}{(n-j)!j!}\times\frac{(n-j)!}{(n-i)!(i-j)!}=\binom{n}{j}\binom{n-j}{i-j}
$$


$$
f_i=\sum_{i=0}^n\binom{n}{i}(-1)^{n-i}g_i
$$


## P6620 [省选联考 2020 A 卷] 组合数问题

计算 
$$\left(\sum_{k=0}^{n}f(k)\times x^k\times \binom{n}{k}\right)\bmod p$$ 
的值。

这个地方要引入一个东西叫做下降幂，因为我们发现这个多项式摆在这里很奇怪/yun，我们把它展开：
$$
f(x)=\sum_{i=0}^{m}a_ix^i
$$
把这个东西转化成一个下降幂多项式
$$
f(x)=\sum_{i=0}^{m}a_ix^i=\sum_{i=0}^{m}b_ix^{\underline{i}}
$$
然后我们知道下降幂跟组合数有一个比较好的结合方式即：
$$
\binom{n}{k}\times k^{\underline{m}}=\frac{n!}{k!(n-k)!}\times \frac{k!}{(k-m)!}=\frac{n!}{(n-k)!(k-m)!}=\frac{n!}{(n-m)!}\times\frac{(n-m)!}{(n-k)!(k-m)}=\binom{n-m}{k-m}\times n^{\underline{m}}
$$
那我们把式子结合一下就是：
$$
\sum_{k=0}^{n}\sum_{i=0}^{m}b_ik^{\underline{i}}\times x^k \times \binom{n}{k}
\newline
=\sum_{k=0}^{n}\sum_{i=0}^{m}b_in^{\underline{i}}\times x^k \times \binom{n-i}{k-i}
\newline
=\sum_{i=0}^{m}b_in^{\underline{i}}\sum_{k=0}^{n}x^k\times\binom{n-i}{k-i}
$$

然后改为枚举$k-i$

$$
=\sum_{i=0}^{m}b_in^{\underline{i}}\sum_{k=0}^{n-i}x^{k+i}\times\binom{n-i}{k}
\newline
=\sum_{i=0}^{m}b_in^{\underline{i}}x^i\sum_{k=0}^{n-i}x^k\times\binom{n-i}{k}
\newline
=\sum_{i=0}^{m}b_in^{\underline{i}}x^i(x+1)^{n-i}
$$

但是我们只知道$a$不知道$b$啊，所以这里还要把下降幂多项式转回去

$$
x^n=\sum_{i=0}^{n} {n \brace i}x^{\underline{i}}
$$
带入一下就是
$$
\sum_{i=0}^{m}a_ix^i
\newline
=\sum_{i=0}^{m}a_i\sum_{k=0}^{i}{i \brace k}x^{\underline{k}}
\newline
=\sum_{k=0}^{m}x^{\underline{k}}\sum_{i=k}^{m}{i \brace k}a_i
\newline
=\sum_{k=0}^{m}b_kx^{\underline{k}}
$$
即
$$
b_k=\sum_{i=k}^{m}{i \brace k}a_i
$$
然后把斯特林数处理出来就可以做啦

## #269. 【清华集训2016】如何优雅地求和

给定函数$f$，$n$和$x$，要你求出来一个变换$Q$的值$mod 998244353$的结果，变换的形式如下：
$$
Q(f,n,x)=\sum_{k=0}^{n}f(k)\binom{n}{k}x^k(1-x)^{n-k}
$$
感觉跟上一题一样熟悉呀！

还是亲切的组合数，亲切的多项式函数，唯一不同的大概就是后面的$x$的部分，那我们直接跳到这一步：
$$
\sum_{k=0}^{n}\sum_{i=0}^{m}b_ik^{\underline{i}}\times x^k \times (1-x)^{n-k}\times\binom{n}{k}
\newline
=\sum_{k=0}^{n}\sum_{i=0}^{m}b_in^{\underline{i}}\times x^k\times (1-x)^{n-k}\binom{n-i}{k-i}
\newline
=\sum_{i=0}^{m}b_in^{\underline{i}}\sum_{k=0}^{n}x^k(1-x)^{n-k}\binom{n-i}{k-i}
\newline
=\sum_{i=0}^{m}b_in^{\underline{i}}\sum_{k=0}^{n-i}x^{i+k}(1-x)^{n-i-k}\binom{n-i}{k}
\newline
=\sum_{i=0}^{m}b_in^{\underline{i}}x^i\sum_{k=0}^{n-i}x^k(1-x)^{n-i-k}\binom{n-i}{k}
\newline
=\sum_{i=0}^{m}b_in^{\underline{i}}x^i(x+1-x)^{n-i}
\newline
=\sum_{i=0}^{m}b_in^{\underline{i}}x^i
$$

## CF932E Team Work

给定 $ n,k $，求：
$$ \sum_{i=1}^n\binom n i \times i^k $$
$ 1 \leq k \leq 5000,1 \leq n \leq 10^9 $

原汁原味
$$
\sum_{i=1}^n\binom{n}{i} \times i^k
\newline
=\sum_{i=1}^n\binom{n}{i}\sum_{j=0}^k {k \brace j}i^{\underline{j}}
\newline
=\sum_{i=1}^n\sum_{j=0}^k {k \brace j}i^{\underline{j}}\binom{n}{i}
\newline
=\sum_{i=1}^n\sum_{j=0}^k {k \brace j}\binom{n-j}{i-j}n^{\underline{j}}
\newline
=\sum_{j=0}^{k}{k \brace j}n^{\underline{j}}\sum_{i}^{n}\binom{n-j}{i-j}
\newline
=\sum_{j=0}^{k}{k \brace j}n^{\underline{j}}\sum_{i=0}^{n-j}\binom{n-j}{i}
\newline
=\sum_{j=0}^{k}{k \brace j}n^{\underline{j}}2^{n-j}
$$

## CF1278F Cards

有 $m$ 张牌，其中一张是王牌。现在你执行 $n$ 次如下操作：洗牌后查看第一张牌是什么。

令 $x$ 为洗牌后第一张牌为王牌的次数，现在假设洗牌时 $m!$ 种牌的排列出现的概率均相等，求 $x^k$ 的期望值。

式子挺显而易见的：
$$
E(x^k)=\sum_{i=0}^{n}i^k\binom{n}{i}(\frac{1}{m})^i(\frac{m-1}{m})^{n-i}
\newline
=\sum_{i=0}^{n}\sum_{j=0}^{k}{k \brace j}i^{\underline{j}}\binom{n}{i}(\frac{1}{m})^i(\frac{m-1}{m})^{n-i}
\newline
=\sum_{i=0}^{n}\sum_{j=0}^{k}{k \brace j}\binom{n-j}{i-j}n^{\underline{j}}(\frac{1}{m})^i(\frac{m-1}{m})^{n-i}
\newline
=\sum_{j=0}^{k}{k \brace j}n^{\underline{j}}\sum_{i=0}^{n}\binom{n-j}{i-j}(\frac{1}{m})^i(\frac{m-1}{m})^{n-i}
\newline
=\sum_{j=0}^{k}{k \brace j}n^{\underline{j}}\sum_{i=0}^{n-j}\binom{n-j}{i}(\frac{1}{m})^{i+j}(\frac{m-1}{m})^{n-i-j}
\newline
=\sum_{j=0}^{k}{k \brace j}n^{\underline{j}}(\frac{1}{m})^j\sum_{i=0}^{n-j}\binom{n-j}{i}(\frac{1}{m})^{i}(\frac{m-1}{m})^{n-i-j}
\newline
=\sum_{j=0}^{k}{k \brace j}n^{\underline{j}}(\frac{1}{m})^j\sum_{i=0}^{n-j}\binom{n-j}{i}(\frac{1}{m})^{i}(\frac{m-1}{m})^{n-i-j}
\newline
=\sum_{j=0}^{k}{k \brace j}n^{\underline{j}}(\frac{1}{m})^j1^{n-j}
\newline
=\sum_{j=0}^{k}{k \brace j}n^{\underline{j}}(\frac{1}{m})^j
$$

## CF785D Anton And School - 2

题意：
给定一个长度`≤2×10^5`由`(`和`)`组成的字符串，问有多少个子串（可以不连续），前半部分是由`(`组成后半部分由`)`组成.

首先答案是好表示的，设$pre_i$表示包括自己这个左括号左边有多少个左括号，$suf_i$表示右边有多少个右括号：
$$
Ans=\sum_{s_i='('}\sum_{j=0}^{min(pre_i-1,suf_i-1)}\binom{pre_i-1}{j}\binom{suf_i}{j+1}
$$
然后我们需要运用一下一个叫做范德蒙德卷积的东西：
$$
\sum_{i=0}^k\binom{n}{i}\binom{m}{k-i}=\binom{n+m}{k}
$$
其实考虑一下组合意义即可证明，这点还是比较简单的

然后式子就变成了：
$$
Ans=\sum_{s_i='('}\sum_{j=0}^{min(pre_i-1,suf_i-1)}\binom{pre_i-1}{j}\binom{suf_i}{j+1}
\newline
=\sum_{s_i='('}\sum_{j=0}^{min(pre_i-1,suf_i-1)}\binom{pre_i-1}{pre_i-1-j}\binom{suf_i}{j+1}
\newline
=\sum_{s_i='('}\binom{pre_i+suf_i-1}{pre_i}
$$

## P4859 已经没有什么好害怕的了

写这道题要学一个东西叫做二项式反演。

记$f_n$代表**恰好**使用$n$个有标号元素形成的方案数，$g_n$表示从$n$个有标号的元素里面选出任意个元素形成的方案数

那么就有：
$$
g_n=\sum_{i=0}^n\binom{n}{i}f_i
$$
但是既然是反演就需要我们用$g$反推出来$f$，然后就有以下的一个式子：
$$
f_i=\sum_{i=0}^n\binom{n}{i}(-1)^{n-i}g_i
$$
感觉需要证明一下！但是正着推又不太好搞，我就直接从后往前写了
$$
f_i=\sum_{i=0}^n\binom{n}{i}(-1)^{n-i}g_i
\newline
f_i=\sum_{i=0}^n\binom{n}{i}(-1)^{n-i}\sum_{j=0}^i\binom{i}{j}f_j
\newline
f_i=\sum_{i=0}^n\sum_{j=0}^i\binom{n}{i}(-1)^{n-i}\binom{i}{j}f_j
\newline
f_i=\sum_{j=0}^if_j\sum_{i=j}^n\binom{n}{i}(-1)^{n-i}\binom{i}{j}
$$
然后这里出来一个棘手的东西就是$\binom{n}{i}\binom{i}{j}$，然后我们展开一下：
$$
\binom{n}{i}\binom{i}{j}=\frac{n!}{i!(n-i)!}\times\frac{i!}{j!(i-j)!}=\frac{n!}{(n-i)!j!(i-j)!}=\frac{n!(n-j)!}{(n-i)!(i-j)!(n-j)!j!}=\frac{n!}{(n-j)!j!}\times\frac{(n-j)!}{(n-i)!(i-j)!}=\binom{n}{j}\binom{n-j}{i-j}
$$
好然后我们加进去
$$
f_i=\sum_{j=0}^if_j\sum_{i=j}^n(-1)^{n-i}\binom{n}{j}\binom{n-j}{i-j}
\newline
f_i=\sum_{j=0}^if_j\binom{n}{j}\sum_{i=j}^n(-1)^{n-i}\binom{n-j}{i-j}
\newline
f_i=\sum_{j=0}^if_j\binom{n}{j}\sum_{i=0}^{n-j}(-1)^{n-i-j}\binom{n-j}{i}
\newline
f_i=\sum_{j=0}^if_j\binom{n}{j}\sum_{i=0}^{n-j}(-1)^{n-i-j}\binom{n-j}{i}1^i
\newline
$$
注意到这里其实如果直接二项式定理确实是$0$，但是$0^0$又不知道是个啥，我们带进去之后发现其实是这样的：
$$
\sum_{i=0}^{n-j}(-1)^{n-i-j}\binom{n-j}{i}1^i=[n-j=0]
$$
所以原式子就是
$$
f_i=\sum_{j=0}^if_j\binom{n}{j}[n-j=0]
$$
得证

然后这个东西其实还有两个形式

$g_n$表示最多$n$个的方案数，$f_n$表示恰好$n$个的方案数
$$
f_n=\sum_{i=0}^n\binom{n}{i}(-1)^{n-i}g_i
$$
$g_n$表示最少$n$个的方案数，$f_n$表示恰好$n$个的方案数
$$
f_n=\sum_{i=n}^m\binom{i}{n}(-1)^{i-n}g_i
$$
好好好，学完了这个把这个题写一下吧。

题意就是

给定两个长度为$n(1\leq n \leq 1000)$的数组$\{a_i\}$和$\{b_i\}$，然后将其两两配对，让你求出来$a_i>b_i$比$a_i\leq b_i$多恰好$k$对的方案数。

首先我们把两种数对的数量都求一下，分别是$\frac{n+k}{2}$和$\frac{n-k}{2}$

然后发现恰好的方案数是不好求的，于是可以化为钦定

那我们设计一个DP，$f_{i,j}$ 表示$a$数组的前$i$个已经组完对了，形成了$j$对$a_i>b_i$

然后我们需要双指针预处理出来$b$数组中比$a_i$大的元素个数记为$cnt_i$

那么DP转移式子就是：
$$
f_{i,j}=f_{i-1,j}+(cnt_i-(j-1))\times f_{i-1,j-1}
$$
那我们套一下之前的$f_i$和$g_i$的模型，其实$g_i$，就是$f_{n,i}\times (n-i)!$，因为其表示至少有$i$个，没有考虑全部的。
$$
Ans=f_{\frac{n+k}{2}}=\sum_{i=\frac{n+k}{2}}^n(-1)^{i-\frac{n+k}{2}}\binom{i}{\frac{n+k}{2}}g_i
$$

## P3803 【模板】多项式乘法（FFT）

啊为啥我要把这个写在这里呢，因为我要学一下NTT，学NTT就要学一下FFT，然后FFT又没有过多的例题，所以只好用板子了。

很久之前就学过原理，但是总是写不出来，我认为还是对于原理掌握的不够透彻导致的，所以来梳理一下。

首先FFT的目的就是在$O(nlogn)$的时间内算出卷积。

首先我们要学一下一个多项式的表达方式，最常见的就是解析式，也就是系数表达式，但实际上还有一种表达形式叫做点值表达式，形如：

$$
\left\{  
             \begin{array}{**lr**}  
             a_0+a_1x_0+a_2x_0^2+......+a_nx_0^n=y_0 \newline
             a_0+a_1x_1+a_2x_1^2+......+a_nx_1^n=y_1 \newline
             a_0+a_1x_2+a_2x_2^2+......+a_nx_2^n=y_2 \newline
             a_0+a_1x_3+a_2x_3^2+......+a_nx_3^n=y_3 \newline
             .......
             \newline
             a_0+a_1x_n+a_2x_n^2+......+a_nx_n^n=y_n
             \end{array}  
\right  
$$

然后我们知道通过$n+1$个点可以唯一确定一个$n$次多项式，那么其实就可以用$n+1$个点来表示出来（前提是这个行列式值不是0）。

然后一会将要用到这个性质，这个时候我们需要引入复数。

我们需要了解的只有复数上的单位根。

什么叫单位根呢，就是一个方程$x^n=1$的解，然后这个解其实一共有$n$个，正好把单位圆分割成$n$份，然后我们就约定$\omega_n^k$表示$x^n=1$的解里面，从$x$轴正半轴开始逆时针旋转开始数的第$k$个根，然后其对应的角度也刚好是$\frac{2\pi}{n}\times k$

那么这个东西有如下几个性质：

性质1：

$\forall 1 \leq i,j \leq n ,i \neq j, \omega_n^i\neq\omega_n^j$

这个性质保证了他有$n$个不同的解，当然其实这个也是高中数学很基础的定理了吧。

性质2：

$\forall i \equiv j (mod \ n),\omega_n^i=\omega_n^j$

带入角度公式就会发现其实是一样的

性质3：

$\omega_n^k=\omega_n^{k\pm\frac{n}{2}}$

这个其实就相当于转了$180°$，带入角度公式发现也是这样的

性质4：

$\omega_n^k=\omega_{jn}^{jk}$

这个也是带入角度公式就可以了

然后来讲一下为什么要用这些东西。

如果直接让系数相乘那么复杂度会爆炸，那么我们可以想到先转成点值再相乘，我们知道$F(x)G(x)=(F*G)(x)$，那这个明显就快多了。

但是还有一个问题，如何快速求出来$F(x)$呢？

这个时候就需要用到单位根的性质了

那么：
$$
F(x)=a_0+a_1x+a_2x^2+a_3x^3+a_4x^4......+a_{n-1}x^{n-1}
$$
由于后来的操作，如果$n$不是$2$的整次幂，我们也自动补成$2$的整次幂

然后我们分成两半
$$
F(x)=(a_0+a_2x^2+a_4x^4+......+a_{n-2}x^{n-2})+(a_1x+a_3x^3+a_5x^5+......+a_{n-1}x^{n-1})
\newline
=F_1(x^2)+xF_2(x^2)
$$
其中
$$
F_1(x)=a_0+a_2x+a_4x^2+a_6x^3+......a_{n-2}x^{\frac{n}{2}-1}
\newline
F_2(x)=a_1+a_3x^1+a_5x^2+a_7x^3+......+a_{n-1}x^{\frac{n}{2}-1}
$$
然后我们把单位根带入一下：
$$
F(\omega_n^k)=F_1((\omega_n^k)^2)+\omega_n^kF_2((\omega_n^k)^2)
$$
这个时候我们根据$k$的范围进行一个讨论

当$k \in [0,\frac{n}{2}-1]$时，我们将式子化成
$$
F(\omega_n^k)=F_1((\omega_n^k)^2)+\omega_n^kF_2((\omega_n^k)^2)\newline
=F_1(\omega_n^{2k})+\omega_n^kF_2(\omega_n^{2k})\newline
=F_1(\omega_{\frac{n}{2}}^{k})+\omega_n^kF_2(\omega_{\frac{n}{2}}^{k})
$$
然后当$k \in [\frac{n}{2},n-1]$时，我们设$k^{'}=k-\frac{n}{2}$

那么就有
$$
F(\omega_n^{k^{'}+\frac{n}{2}})=F_1((\omega_n^{k^{'}+\frac{n}{2}})^2)+\omega_n^{k^{'}+\frac{n}{2}}F_2((\omega_n^{k^{'}+\frac{n}{2}})^2)\newline
=F_1(\omega_n^{2k^{'}+n})-\omega_n^{k^{'}}F_2(\omega_n^{2k^{'}+n})\newline
=F_1(\omega_{\frac{n}{2}}^{k^{'}})-\omega_n^{k^{'}}F_2(\omega_{\frac{n}{2}}^{k^{'}})
$$
然后这样的话，你就会发现，当你求$k \in [0,\frac{n}{2}-1]$的时候，你顺便也把$k^{'} \in [0,\frac{n}{2}-1]$也求出来了。

但是递归的复杂度还是蛮高的，这个时候我们就需要考虑怎么改成循环的形式。

蝴蝶变换：

我们发现一个东西，就是每一个多项式负责计算的系数是有规律的，我拿$n=8$的时候来演示一下：
$$
0:\{0,1,2,3,4,5,6,7\}
\newline
1:\{1,3,5,7\}\{0,2,4,6\}
\newline
2:\{1,5\}\{3,7\}\{0,4\}\{2,6\}
\newline
3:\{1\}\{5\}\{3\}\{7\}\{0\}\{4\}\{2\}\{6\}
$$
然后我们发现位于第$i$层的属于同一个多项式计算的系数的编号的二进制表示下的后$i$位是一样的
$$
0:\{\}
\newline
1:\{1\}\{0\}
\newline
2:\{01\}\{11\}\{00\}\{10\}
\newline
3:\{001\}\{101\}\{011\}\{111\}\{000\}\{100\}\{010\}\{110\}
$$
然后我们现在其实要求的东西就是，在第$log_n$层上，位置为$i$的数，他在原来的序列中的下标是啥，我们记为$rev_i$，然后发现其实这个东西就是二进制逆过来，比如$(10111)_2$逆过来变成了$(11101)_2$。

原因就是，每一次分到下一层的时候，当前层是第$i$层，那么就按照其二进制第$i$位来决定向左还是向右，最后得到的结果就是$rev_i$

然后代码上怎么求解$rev_i$呢？

其实就是这样：

```c++
tot=1<<bit;
for(int i=0;i<tot;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
for(int i=0;i<tot;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);//之所以是小于号是因为如果是不等于号就会换两次，相当于没换了
```

然后代码就是这样的

```c++
void DFT(complex *a){
    for(int i=0;i<tot;i++){
		if(i<rev[i]) swap(a[i],a[rev[i]]);
    }
    for(int mid=1;mid<tot;mid<<=1){
		complex w1=Complex({cos(PI/mid),sin(PI/mid)});
        for(int i=0;i<tot;i+=mid<<1){
            complex wk=Complex({1,0});
            for(int j=0;j<mid;j++,wk=wk*w1){
				complex x=a[i+j],y=wk*a[i+j+mid];
                a[i+j]=x+y,a[i+j+mid]=x-y;
            }
        }
    }
}
```

好，现在已经把系数转为点值了，下一步就是要把点值转换为系数！

我们首先让$H(x)=F(x)G(x)$了，现在要求$[x^i]H(x)$，我们设其为$\frac{c_k}{n}$

 有结论，我们尝试反着推：

$c_k=\sum_{i=0}^{n-1}y_i(\omega _n^{-k})^i$

$$
c_k=\sum_{i=0}^{n-1}y_i(\omega _n^{-k})^i\newline 
 =\sum_{i=0}^{n-1}(\sum_{j=0}^{n-1}a_j(\omega _n^i)^j)(\omega _n^{-k})^i\newline 
 =\sum_{i=0}^{n-1}(\sum_{j=0}^{n-1}a_j\omega _n^{ij})(\omega _n^{-k})^i\newline
 =\sum_{i=0}^{n-1}(\sum_{j=0}^{n-1}a_j(\omega _n^{j})^i)(\omega _n^{-k})^i\newline 
 =\sum_{i=0}^{n-1}(\sum_{j=0}^{n-1}a_j(\omega _n^{j})^i(\omega _n^{-k})^i)\newline 
 =\sum_{i=0}^{n-1}(\sum_{j=0}^{n-1}a_j(\omega _n^{j-k})^i)\newline 
 =\sum_{j=0}^{n-1}a_j(\sum_{i=0}^{n-1}(\omega _n^{j-k})^i)\newline
$$

然后我们再造出来个多项式$L(x)=\sum_{i=0}^{n-1}x^i$

原式子变为：
$$
=\sum_{j=0}^{n-1}a_jL(\omega_{n}^{j-k})\newline
$$
然后由于$n$是个偶数，导致$L(\omega_n^k)$中的所有值都两两抵消掉了，最后剩下一个$0$，除非$k$是$0$，那么所有项都变成了$\omega_n^0=1$，那么求完和就是$n$，式子变为：
$$
=\sum_{j=0}^{n-1}a_j([j-k=0]\times n)\newline
=\sum_{j=0}^{n-1}a_j([j=k]\times n)\newline
=a_k*n
$$
得证

那其实我们可以在设置一个多项式$R(x)=\sum_{i=0}^{n-1}$来直接通过$c_k=\sum_{i=0}^{n-1}y_i(\omega _n^{-k})^i$求出来$c_k$，然后我们发现这个多项式的参数只有一个地方变了就是$\omega_{n}^{k}$变成了$\omega_n^{-k}$，那其实我们可以把两个过程合并一下，加一个标记，来确定每次乘的到底是$\omega_n^1$还是$\omega_n^{-1}$

总的代码：

```c++
void DFT(complex *a,int flg){
    for(int i=0;i<tot;i++){
		if(i<rev[i]) swap(a[i],a[rev[i]]);
    }
    for(int mid=1;mid<tot;mid<<=1){
		complex w1=Complex({cos(PI/mid),flg*sin(PI/mid)});
        for(int i=0;i<tot;i+=mid<<1){
            complex wk=Complex({1,0});
            for(int j=0;j<mid;j++,wk=wk*w1){
				complex x=a[i+j],y=wk*a[i+j+mid];
                a[i+j]=x+y,a[i+j+mid]=x-y;
            }
        }
    }
}
```

然后发现FFT用的实在是太少了，然后就准备过渡到NTT上。

但是学NTT首先要学一些基本的数论知识：

然后先引出一下离散对数问题。

给定$a,b,p$，求出最小的$k$使得$a^k \equiv b (mod \ p)$，$p$是质数。（如果不是质数估计就是个NP问题了）

然后有费马小定理$a^n \equiv a^{n \ mod \ (p-1)} (mod \ p)$，所以只需要考虑$p-1$种$k$

然后我们考虑分块，设$T$为块长，那么我们就是要求$a^{kT+c}\equiv b(mod \ p)$，那么就是$a^{kT}\equiv ba^{-c}(mod \ p )$，那么我们预处理出来$ba^{-c}$，然后用$a^{kT}$去一个个试。

容易发现这个过程是$O(\sqrt p)$的。

有一个例题。

## P4884 多少个 1？

麻了，被这题卡了20min，有点耻辱。

题意就是给定$m$和$K$，求最小的$k$，使得$\sum_{j=0}^{k}10^j\equiv K (mod \ m)$

然后前面的部分就是个等比数列求和$\sum_{k=0}^{N}10^k=\frac{(10^{k}-1)\times 1}{(10-1)}$

$10^{k}-1\equiv 9K(mod \ m)$

$10^{k}\equiv 9K+1(mod \ m)$

然后就是标准的$BSGS$了捏。

然后就看一下原根吧家人们。

感觉这一部分还是性质更重要一些，那就从推性质开始说起吧。

阶：对于$mod \ p$意义下，我们称$a$的阶为最小的$k$使得$a^k\equiv 1(mod \ p)$。不难发现其实阶的意义就是幂的最小循环节的长度，然后其上界即为$\varphi(p)$，我们通常把$a \bmod p$的阶记作$\delta_p(a)$

然后推一下性质：

首先是$\forall i,j \in [1,\delta_p(a)],a^i \not \equiv a^j (\bmod p)$

反证法可以证明。

如果存在的话，设$i>j$就有$a^i \equiv a^j (\bmod p)$，进而$a^{i-j} \equiv 1 (\bmod p)$，那就有$i-j<\delta_p(a)$跟原根的最小性冲突了。

然后是$\forall n ,a^n \equiv 1$有$\delta_p(a)|n$ ，这个直观上就很好理解吧，类似于最小正周期和周期长度的关系。

然后证明也是反证法。

$a^{k\delta_p(a)+b}\equiv a^n,b<\delta_p(a)$，那也就是说$a^b\equiv 1 (\bmod p)$，跟原根的最小性冲突了。

接着是，若$gcd(a,m)=gcd(b,m)=1$，则$\delta_p(a)\delta_p(b)=\delta_p(ab)$成立的充分必要条件是$gcd(\delta_p(a),\delta_p(b))=1$

必要性：

$a^{\delta_p(a)}\equiv b^{\delta_p(b)}\equiv 1(\bmod p)$，就有$(ab)^{lcm(\delta_p(a),\delta_p(b))}\equiv 1 (\bmod p)$

然后，根据上面推出的性质，就有$\delta_p(ab)|lcm(\delta_p(a),\delta_p(b))$

带入条件，$\delta_p(a)\delta_p(b)|lcm(\delta_p(a),\delta_p(b))$

$\delta_p(a)\delta_p(b)=lcm(\delta_p(a),\delta_p(b))gcd(\delta_p(a),\delta_p(b))$

那么就是$gcd(\delta_p(a),\delta_p(b))=1$

充分性：

$(ab)^{\delta_p(ab)}\equiv 1(\bmod p)$然后有$(ab)^{\delta_p(ab)\delta_p(b)}\equiv 1(\bmod p)$，$a^{\delta_p(ab)\delta_p(b)}\equiv 1(\bmod p)$。

也就是说$\delta_p(a)|\delta_p(ab)\delta_p(b)$，同时由于对称性也有$\delta_p(b)|\delta_p(ab)\delta_p(a)$

然后带入条件有$\delta_p(a)|\delta_p(ab)$和$\delta_p(b)|\delta_p(ab)$

就有$\delta_p(a)\delta_p(b)|\delta_p(ab)$

然后又因为$(ab)^{\delta_p(a)\delta_p(b)}\equiv (a^{\delta_p(a)})^{\delta_p(b)}(b^{\delta_p(b)})^{\delta_p(a)}\equiv 1(\bmod p)$

所以就是$\delta_p(ab)|\delta_p(a)\delta_p(b)$

因此只能是$\delta_p(a)\delta_p(b)=\delta_p(ab)$

还有一个性质：$\delta_p(a^k)=\frac{\delta_p(a)}{gcd(\delta_p(a),k)}$

证明如下：

$a^{k\delta_p(a^k)}\equiv (a^k)^{\delta_p(a^k)}\equiv 1(\bmod p)$

所以$\delta_p(a)|k\delta_p(a^k)$

就有$\frac{\delta_p(a)}{gcd(k,\delta_p(a))}|\delta_p(a^k)$

同时也有$(a^k)^{\frac{\delta_p(a)}{gcd(k,\delta_p(a))}}\equiv (a^{\delta_p(a)})^{\frac{k}{gcd(k,\delta_p(a))}} \equiv 1(\bmod p)$

所以有$\delta_p(a^k)|\frac{\delta_p(a)}{gcd(k,\delta_p(a))}$

于是两者只能相等了。

然后到原根了
### 
原根：在$\bmod p$意义下，如果存在一个$a$满足$a^{\varphi(p)}\equiv 1(mod \ p)$，那我们称$a$为$mod \ p $意义下的原根。意义就是它的循环节顶到了上界。

有如下几个定理：

原根判定定理：若$m\geq 3$且$gcd(a,m)=1$，则$a$是$\bmod m$的原根的充要条件是对于$\varphi(m)$的每一个质因子$p$都有$a^{\frac{\varphi(m)}{p}}\not \equiv 1(\bmod m)$

不会证啊qwq

还有个结论：若一个数$m$有原根，则原根的个数为$\varphi(\varphi(m))$

证明如下：

设$m$有原根$a$，那么$\delta_m(a^k)=\frac{\delta_m(a)}{gcd(\delta_m(a),k)}=\frac{\varphi(a)}{gcd(\varphi(a),k)}$

当$k\bot\varphi(a)$时，$a^k$也是一个原根。

然后既要满足$k\leq \varphi(a)$，也要满足$gcd(k,\varphi(a))=1$，那不难发现这其实就是$\varphi(\varphi(a))$个。

然后是原根存在定理。

若一个数有原根，那么这个数必须为$2,4,p^c,2\times p^c$。我也不会证/kk

而且最小的原根不会超过$m^{\frac{1}{4}}$，所以可以直接枚举。

那么求出所有原根只需要先求出来最小的原根，然后枚举次幂$k$，满足$k\bot \varphi(a)$就是原根。

