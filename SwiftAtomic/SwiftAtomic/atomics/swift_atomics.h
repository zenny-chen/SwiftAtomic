//
//  CLib4Swift.h
//  SwiftAtomic
//
//  Created by Zenny Chen on 2016/9/25.
//  Copyright © 2016年 GreenGames Studio. All rights reserved.
//

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stdatomic.h>

extern void swiftCPUPause(void);

// MARK: atomic bool

/** 用于Swift的AtomicBool原子类型 */
struct AtomicBoolSwift {
    volatile atomic_bool atom;
};

/**
 * 对原子对象进行初始化
 * @param pAtom 指向Swift中AtomicBool类型的原子对象，并且不允许为空
 * @param value 指定要给原子对象初始化的值
 */
extern void __attribute__((overloadable)) AtomicSwiftInit(struct AtomicBoolSwift* __nonnull pAtom, bool value);

/**
 * 对原子对象进行加载操作
 * @param pAtom 指向Swift中AtomicBool类型的原子对象，并且不允许为空
 * @return 指定原子对象所存储的值
 */
extern bool __attribute__((overloadable)) AtomicSwiftLoad(struct AtomicBoolSwift* __nonnull pAtom);

/**
 * 对原子对象进行存储操作
 * @param pAtom 指向Swift中AtomicBool类型的原子对象，并且不允许为空
 * @param value 要存储到指定原子对象中的值
 */
extern void __attribute__((overloadable)) AtomicSwiftStore(struct AtomicBoolSwift* __nonnull pAtom, bool value);

/**
 * 将原子对象中存放的值与所指定的基本类型的值进行交换。
 *
 * 也就是说，将基本类型的值存放到原子对象中去，并将原子对象的原始值返回
 * @param pAtom 指向Swift中AtomicBool类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern bool __attribute__((overloadable)) AtomicSwiftExchange(struct AtomicBoolSwift* __nonnull pAtom, bool value);

/**
 * 原子比较与交换
 *
 * 将原子对象中的值与expected的值进行比较，如果相同则将desired的值写入到原子对象中，并返回true；
 * 否则，将当前原子对象中的值写入到expected中去，并返回false
 * @param pAtom 指向Swift中AtomicBool类型的原子对象，并且不允许为空
 * @param expected 存放与原子对象进行比较的值的指针。
 *                 该指针一般指向用原子加载操作所得到值的变量，并且不能为空。
 * @param desired 要存入到原子对象中的值
 * @return 如果expected中的值与原子对象中所存放的值相同，则返回true，否则返回false
 */
extern bool __attribute__((overloadable)) AtomicSwiftCAS(struct AtomicBoolSwift* __nonnull pAtom, bool* restrict __nonnull expected, bool desired);


// MARK: atomic byte

/** 用于Swift的AtomicByte原子类型 */
struct AtomicByteSwift {
    volatile atomic_int_fast8_t atom;
};

/**
 * 对原子对象进行初始化
 * @param pAtom 指向Swift中AtomicByte类型的原子对象，并且不允许为空
 * @param value 指定要给原子对象初始化的值
 */
extern void __attribute__((overloadable)) AtomicSwiftInit(struct AtomicByteSwift* __nonnull pAtom, int8_t value);

/**
 * 对原子对象进行加载操作
 * @param pAtom 指向Swift中AtomicByte类型的原子对象，并且不允许为空
 * @return 指定原子对象所存储的值
 */
extern int8_t __attribute__((overloadable)) AtomicSwiftLoad(struct AtomicByteSwift* __nonnull pAtom);

/**
 * 对原子对象进行存储操作
 * @param pAtom 指向Swift中AtomicByte类型的原子对象，并且不允许为空
 * @param value 要存储到指定原子对象中的值
 */
extern void __attribute__((overloadable)) AtomicSwiftStore(struct AtomicByteSwift* __nonnull pAtom, int8_t value);

/**
 * 将原子对象中存放的值与所指定的基本类型的值进行交换。
 *
 * 也就是说，将基本类型的值存放到原子对象中去，并将原子对象的原始值返回
 * @param pAtom 指向Swift中AtomicByte类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int8_t __attribute__((overloadable)) AtomicSwiftExchange(struct AtomicByteSwift* __nonnull pAtom, int8_t value);

/**
 * 原子比较与交换
 *
 * 将原子对象中的值与expected的值进行比较，如果相同则将desired的值写入到原子对象中，并返回true；
 * 否则，将当前原子对象中的值写入到expected中去，并返回false
 * @param pAtom 指向Swift中AtomicByte类型的原子对象，并且不允许为空
 * @param expected 存放与原子对象进行比较的值的指针。
 *                 该指针一般指向用原子加载操作所得到值的变量，并且不能为空。
 * @param desired 要存入到原子对象中的值
 * @return 如果expected中的值与原子对象中所存放的值相同，则返回true，否则返回false
 */
