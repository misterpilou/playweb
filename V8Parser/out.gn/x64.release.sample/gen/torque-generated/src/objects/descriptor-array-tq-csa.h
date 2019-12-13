#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_DESCRIPTOR_ARRAY_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_DESCRIPTOR_ARRAY_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<FixedArray> LoadEnumCacheKeys_0(compiler::CodeAssemblerState* state_, TNode<EnumCache> p_o);
void StoreEnumCacheKeys_0(compiler::CodeAssemblerState* state_, TNode<EnumCache> p_o, TNode<FixedArray> p_v);
TNode<FixedArray> LoadEnumCacheIndices_0(compiler::CodeAssemblerState* state_, TNode<EnumCache> p_o);
void StoreEnumCacheIndices_0(compiler::CodeAssemblerState* state_, TNode<EnumCache> p_o, TNode<FixedArray> p_v);
TNode<Uint16T> LoadDescriptorArrayNumberOfAllDescriptors_0(compiler::CodeAssemblerState* state_, TNode<DescriptorArray> p_o);
void StoreDescriptorArrayNumberOfAllDescriptors_0(compiler::CodeAssemblerState* state_, TNode<DescriptorArray> p_o, TNode<Uint16T> p_v);
TNode<Uint16T> LoadDescriptorArrayNumberOfDescriptors_0(compiler::CodeAssemblerState* state_, TNode<DescriptorArray> p_o);
void StoreDescriptorArrayNumberOfDescriptors_0(compiler::CodeAssemblerState* state_, TNode<DescriptorArray> p_o, TNode<Uint16T> p_v);
TNode<Uint16T> LoadDescriptorArrayRawNumberOfMarkedDescriptors_0(compiler::CodeAssemblerState* state_, TNode<DescriptorArray> p_o);
void StoreDescriptorArrayRawNumberOfMarkedDescriptors_0(compiler::CodeAssemblerState* state_, TNode<DescriptorArray> p_o, TNode<Uint16T> p_v);
TNode<Uint16T> LoadDescriptorArrayFiller16Bits_0(compiler::CodeAssemblerState* state_, TNode<DescriptorArray> p_o);
void StoreDescriptorArrayFiller16Bits_0(compiler::CodeAssemblerState* state_, TNode<DescriptorArray> p_o, TNode<Uint16T> p_v);
TNode<EnumCache> LoadDescriptorArrayEnumCache_0(compiler::CodeAssemblerState* state_, TNode<DescriptorArray> p_o);
void StoreDescriptorArrayEnumCache_0(compiler::CodeAssemblerState* state_, TNode<DescriptorArray> p_o, TNode<EnumCache> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_DESCRIPTOR_ARRAY_TQ_H_
