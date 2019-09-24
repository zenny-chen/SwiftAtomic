//
//  CLib4Swift.m
//  SwiftAtomic
//
//  Created by Zenny Chen on 2016/9/25.
//  Copyright © 2016年 GreenGames Studio. All rights reserved.
//

#include "swift_atomics.h"
#include <stdio.h>

void swiftCPUPause(void)
{
#if defined(__arm__) || defined(__aarch64__)
    asm("yield");
#elif defined(__x86__) || defined(__x86_64__)
    asm("pause");
#endif
}

// MARK: atomic bool

void __attribute__((overloadable)) AtomicSwiftInit(struct AtomicBoolSwift* __nonnull pAtom, bool value)
{
    if(pAtom == NULL)
        return;
    
    atomic_init(&pAtom->atom, value);
}

bool __attribute__((overloadable)) AtomicSwiftLoad(struct AtomicBoolSwift* __nonnull pAtom)
{
    if(pAtom == NULL)
        return false;
    
    return atomic_load(&pAtom->atom);
}

void __attribute__((overloadable)) AtomicSwiftStore(struct AtomicBoolSwift* __nonnull pAtom, bool value)
{
    if(pAtom == NULL)
        return;
    
    atomic_store(&pAtom->atom, value);
}

bool __attribute__((overloadable)) AtomicSwiftExchange(struct AtomicBoolSwift* __nonnull pAtom, bool value)
{
    if(pAtom == NULL)
        return false;
    
    return atomic_exchange(&pAtom->atom, value);
}

bool __attribute__((overloadable)) AtomicSwiftCAS(struct AtomicBoolSwift* __nonnull pAtom, bool* restrict __nonnull expected, bool desired)
{
    if(pAtom == NULL || expected == NULL)
        return false;
    
    return atomic_compare_exchange_weak(&pAtom->atom, expected, desired);
}


// MARK: atomic byte

void __attribute__((overloadable)) AtomicSwiftInit(struct AtomicByteSwift* __nonnull pAtom, int8_t value)
{
    if(pAtom == NULL)
        return;
    
    atomic_init(&pAtom->atom, value);
}

int8_t __attribute__((overloadable)) AtomicSwiftLoad(struct AtomicByteSwift* __nonnull pAtom)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_load(&pAtom->atom);
}

void __attribute__((overloadable)) AtomicSwiftStore(struct AtomicByteSwift* __nonnull pAtom, int8_t value)
{
    if(pAtom == NULL)
        return;
    
    atomic_store(&pAtom->atom, value);
}

int8_t __attribute__((overloadable)) AtomicSwiftExchange(struct AtomicByteSwift* __nonnull pAtom, int8_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_exchange(&pAtom->atom, value);
}

bool __attribute__((overloadable)) AtomicSwiftCAS(struct AtomicByteSwift* __nonnull pAtom, int8_t* restrict __nonnull expected, int8_t desired)
{
    if(pAtom == NULL || expected == NULL)
        return false;
    
    return atomic_compare_exchange_weak(&pAtom->atom, expected, desired);
}

int8_t __attribute__((overloadable)) AtomicSwiftFetchAdd(struct AtomicByteSwift* __nonnull pAtom, int8_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_add(&pAtom->atom, value);
}

int8_t __attribute__((overloadable)) AtomicSwiftFetchSub(struct AtomicByteSwift* __nonnull pAtom, int8_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_sub(&pAtom->atom, value);
}

int8_t __attribute__((overloadable)) AtomicSwiftFetchOr(struct AtomicByteSwift* __nonnull pAtom, int8_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_or(&pAtom->atom, value);
}

int8_t __attribute__((overloadable)) AtomicSwiftFetchXor(struct AtomicByteSwift* __nonnull pAtom, int8_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_xor(&pAtom->atom, value);
}

int8_t __attribute__((overloadable)) AtomicSwiftFetchAnd(struct AtomicByteSwift* __nonnull pAtom, int8_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_and(&pAtom->atom, value);
}


