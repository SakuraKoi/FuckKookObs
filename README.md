# FuckKookObs

![GitHub License](https://img.shields.io/github/license/SakuraKoi/FuckKookObs?style=for-the-badge) ![GitHub top language](https://img.shields.io/github/languages/top/SakuraKoi/FuckKookObs?style=for-the-badge) ![GitHub Release](https://img.shields.io/github/v/release/SakuraKoi/FuckKookObs?include_prereleases&style=for-the-badge) ![GitHub Downloads (all assets, all releases)](https://img.shields.io/github/downloads/SakuraKoi/FuckKookObs/total?style=for-the-badge)

Allow Kook voice chat while `OBS` or `Bilibili LiveHime` running

允许在 `OBS` 或 `B站直播姬` 运行的情况下使用Kook语音聊天

![image-20240525141645252](https://s2.loli.net/2024/05/25/ymq7H2fJtVLxgke.png)

> 致Kook的产品经理: 喜报! 您🐴在天上飞!

### 使用方式

[下载 Release](https://github.com/SakuraKoi/FuckKookObs/releases/latest/download/version.dll) 中的 `version.dll` 放入Kook安装目录下即可

**注意是放在 `app-版本号` 的子目录里面, 真正的Kook在那里面, 外面的 `KOOK.exe` 只是个启动器**

### 故障排查
1. 检查任务栏kook窗口是否出现 `已解锁` 字样
2. 没有的话是没注入成功, kook三天两头换程序编译架构 可能出现补丁架构不兼容, v2.1和v3两个版本都试试 \
   v2.1 `x86架构`: https://github.com/SakuraKoi/FuckKookObs/releases/download/v2-fix1/version.dll \
   v3 `amd64架构`: https://github.com/SakuraKoi/FuckKookObs/releases/download/v3/version.dll
3. 显示 `已解锁` 但还是失效的话发issue
