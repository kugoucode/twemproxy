#include <gtest/gtest.h>
#include <iostream>
#include <cstring>
#include <cstdint>

// 添加 extern "C" 声明以正确链接 C 函数
extern "C" {
#include "nc_hashkit.h"
uint32_t hash_fnv1a_64(const char *key, size_t key_length);
}

#ifndef FNV_64_INIT
#define FNV_64_INIT 0xcbf29ce484222325
#endif

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(hash_fnv1a_64Test, EmptyString) {
    const char* key = "";
    size_t key_length = strlen(key);
    uint32_t hash = hash_fnv1a_64(key, key_length);
    std::cout << "\tHash value (hex): 0x" << std::hex << hash << key << std::endl;
    EXPECT_EQ(hash, 0x84222325);
}

TEST(hash_fnv1a_64Test, SingleCharacter) {
    const char* key = "a";
    size_t key_length = strlen(key);
    uint32_t hash = hash_fnv1a_64(key, key_length);
    std::cout << "\tHash value (hex): 0x" << std::hex << hash << " " << key << std::endl;
    EXPECT_EQ(hash, 0x8601ec8c);  // 根据FNV-1a算法的结果
}

TEST(hash_fnv1a_64Test, MultipleCharacters) {
    const char* tags[] = {
        "tag00", "tag01", "tag02", "tag03", "tag04",
        "tag05", "tag06", "tag07", "tag08", "tag09", "tag10",
        "tag11", "tag12", "tag13", "tag14", "tag15", "tag16"
    };

    for (const char* key : tags) {
        size_t key_length = strlen(key);
        uint32_t hash = hash_fnv1a_64(key, key_length);
        std::cout << "\n\tTesting tag: " << key << std::endl;
        std::cout << "\tInput string: " << key << std::endl;
        std::cout << "\tHash value (hex): 0x" << std::hex << hash << std::endl;
        std::cout << "\tHash value (dec): " << std::dec << hash << std::endl;
        std::cout << "\tHash mod 16: " << hash % 16 << std::endl;
        std::cout << "\t------------------------" << std::endl;
    }

    // 为了保持原有的测试逻辑，我们保留原来的测试用例
    const char* key = "abc";
    size_t key_length = strlen(key);
    uint32_t hash = hash_fnv1a_64(key, key_length);
    std::cout << "\tHash value (hex): 0x" << std::hex << hash << key << std::endl;
    EXPECT_EQ(hash, 0x541574b);  // 根据FNV-1a算法的结果
}

TEST(hash_fnv1a_64Test, LongString) {
    // 定义要哈希的字符串
    const char* key = "This is a long string that should be hashed.";
    // 计算字符串的长度
    size_t key_length = strlen(key);
    // 调用hash_fnv1a_64函数计算哈希值
    uint32_t hash = hash_fnv1a_64(key, key_length);
    // 输出哈希值（以十六进制形式）
    std::cout << "Hash value (hex): 0x" << std::hex << hash << key << std::endl;
    // 期望的哈希值，根据FNV-1a算法计算得到
    EXPECT_EQ(hash, 0x53153505);  // 根据FNV-1a算法的结果
}
