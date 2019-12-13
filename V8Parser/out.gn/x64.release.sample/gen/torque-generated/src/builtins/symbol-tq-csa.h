#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_SYMBOL_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_SYMBOL_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Symbol> ThisSymbolValue_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, const char* p_method);
TNode<Symbol> UnsafeCast_Symbol_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_SYMBOL_TQ_H_
