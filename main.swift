//
//  main.swift
//  SwiftAtomic
//
//  Created by Zenny Chen on 2016/9/25.
//  Copyright © 2016年 GreenGames Studio. All rights reserved.
//

import Foundation

print("Hello, World!")

let a = size_t(100)

let size = MemoryLayout.size(ofValue: a)
print("a = \(a), size is: \(size)")

let type: size_t.Type = type(of: a)
print("type of a is: \(type)")
print("minimum value is: \(type.min)")


// MARK: atomic test

fileprivate func atomBoolTest() {
    
    var atom = AtomicBool(value: true)
    var value = atom.load()
    print("The initial atom bool value is: \(value)")
    atom.store(by: false)
    value = atom.load()
    print("Now, the atom bool value is: \(value)")
    
    let value2 = atom.exchange(with: true)
    value = atom.load()
    print("Before exchange: \(value2), after exchange: \(value)")
    
    value = atom.load()
    value = !value  // 模拟被读取的值受外界破坏
    var bResult = atom.cas(expected: &value, desired: false)
    value = atom.load()
    print("cas result: \(bResult), value = \(value)")
    
    value = atom.load()
    bResult = atom.cas(expected: &value, desired: false)
    value = atom.load()
    print("cas result: \(bResult), new value: \(value)")
    
    // let _ = atom.fetch_add(operand: false)
}

fileprivate func atomByteTest() {
    
    var atom = AtomicByte(value: 10)
    var value = atom.load()
    print("The initial atom byte value is: \(value)")
    atom.store(by: value + 100)
    value = atom.load()
    print("Now, the atom byte value is: \(value)")
    
    var value2 = atom.exchange(with: -100)
    value = atom.load()
    print("Before exchange: \(value2), after exchange: \(value)")
    
    value = atom.load()
    value += 1  // 模拟被读取的值受外界破坏
    var bResult = atom.cas(expected: &value, desired: 10)
    value = atom.load()
    print("cas result: \(bResult), value = \(value)")
    
    value = atom.load()
    bResult = atom.cas(expected: &value, desired: 10)
    value = atom.load()
    print("cas result: \(bResult), new value: \(value)")
    
    value = atom.fetch_add(operand: 5)
    value2 = atom.load()
    print("before add: \(value), after add: \(value2)")
    
    value = atom.fetch_sub(operand: 5)
    value2 = atom.load()
    print("before sub: \(value), after sub: \(value2)")
}

fileprivate func atomUByteTest() {
    
    var atom = AtomicUByte(value: 10)
    var value = atom.load()
    print("The initial atom ubyte value is: \(value)")
    atom.store(by: value + 100)
    value = atom.load()
    print("Now, the atom ubyte value is: \(value)")
    
    var value2 = atom.exchange(with: 250)
    value = atom.load()
    print("Before exchange: \(value2), after exchange: \(value)")
    
    value = atom.load()
    value += 1  // 模拟被读取的值受外界破坏
    var bResult = atom.cas(expected: &value, desired: 10)
    value = atom.load()
    print("cas result: \(bResult), value = \(value)")
    
    value = atom.load()
    bResult = atom.cas(expected: &value, desired: 10)
    value = atom.load()
    print("cas result: \(bResult), new value: \(value)")
    
    value = atom.fetch_add(operand: 5)
    value2 = atom.load()
    print("before add: \(value), after add: \(value2)")
    
    value = atom.fetch_sub(operand: 5)
    value2 = atom.load()
    print("before sub: \(value), after sub: \(value2)")
}

fileprivate func atomShortTest() {
    
    var atom = AtomicUByte(value: 10)
    var value = atom.load()
    print("The initial atom short value is: \(value)")
    atom.store(by: value + 100)
    value = atom.load()
    print("Now, the atom short value is: \(value)")
    
    var value2 = atom.exchange(with: 250)
    value = atom.load()
    print("Before exchange: \(value2), after exchange: \(value)")
    
    value = atom.load()
    value += 1  // 模拟被读取的值受外界破坏
    var bResult = atom.cas(expected: &value, desired: 10)
    value = atom.load()
    print("cas result: \(bResult), value = \(value)")
    
    value = atom.load()
    bResult = atom.cas(expected: &value, desired: 10)
    value = atom.load()
    print("cas result: \(bResult), new value: \(value)")
    
    value = atom.fetch_add(operand: 5)
    value2 = atom.load()
    print("before add: \(value), after add: \(value2)")
    
    value = atom.fetch_sub(operand: 5)
    value2 = atom.load()
    print("before sub: \(value), after sub: \(value2)")
}

