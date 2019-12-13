#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_NAME_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_NAME_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Uint32T> LoadNameHashField_0(compiler::CodeAssemblerState* state_, TNode<Name> p_o);
void StoreNameHashField_0(compiler::CodeAssemblerState* state_, TNode<Name> p_o, TNode<Uint32T> p_v);
TNode<Int32T> LoadSymbolFlags_0(compiler::CodeAssemblerState* state_, TNode<Symbol> p_o);
void StoreSymbolFlags_0(compiler::CodeAssemblerState* state_, TNode<Symbol> p_o, TNode<Int32T> p_v);
TNode<PrimitiveHeapObject> LoadSymbolDescription_0(compiler::CodeAssemblerState* state_, TNode<Symbol> p_o);
void StoreSymbolDescription_0(compiler::CodeAssemblerState* state_, TNode<Symbol> p_o, TNode<PrimitiveHeapObject> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_NAME_TQ_H_
