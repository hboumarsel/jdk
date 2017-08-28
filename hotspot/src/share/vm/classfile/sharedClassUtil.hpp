/*
 * Copyright (c) 2014, 2017, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef SHARE_VM_CLASSFILE_SHAREDCLASSUTIL_HPP
#define SHARE_VM_CLASSFILE_SHAREDCLASSUTIL_HPP

#include "classfile/sharedPathsMiscInfo.hpp"
#include "memory/filemap.hpp"

class SharedClassUtil : AllStatic {
public:

  static SharedPathsMiscInfo* allocate_shared_paths_misc_info() {
    return new SharedPathsMiscInfo();
  }

  static SharedPathsMiscInfo* allocate_shared_paths_misc_info(char* buf, int size) {
    return new SharedPathsMiscInfo(buf, size);
  }

  static FileMapInfo::FileMapHeader* allocate_file_map_header() {
    return new FileMapInfo::FileMapHeader();
  }

  static size_t file_map_header_size() {
    return sizeof(FileMapInfo::FileMapHeader);
  }

  static size_t shared_class_path_entry_size() {
    return sizeof(SharedClassPathEntry);
  }

  static void update_shared_classpath(ClassPathEntry *cpe,
                                      SharedClassPathEntry* ent, TRAPS) {}
  static void initialize(TRAPS) {}

  inline static bool is_shared_boot_class(Klass* klass) {
    return (klass->_shared_class_path_index >= 0);
  }
};

#endif // SHARE_VM_CLASSFILE_SHAREDCLASSUTIL_HPP
