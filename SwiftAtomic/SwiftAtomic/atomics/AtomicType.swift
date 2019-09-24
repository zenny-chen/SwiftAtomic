//
//  AtomicType.swift
//  SwiftAtomic
//
//  Created by Zenny Chen on 2016/9/25.
//  Copyright © 2016年 GreenGames Studio. All rights reserved.
//

import Foundation

/** 所有原子类型所需遵循的原子类型协议 */
public protocol AtomicType {
    
    /** 当前原子类型所对应的基本类型 */
    associatedtype RawType
    
    /** 初始化器，对当前原子对象初始化为0值。它不具有原子性 */
    init()
    
    /**
     初始化器，对当前原子对象初始化为形参指定的值。它不具有原子性
     
     - parameters:
        - value: 为当前原子对象初始化的初始值
     */
    init(value: RawType)
    
    /**
     加载当前原子对象的值，并返回。
     
     - returns: 当前原子对象对应的基本类型的值
     */
    mutating func load() -> RawType
    
    /**
     将一个指定的基本类型值存放到当前原子对象中
     
     - parameters:
        - value: 指定要存放的基本类型的值
     */
    mutating func store(by value: RawType)
    
    /**
     将指定的基本类型的值存入当前原子对象中，并返回存入之前的原子对象的原始值
     
     - parameters:
        - value: 指定的基本类型的值
     
     - returns: 在将指定值存入之前的原子对象的原始值
     */
    mutating func exchange(with value: RawType) -> RawType
    
    /**
     原子比较与交换。
     
     
     当前原子对象的值先与expected的值进行比较，如果相同则将desired的值存入当前原子对象，并返回true；
     否则将当前原子对象的值存入expected，然后返回false。
     
     - parameters:
        - expected: 指向基本类型对象的指针。此基本类型对象在调用该函数前一般会用load方法将当前原子对象的值加载进去。
        - desired: 最终所要写入的值
     
     - returns: 如果当前原子对象的值与expected中的值相同，那么返回true，否则返回false
     */
    mutating func cas(expected: UnsafeMutablePointer<RawType>, desired: RawType) -> Bool
    
    /**
     原子加法操作
     
     - parameters:
        - operand: 加法操作数
     
     - returns: 加法操作之前原子对象的原始值
     */
    mutating func fetch_add(operand: RawType) -> RawType
    
    /**
     原子减法操作
     
     - parameters:
        - operand: 减法操作数
     
     - returns: 减法操作之前原子对象的原始值
     */
    mutating func fetch_sub(operand: RawType) -> RawType
    
    /**
     原子按位或操作
     
     - parameters:
        - operand: 按位或操作数
     
     - returns: 按位或操作之前原子对象的原始值
     */
    mutating func fetch_or(operand: RawType) -> RawType
    
    /**
     原子按位异或操作
     
     - parameters:
        - operand: 按位异或操作数
     
     - returns: 按位异或操作之前原子对象的原始值
     */
    mutating func fetch_xor(operand: RawType) -> RawType
    
    /**
     原子按位与操作
     
     - parameters:
        - operand: 按位与操作数
     
     - returns: 按位与操作之前原子对象的原始值
     */
    mutating func fetch_and(operand: RawType) -> RawType
}

// MARK: AtomicBool
/** 布尔原子类型 */
public struct AtomicBool: AtomicType {
    
    private var mAtomicValue = AtomicBoolSwift()
    
    public typealias RawType = Bool
    
    public init() {
        AtomicSwiftInit(&mAtomicValue, false)
    }
    
    public init(value: RawType) {
        AtomicSwiftInit(&mAtomicValue, value)
    }
    
    public mutating func load() -> RawType {
        return AtomicSwiftLoad(&mAtomicValue)
    }
    
    public mutating func store(by value: RawType) {
        AtomicSwiftStore(&mAtomicValue, value)
    }
    
    public mutating func exchange(with value: RawType) -> RawType {
        return AtomicSwiftExchange(&mAtomicValue, value)
    }
    
    public mutating func cas(expected: UnsafeMutablePointer<RawType>, desired: RawType) -> Bool {
        return AtomicSwiftCAS(&mAtomicValue, expected, desired)
    }
    
    public mutating func fetch_add(operand: RawType) -> RawType {
        assertionFailure("Atomic Bool does not support fetch operation!")
        return false
    }
    
    public mutating func fetch_sub(operand: RawType) -> RawType {
        assertionFailure("Atomic Bool does not support fetch operation!")
        return false
    }
    
