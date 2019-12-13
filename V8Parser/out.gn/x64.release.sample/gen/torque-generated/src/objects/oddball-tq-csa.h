#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_ODDBALL_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_ODDBALL_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Float64T> LoadOddballToNumberRaw_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_o);
void StoreOddballToNumberRaw_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_o, TNode<Float64T> p_v);
TNode<String> LoadOddballToString_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_o);
void StoreOddballToString_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_o, TNode<String> p_v);
TNode<Number> LoadOddballToNumber_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_o);
void StoreOddballToNumber_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_o, TNode<Number> p_v);
TNode<String> LoadOddballTypeOf_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_o);
void StoreOddballTypeOf_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_o, TNode<String> p_v);
TNode<Smi> LoadOddballKind_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_o);
void StoreOddballKind_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_o, TNode<Smi> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_ODDBALL_TQ_H_