fileprivate func atomUShortTest() {
    
    var atom = AtomicUShort(value: 10)
    var value = atom.load()
    print("The initial atom ushort value is: \(value)")
    atom.store(by: value + 100)
    value = atom.load()
    print("Now, the atom ushort value is: \(value)")
    
    var value2 = atom.exchange(with: 250)
    value = atom.load()
    print("Before exchange: \(value2), after exchange: \(value)")
    
    value = atom.load()
    value += 1  // 模拟被读取的值受外界破坏
    var bResult = atom.cas(expected: &value, desired: 10)
    value = atom.load()
    print("cas result: \(bResult), value = \(value)")
    
    value = atom.load()
    bResult = atom.cas(expected: &value, desired: 10)
    value = atom.load()
    print("cas result: \(bResult), new value: \(value)")
    
    value = atom.fetch_add(operand: 5)
    value2 = atom.load()
    print("before add: \(value), after add: \(value2)")
    
    value = atom.fetch_sub(operand: 5)
    value2 = atom.load()
    print("before sub: \(value), after sub: \(value2)")
}

fileprivate func atomIntTest() {
    
    var atom = AtomicInt(value: 10)
    var value = atom.load()
    print("The initial atom int value is: \(value)")
    atom.store(by: value + 100)
    value = atom.load()
    print("Now, the atom int value is: \(value)")
    
    var value2 = atom.exchange(with: -100)
    value = atom.load()
    print("Before exchange: \(value2), after exchange: \(value)")
    
    value = atom.load()
    value += 1  // 模拟被读取的值受外界破坏
    var bResult = atom.cas(expected: &value, desired: 10)
    value = atom.load()
    print("cas result: \(bResult), value = \(value)")
    
    value = atom.load()
    bResult = atom.cas(expected: &value, desired: 10)
    value = atom.load()
    print("cas result: \(bResult), new value: \(value)")
    
    value = atom.fetch_add(operand: 5)
    value2 = atom.load()
    print("before add: \(value), after add: \(value2)")
    
    value = atom.fetch_sub(operand: 5)
    value2 = atom.load()
    print("before sub: \(value), after sub: \(value2)")
}

fileprivate func atomUIntTest() {
    
    var atom = AtomicUInt(value: 10)
    var value = atom.load()
    print("The initial atom uint value is: \(value)")
    atom.store(by: value + 100)
    value = atom.load()
    print("Now, the atom uint value is: \(value)")
    
    var value2 = atom.exchange(with: 10000)
    value = atom.load()
    print("Before exchange: \(value2), after exchange: \(value)")
    
    value = atom.load()
    value += 1  // 模拟被读取的值受外界破坏
    var bResult = atom.cas(expected: &value, desired: 10)
    value = atom.load()
    print("cas result: \(bResult), value = \(value)")
    
    value = atom.load()
    bResult = atom.cas(expected: &value, desired: 10)
    value = atom.load()
    print("cas result: \(bResult), new value: \(value)")
    
    value = atom.fetch_add(operand: 5)
    value2 = atom.load()
    print("before add: \(value), after add: \(value2)")
    
    value = atom.fetch_sub(operand: 5)
    value2 = atom.load()
    print("before sub: \(value), after sub: \(value2)")
}