extern bool __attribute__((overloadable)) AtomicSwiftCAS(struct AtomicByteSwift* __nonnull pAtom, int8_t* restrict __nonnull expected, int8_t desired);

/**
 * 原子加法操作
 * @param pAtom 指向Swift中AtomicByte类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int8_t __attribute__((overloadable)) AtomicSwiftFetchAdd(struct AtomicByteSwift* __nonnull pAtom, int8_t value);

/**
 * 原子减法操作
 * @param pAtom 指向Swift中AtomicByte类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int8_t __attribute__((overloadable)) AtomicSwiftFetchSub(struct AtomicByteSwift* __nonnull pAtom, int8_t value);

/**
 * 原子按位或操作
 * @param pAtom 指向Swift中AtomicByte类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int8_t __attribute__((overloadable)) AtomicSwiftFetchOr(struct AtomicByteSwift* __nonnull pAtom, int8_t value);

/**
 * 原子按位异或操作
 * @param pAtom 指向Swift中AtomicByte类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int8_t __attribute__((overloadable)) AtomicSwiftFetchXor(struct AtomicByteSwift* __nonnull pAtom, int8_t value);

/**
 * 原子按位与操作
 * @param pAtom 指向Swift中AtomicByte类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int8_t __attribute__((overloadable)) AtomicSwiftFetchAnd(struct AtomicByteSwift* __nonnull pAtom, int8_t value);


// MARK: atomic ubyte

/** 用于Swift的AtomicByte原子类型 */
struct AtomicUByteSwift {
    volatile atomic_uint_fast8_t atom;
};

/**
 * 对原子对象进行初始化
 * @param pAtom 指向Swift中AtomicUByte类型的原子对象，并且不允许为空
 * @param value 指定要给原子对象初始化的值
 */
extern void __attribute__((overloadable)) AtomicSwiftInit(struct AtomicUByteSwift* __nonnull pAtom, uint8_t value);

/**
 * 对原子对象进行加载操作
 * @param pAtom 指向Swift中AtomicUByte类型的原子对象，并且不允许为空
 * @return 指定原子对象所存储的值
 */
extern uint8_t __attribute__((overloadable)) AtomicSwiftLoad(struct AtomicUByteSwift* __nonnull pAtom);

/**
 * 对原子对象进行存储操作
 * @param pAtom 指向Swift中AtomicUByte类型的原子对象，并且不允许为空
 * @param value 要存储到指定原子对象中的值
 */
extern void __attribute__((overloadable)) AtomicSwiftStore(struct AtomicUByteSwift* __nonnull pAtom, uint8_t value);

/**
 * 将原子对象中存放的值与所指定的基本类型的值进行交换。
 *
 * 也就是说，将基本类型的值存放到原子对象中去，并将原子对象的原始值返回
 * @param pAtom 指向Swift中AtomicUByte类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint8_t __attribute__((overloadable)) AtomicSwiftExchange(struct AtomicUByteSwift* __nonnull pAtom, uint8_t value);

/**
 * 原子比较与交换
 *
 * 将原子对象中的值与expected的值进行比较，如果相同则将desired的值写入到原子对象中，并返回true；
 * 否则，将当前原子对象中的值写入到expected中去，并返回false
 * @param pAtom 指向Swift中AtomicUByte类型的原子对象，并且不允许为空
 * @param expected 存放与原子对象进行比较的值的指针。
 *                 该指针一般指向用原子加载操作所得到值的变量，并且不能为空。
 * @param desired 要存入到原子对象中的值
 * @return 如果expected中的值与原子对象中所存放的值相同，则返回true，否则返回false
 */
extern bool __attribute__((overloadable)) AtomicSwiftCAS(struct AtomicUByteSwift* __nonnull pAtom, uint8_t* restrict __nonnull expected, uint8_t desired);

/**
 * 原子加法操作
 * @param pAtom 指向Swift中AtomicUByte类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint8_t __attribute__((overloadable)) AtomicSwiftFetchAdd(struct AtomicUByteSwift* __nonnull pAtom, uint8_t value);

/**
 * 原子减法操作
 * @param pAtom 指向Swift中AtomicUByte类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint8_t __attribute__((overloadable)) AtomicSwiftFetchSub(struct AtomicUByteSwift* __nonnull pAtom, uint8_t value);

/**
 * 原子按位或操作
 * @param pAtom 指向Swift中AtomicUByte类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint8_t __attribute__((overloadable)) AtomicSwiftFetchOr(struct AtomicUByteSwift* __nonnull pAtom, uint8_t value);

/**
 * 原子按位异或操作
 * @param pAtom 指向Swift中AtomicUByte类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint8_t __attribute__((overloadable)) AtomicSwiftFetchXor(struct AtomicUByteSwift* __nonnull pAtom, uint8_t value);

/**
 * 原子按位与操作
 * @param pAtom 指向Swift中AtomicUByte类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint8_t __attribute__((overloadable)) AtomicSwiftFetchAnd(struct AtomicUByteSwift* __nonnull pAtom, uint8_t value);


// MARK: atomic short

/** 用于Swift的AtomicShort原子类型 */
struct AtomicShortSwift {
    volatile atomic_int_fast16_t atom;
};

