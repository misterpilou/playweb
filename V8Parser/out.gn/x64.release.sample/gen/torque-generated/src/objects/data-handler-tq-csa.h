#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_DATA_HANDLER_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_DATA_HANDLER_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Object> LoadDataHandlerSmiHandler_0(compiler::CodeAssemblerState* state_, TNode<DataHandler> p_o);
void StoreDataHandlerSmiHandler_0(compiler::CodeAssemblerState* state_, TNode<DataHandler> p_o, TNode<Object> p_v);
TNode<Object> LoadDataHandlerValidityCell_0(compiler::CodeAssemblerState* state_, TNode<DataHandler> p_o);
void StoreDataHandlerValidityCell_0(compiler::CodeAssemblerState* state_, TNode<DataHandler> p_o, TNode<Object> p_v);
TNode<MaybeObject> LoadDataHandlerData1_0(compiler::CodeAssemblerState* state_, TNode<DataHandler> p_o);
void StoreDataHandlerData1_0(compiler::CodeAssemblerState* state_, TNode<DataHandler> p_o, TNode<MaybeObject> p_v);
TNode<MaybeObject> LoadDataHandlerData2_0(compiler::CodeAssemblerState* state_, TNode<DataHandler> p_o);
void StoreDataHandlerData2_0(compiler::CodeAssemblerState* state_, TNode<DataHandler> p_o, TNode<MaybeObject> p_v);
TNode<MaybeObject> LoadDataHandlerData3_0(compiler::CodeAssemblerState* state_, TNode<DataHandler> p_o);
void StoreDataHandlerData3_0(compiler::CodeAssemblerState* state_, TNode<DataHandler> p_o, TNode<MaybeObject> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_DATA_HANDLER_TQ_H_