fileprivate func atomLongTest() {
    
    var atom = AtomicLong(value: 10)
    var value = atom.load()
    print("The initial atom long value is: \(value)")
    atom.store(by: value + 100)
    value = atom.load()
    print("Now, the atom long value is: \(value)")
    
    var value2 = atom.exchange(with: 10000)
    value = atom.load()
    print("Before exchange: \(value2), after exchange: \(value)")
    
    value = atom.load()
    value += 1  // 模拟被读取的值受外界破坏
    var bResult = atom.cas(expected: &value, desired: 10)
    value = atom.load()
    print("cas result: \(bResult), value = \(value)")
    
    value = atom.load()
    bResult = atom.cas(expected: &value, desired: 10)
    value = atom.load()
    print("cas result: \(bResult), new value: \(value)")
    
    value = atom.fetch_add(operand: 5)
    value2 = atom.load()
    print("before add: \(value), after add: \(value2)")
    
    value = atom.fetch_sub(operand: 5)
    value2 = atom.load()
    print("before sub: \(value), after sub: \(value2)")
}

fileprivate func atomULongTest() {
    
    var atom = AtomicULong(value: 10)
    var value = atom.load()
    print("The initial atom ulong value is: \(value)")
    atom.store(by: value + 100)
    value = atom.load()
    print("Now, the atom ulong value is: \(value)")
    
    var value2 = atom.exchange(with: 10000)
    value = atom.load()
    print("Before exchange: \(value2), after exchange: \(value)")
    
    value = atom.load()
    value += 1  // 模拟被读取的值受外界破坏
    var bResult = atom.cas(expected: &value, desired: 10)
    value = atom.load()
    print("cas result: \(bResult), value = \(value)")
    
    value = atom.load()
    bResult = atom.cas(expected: &value, desired: 10)
    value = atom.load()
    print("cas result: \(bResult), new value: \(value)")
    
    value = atom.fetch_add(operand: 5)
    value2 = atom.load()
    print("before add: \(value), after add: \(value2)")
    
    value = atom.fetch_sub(operand: 5)
    value2 = atom.load()
    print("before sub: \(value), after sub: \(value2)")
}

fileprivate func atomIntPtrTest() {
    
    var atom = AtomicIntPtr(value: 10)
    var value = atom.load()
    print("The initial atom intptr value is: \(value)")
    atom.store(by: value + 100)
    value = atom.load()
    print("Now, the atom intptr value is: \(value)")
    
    var value2 = atom.exchange(with: 10000)
    value = atom.load()
    print("Before exchange: \(value2), after exchange: \(value)")
    
    value = atom.load()
    value += 1  // 模拟被读取的值受外界破坏
    var bResult = atom.cas(expected: &value, desired: 10)
    value = atom.load()
    print("cas result: \(bResult), value = \(value)")
    
    value = atom.load()
    bResult = atom.cas(expected: &value, desired: 10)
    value = atom.load()
    print("cas result: \(bResult), new value: \(value)")
    
    value = atom.fetch_add(operand: 5)
    value2 = atom.load()
    print("before add: \(value), after add: \(value2)")
    
    value = atom.fetch_sub(operand: 5)
    value2 = atom.load()
    print("before sub: \(value), after sub: \(value2)")
}

fileprivate func atomUIntPtrTest() {
    
    var atom = AtomicUIntPtr(value: 10)
    var value = atom.load()
    print("The initial atom uintptr value is: \(value)")
    atom.store(by: value + 100)
    value = atom.load()
    print("Now, the atom uintptr value is: \(value)")
    
    var value2 = atom.exchange(with: 10000)
    value = atom.load()
    print("Before exchange: \(value2), after exchange: \(value)")
    
    value = atom.load()
    value += 1  // 模拟被读取的值受外界破坏
    var bResult = atom.cas(expected: &value, desired: 10)
    value = atom.load()
    print("cas result: \(bResult), value = \(value)")
    
    value = atom.load()
    bResult = atom.cas(expected: &value, desired: 10)
    value = atom.load()
    print("cas result: \(bResult), new value: \(value)")
    
    value = atom.fetch_add(operand: 5)
    value2 = atom.load()
    print("before add: \(value), after add: \(value2)")
    
    value = atom.fetch_sub(operand: 5)
    value2 = atom.load()
    print("before sub: \(value), after sub: \(value2)")
}


atomBoolTest()
atomByteTest()
atomUByteTest()
atomShortTest()
atomUShortTest()
atomIntTest()
atomUIntTest()
atomLongTest()
atomULongTest()
atomIntPtrTest()
atomUIntPtrTest()