    public mutating func fetch_or(operand: RawType) -> RawType {
        assertionFailure("Atomic Bool does not support fetch operation!")
        return false
    }
    
    public mutating func fetch_xor(operand: RawType) -> RawType {
        assertionFailure("Atomic Bool does not support fetch operation!")
        return false
    }
    
    public mutating func fetch_and(operand: RawType) -> RawType {
        assertionFailure("Atomic Bool does not support fetch operation!")
        return false
    }
}

// MARK: AtomicByte
/** 8位带符号整数原子类型 */
public struct AtomicByte: AtomicType {
    
    private var mAtomicValue = AtomicByteSwift()
    
    public typealias RawType = Int8
    
    public init() {
        AtomicSwiftInit(&mAtomicValue, 0)
    }
    
    public init(value: RawType) {
        AtomicSwiftInit(&mAtomicValue, value)
    }
    
    public mutating func load() -> RawType {
        return AtomicSwiftLoad(&mAtomicValue)
    }
    
    public mutating func store(by value: RawType) {
        AtomicSwiftStore(&mAtomicValue, value)
    }
    
    public mutating func exchange(with value: RawType) -> RawType {
        return AtomicSwiftExchange(&mAtomicValue, value)
    }
    
    public mutating func cas(expected: UnsafeMutablePointer<RawType>, desired: RawType) -> Bool {
        return AtomicSwiftCAS(&mAtomicValue, expected, desired)
    }
    
    public mutating func fetch_add(operand: RawType) -> RawType {
        return AtomicSwiftFetchAdd(&mAtomicValue, operand)
    }
    
    public mutating func fetch_sub(operand: RawType) -> RawType {
        return AtomicSwiftFetchSub(&mAtomicValue, operand)
    }
    
    public mutating func fetch_or(operand: RawType) -> RawType {
        return AtomicSwiftFetchOr(&mAtomicValue, operand)
    }
    
    public mutating func fetch_xor(operand: RawType) -> RawType {
        return AtomicSwiftFetchXor(&mAtomicValue, operand)
    }
    
    public mutating func fetch_and(operand: RawType) -> RawType {
        return AtomicSwiftFetchAnd(&mAtomicValue, operand)
    }
}

// MARK: AtomicUByte
/** 8位无符号整数原子类型 */
public struct AtomicUByte: AtomicType {
    
    private var mAtomicValue = AtomicUByteSwift()
    
    public typealias RawType = UInt8
    
    public init() {
        AtomicSwiftInit(&mAtomicValue, 0)
    }
    
    public init(value: RawType) {
        AtomicSwiftInit(&mAtomicValue, value)
    }
    
    public mutating func load() -> RawType {
        return AtomicSwiftLoad(&mAtomicValue)
    }
    
    public mutating func store(by value: RawType) {
        AtomicSwiftStore(&mAtomicValue, value)
    }
    
    public mutating func exchange(with value: RawType) -> RawType {
        return AtomicSwiftExchange(&mAtomicValue, value)
    }
    
    public mutating func cas(expected: UnsafeMutablePointer<RawType>, desired: RawType) -> Bool {
        return AtomicSwiftCAS(&mAtomicValue, expected, desired)
    }
    
    public mutating func fetch_add(operand: RawType) -> RawType {
        return AtomicSwiftFetchAdd(&mAtomicValue, operand)
    }
    
    public mutating func fetch_sub(operand: RawType) -> RawType {
        return AtomicSwiftFetchSub(&mAtomicValue, operand)
    }
    
    public mutating func fetch_or(operand: RawType) -> RawType {
        return AtomicSwiftFetchOr(&mAtomicValue, operand)
    }
    
    public mutating func fetch_xor(operand: RawType) -> RawType {
        return AtomicSwiftFetchXor(&mAtomicValue, operand)
    }
    
    public mutating func fetch_and(operand: RawType) -> RawType {
        return AtomicSwiftFetchAnd(&mAtomicValue, operand)
    }
}

// MARK: AtomicShort
/** 16位带符号整数原子类型 */
public struct AtomicShort: AtomicType {
    
    private var mAtomicValue = AtomicShortSwift()
    
    public typealias RawType = Int16
    
    public init() {
        AtomicSwiftInit(&mAtomicValue, 0)
    }
    
    public init(value: RawType) {
        AtomicSwiftInit(&mAtomicValue, value)
    }
    
    public mutating func load() -> RawType {
        return AtomicSwiftLoad(&mAtomicValue)
    }
    