/**
 * 对原子对象进行初始化
 * @param pAtom 指向Swift中AtomicShort类型的原子对象，并且不允许为空
 * @param value 指定要给原子对象初始化的值
 */
extern void __attribute__((overloadable)) AtomicSwiftInit(struct AtomicShortSwift* __nonnull pAtom, int16_t value);

/**
 * 对原子对象进行加载操作
 * @param pAtom 指向Swift中AtomicShort类型的原子对象，并且不允许为空
 * @return 指定原子对象所存储的值
 */
extern int16_t __attribute__((overloadable)) AtomicSwiftLoad(struct AtomicShortSwift* __nonnull pAtom);

/**
 * 对原子对象进行存储操作
 * @param pAtom 指向Swift中AtomicShort类型的原子对象，并且不允许为空
 * @param value 要存储到指定原子对象中的值
 */
extern void __attribute__((overloadable)) AtomicSwiftStore(struct AtomicShortSwift* __nonnull pAtom, int16_t value);

/**
 * 将原子对象中存放的值与所指定的基本类型的值进行交换。
 *
 * 也就是说，将基本类型的值存放到原子对象中去，并将原子对象的原始值返回
 * @param pAtom 指向Swift中AtomicShort类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int16_t __attribute__((overloadable)) AtomicSwiftExchange(struct AtomicShortSwift* __nonnull pAtom, int16_t value);

/**
 * 原子比较与交换
 *
 * 将原子对象中的值与expected的值进行比较，如果相同则将desired的值写入到原子对象中，并返回true；
 * 否则，将当前原子对象中的值写入到expected中去，并返回false
 * @param pAtom 指向Swift中AtomicShort类型的原子对象，并且不允许为空
 * @param expected 存放与原子对象进行比较的值的指针。
 *                 该指针一般指向用原子加载操作所得到值的变量，并且不能为空。
 * @param desired 要存入到原子对象中的值
 * @return 如果expected中的值与原子对象中所存放的值相同，则返回true，否则返回false
 */
extern bool __attribute__((overloadable)) AtomicSwiftCAS(struct AtomicShortSwift* __nonnull pAtom, int16_t* restrict __nonnull expected, int16_t desired);

/**
 * 原子加法操作
 * @param pAtom 指向Swift中AtomicShort类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int16_t __attribute__((overloadable)) AtomicSwiftFetchAdd(struct AtomicShortSwift* __nonnull pAtom, int16_t value);

/**
 * 原子减法操作
 * @param pAtom 指向Swift中AtomicShort类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int16_t __attribute__((overloadable)) AtomicSwiftFetchSub(struct AtomicShortSwift* __nonnull pAtom, int16_t value);

/**
 * 原子按位或操作
 * @param pAtom 指向Swift中AtomicShort类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int16_t __attribute__((overloadable)) AtomicSwiftFetchOr(struct AtomicShortSwift* __nonnull pAtom, int16_t value);

/**
 * 原子按位异或操作
 * @param pAtom 指向Swift中AtomicShort类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int16_t __attribute__((overloadable)) AtomicSwiftFetchXor(struct AtomicShortSwift* __nonnull pAtom, int16_t value);

/**
 * 原子按位与操作
 * @param pAtom 指向Swift中AtomicShort类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int16_t __attribute__((overloadable)) AtomicSwiftFetchAnd(struct AtomicShortSwift* __nonnull pAtom, int16_t value);


// MARK: atomic ushort

/** 用于Swift的AtomicShort原子类型 */
struct AtomicUShortSwift {
    volatile atomic_uint_fast16_t atom;
};

/**
 * 对原子对象进行初始化
 * @param pAtom 指向Swift中AtomicUShort类型的原子对象，并且不允许为空
 * @param value 指定要给原子对象初始化的值
 */
extern void __attribute__((overloadable)) AtomicSwiftInit(struct AtomicUShortSwift* __nonnull pAtom, uint16_t value);

/**
 * 对原子对象进行加载操作
 * @param pAtom 指向Swift中AtomicUShort类型的原子对象，并且不允许为空
 * @return 指定原子对象所存储的值
 */
extern uint16_t __attribute__((overloadable)) AtomicSwiftLoad(struct AtomicUShortSwift* __nonnull pAtom);

/**
 * 对原子对象进行存储操作
 * @param pAtom 指向Swift中AtomicUShort类型的原子对象，并且不允许为空
 * @param value 要存储到指定原子对象中的值
 */
extern void __attribute__((overloadable)) AtomicSwiftStore(struct AtomicUShortSwift* __nonnull pAtom, uint16_t value);

