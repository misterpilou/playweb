#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_CODE_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_CODE_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<ByteArray> LoadSourcePositionTableWithFrameCacheSourcePositionTable_0(compiler::CodeAssemblerState* state_, TNode<SourcePositionTableWithFrameCache> p_o);
void StoreSourcePositionTableWithFrameCacheSourcePositionTable_0(compiler::CodeAssemblerState* state_, TNode<SourcePositionTableWithFrameCache> p_o, TNode<ByteArray> p_v);
TNode<Object> LoadSourcePositionTableWithFrameCacheStackFrameCache_0(compiler::CodeAssemblerState* state_, TNode<SourcePositionTableWithFrameCache> p_o);
void StoreSourcePositionTableWithFrameCacheStackFrameCache_0(compiler::CodeAssemblerState* state_, TNode<SourcePositionTableWithFrameCache> p_o, TNode<Object> p_v);
TNode<FixedArray> LoadBytecodeArrayConstantPool_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);
void StoreBytecodeArrayConstantPool_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<FixedArray> p_v);
TNode<ByteArray> LoadBytecodeArrayHandlerTable_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);
void StoreBytecodeArrayHandlerTable_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<ByteArray> p_v);
TNode<HeapObject> LoadBytecodeArraySourcePositionTable_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);
void StoreBytecodeArraySourcePositionTable_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<HeapObject> p_v);
TNode<Int32T> LoadBytecodeArrayFrameSize_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);
void StoreBytecodeArrayFrameSize_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<Int32T> p_v);
TNode<Int32T> LoadBytecodeArrayParameterSize_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);
void StoreBytecodeArrayParameterSize_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<Int32T> p_v);
TNode<Int32T> LoadBytecodeArrayIncomingNewTargetOrGeneratorRegister_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);
void StoreBytecodeArrayIncomingNewTargetOrGeneratorRegister_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<Int32T> p_v);
TNode<Int8T> LoadBytecodeArrayOsrNestingLevel_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);
void StoreBytecodeArrayOsrNestingLevel_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<Int8T> p_v);
TNode<Int8T> LoadBytecodeArrayBytecodeAge_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);
void StoreBytecodeArrayBytecodeAge_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<Int8T> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_CODE_TQ_H_