// MARK: atomic ubyte

void __attribute__((overloadable)) AtomicSwiftInit(struct AtomicUByteSwift* __nonnull pAtom, uint8_t value)
{
    if(pAtom == NULL)
        return;
    
    atomic_init(&pAtom->atom, value);
}

uint8_t __attribute__((overloadable)) AtomicSwiftLoad(struct AtomicUByteSwift* __nonnull pAtom)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_load(&pAtom->atom);
}

void __attribute__((overloadable)) AtomicSwiftStore(struct AtomicUByteSwift* __nonnull pAtom, uint8_t value)
{
    if(pAtom == NULL)
        return;
    
    atomic_store(&pAtom->atom, value);
}

uint8_t __attribute__((overloadable)) AtomicSwiftExchange(struct AtomicUByteSwift* __nonnull pAtom, uint8_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_exchange(&pAtom->atom, value);
}

bool __attribute__((overloadable)) AtomicSwiftCAS(struct AtomicUByteSwift* __nonnull pAtom, uint8_t* restrict __nonnull expected, uint8_t desired)
{
    if(pAtom == NULL || expected == NULL)
        return false;
    
    return atomic_compare_exchange_weak(&pAtom->atom, expected, desired);
}

uint8_t __attribute__((overloadable)) AtomicSwiftFetchAdd(struct AtomicUByteSwift* __nonnull pAtom, uint8_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_add(&pAtom->atom, value);
}

uint8_t __attribute__((overloadable)) AtomicSwiftFetchSub(struct AtomicUByteSwift* __nonnull pAtom, uint8_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_sub(&pAtom->atom, value);
}

uint8_t __attribute__((overloadable)) AtomicSwiftFetchOr(struct AtomicUByteSwift* __nonnull pAtom, uint8_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_or(&pAtom->atom, value);
}

uint8_t __attribute__((overloadable)) AtomicSwiftFetchXor(struct AtomicUByteSwift* __nonnull pAtom, uint8_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_xor(&pAtom->atom, value);
}

uint8_t __attribute__((overloadable)) AtomicSwiftFetchAnd(struct AtomicUByteSwift* __nonnull pAtom, uint8_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_and(&pAtom->atom, value);
}


// MARK: atomic short

void __attribute__((overloadable)) AtomicSwiftInit(struct AtomicShortSwift* __nonnull pAtom, int16_t value)
{
    if(pAtom == NULL)
        return;
    
    atomic_init(&pAtom->atom, value);
}

int16_t __attribute__((overloadable)) AtomicSwiftLoad(struct AtomicShortSwift* __nonnull pAtom)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_load(&pAtom->atom);
}

void __attribute__((overloadable)) AtomicSwiftStore(struct AtomicShortSwift* __nonnull pAtom, int16_t value)
{
    if(pAtom == NULL)
        return;
    
    atomic_store(&pAtom->atom, value);
}

int16_t __attribute__((overloadable)) AtomicSwiftExchange(struct AtomicShortSwift* __nonnull pAtom, int16_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_exchange(&pAtom->atom, value);
}

bool __attribute__((overloadable)) AtomicSwiftCAS(struct AtomicShortSwift* __nonnull pAtom, int16_t* restrict __nonnull expected, int16_t desired)
{
    if(pAtom == NULL || expected == NULL)
        return false;
    
    return atomic_compare_exchange_weak(&pAtom->atom, expected, desired);
}

int16_t __attribute__((overloadable)) AtomicSwiftFetchAdd(struct AtomicShortSwift* __nonnull pAtom, int16_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_add(&pAtom->atom, value);
}

int16_t __attribute__((overloadable)) AtomicSwiftFetchSub(struct AtomicShortSwift* __nonnull pAtom, int16_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_sub(&pAtom->atom, value);
}

int16_t __attribute__((overloadable)) AtomicSwiftFetchOr(struct AtomicShortSwift* __nonnull pAtom, int16_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_or(&pAtom->atom, value);
}

