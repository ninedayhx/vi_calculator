# 一个基于labview的简易计算器

## 开发环境

+  vs2019
+ labview 2018

## 运行逻辑

### 前端

前端主要完成用户输入的任务，最后输入的算式是一个中缀表达式，其将在后端进行计算和处理

### 后端

后端是根目录下的用c++编写的test_DLL.dll，该DLL包含两个api:

+ `calc`:本api完成本vi的核心任务，主要是包括以下两个步骤
  + 用户输入的中缀表达式转为后缀表达式
  + 计算后缀表达式，并返回计算结果
+ `stringreplace`:本api主要用于处理文件sin、cos等字符的显示问题

## 文件结构

文件结构如下

```bash
❯ tree
.
├── Calculator.ico
├── README.md
├── calc.vi				主vi
├── calc3.0.aliases
├── calc3.0.lvlps
├── calc3.0.lvproj		工程源码
├── test_Dll			DLL源码
│   ├── dllmain.cpp
│   ├── framework.h
│   ├── pch.cpp
│   ├── pch.h
│   ├── testDLL.cpp
│   └── testDLL.h
├── test_Dll.dll		release版dll
├── 显示.ctl
└── 菜单.rtm
```