/**
 * 将原子对象中存放的值与所指定的基本类型的值进行交换。
 *
 * 也就是说，将基本类型的值存放到原子对象中去，并将原子对象的原始值返回
 * @param pAtom 指向Swift中AtomicUShort类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint16_t __attribute__((overloadable)) AtomicSwiftExchange(struct AtomicUShortSwift* __nonnull pAtom, uint16_t value);

/**
 * 原子比较与交换
 *
 * 将原子对象中的值与expected的值进行比较，如果相同则将desired的值写入到原子对象中，并返回true；
 * 否则，将当前原子对象中的值写入到expected中去，并返回false
 * @param pAtom 指向Swift中AtomicUShort类型的原子对象，并且不允许为空
 * @param expected 存放与原子对象进行比较的值的指针。
 *                 该指针一般指向用原子加载操作所得到值的变量，并且不能为空。
 * @param desired 要存入到原子对象中的值
 * @return 如果expected中的值与原子对象中所存放的值相同，则返回true，否则返回false
 */
extern bool __attribute__((overloadable)) AtomicSwiftCAS(struct AtomicUShortSwift* __nonnull pAtom, uint16_t* restrict __nonnull expected, uint16_t desired);

/**
 * 原子加法操作
 * @param pAtom 指向Swift中AtomicUShort类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint16_t __attribute__((overloadable)) AtomicSwiftFetchAdd(struct AtomicUShortSwift* __nonnull pAtom, uint16_t value);

/**
 * 原子减法操作
 * @param pAtom 指向Swift中AtomicUShort类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint16_t __attribute__((overloadable)) AtomicSwiftFetchSub(struct AtomicUShortSwift* __nonnull pAtom, uint16_t value);

/**
 * 原子按位或操作
 * @param pAtom 指向Swift中AtomicUShort类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint16_t __attribute__((overloadable)) AtomicSwiftFetchOr(struct AtomicUShortSwift* __nonnull pAtom, uint16_t value);

/**
 * 原子按位异或操作
 * @param pAtom 指向Swift中AtomicUShort类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint16_t __attribute__((overloadable)) AtomicSwiftFetchXor(struct AtomicUShortSwift* __nonnull pAtom, uint16_t value);

/**
 * 原子按位与操作
 * @param pAtom 指向Swift中AtomicUShort类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint16_t __attribute__((overloadable)) AtomicSwiftFetchAnd(struct AtomicUShortSwift* __nonnull pAtom, uint16_t value);


// MARK: atomic int

/** 用于Swift的AtomicInt原子类型 */
struct AtomicIntSwift {
    volatile atomic_int atom;
};

/**
 * 对原子对象进行初始化
 * @param pAtom 指向Swift中AtomicInt类型的原子对象，并且不允许为空
 * @param value 指定要给原子对象初始化的值
 */
extern void __attribute__((overloadable)) AtomicSwiftInit(struct AtomicIntSwift* __nonnull pAtom, int32_t value);

/**
 * 对原子对象进行加载操作
 * @param pAtom 指向Swift中AtomicInt类型的原子对象，并且不允许为空
 * @return 指定原子对象所存储的值
 */
extern int32_t __attribute__((overloadable)) AtomicSwiftLoad(struct AtomicIntSwift* __nonnull pAtom);

/**
 * 对原子对象进行存储操作
 * @param pAtom 指向Swift中AtomicInt类型的原子对象，并且不允许为空
 * @param value 要存储到指定原子对象中的值
 */
extern void __attribute__((overloadable)) AtomicSwiftStore(struct AtomicIntSwift* __nonnull pAtom, int32_t value);

/**
 * 将原子对象中存放的值与所指定的基本类型的值进行交换。
 *
 * 也就是说，将基本类型的值存放到原子对象中去，并将原子对象的原始值返回
 * @param pAtom 指向Swift中AtomicInt类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int32_t __attribute__((overloadable)) AtomicSwiftExchange(struct AtomicIntSwift* __nonnull pAtom, int32_t value);

/**
 * 原子比较与交换
 *
 * 将原子对象中的值与expected的值进行比较，如果相同则将desired的值写入到原子对象中，并返回true；
 * 否则，将当前原子对象中的值写入到expected中去，并返回false
 * @param pAtom 指向Swift中AtomicInt类型的原子对象，并且不允许为空
 * @param expected 存放与原子对象进行比较的值的指针。
 *                 该指针一般指向用原子加载操作所得到值的变量，并且不能为空。
 * @param desired 要存入到原子对象中的值
 * @return 如果expected中的值与原子对象中所存放的值相同，则返回true，否则返回false
 */
extern bool __attribute__((overloadable)) AtomicSwiftCAS(struct AtomicIntSwift* __nonnull pAtom, int32_t* restrict __nonnull expected, int32_t desired);

