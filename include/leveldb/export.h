// Copyright (c) 2017 The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef STORAGE_LEVELDB_INCLUDE_EXPORT_H_
#define STORAGE_LEVELDB_INCLUDE_EXPORT_H_

#if !defined(LEVELDB_EXPORT)

#if defined(LEVELDB_SHARED_LIBRARY)
#if defined(OS_WIN)

#if defined(LEVELDB_COMPILE_LIBRARY)
/*
 * _declspec用于指定所给定类型的实例的与Microsoft相关的存储方式。
 * 其它的有关存储方式的修饰符如static与extern等是C和 C++语言的ANSI规范，
 * 而__declspec是一种扩展属性的定义。扩展属性语法简化并标准化了C和C++
 * 语言关于Microsoft的扩展。
 */
#define LEVELDB_EXPORT __declspec(dllexport)
#else
#define LEVELDB_EXPORT __declspec(dllimport)
#endif  // defined(LEVELDB_COMPILE_LIBRARY)

#else  // defined(OS_WIN)
#if defined(LEVELDB_COMPILE_LIBRARY)
/*
 * -fvisibility=default|internal|hidden|protected
 * gcc的visibility是说，如果编译的时候用了这个属性，
 * 那么动态库的符号都是hidden的，除非强制声明。
 * __attribute__((visibility("default")))可以让被声明的函数不被隐藏
 * http://blog.csdn.net/mutourenzhang/article/details/47803803
 */
#define LEVELDB_EXPORT __attribute__((visibility("default")))
#else
#define LEVELDB_EXPORT
#endif
#endif  // defined(OS_WIN)

#else  // defined(LEVELDB_SHARED_LIBRARY)
#define LEVELDB_EXPORT
#endif

#endif  // !defined(LEVELDB_EXPORT)

#endif  // STORAGE_LEVELDB_INCLUDE_EXPORT_H_