int16_t __attribute__((overloadable)) AtomicSwiftFetchXor(struct AtomicShortSwift* __nonnull pAtom, int16_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_xor(&pAtom->atom, value);
}

int16_t __attribute__((overloadable)) AtomicSwiftFetchAnd(struct AtomicShortSwift* __nonnull pAtom, int16_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_and(&pAtom->atom, value);
}


// MARK: atomic ushort

void __attribute__((overloadable)) AtomicSwiftInit(struct AtomicUShortSwift* __nonnull pAtom, uint16_t value)
{
    if(pAtom == NULL)
        return;
    
    atomic_init(&pAtom->atom, value);
}

uint16_t __attribute__((overloadable)) AtomicSwiftLoad(struct AtomicUShortSwift* __nonnull pAtom)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_load(&pAtom->atom);
}

void __attribute__((overloadable)) AtomicSwiftStore(struct AtomicUShortSwift* __nonnull pAtom, uint16_t value)
{
    if(pAtom == NULL)
        return;
    
    atomic_store(&pAtom->atom, value);
}

uint16_t __attribute__((overloadable)) AtomicSwiftExchange(struct AtomicUShortSwift* __nonnull pAtom, uint16_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_exchange(&pAtom->atom, value);
}

bool __attribute__((overloadable)) AtomicSwiftCAS(struct AtomicUShortSwift* __nonnull pAtom, uint16_t* restrict __nonnull expected, uint16_t desired)
{
    if(pAtom == NULL || expected == NULL)
        return false;
    
    return atomic_compare_exchange_weak(&pAtom->atom, expected, desired);
}

uint16_t __attribute__((overloadable)) AtomicSwiftFetchAdd(struct AtomicUShortSwift* __nonnull pAtom, uint16_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_add(&pAtom->atom, value);
}

uint16_t __attribute__((overloadable)) AtomicSwiftFetchSub(struct AtomicUShortSwift* __nonnull pAtom, uint16_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_sub(&pAtom->atom, value);
}

uint16_t __attribute__((overloadable)) AtomicSwiftFetchOr(struct AtomicUShortSwift* __nonnull pAtom, uint16_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_or(&pAtom->atom, value);
}

uint16_t __attribute__((overloadable)) AtomicSwiftFetchXor(struct AtomicUShortSwift* __nonnull pAtom, uint16_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_xor(&pAtom->atom, value);
}

uint16_t __attribute__((overloadable)) AtomicSwiftFetchAnd(struct AtomicUShortSwift* __nonnull pAtom, uint16_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_and(&pAtom->atom, value);
}


// MARK: atomic int

void __attribute__((overloadable)) AtomicSwiftInit(struct AtomicIntSwift* __nonnull pAtom, int32_t value)
{
    if(pAtom == NULL)
        return;
    
    atomic_init(&pAtom->atom, value);
}

int32_t __attribute__((overloadable)) AtomicSwiftLoad(struct AtomicIntSwift* __nonnull pAtom)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_load(&pAtom->atom);
}

void __attribute__((overloadable)) AtomicSwiftStore(struct AtomicIntSwift* __nonnull pAtom, int32_t value)
{
    if(pAtom == NULL)
        return;
    
    atomic_store(&pAtom->atom, value);
}

int32_t __attribute__((overloadable)) AtomicSwiftExchange(struct AtomicIntSwift* __nonnull pAtom, int32_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_exchange(&pAtom->atom, value);
}

bool __attribute__((overloadable)) AtomicSwiftCAS(struct AtomicIntSwift* __nonnull pAtom, int32_t* restrict __nonnull expected, int32_t desired)
{
    if(pAtom == NULL || expected == NULL)
        return false;
    
    return atomic_compare_exchange_weak(&pAtom->atom, expected, desired);
}

int32_t __attribute__((overloadable)) AtomicSwiftFetchAdd(struct AtomicIntSwift* __nonnull pAtom, int32_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_add(&pAtom->atom, value);
}

