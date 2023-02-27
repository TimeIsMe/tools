# Misc Tools

<!-- TOC -->

- [Misc Tools](#misc-tools)
    - [emacs configure file](#emacs-configure-file)
        - [部署路径](#%E9%83%A8%E7%BD%B2%E8%B7%AF%E5%BE%84)
        - [Ubuntu安装新版emacs](#ubuntu%E5%AE%89%E8%A3%85%E6%96%B0%E7%89%88emacs)
        - [gtags跨文件夹搜索](#gtags%E8%B7%A8%E6%96%87%E4%BB%B6%E5%A4%B9%E6%90%9C%E7%B4%A2)
        - [gtags查看C++头文件](#gtags%E6%9F%A5%E7%9C%8Bc%E5%A4%B4%E6%96%87%E4%BB%B6)

<!-- /TOC -->

## 1. emacs configure file

[.emacs](./Emacs/.emacs)

### 部署路径

windows下配置文件路径：

`C:\Users\UserName\AppData\Roaming`

Linux下配置文件路径：

```
~/.emacs
~/.emacs.el
~/.emacs.d/init.el
~/.config/emacs/init.el
```

### Ubuntu安装新版emacs

```
sudo add-apt-repository ppa:kelleyk/emacs
sudo apt update
sudo apt install emacs26
```

### gtags跨文件夹搜索

`export GTAGSLIBPATH=${GCC_HOME}`

### gtags查看C++头文件

[FAQ: Q3. I'm a C++ programmer. Why does not gtags pick up class names in *.h?](https://fossies.org/linux/global/FAQ)

```
setenv GTAGSFORCECPP
or
export GTAGSFORCECPP=
```

## 2. windows ipset script

**windows10需要使用管理员权限运行**

使用前请确认脚本中网卡名称是否正确。