    public mutating func store(by value: RawType) {
        AtomicSwiftStore(&mAtomicValue, value)
    }
    
    public mutating func exchange(with value: RawType) -> RawType {
        return AtomicSwiftExchange(&mAtomicValue, value)
    }
    
    public mutating func cas(expected: UnsafeMutablePointer<RawType>, desired: RawType) -> Bool {
        return AtomicSwiftCAS(&mAtomicValue, expected, desired)
    }
    
    public mutating func fetch_add(operand: RawType) -> RawType {
        return AtomicSwiftFetchAdd(&mAtomicValue, operand)
    }
    
    public mutating func fetch_sub(operand: RawType) -> RawType {
        return AtomicSwiftFetchSub(&mAtomicValue, operand)
    }
    
    public mutating func fetch_or(operand: RawType) -> RawType {
        return AtomicSwiftFetchOr(&mAtomicValue, operand)
    }
    
    public mutating func fetch_xor(operand: RawType) -> RawType {
        return AtomicSwiftFetchXor(&mAtomicValue, operand)
    }
    
    public mutating func fetch_and(operand: RawType) -> RawType {
        return AtomicSwiftFetchAnd(&mAtomicValue, operand)
    }
}

// MARK: AtomicUShort
/** 16位无符号整数原子类型 */
public struct AtomicUShort: AtomicType {
    
    private var mAtomicValue = AtomicUShortSwift()
    
    public typealias RawType = UInt16
    
    public init() {
        AtomicSwiftInit(&mAtomicValue, 0)
    }
    
    public init(value: RawType) {
        AtomicSwiftInit(&mAtomicValue, value)
    }
    
    public mutating func load() -> RawType {
        return AtomicSwiftLoad(&mAtomicValue)
    }
    
    public mutating func store(by value: RawType) {
        AtomicSwiftStore(&mAtomicValue, value)
    }
    
    public mutating func exchange(with value: RawType) -> RawType {
        return AtomicSwiftExchange(&mAtomicValue, value)
    }
    
    public mutating func cas(expected: UnsafeMutablePointer<RawType>, desired: RawType) -> Bool {
        return AtomicSwiftCAS(&mAtomicValue, expected, desired)
    }
    
    public mutating func fetch_add(operand: RawType) -> RawType {
        return AtomicSwiftFetchAdd(&mAtomicValue, operand)
    }
    
    public mutating func fetch_sub(operand: RawType) -> RawType {
        return AtomicSwiftFetchSub(&mAtomicValue, operand)
    }
    
    public mutating func fetch_or(operand: RawType) -> RawType {
        return AtomicSwiftFetchOr(&mAtomicValue, operand)
    }
    
    public mutating func fetch_xor(operand: RawType) -> RawType {
        return AtomicSwiftFetchXor(&mAtomicValue, operand)
    }
    
    public mutating func fetch_and(operand: RawType) -> RawType {
        return AtomicSwiftFetchAnd(&mAtomicValue, operand)
    }
}

// MARK: AtomicInt
/** 32位带符号整数原子类型 */
public struct AtomicInt: AtomicType {
    
    private var mAtomicValue = AtomicIntSwift()
    
    public typealias RawType = Int32
    
    public init() {
        AtomicSwiftInit(&mAtomicValue, 0)
    }
    
    public init(value: RawType) {
        AtomicSwiftInit(&mAtomicValue, value)
    }
    
    public mutating func load() -> RawType {
        return AtomicSwiftLoad(&mAtomicValue)
    }
    
    public mutating func store(by value: RawType) {
        AtomicSwiftStore(&mAtomicValue, value)
    }
    
    public mutating func exchange(with value: RawType) -> RawType {
        return AtomicSwiftExchange(&mAtomicValue, value)
    }
    
    public mutating func cas(expected: UnsafeMutablePointer<RawType>, desired: RawType) -> Bool {
        return AtomicSwiftCAS(&mAtomicValue, expected, desired)
    }
    
    public mutating func fetch_add(operand: RawType) -> RawType {
        return AtomicSwiftFetchAdd(&mAtomicValue, operand)
    }
    
    public mutating func fetch_sub(operand: RawType) -> RawType {
        return AtomicSwiftFetchSub(&mAtomicValue, operand)
    }
    
    public mutating func fetch_or(operand: RawType) -> RawType {
        return AtomicSwiftFetchOr(&mAtomicValue, operand)
    }
    
    public mutating func fetch_xor(operand: RawType) -> RawType {
        return AtomicSwiftFetchXor(&mAtomicValue, operand)
    }
    
