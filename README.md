# Algorithm_code

记录日常算法题的解题代码、思路与心得，持续积累、系统化复盘，帮助自己构建“可检索、可复用、可演进”的题解知识库。

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](#license) [![Last Commit](https://img.shields.io/github/last-commit/SinceraXY/Algorithm_code)](https://github.com/SinceraXY/Algorithm_code/commits) [![Issues](https://img.shields.io/github/issues/SinceraXY/Algorithm_code)](https://github.com/SinceraXY/Algorithm_code/issues)

---

## 目录

- [Algorithm\_code](#algorithm_code)
  - [目录](#目录)
  - [目标与宗旨](#目标与宗旨)
  - [内容组织与目录约定](#内容组织与目录约定)
  - [文件命名规范](#文件命名规范)
  - [题解模板（建议）](#题解模板建议)
  - [如何运行与测试](#如何运行与测试)
  - [代码风格与工具建议](#代码风格与工具建议)
  - [提交信息与分支规范](#提交信息与分支规范)
  - [规划与进度追踪](#规划与进度追踪)
  - [贡献指南](#贡献指南)
  - [License](#license)
  - [致谢](#致谢)

---

## 目标与宗旨

- 系统化：以专题与难度为主线组织题目，沉淀通用解题套路与模板。
- 实战化：每道题给出可运行代码与复杂度分析，尽量附上边界用例和对拍思路。
- 复盘化：记录“为什么卡住”“如何优化”的思考过程，避免二次踩坑。

---

## 内容组织与目录约定

建议采用“平台 → 难度 → 题目文件夹”的层级组织；同一题的不同语言解法统一放在该题文件夹内。

```
.
├─ leetcode/
│  ├─ easy/
│  │  ├─ 0001_two_sum/
│  │  │  ├─ README.md           # 本题题解与思路
│  │  │  ├─ solution.py         # 示例：Python 解法
│  │  │  ├─ solution.cpp        # 示例：C++ 解法
│  │  │  └─ solution_v2.py      # 多解可追加 v2/v3 或方法名
│  │  ├─ 0239_sliding_window_maximum/
│  │  │  └─ ...
│  ├─ medium/
│  └─ hard/
├─ nowcoder/
├─ acwing/
├─ templates/          # 常用模板：并查集、单调栈/队列、前缀和、差分、二分、DP 框架等
├─ notes/              # 专题笔记、思路总结、易错点、复杂度分析
│  ├─ topics/
│  └─ mistakes/
├─ tests/              # 单元测试（可选）
├─ scripts/            # 辅助脚本（对拍、统计、生成目录）
└─ README.md
```

说明：
- 同一题的不同语言解法统一放在该题文件夹内，不再按语言分层。
- 多解方案命名建议：`solution_v2.*` 或按思路命名：`two_pointers.*`、`binary_search.*`。
- 可按需增减平台目录（如 `luogu/`、`codeforces/`）。
- 是否保留难度层级可按个人习惯调整。

---

## 文件命名规范

- 题目文件夹：`题号_题目英文蛇形`
  - 例如：`0001_two_sum`、`0239_sliding_window_maximum`
- 题解文件（文件夹内）：
  - 主解：`solution.py`、`solution.cpp`、`solution.java`、`solution.js` 等
  - 多解：`solution_v2.py`、`two_pointers.cpp`、`binary_search.py` 等
- 题解说明（可选）：每题文件夹内放 `README.md`，记录思路与复杂度。
- 备用方案（不建题目文件夹时）：可退而使用单文件命名 `lc_0001_two_sum.py`，但不推荐。

---

## 题解模板（建议）

为便于复盘，建议每题附带简短说明。可复制下面模板到每题的 `README.md` 或题解顶部注释中。

````md
# 题目：<标题>
- 平台：<LeetCode / NowCoder / ...>
- 链接：<题目链接>
- 难度：<Easy / Medium / Hard>

## 思路
- 核心：
- 关键细节：
- 边界情况：

## 复杂度
- 时间：O(...)
- 空间：O(...)

## 代码（Python 示例）
```python
from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        index_by_value = {}
        for i, x in enumerate(nums):
            if (target - x) in index_by_value:
                return [index_by_value[target - x], i]
            index_by_value[x] = i
        return []
```

## 备注
- 可选：对拍脚本、对比多种写法的优缺点
````

---

## 如何运行与测试

不同语言按需选择：

- Python
  - 直接运行：`python leetcode/easy/0001_two_sum/solution.py`
  - 建议创建虚拟环境并使用 `requirements.txt`（若有）：
    ```bash
    python -m venv .venv
    .venv/Scripts/activate  # Windows
    pip install -r requirements.txt
    ```
  - 单元测试（建议 `pytest`）：
    - 测试文件放在 `tests/`，如：`tests/leetcode/easy/test_0001_two_sum.py`
    - 约定被测函数/类的可导入路径，避免包含非法字符（文件名使用下划线）。

- C++
  - 编译运行：
    ```bash
    g++ -std=c++17 -O2 -Wall leetcode/easy/0239_sliding_window_maximum/solution.cpp -o main && ./main
    ```

- Java
  - 编译运行：
    ```bash
    javac leetcode/easy/0001_two_sum/Solution.java && java -cp leetcode/easy/0001_two_sum Solution
    ```

- JavaScript/TypeScript
  - 运行：`node leetcode/easy/0001_two_sum/solution.js` 或使用 `ts-node`（TypeScript）

> 可在 `scripts/` 中添加对拍与统计脚本（例如：随机数据生成、不同解法耗时对比、目录自动索引）。

---

## 代码风格与工具建议

- Python：`ruff` + `black` + `pytest`
- C++：`clang-format` + `cpplint`
- JavaScript/TypeScript：`eslint` + `prettier`
- Git Hooks：可使用 `pre-commit` 统一做格式化与静态检查

---

## 提交信息与分支规范

推荐采用 Conventional Commits：
- `feat: add leetcode/easy/0001_two_sum: python solution`
- `refactor: leetcode/easy/0239_sliding_window_maximum: optimize using deque`
- `docs: add notes/topics/动态规划-背包九讲`
- `test: add tests/leetcode/easy/test_0001_two_sum.py`

分支建议：
- `main`：稳定可读的题解与文档
- `feat/<topic-or-problem>`：新题/新专题开发

---

## 规划与进度追踪

- 每周目标：至少 4 道（覆盖 1-2 个专题）
- 专题清单（示例）：
  - [ ] 基础：哈希、双指针、二分、栈/队列、链表、树/图遍历
  - [ ] 进阶：滑动窗口、前缀和/差分、并查集、字典树、拓扑排序
  - [ ] 动态规划：背包、区间 DP、状态压缩、数位 DP
  - [ ] 经典题单复盘与错题集
- 数据统计（可选）：维护 `scripts/stats.py` 输出完成度报表

---

## 贡献指南

欢迎提交 Issue/PR：
1. Fork 本仓库，创建特性分支：`git checkout -b feat/xxx`
2. 按上述目录与命名提交题解与说明
3. 确保代码可运行、说明完整、通过基本测试
4. 提交 PR 并简述变更

---

## License

本仓库采用 MIT 协议开源。仓库根目录包含 `LICENSE` 文件（MIT）。

---

## 致谢

- 平台题源与社区讨论：LeetCode、牛客、AcWing 等
- 开源工具与格式化规范维护者

> 如果你也在刷题，欢迎交流思路与补充更优解法 🙌