/**
 * 原子加法操作
 * @param pAtom 指向Swift中AtomicInt类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int32_t __attribute__((overloadable)) AtomicSwiftFetchAdd(struct AtomicIntSwift* __nonnull pAtom, int32_t value);

/**
 * 原子减法操作
 * @param pAtom 指向Swift中AtomicInt类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int32_t __attribute__((overloadable)) AtomicSwiftFetchSub(struct AtomicIntSwift* __nonnull pAtom, int32_t value);

/**
 * 原子按位或操作
 * @param pAtom 指向Swift中AtomicInt类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int32_t __attribute__((overloadable)) AtomicSwiftFetchOr(struct AtomicIntSwift* __nonnull pAtom, int32_t value);

/**
 * 原子按位异或操作
 * @param pAtom 指向Swift中AtomicInt类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int32_t __attribute__((overloadable)) AtomicSwiftFetchXor(struct AtomicIntSwift* __nonnull pAtom, int32_t value);

/**
 * 原子按位与操作
 * @param pAtom 指向Swift中AtomicInt类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int32_t __attribute__((overloadable)) AtomicSwiftFetchAnd(struct AtomicIntSwift* __nonnull pAtom, int32_t value);


// MARK: atomic uint

/** 用于Swift的AtomicUInt原子类型 */
struct AtomicUIntSwift {
    volatile atomic_uint atom;
};

/**
 * 对原子对象进行初始化
 * @param pAtom 指向Swift中AtomicUInt类型的原子对象，并且不允许为空
 * @param value 指定要给原子对象初始化的值
 */
extern void __attribute__((overloadable)) AtomicSwiftInit(struct AtomicUIntSwift* __nonnull pAtom, uint32_t value);

/**
 * 对原子对象进行加载操作
 * @param pAtom 指向Swift中AtomicUInt类型的原子对象，并且不允许为空
 * @return 指定原子对象所存储的值
 */
extern uint32_t __attribute__((overloadable)) AtomicSwiftLoad(struct AtomicUIntSwift* __nonnull pAtom);

/**
 * 对原子对象进行存储操作
 * @param pAtom 指向Swift中AtomicUInt类型的原子对象，并且不允许为空
 * @param value 要存储到指定原子对象中的值
 */
extern void __attribute__((overloadable)) AtomicSwiftStore(struct AtomicUIntSwift* __nonnull pAtom, uint32_t value);

/**
 * 将原子对象中存放的值与所指定的基本类型的值进行交换。
 *
 * 也就是说，将基本类型的值存放到原子对象中去，并将原子对象的原始值返回
 * @param pAtom 指向Swift中AtomicUInt类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint32_t __attribute__((overloadable)) AtomicSwiftExchange(struct AtomicUIntSwift* __nonnull pAtom, uint32_t value);

/**
 * 原子比较与交换
 *
 * 将原子对象中的值与expected的值进行比较，如果相同则将desired的值写入到原子对象中，并返回true；
 * 否则，将当前原子对象中的值写入到expected中去，并返回false
 * @param pAtom 指向Swift中AtomicUInt类型的原子对象，并且不允许为空
 * @param expected 存放与原子对象进行比较的值的指针。
 *                 该指针一般指向用原子加载操作所得到值的变量，并且不能为空。
 * @param desired 要存入到原子对象中的值
 * @return 如果expected中的值与原子对象中所存放的值相同，则返回true，否则返回false
 */
extern bool __attribute__((overloadable)) AtomicSwiftCAS(struct AtomicUIntSwift* __nonnull pAtom, uint32_t* restrict __nonnull expected, uint32_t desired);

/**
 * 原子加法操作
 * @param pAtom 指向Swift中AtomicUInt类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint32_t __attribute__((overloadable)) AtomicSwiftFetchAdd(struct AtomicUIntSwift* __nonnull pAtom, uint32_t value);

/**
 * 原子减法操作
 * @param pAtom 指向Swift中AtomicUInt类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint32_t __attribute__((overloadable)) AtomicSwiftFetchSub(struct AtomicUIntSwift* __nonnull pAtom, uint32_t value);

/**
 * 原子按位或操作
 * @param pAtom 指向Swift中AtomicUInt类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint32_t __attribute__((overloadable)) AtomicSwiftFetchOr(struct AtomicUIntSwift* __nonnull pAtom, uint32_t value);

/**
 * 原子按位异或操作
 * @param pAtom 指向Swift中AtomicUInt类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint32_t __attribute__((overloadable)) AtomicSwiftFetchXor(struct AtomicUIntSwift* __nonnull pAtom, uint32_t value);

/**
 * 原子按位与操作
 * @param pAtom 指向Swift中AtomicUInt类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint32_t __attribute__((overloadable)) AtomicSwiftFetchAnd(struct AtomicUIntSwift* __nonnull pAtom, uint32_t value);


// MARK: atomic long

/** 用于Swift的AtomicLong原子类型 */
struct AtomicLongSwift {
    volatile atomic_int_fast64_t atom;
};

