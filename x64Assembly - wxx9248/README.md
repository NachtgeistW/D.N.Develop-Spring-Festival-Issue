# D.N.Develop Spring Festival Issue

## 使用语言

Intel x86-64 `Assembly Language`

## 作者

wxx9248

## 如何实现的

* 调用`CreateProcess`*无限*创建子线程`ShowWindow`

* 然后每个线程调用`MessageBox`弹出窗口

```C
// 学了一天的水平还敢拿出来（
```

## 编译器

Microsoft (R) Macro Assembler (x64), 即`ML64`。

（对就是`Visual Studio`VC工具链里面自带的x）

## 如何编译

在用`vcvars64.bat`（依然是工具链自带）配置好环境的命令行窗口里面直接运行`compile.bat`即可。

## ASM文件编码

`ANSI`

（至于中文嘛……我直接硬编码进去了，我太菜宽字符不知道怎么处理）

## 注意事项

* 为了表达我对夜轮大大的敬仰之情，这个程序会不断地弹出跑圈窗口。

（本来想做出来跑圈效果但是由于我太过于菜我汇编写不出来就只能这样了诶我为啥没打标点）

* 我只是来拉低中奖率的wwww
