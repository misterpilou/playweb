#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_STRUCT_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_STRUCT_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Object> LoadTuple2Value1_0(compiler::CodeAssemblerState* state_, TNode<Tuple2> p_o);
void StoreTuple2Value1_0(compiler::CodeAssemblerState* state_, TNode<Tuple2> p_o, TNode<Object> p_v);
TNode<Object> LoadTuple2Value2_0(compiler::CodeAssemblerState* state_, TNode<Tuple2> p_o);
void StoreTuple2Value2_0(compiler::CodeAssemblerState* state_, TNode<Tuple2> p_o, TNode<Object> p_v);
TNode<Object> LoadAccessorPairGetter_0(compiler::CodeAssemblerState* state_, TNode<AccessorPair> p_o);
void StoreAccessorPairGetter_0(compiler::CodeAssemblerState* state_, TNode<AccessorPair> p_o, TNode<Object> p_v);
TNode<Object> LoadAccessorPairSetter_0(compiler::CodeAssemblerState* state_, TNode<AccessorPair> p_o);
void StoreAccessorPairSetter_0(compiler::CodeAssemblerState* state_, TNode<AccessorPair> p_o, TNode<Object> p_v);
TNode<Smi> LoadClassPositionsStart_0(compiler::CodeAssemblerState* state_, TNode<ClassPositions> p_o);
void StoreClassPositionsStart_0(compiler::CodeAssemblerState* state_, TNode<ClassPositions> p_o, TNode<Smi> p_v);
TNode<Smi> LoadClassPositionsEnd_0(compiler::CodeAssemblerState* state_, TNode<ClassPositions> p_o);
void StoreClassPositionsEnd_0(compiler::CodeAssemblerState* state_, TNode<ClassPositions> p_o, TNode<Smi> p_v);
TNode<Object> LoadTuple3Value1_0(compiler::CodeAssemblerState* state_, TNode<Tuple3> p_o);
void StoreTuple3Value1_0(compiler::CodeAssemblerState* state_, TNode<Tuple3> p_o, TNode<Object> p_v);
TNode<Object> LoadTuple3Value2_0(compiler::CodeAssemblerState* state_, TNode<Tuple3> p_o);
void StoreTuple3Value2_0(compiler::CodeAssemblerState* state_, TNode<Tuple3> p_o, TNode<Object> p_v);
TNode<Object> LoadTuple3Value3_0(compiler::CodeAssemblerState* state_, TNode<Tuple3> p_o);
void StoreTuple3Value3_0(compiler::CodeAssemblerState* state_, TNode<Tuple3> p_o, TNode<Object> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_STRUCT_TQ_H_