print("\n--------\n")

/// 通过泛型定义自己的一个原子数组结构体类型
public struct MyAtomicArray<Element> {

    /// 内部数组容器对象
    private var mArray = Array<Element>()
    
    /// 用于旋锁的原子对象
    private var mFlag = AtomicBool(value: true)
    
    /// 旋锁上锁
    private mutating func spinLock() {
        while !mFlag.exchange(with: false) {
            swiftCPUPause()
        }
    }
    
    /// 旋锁解锁
    private mutating func spinUnlock() {
        mFlag.store(by: true)
    }
    
    /// 默认的构造方法，空实现
    public init() {

    }
    
    /// 用一个数组对本原子数组进行初始化
    ///
    /// 这里要注意的是，初始化过程是非原子的
    /// - parameters:
    ///     - withArray: 已构建好的一个数组
    ///
    public init(withArray: [Element]) {
        mArray.append(contentsOf: withArray)
    }
    
    /// 通过数组下标索引来访问指定数组元素，此操作是原子的
    /// - parameters:
    ///     - index: 指定数组下标索引
    /// - returns: 当前指定的数组元素对象
    public subscript(index: Int) -> Element {
        
        /// 获取指定元素对象
        mutating get {
            spinLock()
            let value = mArray[index]
            spinUnlock()
            return value
        }
        
        /// 更新指定元素对象。默认参数是newValue
        mutating set {
            spinLock()
            mArray[index] = newValue
            spinUnlock()
        }
    }
    
    /// 原子添加一个新的元素
    /// - parameters:
    ///     - parameter newElement: 指定的新元素对象
    ///
    public mutating func append(_ newElement: Element) {
        spinLock()
        mArray.append(newElement)
        spinUnlock()
    }
    
    /// 原子插入一个新的元素
    /// - parameters:
    ///     - newElement: 指定的新元素
    ///     - index: 在指定的index位置插入新元素对象，而此位置原本的元素对象将会往后挪一个索引位置
    ///
    public mutating func insert(_ newElement: Element, at index: Int) {
        spinLock()
        mArray.insert(newElement, at: index)
        spinUnlock()
    }
    
    /// 原子移除指定位置的元素
    /// - parameters:
    ///     - index: 指定的位置索引
    ///
    public mutating func remove(at index: Int) {
        spinLock()
        mArray.remove(at: index)
        spinUnlock()
    }
    
    /// 原子移除本数组所有元素
    public mutating func removeAll() {
        spinLock()
        mArray.removeAll()
        spinUnlock()
    }
    
    /// 原子获取当前数组的长度，这个是只读属性
    public var count: Int {
        
        mutating get {
            spinLock()
            let length = mArray.count
            spinUnlock()
            
            return length
        }
    }
}

// 创建并初始化一个原子数组
var arr = MyAtomicArray(withArray: [1, 2, 3, 4, 5])
//var arr = [1, 2, 3, 4, 5]     // 此普通数组可用于测量非原子数组对象的操作结果
arr[2] += 10
print("arr length: \(arr.count), arr[2] = \(arr[2])")

arr.removeAll()

// 用于标识用户线程是否已执行完毕
var isComplete = false

let beginTime = ProcessInfo.processInfo.systemUptime

// 以下将通过用两个线程给原子数组添加0到1000000的元素来测量其操作的原子性
DispatchQueue.global(qos: .userInitiated).async() {
    for i in 0 ..< 500_000 {
        arr.append(i)
    }
    
    isComplete = true
}

for i in 500_000 ..< 1_000_000 {
    arr.append(i)
}

while !isComplete {
    swiftCPUPause()
}

let spentTime = ProcessInfo.processInfo.systemUptime - beginTime

print("Time spent: \(spentTime * 1000.0) ms")

var sum = Int64(0)
for i in 0 ..< arr.count {
    sum += arr[i]
}

print("sum = \(sum)")

// 测试结果正确性
sum = 0
for i in 0 ..< 1_000_000 {
    sum += i
}

print("test sum = \(sum)")
