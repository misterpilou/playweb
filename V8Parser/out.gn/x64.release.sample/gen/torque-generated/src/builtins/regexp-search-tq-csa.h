#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_REGEXP_SEARCH_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_REGEXP_SEARCH_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Object> RegExpPrototypeSearchBodyFast_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_regexp, TNode<String> p_string);
TNode<BoolT> IsRegExpResult_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_execResult);
TNode<Object> RegExpPrototypeSearchBodySlow_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_regexp, TNode<String> p_string);
TNode<JSArray> Cast_JSRegExpResult_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_REGEXP_SEARCH_TQ_H_
