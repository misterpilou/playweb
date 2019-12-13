#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_ALLOCATION_SITE_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_ALLOCATION_SITE_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<AllocationSite> LoadAllocationMementoAllocationSite_0(compiler::CodeAssemblerState* state_, TNode<AllocationMemento> p_o);
void StoreAllocationMementoAllocationSite_0(compiler::CodeAssemblerState* state_, TNode<AllocationMemento> p_o, TNode<AllocationSite> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_ALLOCATION_SITE_TQ_H_
