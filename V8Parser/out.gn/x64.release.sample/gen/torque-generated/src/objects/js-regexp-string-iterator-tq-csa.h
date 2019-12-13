#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_REGEXP_STRING_ITERATOR_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_REGEXP_STRING_ITERATOR_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<JSReceiver> LoadJSRegExpStringIteratorIteratingRegExp_0(compiler::CodeAssemblerState* state_, TNode<JSRegExpStringIterator> p_o);
void StoreJSRegExpStringIteratorIteratingRegExp_0(compiler::CodeAssemblerState* state_, TNode<JSRegExpStringIterator> p_o, TNode<JSReceiver> p_v);
TNode<String> LoadJSRegExpStringIteratorIteratedString_0(compiler::CodeAssemblerState* state_, TNode<JSRegExpStringIterator> p_o);
void StoreJSRegExpStringIteratorIteratedString_0(compiler::CodeAssemblerState* state_, TNode<JSRegExpStringIterator> p_o, TNode<String> p_v);
TNode<Smi> LoadJSRegExpStringIteratorFlags_0(compiler::CodeAssemblerState* state_, TNode<JSRegExpStringIterator> p_o);
void StoreJSRegExpStringIteratorFlags_0(compiler::CodeAssemblerState* state_, TNode<JSRegExpStringIterator> p_o, TNode<Smi> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_REGEXP_STRING_ITERATOR_TQ_H_