/**
 * 对原子对象进行初始化
 * @param pAtom 指向Swift中AtomicLong类型的原子对象，并且不允许为空
 * @param value 指定要给原子对象初始化的值
 */
extern void __attribute__((overloadable)) AtomicSwiftInit(struct AtomicLongSwift* __nonnull pAtom, int64_t value);

/**
 * 对原子对象进行加载操作
 * @param pAtom 指向Swift中AtomicLong类型的原子对象，并且不允许为空
 * @return 指定原子对象所存储的值
 */
extern int64_t __attribute__((overloadable)) AtomicSwiftLoad(struct AtomicLongSwift* __nonnull pAtom);

/**
 * 对原子对象进行存储操作
 * @param pAtom 指向Swift中AtomicLong类型的原子对象，并且不允许为空
 * @param value 要存储到指定原子对象中的值
 */
extern void __attribute__((overloadable)) AtomicSwiftStore(struct AtomicLongSwift* __nonnull pAtom, int64_t value);

/**
 * 将原子对象中存放的值与所指定的基本类型的值进行交换。
 *
 * 也就是说，将基本类型的值存放到原子对象中去，并将原子对象的原始值返回
 * @param pAtom 指向Swift中AtomicLong类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int64_t __attribute__((overloadable)) AtomicSwiftExchange(struct AtomicLongSwift* __nonnull pAtom, int64_t value);

/**
 * 原子比较与交换
 *
 * 将原子对象中的值与expected的值进行比较，如果相同则将desired的值写入到原子对象中，并返回true；
 * 否则，将当前原子对象中的值写入到expected中去，并返回false
 * @param pAtom 指向Swift中AtomicLong类型的原子对象，并且不允许为空
 * @param expected 存放与原子对象进行比较的值的指针。
 *                 该指针一般指向用原子加载操作所得到值的变量，并且不能为空。
 * @param desired 要存入到原子对象中的值
 * @return 如果expected中的值与原子对象中所存放的值相同，则返回true，否则返回false
 */
extern bool __attribute__((overloadable)) AtomicSwiftCAS(struct AtomicLongSwift* __nonnull pAtom, int64_t* restrict __nonnull expected, int64_t desired);

/**
 * 原子加法操作
 * @param pAtom 指向Swift中AtomicLong类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int64_t __attribute__((overloadable)) AtomicSwiftFetchAdd(struct AtomicLongSwift* __nonnull pAtom, int64_t value);

/**
 * 原子减法操作
 * @param pAtom 指向Swift中AtomicLong类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int64_t __attribute__((overloadable)) AtomicSwiftFetchSub(struct AtomicLongSwift* __nonnull pAtom, int64_t value);

/**
 * 原子按位或操作
 * @param pAtom 指向Swift中AtomicLong类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int64_t __attribute__((overloadable)) AtomicSwiftFetchOr(struct AtomicLongSwift* __nonnull pAtom, int64_t value);

/**
 * 原子按位异或操作
 * @param pAtom 指向Swift中AtomicLong类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int64_t __attribute__((overloadable)) AtomicSwiftFetchXor(struct AtomicLongSwift* __nonnull pAtom, int64_t value);

/**
 * 原子按位与操作
 * @param pAtom 指向Swift中AtomicLong类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern int64_t __attribute__((overloadable)) AtomicSwiftFetchAnd(struct AtomicLongSwift* __nonnull pAtom, int64_t value);


// MARK: atomic ulong

/** 用于Swift的AtomicULong原子类型 */
struct AtomicULongSwift {
    volatile atomic_uint_fast64_t atom;
};

/**
 * 对原子对象进行初始化
 * @param pAtom 指向Swift中AtomicULong类型的原子对象，并且不允许为空
 * @param value 指定要给原子对象初始化的值
 */
extern void __attribute__((overloadable)) AtomicSwiftInit(struct AtomicULongSwift* __nonnull pAtom, uint64_t value);

/**
 * 对原子对象进行加载操作
 * @param pAtom 指向Swift中AtomicULong类型的原子对象，并且不允许为空
 * @return 指定原子对象所存储的值
 */
extern uint64_t __attribute__((overloadable)) AtomicSwiftLoad(struct AtomicULongSwift* __nonnull pAtom);

/**
 * 对原子对象进行存储操作
 * @param pAtom 指向Swift中AtomicULong类型的原子对象，并且不允许为空
 * @param value 要存储到指定原子对象中的值
 */
extern void __attribute__((overloadable)) AtomicSwiftStore(struct AtomicULongSwift* __nonnull pAtom, uint64_t value);

