# 贡献指南

非常感谢你对本仓库的关注与贡献！为保持仓库整洁一致，建议遵循以下约定。

## 开发流程
1. Fork 本仓库并克隆到本地
2. 创建特性分支：`git checkout -b feat/<topic-or-problem>`
3. 按 `README` 的目录与命名规范添加/修改代码与文档
4. 自检并确保可运行、说明完整
5. 提交并推送分支，发起 Pull Request（PR）

## 分支命名
- 新增题解/功能：`feat/<topic-or-problem>`
- 修复问题：`fix/<scope>`
- 文档变更：`docs/<scope>`
- 重构优化：`refactor/<scope>`

## 提交信息（Conventional Commits）
- `feat: add leetcode/easy/0001_two_sum: python solution`
- `fix: leetcode/easy/0001_two_sum: handle empty input`
- `docs: add notes/topics/动态规划-背包九讲`
- `refactor: leetcode/easy/0239_sliding_window_maximum: optimize using deque`

## 代码与文档风格
- 遵循 `README` 中的目录/命名规范
- Python 建议：`ruff` + `black`
- C++ 建议：`clang-format` + `cpplint`
- JS/TS 建议：`eslint` + `prettier`
- 每题尽量附带：思路、复杂度分析与必要的边界说明

## PR 提交清单（Checklist）
- [ ] 目录位置正确，命名规范
- [ ] 代码可运行（示例命令或主函数）
- [ ] 题解/备注清晰（如在每题 `README.md` 或代码头注释中）
- [ ] 无明显格式/风格问题（按建议的格式化工具处理）
- [ ] 变更描述清楚，便于 Review

## 沟通
- 有问题请开 Issue，或在 PR 中说明背景与动机
- 讨论题解思路时欢迎贴出不同方案对比（时间/空间/可读性） 