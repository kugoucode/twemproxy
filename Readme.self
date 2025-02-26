# README

## Mac OS Inter builder

```bash
# 安装必要依赖
brew install automake autoconf libtool googletest pkg-config

# 生成构建系统
autoreconf -fvi
./configure

# 重新编译
make clean
make check

# 切换目录
cd ./src/hashkit

# 运行测试
./nc_fnv_test --gtest_filter="hash_fnv1a_64Test.MultipleCharacters" --gtest_color=yes
```