int32_t __attribute__((overloadable)) AtomicSwiftFetchSub(struct AtomicIntSwift* __nonnull pAtom, int32_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_sub(&pAtom->atom, value);
}

int32_t __attribute__((overloadable)) AtomicSwiftFetchOr(struct AtomicIntSwift* __nonnull pAtom, int32_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_or(&pAtom->atom, value);
}

int32_t __attribute__((overloadable)) AtomicSwiftFetchXor(struct AtomicIntSwift* __nonnull pAtom, int32_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_xor(&pAtom->atom, value);
}

int32_t __attribute__((overloadable)) AtomicSwiftFetchAnd(struct AtomicIntSwift* __nonnull pAtom, int32_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_and(&pAtom->atom, value);
}


// MARK: atomic uint

void __attribute__((overloadable)) AtomicSwiftInit(struct AtomicUIntSwift* __nonnull pAtom, uint32_t value)
{
    if(pAtom == NULL)
        return;
    
    atomic_init(&pAtom->atom, value);
}

uint32_t __attribute__((overloadable)) AtomicSwiftLoad(struct AtomicUIntSwift* __nonnull pAtom)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_load(&pAtom->atom);
}

void __attribute__((overloadable)) AtomicSwiftStore(struct AtomicUIntSwift* __nonnull pAtom, uint32_t value)
{
    if(pAtom == NULL)
        return;
    
    atomic_store(&pAtom->atom, value);
}

uint32_t __attribute__((overloadable)) AtomicSwiftExchange(struct AtomicUIntSwift* __nonnull pAtom, uint32_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_exchange(&pAtom->atom, value);
}

bool __attribute__((overloadable)) AtomicSwiftCAS(struct AtomicUIntSwift* __nonnull pAtom, uint32_t* restrict __nonnull expected, uint32_t desired)
{
    if(pAtom == NULL || expected == NULL)
        return false;
    
    return atomic_compare_exchange_weak(&pAtom->atom, expected, desired);
}

uint32_t __attribute__((overloadable)) AtomicSwiftFetchAdd(struct AtomicUIntSwift* __nonnull pAtom, uint32_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_add(&pAtom->atom, value);
}

uint32_t __attribute__((overloadable)) AtomicSwiftFetchSub(struct AtomicUIntSwift* __nonnull pAtom, uint32_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_sub(&pAtom->atom, value);
}

uint32_t __attribute__((overloadable)) AtomicSwiftFetchOr(struct AtomicUIntSwift* __nonnull pAtom, uint32_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_or(&pAtom->atom, value);
}

uint32_t __attribute__((overloadable)) AtomicSwiftFetchXor(struct AtomicUIntSwift* __nonnull pAtom, uint32_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_xor(&pAtom->atom, value);
}

uint32_t __attribute__((overloadable)) AtomicSwiftFetchAnd(struct AtomicUIntSwift* __nonnull pAtom, uint32_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_and(&pAtom->atom, value);
}


// MARK: atomic int64_t

void __attribute__((overloadable)) AtomicSwiftInit(struct AtomicLongSwift* __nonnull pAtom, int64_t value)
{
    if(pAtom == NULL)
        return;
    
    atomic_init(&pAtom->atom, value);
}

int64_t __attribute__((overloadable)) AtomicSwiftLoad(struct AtomicLongSwift* __nonnull pAtom)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_load(&pAtom->atom);
}

void __attribute__((overloadable)) AtomicSwiftStore(struct AtomicLongSwift* __nonnull pAtom, int64_t value)
{
    if(pAtom == NULL)
        return;
    
    atomic_store(&pAtom->atom, value);
}

int64_t __attribute__((overloadable)) AtomicSwiftExchange(struct AtomicLongSwift* __nonnull pAtom, int64_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_exchange(&pAtom->atom, value);
}

bool __attribute__((overloadable)) AtomicSwiftCAS(struct AtomicLongSwift* __nonnull pAtom, int64_t* restrict __nonnull expected, int64_t desired)
{
    if(pAtom == NULL || expected == NULL)
        return false;
    
    return atomic_compare_exchange_weak(&pAtom->atom, expected, desired);
}

