#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_MODULE_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_MODULE_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<ObjectHashTable> LoadModuleExports_0(compiler::CodeAssemblerState* state_, TNode<Module> p_o);
void StoreModuleExports_0(compiler::CodeAssemblerState* state_, TNode<Module> p_o, TNode<ObjectHashTable> p_v);
TNode<Smi> LoadModuleHash_0(compiler::CodeAssemblerState* state_, TNode<Module> p_o);
void StoreModuleHash_0(compiler::CodeAssemblerState* state_, TNode<Module> p_o, TNode<Smi> p_v);
TNode<Smi> LoadModuleStatus_0(compiler::CodeAssemblerState* state_, TNode<Module> p_o);
void StoreModuleStatus_0(compiler::CodeAssemblerState* state_, TNode<Module> p_o, TNode<Smi> p_v);
TNode<HeapObject> LoadModuleModuleNamespace_0(compiler::CodeAssemblerState* state_, TNode<Module> p_o);
void StoreModuleModuleNamespace_0(compiler::CodeAssemblerState* state_, TNode<Module> p_o, TNode<HeapObject> p_v);
TNode<Object> LoadModuleException_0(compiler::CodeAssemblerState* state_, TNode<Module> p_o);
void StoreModuleException_0(compiler::CodeAssemblerState* state_, TNode<Module> p_o, TNode<Object> p_v);
TNode<Module> LoadJSModuleNamespaceModule_0(compiler::CodeAssemblerState* state_, TNode<JSModuleNamespace> p_o);
void StoreJSModuleNamespaceModule_0(compiler::CodeAssemblerState* state_, TNode<JSModuleNamespace> p_o, TNode<Module> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_MODULE_TQ_H_
