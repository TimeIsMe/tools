# Misc Tools

<!-- TOC -->

- [Misc Tools](#misc-tools)
  - [1. emacs configure file](#1-emacs-configure-file)
    - [部署路径](#部署路径)
    - [Ubuntu安装新版emacs](#ubuntu安装新版emacs)
    - [gtags跨文件夹搜索](#gtags跨文件夹搜索)
    - [gtags查看C++头文件](#gtags查看c头文件)
  - [2. windows ipset script](#2-windows-ipset-script)

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
``

## 2. windows ipset script

**windows10需要使用管理员权限运行**

使用前请确认脚本中网卡名称是否正确。