/**
 * 将原子对象中存放的值与所指定的基本类型的值进行交换。
 *
 * 也就是说，将基本类型的值存放到原子对象中去，并将原子对象的原始值返回
 * @param pAtom 指向Swift中AtomicULong类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint64_t __attribute__((overloadable)) AtomicSwiftExchange(struct AtomicULongSwift* __nonnull pAtom, uint64_t value);

/**
 * 原子比较与交换
 *
 * 将原子对象中的值与expected的值进行比较，如果相同则将desired的值写入到原子对象中，并返回true；
 * 否则，将当前原子对象中的值写入到expected中去，并返回false
 * @param pAtom 指向Swift中AtomicULong类型的原子对象，并且不允许为空
 * @param expected 存放与原子对象进行比较的值的指针。
 *                 该指针一般指向用原子加载操作所得到值的变量，并且不能为空。
 * @param desired 要存入到原子对象中的值
 * @return 如果expected中的值与原子对象中所存放的值相同，则返回true，否则返回false
 */
extern bool __attribute__((overloadable)) AtomicSwiftCAS(struct AtomicULongSwift* __nonnull pAtom, uint64_t* restrict __nonnull expected, uint64_t desired);

/**
 * 原子加法操作
 * @param pAtom 指向Swift中AtomicULong类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint64_t __attribute__((overloadable)) AtomicSwiftFetchAdd(struct AtomicULongSwift* __nonnull pAtom, uint64_t value);

/**
 * 原子减法操作
 * @param pAtom 指向Swift中AtomicULong类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint64_t __attribute__((overloadable)) AtomicSwiftFetchSub(struct AtomicULongSwift* __nonnull pAtom, uint64_t value);

/**
 * 原子按位或操作
 * @param pAtom 指向Swift中AtomicULong类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint64_t __attribute__((overloadable)) AtomicSwiftFetchOr(struct AtomicULongSwift* __nonnull pAtom, uint64_t value);

/**
 * 原子按位异或操作
 * @param pAtom 指向Swift中AtomicULong类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint64_t __attribute__((overloadable)) AtomicSwiftFetchXor(struct AtomicULongSwift* __nonnull pAtom, uint64_t value);

/**
 * 原子按位与操作
 * @param pAtom 指向Swift中AtomicULong类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uint64_t __attribute__((overloadable)) AtomicSwiftFetchAnd(struct AtomicULongSwift* __nonnull pAtom, uint64_t value);


// MARK: atomic intptr_t

/** 用于Swift的AtomicIntPtr原子类型 */
struct AtomicIntPtrSwift {
    volatile atomic_intptr_t atom;
};

/**
 * 对原子对象进行初始化
 * @param pAtom 指向Swift中AtomicIntPtr类型的原子对象，并且不允许为空
 * @param value 指定要给原子对象初始化的值
 */
extern void __attribute__((overloadable)) AtomicSwiftInit(struct AtomicIntPtrSwift* __nonnull pAtom, intptr_t value);

/**
 * 对原子对象进行加载操作
 * @param pAtom 指向Swift中AtomicIntPtr类型的原子对象，并且不允许为空
 * @return 指定原子对象所存储的值
 */
extern intptr_t __attribute__((overloadable)) AtomicSwiftLoad(struct AtomicIntPtrSwift* __nonnull pAtom);

/**
 * 对原子对象进行存储操作
 * @param pAtom 指向Swift中AtomicIntPtr类型的原子对象，并且不允许为空
 * @param value 要存储到指定原子对象中的值
 */
extern void __attribute__((overloadable)) AtomicSwiftStore(struct AtomicIntPtrSwift* __nonnull pAtom, intptr_t value);

/**
 * 将原子对象中存放的值与所指定的基本类型的值进行交换。
 *
 * 也就是说，将基本类型的值存放到原子对象中去，并将原子对象的原始值返回
 * @param pAtom 指向Swift中AtomicIntPtr类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern intptr_t __attribute__((overloadable)) AtomicSwiftExchange(struct AtomicIntPtrSwift* __nonnull pAtom, intptr_t value);

/**
 * 原子比较与交换
 *
 * 将原子对象中的值与expected的值进行比较，如果相同则将desired的值写入到原子对象中，并返回true；
 * 否则，将当前原子对象中的值写入到expected中去，并返回false
 * @param pAtom 指向Swift中AtomicIntPtr类型的原子对象，并且不允许为空
 * @param expected 存放与原子对象进行比较的值的指针。
 *                 该指针一般指向用原子加载操作所得到值的变量，并且不能为空。
 * @param desired 要存入到原子对象中的值
 * @return 如果expected中的值与原子对象中所存放的值相同，则返回true，否则返回false
 */
extern bool __attribute__((overloadable)) AtomicSwiftCAS(struct AtomicIntPtrSwift* __nonnull pAtom, intptr_t* restrict __nonnull expected, intptr_t desired);