int64_t __attribute__((overloadable)) AtomicSwiftFetchAdd(struct AtomicLongSwift* __nonnull pAtom, int64_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_add(&pAtom->atom, value);
}

int64_t __attribute__((overloadable)) AtomicSwiftFetchSub(struct AtomicLongSwift* __nonnull pAtom, int64_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_sub(&pAtom->atom, value);
}

int64_t __attribute__((overloadable)) AtomicSwiftFetchOr(struct AtomicLongSwift* __nonnull pAtom, int64_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_or(&pAtom->atom, value);
}

int64_t __attribute__((overloadable)) AtomicSwiftFetchXor(struct AtomicLongSwift* __nonnull pAtom, int64_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_xor(&pAtom->atom, value);
}

int64_t __attribute__((overloadable)) AtomicSwiftFetchAnd(struct AtomicLongSwift* __nonnull pAtom, int64_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_and(&pAtom->atom, value);
}


// MARK: atomic uint64_t

void __attribute__((overloadable)) AtomicSwiftInit(struct AtomicULongSwift* __nonnull pAtom, uint64_t value)
{
    if(pAtom == NULL)
        return;
    
    atomic_init(&pAtom->atom, value);
}

uint64_t __attribute__((overloadable)) AtomicSwiftLoad(struct AtomicULongSwift* __nonnull pAtom)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_load(&pAtom->atom);
}

void __attribute__((overloadable)) AtomicSwiftStore(struct AtomicULongSwift* __nonnull pAtom, uint64_t value)
{
    if(pAtom == NULL)
        return;
    
    atomic_store(&pAtom->atom, value);
}

uint64_t __attribute__((overloadable)) AtomicSwiftExchange(struct AtomicULongSwift* __nonnull pAtom, uint64_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_exchange(&pAtom->atom, value);
}

bool __attribute__((overloadable)) AtomicSwiftCAS(struct AtomicULongSwift* __nonnull pAtom, uint64_t* restrict __nonnull expected, uint64_t desired)
{
    if(pAtom == NULL || expected == NULL)
        return false;
    
    return atomic_compare_exchange_weak(&pAtom->atom, expected, desired);
}

uint64_t __attribute__((overloadable)) AtomicSwiftFetchAdd(struct AtomicULongSwift* __nonnull pAtom, uint64_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_add(&pAtom->atom, value);
}

uint64_t __attribute__((overloadable)) AtomicSwiftFetchSub(struct AtomicULongSwift* __nonnull pAtom, uint64_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_sub(&pAtom->atom, value);
}

uint64_t __attribute__((overloadable)) AtomicSwiftFetchOr(struct AtomicULongSwift* __nonnull pAtom, uint64_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_or(&pAtom->atom, value);
}

uint64_t __attribute__((overloadable)) AtomicSwiftFetchXor(struct AtomicULongSwift* __nonnull pAtom, uint64_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_xor(&pAtom->atom, value);
}

uint64_t __attribute__((overloadable)) AtomicSwiftFetchAnd(struct AtomicULongSwift* __nonnull pAtom, uint64_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_and(&pAtom->atom, value);
}


// MARK: atomic intptr_t

void __attribute__((overloadable)) AtomicSwiftInit(struct AtomicIntPtrSwift* __nonnull pAtom, intptr_t value)
{
    if(pAtom == NULL)
        return;
    
    atomic_init(&pAtom->atom, value);
}

intptr_t __attribute__((overloadable)) AtomicSwiftLoad(struct AtomicIntPtrSwift* __nonnull pAtom)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_load(&pAtom->atom);
}

void __attribute__((overloadable)) AtomicSwiftStore(struct AtomicIntPtrSwift* __nonnull pAtom, intptr_t value)
{
    if(pAtom == NULL)
        return;
    
    atomic_store(&pAtom->atom, value);
}

