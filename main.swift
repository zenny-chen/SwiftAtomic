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