    public mutating func fetch_and(operand: RawType) -> RawType {
        return AtomicSwiftFetchAnd(&mAtomicValue, operand)
    }
}

// MARK: AtomicUInt
/** 32位无符号整数原子类型 */
public struct AtomicUInt: AtomicType {
    
    private var mAtomicValue = AtomicUIntSwift()
    
    public typealias RawType = UInt32
    
    public init() {
        AtomicSwiftInit(&mAtomicValue, 0)
    }
    
    public init(value: RawType) {
        AtomicSwiftInit(&mAtomicValue, value)
    }
    
    public mutating func load() -> RawType {
        return AtomicSwiftLoad(&mAtomicValue)
    }
    
    public mutating func store(by value: RawType) {
        AtomicSwiftStore(&mAtomicValue, value)
    }
    
    public mutating func exchange(with value: RawType) -> RawType {
        return AtomicSwiftExchange(&mAtomicValue, value)
    }
    
    public mutating func cas(expected: UnsafeMutablePointer<RawType>, desired: RawType) -> Bool {
        return AtomicSwiftCAS(&mAtomicValue, expected, desired)
    }
    
    public mutating func fetch_add(operand: RawType) -> RawType {
        return AtomicSwiftFetchAdd(&mAtomicValue, operand)
    }
    
    public mutating func fetch_sub(operand: RawType) -> RawType {
        return AtomicSwiftFetchSub(&mAtomicValue, operand)
    }
    
    public mutating func fetch_or(operand: RawType) -> RawType {
        return AtomicSwiftFetchOr(&mAtomicValue, operand)
    }
    
    public mutating func fetch_xor(operand: RawType) -> RawType {
        return AtomicSwiftFetchXor(&mAtomicValue, operand)
    }
    
    public mutating func fetch_and(operand: RawType) -> RawType {
        return AtomicSwiftFetchAnd(&mAtomicValue, operand)
    }
}

// MARK: AtomicLong
/** 64位无符号整数原子类型 */
public struct AtomicLong: AtomicType {
    
    private var mAtomicValue = AtomicLongSwift()
    
    public typealias RawType = Int64
    
    public init() {
        AtomicSwiftInit(&mAtomicValue, 0)
    }
    
    public init(value: RawType) {
        AtomicSwiftInit(&mAtomicValue, value)
    }
    
    public mutating func load() -> RawType {
        return AtomicSwiftLoad(&mAtomicValue)
    }
    
    public mutating func store(by value: RawType) {
        AtomicSwiftStore(&mAtomicValue, value)
    }
    
    public mutating func exchange(with value: RawType) -> RawType {
        return AtomicSwiftExchange(&mAtomicValue, value)
    }
    
    public mutating func cas(expected: UnsafeMutablePointer<RawType>, desired: RawType) -> Bool {
        return AtomicSwiftCAS(&mAtomicValue, expected, desired)
    }
    
    public mutating func fetch_add(operand: RawType) -> RawType {
        return AtomicSwiftFetchAdd(&mAtomicValue, operand)
    }
    
    public mutating func fetch_sub(operand: RawType) -> RawType {
        return AtomicSwiftFetchSub(&mAtomicValue, operand)
    }
    
    public mutating func fetch_or(operand: RawType) -> RawType {
        return AtomicSwiftFetchOr(&mAtomicValue, operand)
    }
    
    public mutating func fetch_xor(operand: RawType) -> RawType {
        return AtomicSwiftFetchXor(&mAtomicValue, operand)
    }
    
    public mutating func fetch_and(operand: RawType) -> RawType {
        return AtomicSwiftFetchAnd(&mAtomicValue, operand)
    }
}

// MARK: AtomicULong
/** 64位无符号整数原子类型 */
public struct AtomicULong: AtomicType {
    
    private var mAtomicValue = AtomicULongSwift()
    
    public typealias RawType = UInt64
    
    public init() {
        AtomicSwiftInit(&mAtomicValue, 0)
    }
    
    public init(value: RawType) {
        AtomicSwiftInit(&mAtomicValue, value)
    }
    
    public mutating func load() -> RawType {
        return AtomicSwiftLoad(&mAtomicValue)
    }
    
    public mutating func store(by value: RawType) {
        AtomicSwiftStore(&mAtomicValue, value)
    }
    
    public mutating func exchange(with value: RawType) -> RawType {
        return AtomicSwiftExchange(&mAtomicValue, value)
    }
    