/**
 * 原子加法操作
 * @param pAtom 指向Swift中AtomicIntPtr类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern intptr_t __attribute__((overloadable)) AtomicSwiftFetchAdd(struct AtomicIntPtrSwift* __nonnull pAtom, intptr_t value);

/**
 * 原子减法操作
 * @param pAtom 指向Swift中AtomicIntPtr类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern intptr_t __attribute__((overloadable)) AtomicSwiftFetchSub(struct AtomicIntPtrSwift* __nonnull pAtom, intptr_t value);

/**
 * 原子按位或操作
 * @param pAtom 指向Swift中AtomicIntPtr类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern intptr_t __attribute__((overloadable)) AtomicSwiftFetchOr(struct AtomicIntPtrSwift* __nonnull pAtom, intptr_t value);

/**
 * 原子按位异或操作
 * @param pAtom 指向Swift中AtomicIntPtr类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern intptr_t __attribute__((overloadable)) AtomicSwiftFetchXor(struct AtomicIntPtrSwift* __nonnull pAtom, intptr_t value);

/**
 * 原子按位与操作
 * @param pAtom 指向Swift中AtomicIntPtr类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern intptr_t __attribute__((overloadable)) AtomicSwiftFetchAnd(struct AtomicIntPtrSwift* __nonnull pAtom, intptr_t value);


// MARK: atomic uintptr_t

/** 用于Swift的AtomicUIntPtr原子类型 */
struct AtomicUIntPtrSwift {
    volatile atomic_uintptr_t atom;
};

/**
 * 对原子对象进行初始化
 * @param pAtom 指向Swift中AtomicIntPtr类型的原子对象，并且不允许为空
 * @param value 指定要给原子对象初始化的值
 */
extern void __attribute__((overloadable)) AtomicSwiftInit(struct AtomicUIntPtrSwift* __nonnull pAtom, uintptr_t value);

/**
 * 对原子对象进行加载操作
 * @param pAtom 指向Swift中AtomicUIntPtr类型的原子对象，并且不允许为空
 * @return 指定原子对象所存储的值
 */
extern uintptr_t __attribute__((overloadable)) AtomicSwiftLoad(struct AtomicUIntPtrSwift* __nonnull pAtom);

/**
 * 对原子对象进行存储操作
 * @param pAtom 指向Swift中AtomicUIntPtrSwift类型的原子对象，并且不允许为空
 * @param value 要存储到指定原子对象中的值
 */
extern void __attribute__((overloadable)) AtomicSwiftStore(struct AtomicUIntPtrSwift* __nonnull pAtom, uintptr_t value);

/**
 * 将原子对象中存放的值与所指定的基本类型的值进行交换。
 *
 * 也就是说，将基本类型的值存放到原子对象中去，并将原子对象的原始值返回
 * @param pAtom 指向Swift中AtomicUIntPtr类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uintptr_t __attribute__((overloadable)) AtomicSwiftExchange(struct AtomicUIntPtrSwift* __nonnull pAtom, uintptr_t value);

/**
 * 原子比较与交换
 *
 * 将原子对象中的值与expected的值进行比较，如果相同则将desired的值写入到原子对象中，并返回true；
 * 否则，将当前原子对象中的值写入到expected中去，并返回false
 * @param pAtom 指向Swift中AtomicUIntPtr类型的原子对象，并且不允许为空
 * @param expected 存放与原子对象进行比较的值的指针。
 *                 该指针一般指向用原子加载操作所得到值的变量，并且不能为空。
 * @param desired 要存入到原子对象中的值
 * @return 如果expected中的值与原子对象中所存放的值相同，则返回true，否则返回false
 */
extern bool __attribute__((overloadable)) AtomicSwiftCAS(struct AtomicUIntPtrSwift* __nonnull pAtom, uintptr_t* restrict __nonnull expected, uintptr_t desired);

/**
 * 原子加法操作
 * @param pAtom 指向Swift中AtomicUIntPtr类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uintptr_t __attribute__((overloadable)) AtomicSwiftFetchAdd(struct AtomicUIntPtrSwift* __nonnull pAtom, uintptr_t value);

/**
 * 原子减法操作
 * @param pAtom 指向Swift中AtomicUIntPtr类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uintptr_t __attribute__((overloadable)) AtomicSwiftFetchSub(struct AtomicUIntPtrSwift* __nonnull pAtom, uintptr_t value);

/**
 * 原子按位或操作
 * @param pAtom 指向Swift中AtomicUIntPtr类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uintptr_t __attribute__((overloadable)) AtomicSwiftFetchOr(struct AtomicUIntPtrSwift* __nonnull pAtom, uintptr_t value);

/**
 * 原子按位异或操作
 * @param pAtom 指向Swift中AtomicUIntPtr类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uintptr_t __attribute__((overloadable)) AtomicSwiftFetchXor(struct AtomicUIntPtrSwift* __nonnull pAtom, uintptr_t value);

/**
 * 原子按位与操作
 * @param pAtom 指向Swift中AtomicUIntPtr类型的原子对象，并且不允许为空
 * @param value 指定的基本类型的值
 * @return 原子对象的原始值
 */
extern uintptr_t __attribute__((overloadable)) AtomicSwiftFetchAnd(struct AtomicUIntPtrSwift* __nonnull pAtom, uintptr_t value);

