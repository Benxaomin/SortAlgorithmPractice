# SortAlgorithmPractice
简介
鉴于排序是高频面试题，所以笔者花了点时间写了个高复用性的验证排序算法的小demo。分为两个文件，其中sort.h中负责排序算法的核心功能实现，而test.cpp中则负责验证排序算法的正确性和耗时。

如何使用
大家拿到这份代码可以直接去sort.h文件中删除核心代码，然后可以尝试自己实现排序功能，实现完后可以运行test.cpp文件验证自己的代码的正确性和性能。
目前排序的是一个1-100的数据，如果大家想要修改排序数据，可以直接去test.cpp中修改data()函数中的排序数据即可。

同时，非常欢迎大家用本仓库来练习Git操作，下面是具体练习步骤：
1 Fork本项目到自己的仓库
2 将本仓库克隆到本地
git clone git@github.com:user/example_repo.git
3 创建一个分支
git checkout -b "你的分支名"
4 创建属于你自己的sort.h文件，可以复制一份新的仓库内的sort.h文件，修改文件名为"你的用户名_sort.h"，并自己实现排序算法核心功能
5 将你的sort.h文件加入src文件文件中
6 提交修改
git add .
git commit -m "你的修改内容概括，如: (update):Benxaomin_sort.h"
7 推送分支
git push origin "你的分支名"
8 进入GitHub点进你的分支仓库，创建Pull Request，把你的分支仓库合并到本仓库





创建一个新的sort.h文件并并以“用户名_sort.h”的格式pr上自己写的代码，放入
