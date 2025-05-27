This is a repo to share my Souls-Like GameDemo in UE5.

### Presentation Section

Preview video:

(Click the following image to view this video in YouTube. 百度网盘链接： [UE ARPG Demo for TestMap](https://pan.baidu.com/s/1D7eyftY-N_tCuY2QeWxKtA?pwd=26nn).)
[![UE ARPG Demo for TestMap - YouTube](https://res.cloudinary.com/marcomontalbano/image/upload/v1748174740/video_to_markdown/images/youtube--0Ce0PA_BQLc-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://www.youtube.com/watch?v=0Ce0PA_BQLc "UE ARPG Demo for TestMap - YouTube")


Dodge gif:



https://github.com/user-attachments/assets/9f9e362d-33e1-4372-b999-984e03dc0238


------

### Notion Note Section: (笔记链接)
https://www.notion.so/UE-slash-1a5171de03fd80e4b3cae200b9060691?pvs=4

------

技术栈：UE 5.5 | C++ | Blueprint | Control Rig | Niagara | Chaos

项目亮点：

- 战斗与特效系统​​
基于Chaos物理系统​实现武器劈砍破坏效果，支持动态网格碎裂。通过​​Niagara系统​​添加剑刃轨迹、血液飞溅特效，支持GPU粒子性能优化。
开发​​角色闪避系统​​ ，结合Root Motion与碰撞检测，实现无敌帧与残影效果。
- 角色动画系统​​
基于​​Control Rig​​实现全身IK​​，优化腿部运动适配地形（如斜坡、台阶），支持动态调整骨骼权重，动画流畅度提升40%。
结合玩家位置动态修正敌人攻击动画轨迹（Dot/Cross计算方向差），提升战斗策略性。
设计​​动画蓝图模板​​ ，按攻击、受击、闪避等行为分类管理状态机，降低后续角色扩展成本。
- 敌人AI与交互​​
实现​​方向性受击反馈​​，通过点积和叉乘判断攻击方向，播放前/后/左/右向击退动画。
集成​Pawn Sensing组件​​，配置视觉锥角与听觉范围，支持敌人巡逻、追逐、攻击多状态切换，使用NavMesh优化敌人导航绕障逻辑。
- 工程化与架构​​
采用​​接口解耦设计​​（如IHitInterface），分离受击逻辑与具体角色类，代码可维护性提升70%。
​​使用动画重定向管线​​ ，利用IK Rig标准化骨骼结构，支持跨角色复用动画资源，节省美术工时。
