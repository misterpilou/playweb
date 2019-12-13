#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_REGEXP_MATCH_ALL_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_REGEXP_MATCH_ALL_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Object> RegExpPrototypeMatchAllImpl_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_receiver, TNode<Object> p_string);
TNode<BoolT> HasDoneFlag_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_flags);
TNode<BoolT> HasGlobalFlag_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_flags);
TNode<BoolT> HasUnicodeFlag_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_flags);
void SetDoneFlag_0(compiler::CodeAssemblerState* state_, TNode<JSRegExpStringIterator> p_iterator, TNode<Smi> p_flags);
TNode<JSRegExp> UnsafeCast_JSRegExp_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);
TNode<JSRegExp> UnsafeCast_FastJSRegExp_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);
TNode<JSRegExpStringIterator> Cast_JSRegExpStringIterator_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSArray> UnsafeCast_JSRegExpResult_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);
TNode<String> UnsafeCast_String_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_REGEXP_MATCH_ALL_TQ_H_
