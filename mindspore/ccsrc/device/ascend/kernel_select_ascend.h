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

#ifndef MINDSPORE_MINDSPORE_CCSRC_DEVICE_ASCEND_KERNEL_SELECT_ASCEND_ANFALGO_H_
#define MINDSPORE_MINDSPORE_CCSRC_DEVICE_ASCEND_KERNEL_SELECT_ASCEND_ANFALGO_H_
#include "ir/anf.h"
#include "kernel/kernel_build_info.h"
namespace mindspore {
namespace device {
namespace ascend {
int SelectKernelInfo(const CNodePtr &kernel_node);
bool CheckKernelAccuracySupported(const CNodePtr &kernel_node, const kernel::KernelBuildInfoPtr &new_kernel_build_info);
}  // namespace ascend
}  // namespace device
}  // namespace mindspore

#endif  // MINDSPORE_MINDSPORE_CCSRC_DEVICE_ASCEND_KERNEL_SELECT_ASCEND_ANFALGO_H_