intptr_t __attribute__((overloadable)) AtomicSwiftExchange(struct AtomicIntPtrSwift* __nonnull pAtom, intptr_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_exchange(&pAtom->atom, value);
}

bool __attribute__((overloadable)) AtomicSwiftCAS(struct AtomicIntPtrSwift* __nonnull pAtom, intptr_t* restrict __nonnull expected, intptr_t desired)
{
    if(pAtom == NULL || expected == NULL)
        return false;
    
    return atomic_compare_exchange_weak(&pAtom->atom, expected, desired);
}

intptr_t __attribute__((overloadable)) AtomicSwiftFetchAdd(struct AtomicIntPtrSwift* __nonnull pAtom, intptr_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_add(&pAtom->atom, value);
}

intptr_t __attribute__((overloadable)) AtomicSwiftFetchSub(struct AtomicIntPtrSwift* __nonnull pAtom, intptr_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_sub(&pAtom->atom, value);
}

intptr_t __attribute__((overloadable)) AtomicSwiftFetchOr(struct AtomicIntPtrSwift* __nonnull pAtom, intptr_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_or(&pAtom->atom, value);
}

intptr_t __attribute__((overloadable)) AtomicSwiftFetchXor(struct AtomicIntPtrSwift* __nonnull pAtom, intptr_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_xor(&pAtom->atom, value);
}

intptr_t __attribute__((overloadable)) AtomicSwiftFetchAnd(struct AtomicIntPtrSwift* __nonnull pAtom, intptr_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_and(&pAtom->atom, value);
}


// MARK: atomic uintptr_t

void __attribute__((overloadable)) AtomicSwiftInit(struct AtomicUIntPtrSwift* __nonnull pAtom, uintptr_t value)
{
    if(pAtom == NULL)
        return;
    
    atomic_init(&pAtom->atom, value);
}

uintptr_t __attribute__((overloadable)) AtomicSwiftLoad(struct AtomicUIntPtrSwift* __nonnull pAtom)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_load(&pAtom->atom);
}

void __attribute__((overloadable)) AtomicSwiftStore(struct AtomicUIntPtrSwift* __nonnull pAtom, uintptr_t value)
{
    if(pAtom == NULL)
        return;
    
    atomic_store(&pAtom->atom, value);
}

uintptr_t __attribute__((overloadable)) AtomicSwiftExchange(struct AtomicUIntPtrSwift* __nonnull pAtom, uintptr_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_exchange(&pAtom->atom, value);
}

bool __attribute__((overloadable)) AtomicSwiftCAS(struct AtomicUIntPtrSwift* __nonnull pAtom, uintptr_t* restrict __nonnull expected, uintptr_t desired)
{
    if(pAtom == NULL || expected == NULL)
        return false;
    
    return atomic_compare_exchange_weak(&pAtom->atom, expected, desired);
}

uintptr_t __attribute__((overloadable)) AtomicSwiftFetchAdd(struct AtomicUIntPtrSwift* __nonnull pAtom, uintptr_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_add(&pAtom->atom, value);
}

uintptr_t __attribute__((overloadable)) AtomicSwiftFetchSub(struct AtomicUIntPtrSwift* __nonnull pAtom, uintptr_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_sub(&pAtom->atom, value);
}

uintptr_t __attribute__((overloadable)) AtomicSwiftFetchOr(struct AtomicUIntPtrSwift* __nonnull pAtom, uintptr_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_or(&pAtom->atom, value);
}

uintptr_t __attribute__((overloadable)) AtomicSwiftFetchXor(struct AtomicUIntPtrSwift* __nonnull pAtom, uintptr_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_xor(&pAtom->atom, value);
}

uintptr_t __attribute__((overloadable)) AtomicSwiftFetchAnd(struct AtomicUIntPtrSwift* __nonnull pAtom, uintptr_t value)
{
    if(pAtom == NULL)
        return 0;
    
    return atomic_fetch_and(&pAtom->atom, value);
}

