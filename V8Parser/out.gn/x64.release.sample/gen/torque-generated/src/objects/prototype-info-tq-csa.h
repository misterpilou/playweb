#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_PROTOTYPE_INFO_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_PROTOTYPE_INFO_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

  TNode<Map> kPrototypeInfoMap_0(compiler::CodeAssemblerState* state_);
TNode<PrototypeInfo> Cast_PrototypeInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<HeapObject> LoadPrototypeInfoJsModuleNamespace_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o);
void StorePrototypeInfoJsModuleNamespace_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o, TNode<HeapObject> p_v);
TNode<Object> LoadPrototypeInfoPrototypeUsers_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o);
void StorePrototypeInfoPrototypeUsers_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o, TNode<Object> p_v);
TNode<Smi> LoadPrototypeInfoRegistrySlot_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o);
void StorePrototypeInfoRegistrySlot_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o, TNode<Smi> p_v);
TNode<Object> LoadPrototypeInfoValidityCell_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o);
void StorePrototypeInfoValidityCell_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o, TNode<Object> p_v);
TNode<MaybeObject> LoadPrototypeInfoObjectCreateMap_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o);
void StorePrototypeInfoObjectCreateMap_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o, TNode<MaybeObject> p_v);
TNode<Smi> LoadPrototypeInfoBitField_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o);
void StorePrototypeInfoBitField_0(compiler::CodeAssemblerState* state_, TNode<PrototypeInfo> p_o, TNode<Smi> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_PROTOTYPE_INFO_TQ_H_
