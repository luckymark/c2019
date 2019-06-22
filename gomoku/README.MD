# 项目相关
由于使用CLR绘制GUI，运行需要.NET环境。

多模式匹配算法（AC算法）不属于五子棋AI范畴，只是为了加快匹配速度，所以直接拿来主义用了别人的轮子。

**请老师高抬贵手多给点分😜**

# 可修改项
可以通过`Gomoku.h`中的`DEPTH`修改搜索深度，`MAXCOUNT`修改搜索广度

默认的深度被我调的有点高了，大概15-20秒才出结果（玩的越久速度越快）...

可以把DEPTH改为3，MAXCOUNT改为10

## 默认常量值
| 常量名称 | 默认值 |
| ----------- | ----------- |
| DEPTH | 5 |
| MAXCOUNT | 5 |
| WIDTH | 15 |


# 参考资料
1. [如何设计一个还可以的五子棋AI](https://kimlongli.github.io/2016/12/14/%E5%A6%82%E4%BD%95%E8%AE%BE%E8%AE%A1%E4%B8%80%E4%B8%AA%E8%BF%98%E5%8F%AF%E4%BB%A5%E7%9A%84%E4%BA%94%E5%AD%90%E6%A3%8BAI/)
2. [五子棋入门级AI的设计与实现 - 知乎](https://zhuanlan.zhihu.com/p/25650252)
3. [五子棋AI教程第二版](https://github.com/lihongxun945/myblog/labels/%E4%BA%94%E5%AD%90%E6%A3%8BAI%E6%95%99%E7%A8%8B%E7%AC%AC%E4%BA%8C%E7%89%88)
