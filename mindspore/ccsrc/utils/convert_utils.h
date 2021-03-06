/**
 * Copyright 2019 Huawei Technologies Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MINDSPORE_CCSRC_UTILS_CONVERT_UTILS_H_
#define MINDSPORE_CCSRC_UTILS_CONVERT_UTILS_H_

#include <limits>
#include <memory>
#include "pybind11/pybind11.h"

#include "utils/any.h"
#include "ir/base.h"
#include "ir/anf.h"
#include "utils/base_ref.h"

namespace py = pybind11;

namespace mindspore {

py::object AnyToPyData(const Any &value);
py::object BaseRefToPyData(const BaseRef &value);
bool BaseRefToBool(const BaseRef &in, bool *out);
bool ValueToBool(const ValuePtr &in, bool *out);
py::object ValuePtrToPyData(const ValuePtr &value);

inline int SizeToInt(size_t u) {
  if (u > static_cast<size_t>((std::numeric_limits<int>::max)())) {
    MS_LOG(EXCEPTION) << "The size_t value(" << u << ") exceeds the maximum value of int.";
  }
  return static_cast<int>(u);
}

inline uint32_t SizeToUint(size_t u) {
  if (u > static_cast<size_t>((std::numeric_limits<uint32_t>::max)())) {
    MS_LOG(EXCEPTION) << "The size_t value(" << u << ") exceeds the maximum value of uint32_t.";
  }
  return static_cast<uint32_t>(u);
}

inline int64_t SizeToLong(size_t u) {
  if (u > static_cast<size_t>((std::numeric_limits<int64_t>::max)())) {
    MS_LOG(EXCEPTION) << "The size_t value(" << u << ") exceeds the maximum value of int64_t.";
  }
  return static_cast<int64_t>(u);
}

inline size_t IntToSize(int u) {
  if (u < 0) {
    MS_LOG(EXCEPTION) << "The int value(" << u << ") is less than 0.";
  }
  return static_cast<size_t>(u);
}

inline size_t LongToSize(int64_t u) {
  if (u < 0) {
    MS_LOG(EXCEPTION) << "The int64_t value(" << u << ") is less than 0.";
  }
  return static_cast<size_t>(u);
}

inline size_t FloatToSize(float u) {
  if (u < 0) {
    MS_LOG(EXCEPTION) << "The float value(" << u << ") is less than 0.";
  }

  if (u > static_cast<float>((std::numeric_limits<size_t>::max)())) {
    MS_LOG(EXCEPTION) << "The float value(" << u << ") exceeds the maximum value of size_t.";
  }
  return static_cast<size_t>(u);
}
inline float IntToFloat(int32_t v) { return static_cast<float>(v); }

inline uint32_t IntToUint(int32_t u) {
  if (u < 0) {
    MS_LOG(EXCEPTION) << "The int32_t value(" << u << ") is less than 0.";
  }
  return static_cast<uint32_t>(u);
}

inline int32_t UintToInt(uint32_t u) {
  if (u > static_cast<uint32_t>((std::numeric_limits<int32_t>::max)())) {
    MS_LOG(EXCEPTION) << "The uint32_t value(" << u << ") exceeds the maximum value of int32_t.";
  }
  return static_cast<int32_t>(u);
}

inline unsigned int UlongToUint(size_t u) {
  if (u > static_cast<size_t>((std::numeric_limits<unsigned int>::max)())) {
    MS_LOG(EXCEPTION) << "The size_t value(" << u << ") exceeds the maximum value of unsigned int.";
  }
  return static_cast<unsigned int>(u);
}

inline void IntMulWithOverflowCheck(int a, int b, int *c) {
  int out = a * b;
  if (a != 0) {
    bool ok = ((out / a) != b);
    if (ok) {
      MS_LOG(EXCEPTION) << "Mul: a(" << a << ") * b(" << b << ") result is overflow";
    }
  }
  *c = out;
}

inline uint8_t *AddressOffset(void *address, size_t offset) {
  MS_EXCEPTION_IF_NULL(address);
  return static_cast<uint8_t *>(address) + offset;
}

AbstractBasePtr PyListDtype2AbstractTensor(const py::object &shape_obj, const py::object &type_obj);

bool IsGraphOutputValueNodeOrParameter(const AnfNodePtr &output, const py::tuple &args,
                                       const std::shared_ptr<py::object> &ret_val);

}  // namespace mindspore

#endif  // MINDSPORE_CCSRC_UTILS_CONVERT_UTILS_H_
