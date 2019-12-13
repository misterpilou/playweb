#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_COLLECTION_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_COLLECTION_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Object> LoadJSCollectionTable_0(compiler::CodeAssemblerState* state_, TNode<JSCollection> p_o);
void StoreJSCollectionTable_0(compiler::CodeAssemblerState* state_, TNode<JSCollection> p_o, TNode<Object> p_v);
TNode<Object> LoadJSWeakCollectionTable_0(compiler::CodeAssemblerState* state_, TNode<JSWeakCollection> p_o);
void StoreJSWeakCollectionTable_0(compiler::CodeAssemblerState* state_, TNode<JSWeakCollection> p_o, TNode<Object> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_COLLECTION_TQ_H_