    public mutating func cas(expected: UnsafeMutablePointer<RawType>, desired: RawType) -> Bool {
        return AtomicSwiftCAS(&mAtomicValue, expected, desired)
    }
    
    public mutating func fetch_add(operand: RawType) -> RawType {
        return AtomicSwiftFetchAdd(&mAtomicValue, operand)
    }
    
    public mutating func fetch_sub(operand: RawType) -> RawType {
        return AtomicSwiftFetchSub(&mAtomicValue, operand)
    }
    
    public mutating func fetch_or(operand: RawType) -> RawType {
        return AtomicSwiftFetchOr(&mAtomicValue, operand)
    }
    
    public mutating func fetch_xor(operand: RawType) -> RawType {
        return AtomicSwiftFetchXor(&mAtomicValue, operand)
    }
    
    public mutating func fetch_and(operand: RawType) -> RawType {
        return AtomicSwiftFetchAnd(&mAtomicValue, operand)
    }
}

// MARK: AtomicIntPtr
/** 64位无符号整数原子类型 */
public struct AtomicIntPtr: AtomicType {
    
    private var mAtomicValue = AtomicIntPtrSwift()
    
    public typealias RawType = intptr_t
    
    public init() {
        AtomicSwiftInit(&mAtomicValue, 0)
    }
    
    public init(value: RawType) {
        AtomicSwiftInit(&mAtomicValue, value)
    }
    
    public mutating func load() -> RawType {
        return AtomicSwiftLoad(&mAtomicValue)
    }
    
    public mutating func store(by value: RawType) {
        AtomicSwiftStore(&mAtomicValue, value)
    }
    
    public mutating func exchange(with value: RawType) -> RawType {
        return AtomicSwiftExchange(&mAtomicValue, value)
    }
    
    public mutating func cas(expected: UnsafeMutablePointer<RawType>, desired: RawType) -> Bool {
        return AtomicSwiftCAS(&mAtomicValue, expected, desired)
    }
    
    public mutating func fetch_add(operand: RawType) -> RawType {
        return AtomicSwiftFetchAdd(&mAtomicValue, operand)
    }
    
    public mutating func fetch_sub(operand: RawType) -> RawType {
        return AtomicSwiftFetchSub(&mAtomicValue, operand)
    }
    
    public mutating func fetch_or(operand: RawType) -> RawType {
        return AtomicSwiftFetchOr(&mAtomicValue, operand)
    }
    
    public mutating func fetch_xor(operand: RawType) -> RawType {
        return AtomicSwiftFetchXor(&mAtomicValue, operand)
    }
    
    public mutating func fetch_and(operand: RawType) -> RawType {
        return AtomicSwiftFetchAnd(&mAtomicValue, operand)
    }
}

// MARK: AtomicUIntPtr
/** 64位无符号整数原子类型 */
public struct AtomicUIntPtr: AtomicType {
    
    private var mAtomicValue = AtomicUIntPtrSwift()
    
    public typealias RawType = uintptr_t
    
    public init() {
        AtomicSwiftInit(&mAtomicValue, 0)
    }
    
    public init(value: RawType) {
        AtomicSwiftInit(&mAtomicValue, value)
    }
    
    public mutating func load() -> RawType {
        return AtomicSwiftLoad(&mAtomicValue)
    }
    
    public mutating func store(by value: RawType) {
        AtomicSwiftStore(&mAtomicValue, value)
    }
    
    public mutating func exchange(with value: RawType) -> RawType {
        return AtomicSwiftExchange(&mAtomicValue, value)
    }
    
    public mutating func cas(expected: UnsafeMutablePointer<RawType>, desired: RawType) -> Bool {
        return AtomicSwiftCAS(&mAtomicValue, expected, desired)
    }
    
    public mutating func fetch_add(operand: RawType) -> RawType {
        return AtomicSwiftFetchAdd(&mAtomicValue, operand)
    }
    
    public mutating func fetch_sub(operand: RawType) -> RawType {
        return AtomicSwiftFetchSub(&mAtomicValue, operand)
    }
    
    public mutating func fetch_or(operand: RawType) -> RawType {
        return AtomicSwiftFetchOr(&mAtomicValue, operand)
    }
    
    public mutating func fetch_xor(operand: RawType) -> RawType {
        return AtomicSwiftFetchXor(&mAtomicValue, operand)
    }
    
    public mutating func fetch_and(operand: RawType) -> RawType {
        return AtomicSwiftFetchAnd(&mAtomicValue, operand)
    }
}

